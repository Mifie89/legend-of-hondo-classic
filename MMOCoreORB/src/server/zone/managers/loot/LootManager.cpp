#include "LootManager.h"
#include "../loot/LootTableManager.h"
#include "../loot/LootTableTemplate.h"

#include "../../ZoneServer.h"
#include "../../ZoneProcessServerImplementation.h"

#include "../../objects.h"

LootManager::LootManager(ZoneProcessServerImplementation* procServer) {
	processServer = procServer;
}

void LootManager::lootCorpse(Player* player, Creature* creature) {
	//Pre: player wlocked, creature unlocked
	//Post: player wlocked, creature unlocked

	try {
		creature->wlock(player);
		CreatureObject* creatureObject = ((CreatureObject*)creature);

		if (!creature->isInQuadTree()) {
			creature->unlock();
			return;
		}

		if (!creature->isDead()) {
			creature->unlock();
			return;
		}

		if (!creatureObject->isLootOwner(player)) {
			player->sendSystemMessage("error_message", "no_corpse_permission"); //You do not have permission to access this corpse
			creature->unlock();
			return;
		}

		/*
		// DEBUG COUTS
		cout << "Hide type is " << ((CreatureObject*)creature)->getHideType() << "\n";
		cout << "Hide max is " << ((CreatureObject*)creature)->getHideMax() << "\n";

		cout << "Bone type is " << ((CreatureObject*)creature)->getBoneType() << "\n";
		cout << "Bone max is " << ((CreatureObject*)creature)->getBoneMax() << "\n";

		cout << "Meat type is " << ((CreatureObject*)creature)->getMeatType() << "\n";
		cout << "Meat max is " << ((CreatureObject*)creature)->getMeatMax() << "\n";

		cout << "Milk is " << ((CreatureObject*)creature)->getMilk() << "\n";

		cout << "faction is " << ((CreatureObject*)creature)->getCreatureFaction() << "\n";
		cout << "XP is " << ((CreatureObject*)creature)->getXP() << "\n";
		cout << "healer " << ((CreatureObject*)creature)->isHealer() << "\n";
		cout << "pack is " << ((CreatureObject*)creature)->isPack() << "\n";
		cout << "herd is " << ((CreatureObject*)creature)->isHerd() << "\n";
		cout << "Stalker is " << ((CreatureObject*)creature)->isStalker() << "\n";
		cout << "Killer is " << ((CreatureObject*)creature)->isKiller() << "\n";
		cout << "Aggressive is " << ((CreatureObject*)creature)->isAggressive() << "\n";

		cout << "BehaviorScript is " << ((CreatureObject*)creature)->getBehaviorScript() << "\n";

		cout << "Weapon is " << ((CreatureObject*)creature)->getCreatureWeapon() << "\n";
		cout << "WeaponName is " << ((CreatureObject*)creature)->getCreatureWeaponName() << "\n";
		cout << "WeaponTemp is " << ((CreatureObject*)creature)->getCreatureWeaponTemp() << "\n";
		cout << "WeaponClass is " << ((CreatureObject*)creature)->getCreatureWeaponClass() << "\n";
		cout << "WeaponEquipped is " << ((CreatureObject*)creature)->getCreatureWeaponEquipped() << "\n";
		cout << "WeaponMinDamage is " << ((CreatureObject*)creature)->getCreatureWeaponMinDamage() << "\n";
		cout << "WeaponMaxDamage is " << ((CreatureObject*)creature)->getCreatureWeaponMaxDamage() << "\n";
		cout << "WeaponAttackSpeed is " << ((CreatureObject*)creature)->getCreatureWeaponAttackSpeed() << "\n";
		cout << "WeaponDamageType is " << ((CreatureObject*)creature)->getCreatureWeaponDamageType() << "\n";
		cout << "WeaponArmorPiercing is " << ((CreatureObject*)creature)->getCreatureWeaponArmorPiercing() << "\n";

		cout << "Internal damage modifier " << ((CreatureObject*)creature)->getInternalNPCDamageModifier() << "\n";

		cout << "loot group is " << ((CreatureObject*)creature)->getLootGroup() << "\n";
		cout << "Tame is " << ((CreatureObject*)creature)->getTame() << "\n";
		//end debug COUTS
		*/

		createLoot(creature, player);

		lootCredits(player, creature);

		Container* lootContainer = creature->getLootContainer();

		if (lootContainer != NULL && lootContainer->objectsSize() > 0) {
			for (int i = lootContainer->objectsSize() - 1; i >= 0 && !player->hasFullInventory(); --i) {
				TangibleObject* lootItem = (TangibleObject*) lootContainer->getObject(i);

				moveObject(lootItem, player, creature);
			}

			player->sendSystemMessage("base_player", "corpse_looted");
		} else
			player->sendSystemMessage("error_message", "corpse_empty");


		creature->wasLooted();

		creature->unlock();

	} catch (...) {
		cout << "Unreported exception caught in LootManager::lootCorpse(Player* player, Creature* creature)";
		creature->unlock();
	}
}

void LootManager::moveObject(TangibleObject* object, Player* player, Creature* creature) {
	// Pre: everything wlocked
	SceneObjectDestroyMessage* msg = new SceneObjectDestroyMessage(object);
	creature->broadcastMessage(msg);

	Container* lootContainer = creature->getLootContainer();
	lootContainer->removeObject(object->getObjectID());

	object->setObjectID(player->getNewItemID());
	player->addInventoryItem(object);

	object->sendTo(player);

	object->setPersistent(false);

	if (player->getGroupObject() != NULL) {
		stringstream grouptxt;
		grouptxt << player->getCharacterName().c_str() << " looted " << object->getName().c_str() << "\\#ffffff from " << creature->getCharacterName().c_str();

		unicode utxt = unicode(grouptxt.str());
		BaseMessage* packet = new ChatSystemMessage(utxt);

		player->getGroupObject()->broadcastMessage(packet);
	}
}

void LootManager::lootCredits(Player* player, Creature* creature) {
	// Pre: player && creature wlocked

	int credits = creature->getCashCredits();

	if (credits > 0) {
		creature->setCashCredits(0);

		player->addCashCredits(credits);

		stringstream creditText;
		creditText << "You loot " << credits << " credits from corpse of " << creature->getCharacterName().c_str() << ".";

		player->sendSystemMessage(creditText.str());
	}
}

void LootManager::showLoot(Player* player, Creature* creature) {
	try {
		creature->wlock(player);

		if (!creature->isInQuadTree()) {
			creature->unlock();
			return;
		}

		if (!creature->isDead()) {
			creature->unlock();
			return;
		}

		if (!creature->isLootOwner(player)) {
			player->sendSystemMessage("error_message", "no_corpse_permission");
			creature->unlock();
			return;
		}

		createLoot(creature, player);

		lootCredits(player, creature);

		Container* lootContainer = creature->getLootContainer();
		lootContainer->sendTo(player);

		lootContainer->openTo(player);

		creature->unlock();
	} catch (...) {
		cout << "Unreported exception caugh in void LootManager::showLoot(Player* player, Creature* creature)";
		creature->unlock();
	}
}

void LootManager::lootObject(Player* player, Creature* creature, uint64 objectID) {
	//Pre: player wlocked

	try {
		creature->wlock(player);

		if (!creature->isLootOwner(player)) {
			player->sendSystemMessage("error_message", "no_corpse_permission");
			creature->unlock();
			return;
		}

		Container* lootContainer = creature->getLootContainer();

		if (lootContainer == NULL) {
			creature->unlock();
			return;
		}

		SceneObject* lootItem = (SceneObject*) lootContainer->getObject(objectID);

		if (lootItem == NULL || !lootItem->isTangible()) {
			creature->unlock();
			return;
		}

		if (!player->hasFullInventory())
			moveObject((TangibleObject*) lootItem, player, creature);

		creature->unlock();
	} catch (...) {
		cout << "Unreported exception caugh in void LootManager::lootObject(Player* player, Creature* creature, uint64 objectID)";
		creature->unlock();
	}
}

void LootManager::createLoot(Creature* creature, Player* player) {
	//Pre: creature wlocked
	//Post: creature wlocked

	if (creature->hasLootCreated())
		return;

	Container* lootContainer = creature->getLootContainer();

	if (lootContainer == NULL)
		return;

	if (lootContainer->objectsSize() > 0)
		return;

	int creatureLevel = creature->getLevel();

	if (creatureLevel == 0)
		creatureLevel = 1;

	creature->setCashCredits(0);

	/* old code
	int itemcount = System::random(creatureLevel / 100) + 1;

	for (int i = 0; i < itemcount; ++i) {
		int lootchance = System::random(100);

		int creaturechancemodifier = creatureLevel / 100;

		if (lootchance < 5 + creaturechancemodifier) {
			createArmorLoot(creature, creatureLevel + 50);
		} else if (lootchance < 10 + 2 * creaturechancemodifier) {
			createClothingLoot(creature, creatureLevel + 50);
		} else if (lootchance < 15 + 3 * creaturechancemodifier) {
			createWeaponLoot(creature, creatureLevel + 50);
		} else if (lootchance < 20 + 4 * creaturechancemodifier) {
			createAttachmentLoot(creature, creatureLevel + 50);
		} else if (lootchance < 25 + 5 * creaturechancemodifier) {
			createPowerupLoot(creature, creatureLevel + 50);
		} else if (lootchance < 25 + 5 * creaturechancemodifier) {
			createJunkLoot(creature);
		}

	}
	 */

	LootTableManager* ltm;
	Zone* zone = creature->getZone();

	if (zone != NULL) {
		ZoneServer* zoneServer = zone->getZoneServer();

		if (zoneServer != NULL) {
			ltm = zoneServer->getLootTableManager();
		} else {
			return;
		}
	} else {
		return;
	}

	ltm->createLootItem(creature, creatureLevel, player);

	creature->setCashCredits(creatureLevel * System::random(1234) / 25);
	creature->setLootCreated(true);
}


void LootManager::createWeaponLoot(Creature* creature, int creatureLevel) {
	Weapon* item = NULL;

	string certification = "";

	uint32 objectCRC = creature->getObjectCRC();

	//ankerpunkt
	//uint32 lootGroup = creature->getLootGroup();

	switch (System::random(23)) {
	case 0 :	// UNARMED
		item = new UnarmedMeleeWeapon(creature,
				"object/weapon/melee/special/shared_vibroknuckler.iff",	unicode("Vibroknuckler"), "vibroknuckler", false);
		item->setDamageType(WeaponImplementation::KINETIC);
		item->setArmorPiercing(WeaponImplementation::LIGHT);
		certification = "cert_vibroknuckler";
		break;
	case 1 :	// ONEHANDED
		item = new OneHandedMeleeWeapon(creature,
				"object/weapon/melee/baton/shared_baton_gaderiffi.iff", unicode("Gaderiffi"), "baton_gaderiffi", false);
		item->setDamageType(WeaponImplementation::KINETIC);
		item->setArmorPiercing(WeaponImplementation::NONE);
		certification = "cert_baton_gaderiffi";
		break;
	case 2 :	// TWOHANDED
		item = new TwoHandedMeleeWeapon(creature,
				"object/weapon/melee/2h_sword/shared_2h_sword_maul.iff", unicode("Power Hammer"), "2h_sword_battleaxe", false);
		item->setDamageType(WeaponImplementation::BLAST);
		item->setArmorPiercing(WeaponImplementation::MEDIUM);
		certification = "cert_sword_2h_maul";
		break;
	case 3 :	// POLEARM
		item = new PolearmMeleeWeapon(creature,
				"object/weapon/melee/polearm/shared_lance_vibrolance.iff", unicode("Vibrolance"), "lance_vibrolance", false);
		item->setDamageType(WeaponImplementation::ELECTRICITY);
		item->setArmorPiercing(WeaponImplementation::LIGHT);
		certification = "cert_lance_vibrolance";
		break;
	case 4 :	// PISTOL
		item = new PistolRangedWeapon(creature,
				"object/weapon/ranged/pistol/shared_pistol_cdef.iff", unicode("CDEF Pistol"), "pistol_cdef", false);
		item->setDamageType(WeaponImplementation::ENERGY);
		item->setArmorPiercing(WeaponImplementation::NONE);
		break;
	case 5 :	// CARBINE
		item = new CarbineRangedWeapon(creature,
				"object/weapon/ranged/carbine/shared_carbine_cdef.iff", unicode("CDEF Carbine"), "carbine_cdef", false);
		item->setDamageType(WeaponImplementation::ENERGY);
		item->setArmorPiercing(WeaponImplementation::NONE);
		break;
	case 6 :	// RIFLE
		item = new RifleRangedWeapon(creature,
				"object/weapon/ranged/rifle/shared_rifle_t21.iff", unicode("T21 Rifle"), "rifle_t21", false);
		item->setDamageType(WeaponImplementation::ENERGY);
		item->setArmorPiercing(WeaponImplementation::HEAVY);
		certification = "cert_rifle_t21";
		break;
	case 7 :	// ONEHANDED
		item = new OneHandedMeleeWeapon(creature,
				"object/weapon/melee/baton/shared_baton_stun.iff", unicode("Stun Baton"), "baton_stun", false);
		item->setDamageType(WeaponImplementation::STUN);
		item->setArmorPiercing(WeaponImplementation::NONE);
		certification = "cert_baton_stun";
		break;
	case 8 :	// TWOHANDED
		item = new TwoHandedMeleeWeapon(creature,
				"object/weapon/melee/2h_sword/shared_2h_sword_scythe.iff", unicode("Scythe"), "2h_sword_scythe", false);
		item->setDamageType(WeaponImplementation::KINETIC);
		item->setArmorPiercing(WeaponImplementation::MEDIUM);
		certification = "cert_sword_2h_scythe";
		break;
	case 9 :	// POLEARM
		item = new PolearmMeleeWeapon(creature,
				"object/weapon/melee/polearm/shared_polearm_vibro_axe.iff", unicode("Long Vibro Axe"), "lance_vibro_axe", false);
		item->setDamageType(WeaponImplementation::KINETIC);
		item->setArmorPiercing(WeaponImplementation::MEDIUM);
		certification = "cert_lance_vibro_axe";
		break;
	case 10 :	// PISTOL
		item = new PistolRangedWeapon(creature,
				"object/weapon/ranged/pistol/shared_pistol_dx2.iff", unicode("DX2 Pistol"), "pistol_dx2", false);
		item->setDamageType(WeaponImplementation::ACID);
		item->setArmorPiercing(WeaponImplementation::LIGHT);
		certification = "cert_pistol_dx2";
		break;
	case 11 :	// CARBINE
		item = new CarbineRangedWeapon(creature,
				"object/weapon/ranged/carbine/shared_carbine_dxr6.iff", unicode("DXR6 Carbine"), "carbine_dxr6", false);
		item->setDamageType(WeaponImplementation::ACID);
		item->setArmorPiercing(WeaponImplementation::LIGHT);
		certification = "cert_carbine_dxr6";
		break;
	case 12 :	// RIFLE
		item = new RifleRangedWeapon(creature,
				"object/weapon/ranged/rifle/shared_rifle_tenloss_dxr6_disruptor_loot.iff", unicode("DXR-6b Disruptor Rifle"), "rifle_tenloss_dxr6", false);
		item->setDamageType(WeaponImplementation::ACID);
		item->setArmorPiercing(WeaponImplementation::MEDIUM);

		item->setAttackSpeed(7.4);
		item->setMinDamage(104);
		item->setMaxDamage(249);
		item->setWoundsRatio(22.7);

		item->setPointBlankAccuracy(-60);
		item->setPointBlankRange(0);

		item->setIdealAccuracy(60);
		item->setIdealRange(54);

		item->setMaxRangeAccuracy(20);
		item->setMaxRange(64);

		item->setHealthAttackCost(22);
		item->setActionAttackCost(44);
		item->setMindAttackCost(54);

		certification = "cert_rifle_t21";  // no cert we need to do it by skill box
		break;
	case 13 :	// POLEARM
		if (objectCRC == 0xAA197516 || objectCRC == 0xF0663601 || objectCRC == 0x158DC349 ||
			objectCRC == 0xB0DC0219 || objectCRC == 0x1FA893FD || objectCRC == 0x90D8EBF8 ||
			objectCRC == 0xAC722907 || objectCRC == 0x2D98A9B3 || objectCRC == 0xD84925C2 ||
			objectCRC == 0x514A2CBF || objectCRC == 0x5861C6A3 || objectCRC == 0x889ADF8D ||
			objectCRC == 0x44F934A9) {
				item = new PolearmMeleeWeapon(creature,
						"object/weapon/melee/polearm/shared_lance_controllerfp_nightsister.iff", unicode("Nightsister Lance"), "lance_controllerfp_nightsister", false);
				item->setDamageType(WeaponImplementation::KINETIC);
				item->setArmorPiercing(WeaponImplementation::NONE);
				item->setMinDamage(7);
				item->setMaxDamage(133);
				item->setDot0Attribute(WeaponImplementation::HEALTH);
				item->setDot0Type(WeaponImplementation::DISEASE);
				item->setDot0Potency(70);
				item->setDot0Strength(40);
				item->setDot0Duration(1200);
				item->setDot0Uses(8000);
				certification = "cert_lance_controllerfp";
		}
		break;
	case 14 :	// PISTOL
		if (creatureLevel > 150) {
			item = new PistolRangedWeapon(creature,
					"object/weapon/ranged/pistol/shared_pistol_geonosian_sonic_blaster_loot.iff", unicode("Genosian Sonic Blaster"), "pistol_sonic_blaster", false);
			item->setDamageType(WeaponImplementation::STUN);
			item->setArmorPiercing(WeaponImplementation::NONE);
			item->setAttackSpeed(2.6);
			item->setMinDamage(65);
			item->setMaxDamage(100);
			item->setWoundsRatio(4);

			item->setPointBlankAccuracy(18);
			item->setPointBlankRange(0);
			item->setIdealAccuracy(34);
			item->setIdealRange(15);
			item->setMaxRangeAccuracy(-90);
			item->setMaxRange(48);
			certification = "cert_pistol_dx2";  // need to add a cert to the db for this
		}
		break;
	case 15 :	// FLAMETHROWER
		item = new SpecialHeavyRangedWeapon(creature,
				"object/weapon/ranged/rifle/shared_rifle_flame_thrower.iff", unicode("Flame Thrower"), "rifle_flame_thrower", false);
		item->setMinDamage(125);
		item->setMaxDamage(377);
		item->setWoundsRatio(36);
		certification = "cert_rifle_flame_thrower";
		break;
	case 16 :	// LAUNCHER PISTOL
		item = new PistolRangedWeapon(creature,
				"object/weapon/ranged/pistol/shared_pistol_launcher.iff", unicode("Launcher Pistol"), "pistol_launcher", false);
		item->setDamageType(WeaponImplementation::BLAST);
		item->setArmorPiercing(WeaponImplementation::NONE);

		item->setAttackSpeed(2.8);
		item->setMinDamage(56);
		item->setMaxDamage(217);
		item->setWoundsRatio(21);

		item->setPointBlankAccuracy(0);
		item->setPointBlankRange(0);
		item->setIdealAccuracy(4);
		item->setIdealRange(0);
		item->setMaxRangeAccuracy(0);
		item->setMaxRange(64);

		certification = "cert_pistol_launcher";

		break;
	case 17 :	// LASER CARBINE
		item = new CarbineRangedWeapon(creature,
				"object/weapon/ranged/carbine/shared_carbine_laser.iff", unicode("Laser Carbine"), "carbine_laser", false);
		item->setDamageType(WeaponImplementation::ENERGY);
		item->setArmorPiercing(WeaponImplementation::MEDIUM);

		item->setAttackSpeed(5.0);
		item->setMinDamage(7);
		item->setMaxDamage(129);
		item->setWoundsRatio(7);

		item->setPointBlankAccuracy(-10);
		item->setPointBlankRange(0);
		item->setIdealAccuracy(3);
		item->setIdealRange(50);
		item->setMaxRangeAccuracy(-40);
		item->setMaxRange(64);

		certification = "cert_carbine_laser";
		break;
	case 18 :	// JAWA ION RIFLE
		item = new RifleRangedWeapon(creature,
				"object/weapon/ranged/rifle/shared_rifle_jawa_ion.iff", unicode("Jawa Ion Rifle"), "rifle_jawa_ion", false);
		item->setDamageType(WeaponImplementation::STUN);
		item->setArmorPiercing(WeaponImplementation::LIGHT);

		item->setAttackSpeed(6.8);
		item->setMinDamage(53);
		item->setMaxDamage(98);
		item->setWoundsRatio(4);

		item->setPointBlankAccuracy(-50);
		item->setPointBlankRange(0);
		item->setIdealAccuracy(15);
		item->setIdealRange(40);
		item->setMaxRangeAccuracy(-80);
		item->setMaxRange(64);

		certification = "cert_rifle_jawa_ion";
		break;
	case 19 :	// VIBROBLADE
		item = new OneHandedMeleeWeapon(creature,
				"object/weapon/melee/knife/shared_knife_vibroblade.iff", unicode("A Vibroblade"), "knife_vibroblade", false);
		item->setArmorPiercing(WeaponImplementation::LIGHT);
		item->setDamageType(WeaponImplementation::KINETIC);

		item->setAttackSpeed(4.2);
		item->setMinDamage(10);
		item->setMaxDamage(59);
		item->setWoundsRatio(8.0);

		item->setPointBlankAccuracy(3);
		item->setPointBlankRange(0);

		item->setIdealAccuracy(3);
		item->setIdealRange(3);

		item->setMaxRangeAccuracy(3);
		item->setMaxRange(4);

		item->setHealthAttackCost(13);
		item->setActionAttackCost(46);
		item->setMindAttackCost(13);

		certification = "cert_knife_vibroblade";
		break;
	case 20 :	// DE-10 PISTOL
		if (creatureLevel > 150) {
			item = new PistolRangedWeapon(creature,
					"object/weapon/ranged/pistol/shared_pistol_de_10.iff", unicode("DE-10 Pistol"), "pistol_de_10", false);
			item->setDamageType(WeaponImplementation::ENERGY);
			item->setArmorPiercing(WeaponImplementation::LIGHT);
			item->setAttackSpeed(5.6);
			item->setMinDamage(128);
			item->setMaxDamage(320);
			item->setWoundsRatio(38.7);

			item->setPointBlankAccuracy(-2);
			item->setPointBlankRange(0);
			item->setIdealAccuracy(46);
			item->setIdealRange(20);
			item->setMaxRangeAccuracy(-80);
			item->setMaxRange(64);
			certification = "cert_pistol_dx2";  // need to add a cert to the db for this
		}
		break;
	case 21 :	// LIGHT LIGHTNING CANNON
		item = new SpecialHeavyRangedWeapon(creature,
				"object/weapon/ranged/rifle/shared_rifle_lightning.iff", unicode("Light Lightning Cannon"), "rifle_lightning", false);
		item->setType(WeaponImplementation::RIFLELIGHTNING);
		item->setDamageType(WeaponImplementation::ELECTRICITY);
		item->setArmorPiercing(WeaponImplementation::LIGHT);

		item->setAttackSpeed(5.6);
		item->setMinDamage(127.2);
		item->setMaxDamage(257.3);
		item->setWoundsRatio(17.2);

		item->setPointBlankAccuracy(-30);
		item->setPointBlankRange(0);
		item->setIdealAccuracy(20);
		item->setIdealRange(48);
		item->setMaxRangeAccuracy(30);
		item->setMaxRange(64);

		item->setHealthAttackCost(63);
		item->setActionAttackCost(66);
		item->setMindAttackCost(63);

		certification = "cert_rifle_lightning";
		break;
	case 22 :	// ROCKET LAUNCHER
		item = new HeavyRangedWeapon(creature,
				"object/weapon/ranged/heavy/shared_heavy_rocket_launcher.iff", unicode("Rocket Launcher"), "heavy_rocket_launcher", false);
		item->setType(WeaponImplementation::HEAVYROCKETLAUNCHER);
		item->setDamageType(WeaponImplementation::BLAST);
		item->setArmorPiercing(WeaponImplementation::HEAVY);

		item->setAttackSpeed(7.0);
		item->setMinDamage(617.2);
		item->setMaxDamage(987.3);
		item->setWoundsRatio(37);

		item->setPointBlankAccuracy(-100);
		item->setPointBlankRange(0);
		item->setIdealAccuracy(20);
		item->setIdealRange(48);
		item->setMaxRangeAccuracy(30);
		item->setMaxRange(64);

		item->setHealthAttackCost(113);
		item->setActionAttackCost(86);
		item->setMindAttackCost(69);

		item->setUsesRemaining(creatureLevel / (System::random(5) + 5));

		certification = "cert_heavy_rocket_launcher";
		break;
	case 23 :	// RIFLE
		if ((objectCRC == 0xE158FEC1 ) && System::random(10) >= 7) {
			item = new RifleRangedWeapon(creature,
				 	"object/weapon/ranged/rifle/shared_rifle_tusken.iff", unicode("Tusken Rifle"), "rifle_tusken", false);
			item->setDamageType(WeaponImplementation::ENERGY);
			item->setArmorPiercing(WeaponImplementation::LIGHT);
			certification = "cert_rifle_tusken";
		}
		break;
	}

	if (item != NULL) {
		item->setCert(certification);
		item->setWeaponStats(creatureLevel);
		item->setConditionDamage(System::random(649));

		creature->addLootItem(item);
	}
}

void LootManager::createArmorLoot(Creature* creature, int32 creatureLevel) {
	Armor* item = NULL;

	uint32 objectCRC = creature->getObjectCRC();

	switch (System::random(5)){
	case 0:
		switch (System::random(8)) {
		case 0 :
			item = new Armor(creature, 0x7B476F26,
					unicode("Composite Chestplate"), "armor_composite_chestplate", false);
			item->setType(ArmorImplementation::CHEST);
			break;
		case 1 :
			item = new Armor(creature, 0x9AF51EAA,
					unicode("Composite Helmet"), "armor_composite_helmet", false);
			item->setType(ArmorImplementation::HEAD);
			break;
		case 2 :
			item = new Armor(creature, 0xDB91E9DB,
					unicode("Composite Boots"), "armor_composite_boots", false);
			item->setType(ArmorImplementation::FOOT);
			break;
		case 3 :
			item = new Armor(creature, 0x2C35FFA2,
					unicode("Composite Gloves"), "armor_composite_gloves", false);
			item->setType(ArmorImplementation::HAND);
			break;
		case 4 :
			item = new Armor(creature, 0xC294C432,
					unicode("Composite Leggings"), "armor_composite_pants", false);
			item->setType(ArmorImplementation::LEG);
			break;
		case 5 :
			item = new Armor(creature, 0x13A4DA11,
					unicode("Composite Bicep"), "armor_composite_bicep_l", false);
			item->setType(ArmorImplementation::BICEPL);
			break;
		case 6 :
			item = new Armor(creature, 0x63719F82,
					unicode("Composite Bicep"), "armor_composite_bicep_r", false);
			item->setType(ArmorImplementation::BICEPR);
			break;
		case 7 :
			item = new Armor(creature, 0x4DB0192D,
					unicode("Composite Bracer"), "armor_composite_bracer_l", false);
			item->setType(ArmorImplementation::BRACERL);
			break;
		case 8 :
			item = new Armor(creature, 0x3D655CBE,
					unicode("Composite Bracer"), "armor_composite_bracer_r", false);
			item->setType(ArmorImplementation::BRACERR);
			break;
		}
		break;
	case 1:
		if (creatureLevel > 99 && System::random(1) == 1) {
			switch (System::random(8)) {	// BH Armor
			case 0 :
				item = new Armor(creature, 0x4FD29AA3,
						unicode("Bounty Hunter Chestplate"), "armor_bounty_hunter_chestplate", false);
				item->setType(ArmorImplementation::CHEST);
				break;
			case 1 :
				item = new Armor(creature, 0x30DB6875,
						unicode("Bounty Hunter Helmet"), "armor_bounty_hunter_helmet", false);
				item->setType(ArmorImplementation::HEAD);
				break;
			case 2 :
				item = new Armor(creature, 0x219DF586,
						unicode("Bounty Hunter Boots"), "armor_bounty_hunter_boots", false);
				item->setType(ArmorImplementation::FOOT);
				break;
			case 3 :
				item = new Armor(creature, 0x861B897D,
						unicode("Bounty Hunter Gloves"), "armor_bounty_hunter_gloves", false);
				item->setType(ArmorImplementation::HAND);
				break;
			case 4 :
				item = new Armor(creature, 0x9873E13B,
						unicode("Bounty Hunter Leggings"), "armor_bounty_hunter_pants", false);
				item->setType(ArmorImplementation::LEG);
				break;
			case 5 :
				item = new Armor(creature, 0xE37785C9,
						unicode("Bounty Hunter Bicep"), "armor_bounty_hunter_bicep_l", false);
				item->setType(ArmorImplementation::BICEPL);
				break;
			case 6 :
				item = new Armor(creature, 0x93A2C05A,
						unicode("Bounty Hunter Bicep"), "armor_bounty_hunter_bicep_r", false);
				item->setType(ArmorImplementation::BICEPR);
				break;
			case 7 :
				item = new Armor(creature, 0x17573C24,
						unicode("Bounty Hunter Bracer"), "armor_bounty_hunter_bracer_l", false);
				item->setType(ArmorImplementation::BRACERL);
				break;
			case 8 :
				item = new Armor(creature, 0x678279B7,
						unicode("Bounty Hunter Bracer"), "armor_bounty_hunter_bracer_r", false);
				item->setType(ArmorImplementation::BRACERR);
				break;
			}
		}

		break;
	case 2:
		if (creatureLevel > 149 && System::random(2) == 1) {
			switch (System::random(8)) {	// Mando Armor
			case 0 :
				item = new Armor(creature, 0x24525C1C,
						unicode("Mandalorian Chestplate"), "armor_mandalorian_chest", false);
				item->setType(ArmorImplementation::CHEST);
				break;
			case 1 :
				item = new Armor(creature, 0x37A4683E,
						unicode("Mandalorian Helmet"), "armor_mandalorian_helmet", false);
				item->setType(ArmorImplementation::HEAD);
				break;
			case 2 :
				item = new Armor(creature, 0x84AD5603,
						unicode("Mandalorian Boots"), "armor_mandalorian_shoes", false);
				item->setType(ArmorImplementation::FOOT);
				break;
			case 3 :
				item = new Armor(creature, 0x81648936,
						unicode("Mandalorian Gloves"), "armor_mandalorian_gloves", false);
				item->setType(ArmorImplementation::HAND);
				break;
			case 4 :
				item = new Armor(creature, 0x770C3F1B,
						unicode("Mandalorian Leggings"), "armor_mandalorian_pants", false);
				item->setType(ArmorImplementation::LEG);
				break;
			case 5 :
				item = new Armor(creature, 0x82309ECC,
						unicode("Mandalorian Bicep"), "armor_mandalorian_bicep_l", false);
				item->setType(ArmorImplementation::BICEPL);
				break;
			case 6 :
				item = new Armor(creature, 0xF2E5DB5F,
						unicode("Mandalorian Bicep"), "armor_mandalorian_bicep_r", false);
				item->setType(ArmorImplementation::BICEPR);
				break;
			case 7 :
				item = new Armor(creature, 0xF828E204,
						unicode("Mandalorian Bracer"), "armor_mandalorian_bracer_l", false);
				item->setType(ArmorImplementation::BRACERL);
				break;
			case 8 :
				item = new Armor(creature, 0x88FDA797,
						unicode("Mandalorian Bracer"), "armor_mandalorian_bracer_r", false);
				item->setType(ArmorImplementation::BRACERR);
				break;
			}
		}

		break;
	case 3:
		if (objectCRC == 0xBA7F23CD || 0x4E38DA33) {
			switch (System::random(8)) {
			case 0 :
				item = new Armor(creature, 0xF22790E,
						unicode("Stormtrooper Chestplate"), "armor_stormtrooper_chest", false);
				item->setType(ArmorImplementation::CHEST);
				break;
			case 1 :
				item = new Armor(creature, 0xC499637D,
						unicode("Stormtrooper Helmet"), "armor_stormtrooper_helmet", false);
				item->setType(ArmorImplementation::HEAD);
				break;
			case 2 :
				item = new Armor(creature, 0x7833E9D6,
						unicode("Stormtrooper Boots"), "armor_stormtrooper_boots", false);
				item->setType(ArmorImplementation::FOOT);
				break;
			case 3 :
				item = new Armor(creature, 0x72598275,
						unicode("Stormtrooper Gloves"), "armor_stormtrooper_gloves", false);
				item->setType(ArmorImplementation::HAND);
				break;
			case 4 :
				item = new Armor(creature, 0x1863926A,
						unicode("Stormtrooper Leggings"), "armor_stormtrooper_pants", false);
				item->setType(ArmorImplementation::LEG);
				break;
			case 5 :
				item = new Armor(creature, 0x3BC0061C,
						unicode("Stormtrooper Bicep"), "armor_stormtrooper_bicep_l", false);
				item->setType(ArmorImplementation::BICEPL);
				break;
			case 6 :
				item = new Armor(creature, 0x4B15438F,
						unicode("Stormtrooper Bicep"), "armor_stormtrooper_bicep_r", false);
				item->setType(ArmorImplementation::BICEPR);
				break;
			case 7 :
				item = new Armor(creature, 0x97474F75,
						unicode("Stormtrooper Bracer"), "armor_stormtrooper_bracer_l", false);
				item->setType(ArmorImplementation::BRACERL);
				break;
			case 8 :
				item = new Armor(creature, 0xE7920AE6,
						unicode("Stormtrooper Bracer"), "armor_stormtrooper_bracer_r", false);
				item->setType(ArmorImplementation::BRACERR);
				break;
			}
		}

		break;
	case 4:
		if (objectCRC == 0x1527DF01 || objectCRC == 0x71F874) {
			switch (System::random(5)) {
			case 0 :
				item = new Armor(creature, 0x98A41A65,
						unicode("Marine Chestplate"), "armor_marine_chest", false);
				item->setType(ArmorImplementation::CHEST);
				break;
			case 1 :
				item = new Armor(creature, 0x1890B6F4,
						unicode("Marine Helmet"), "armor_marine_helmet", false);
				item->setType(ArmorImplementation::HEAD);
				break;
			case 2 :
				item = new Armor(creature, 0xA06D625,
						unicode("Marine Boots"), "armor_marine_boots", false);
				item->setType(ArmorImplementation::FOOT);
				break;
			case 3 :
				item = new Armor(creature, 0xF3D42F59,
						unicode("Marine Leggings"), "armor_marine_pants", false);
				item->setType(ArmorImplementation::LEG);
				break;
			case 4 :
				item = new Armor(creature, 0x16825F91,
						unicode("Marine Bicep"), "armor_marine_bicep_l", false);
				item->setType(ArmorImplementation::BICEPL);
				break;
			case 5 :
				item = new Armor(creature, 0x66571A02,
						unicode("Marine Bicep"), "armor_marine_bicep_r", false);
				item->setType(ArmorImplementation::BICEPR);
				break;
			}
		}
		break;
	case 5:
		if ((objectCRC == 0xF0663601 || objectCRC == 0xAA197516) && System::random(10) == 7) {
			item = new Armor(creature, 0x2E943BD2, unicode("Nightsister Bicep"), "nightsister_bicep_r", false);
			item->setType(ArmorImplementation::BICEPR);
		break;
		}
	}

	if (item != NULL) {
		item->setHealthEncumbrance((System::random(7) + 9) * 19 / 3 + item->getType());
		item->setActionEncumbrance((System::random(8) + 9) * 18 / 3 + item->getType());
		item->setMindEncumbrance((System::random(9) + 9) * 17 / 3 + item->getType());

		item->setArmorStats(creatureLevel);
		item->setConditionDamage(System::random(item->getMaxCondition() * 3 / 4));

		creature->addLootItem(item);
	}
}

void LootManager::createClothingLoot(Creature* creature, int32 creatureLevel) {
	Wearable* item = NULL;

	uint32 objectCRC = creature->getObjectCRC();

	switch (System::random(5)) {
	case 0 :
		item = new Wearable(creature, 0x29031E7D,
				unicode("Tusken Boots"), "boots_tusken_raider", false);
		item->setObjectSubType(TangibleObjectImplementation::FOOTWEAR);
		break;
	case 1 :
		item = new Wearable(creature, 0x67A25943,
				unicode("Tusken Gloves"), "gloves_tusken_raider", false);
		item->setObjectSubType(TangibleObjectImplementation::HANDWEAR);
		break;
	case 2 :
		item = new Wearable(creature, 0xF7B87D4B,
				unicode("Tusken Helmet"), "helmet_tusken_raider", false);
		item->setObjectSubType(TangibleObjectImplementation::HEADWEAR);
		break;
	case 3 :
		item = new Wearable(creature, 0x50EF8B3E,
				unicode("Tusken Robe"), "robe_tusken_raider", false);
		item->setObjectSubType(TangibleObjectImplementation::ROBE);
		break;
	case 4 :
		item = new Wearable(creature, 0xFC978255,
				unicode("Chef Hat"), "hat_chef", false);
		item->setObjectSubType(TangibleObjectImplementation::HEADWEAR);
		break;
	case 5 :
		item = new Wearable(creature, 0x6CE36E4C,
				unicode("Aakuan Shirt"), "aakuan_shirt", false);
		item->setObjectSubType(TangibleObjectImplementation::SHIRT);
		break;
	}

	if (item != NULL) {
		item->setConditionDamage(System::random(item->getMaxCondition() * 3 / 4));

		creature->addLootItem(item);
	}
}


void LootManager::createJunkLoot(Creature* creature) {
	TangibleObject* item = NULL;

	switch (System::random(10)) {
	case 0 :
		item = new TangibleObject(creature, 0xBC03F94, unicode("a Viewscreen (broken)"),
				"object/tangible/loot/tool/shared_viewscreen_broken_s2.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 1 :
		item = new TangibleObject(creature, 0x1E84585F, unicode("Binoculars (broken)"), 
				"object/tangible/loot/tool/shared_binoculars_broken_s1.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 2 :
		item = new TangibleObject(creature, 0x25B24532, unicode("a Human Skull"), 
				"object/tangible/loot/misc/shared_loot_skull_human.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 3 :
		item = new TangibleObject(creature, 0x2D13F714, unicode("an Impulse Detector (broken)"), 
				"/tangible/loot/tool/shared_impulse_detector_broken_s3.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 4 :
		item = new TangibleObject(creature, 0x3238DD4A, unicode("a Cage"), 
				"object/tangible/loot/misc/shared_cage_s01.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 5 :
		item = new TangibleObject(creature, 0x3393694D, unicode("a Rare Artifact"), 
				"object/tangible/loot/misc/shared_artifact_rare_s01.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 6 :
		item = new TangibleObject(creature, 0x3CEA7897, unicode("Holocron Splinters"), 
				"object/tangible/loot/misc/shared_holocron_splinters_sith_s01.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 7 :
		item = new TangibleObject(creature, 0x5289E0D9, unicode("a Calibrator (broken)"), 
				"object/tangible/loot/tool/shared_calibrator_broken.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 8 :
		item = new TangibleObject(creature, 0x5F4B8D76, unicode("a Corrupt Datadisk"), 
				"object/tangible/loot/misc/shared_datadisk_corrupt.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 9 :
		item = new TangibleObject(creature, 0x619F4DFD, unicode("Jawa Beads"), 
				"object/tangible/loot/misc/shared_jawa_beads.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 10 :
		item = new TangibleObject(creature, 0x6C34F325, unicode("a Briefcase"), 
				"object/tangible/loot/misc/shared_briefcase_s01.iff", TangibleObjectImplementation::GENERICITEM);
		break;
	case 11 :
		item = new Firework((Player*) creature, 0x7C540DEB,
				unicode("a Firework"), "object/tangible/firework/shared_firework_s04.iff",1);
		break;
	case 12 :
		item = new Holocron((Player*) creature, 0x9BA06548,
				unicode("Holocron"), "object/tangible/jedi/shared_jedi_holocron_light.iff");
		break;
	}

	if (item != NULL) {
		creature->addLootItem(item);
	}
}

void LootManager::createAttachmentLoot(Creature* creature, int creatureLevel) {
	Attachment* item = new Attachment(creature->getNewItemID(), AttachmentImplementation::ARMOR);

	item->setSkillMods(creatureLevel / 2);

	creature->addLootItem(item);
}

void LootManager::createPowerupLoot(Creature* creature, int creatureLevel) {
	Powerup* item = new Powerup(creature->getNewItemID());

	item->setPowerupStats(creatureLevel);

	creature->addLootItem(item);
}
