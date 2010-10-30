/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#include "SuiManager.h"

/*
#include "../../objects/player/sui/messagebox/SuiMessageBox.h"
#include "../../objects/player/sui/colorpicker/SuiColorPicker.h"*/

#include "../radial/RadialManager.h"

#include "server/zone/ZoneProcessServerImplementation.h"
#include "server/zone/objects/player/PlayerCreature.h"
#include "server/zone/objects/player/sui/SuiWindowType.h"
#include "server/zone/objects/player/sui/banktransferbox/SuiBankTransferBox.h"
#include "server/zone/objects/player/sui/characterbuilderbox/SuiCharacterBuilderBox.h"
#include "server/zone/objects/player/sui/transferbox/SuiTransferBox.h"
#include "server/zone/objects/creature/commands/UnconsentCommand.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "server/zone/managers/professions/ProfessionManager.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/managers/structure/StructureManager.h"
#include "server/zone/objects/group/GroupObject.h"
#include "server/zone/packets/chat/ChatSystemMessage.h"
#include "server/zone/objects/player/sui/SuiBox.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/listbox/teachplayerlistbox/TeachPlayerListBox.h"
#include "server/zone/objects/player/sui/listbox/playerlearnlistbox/PlayerLearnListBox.h"
#include "server/zone/objects/player/sui/listbox/resourcedeedlistbox/ResourceDeedListBox.h"
#include "server/zone/objects/player/sui/inputbox/SuiInputBox.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/Zone.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/minigames/FishingManager.h"
#include "server/zone/managers/minigames/GamblingManager.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/tangible/tool/SurveyTool.h"
#include "server/zone/objects/tangible/ticket/TicketObject.h"
#include "server/zone/objects/installation/InstallationObject.h"
#include "server/zone/objects/installation/factory/FactoryObject.h"
#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"
#include "server/zone/objects/building/city/CityHallObject.h"
#include "server/zone/objects/tangible/terminal/characterbuilder/CharacterBuilderTerminal.h"
#include "server/zone/objects/tangible/deed/resource/ResourceDeed.h"
#include "server/zone/managers/planet/MapLocationType.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/objects/creature/commands/FindCommand.h"

#include "server/zone/managers/guild/GuildManager.h"
#include "server/zone/objects/tangible/terminal/guild/GuildTerminal.h"
#include "server/zone/objects/guild/GuildObject.h"


SuiManager::SuiManager(ZoneProcessServerImplementation* serv) : Logger("SuiManager") {
	server = serv;

	setGlobalLogging(true);
	setLogging(false);

	registerMessages();
}

void SuiManager::registerMessages() {
}

void SuiManager::handleSuiEventNotification(uint32 boxID, PlayerCreature* player, uint32 cancel, Vector<UnicodeString>* args) {
	uint16 type = (uint16) boxID;

	Locker _lock(player);

	ManagedReference<SuiBox*> suiBox = player->getSuiBox(boxID);

	if (suiBox == NULL)
		return;

	player->removeSuiBox(boxID);
	suiBox->clearOptions();

	switch (type) {
	case SuiWindowType::JUNK_DEALER_SELL_LIST:
		handleSellJunkLootSelection(player, suiBox, cancel, args);
		break;
	case SuiWindowType::STRUCTURE_STATUS:
		handleStructureStatus(player, suiBox, cancel, args);
		break;
	case SuiWindowType::STRUCTURE_DESTROY_CONFIRM:
		handleStructureDestroyConfirm(player, suiBox, cancel, args);
		break;
	case SuiWindowType::STRUCTURE_DESTROY_CODE:
		handleStructureDestroyCode(player, suiBox, cancel, args);
		break;
	case SuiWindowType::STRUCTURE_MANAGE_MAINTENANCE:
		handleManageMaintenance(player, suiBox, cancel, args);
		break;
	case SuiWindowType::MEDIC_CONSENT:
		handleConsentBox(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CLONE_REQUEST:
		handleCloneRequest(player, suiBox, cancel, args);
		break;
	case SuiWindowType::DANCING_START:
		handleStartDancing(player, suiBox, cancel, args);
		break;
	case SuiWindowType::DANCING_CHANGE:
		handleStartDancing(player, suiBox, cancel, args);
		break;
	case SuiWindowType::SURVEY_TOOL_RANGE:
		handleSurveyToolRange(player, suiBox, cancel, args);
		break;
	case SuiWindowType::SAMPLE_RADIOACTIVE_CONFIRM:
		handleSampleRadioactiveConfirm(player, suiBox, cancel, args);
		break;
	case SuiWindowType::SURVEY_TOOL_CONCENTRATED_MINIGAME:
		handleSurveyConcentratedMinigame(player, suiBox, cancel, args);
		break;
	case SuiWindowType::SURVEY_TOOL_CONCENTRATED_MINIGAME2:
		handleSurveyConcentratedMinigame2(player, suiBox, cancel, args);
		break;
	case SuiWindowType::TICKET_COLLECTOR_RESPONSES:
		handleTicketCollectorResponse(player, suiBox, cancel, args);
		break;
	case SuiWindowType::BANK_TRANSFER:
		handleBankTransfer(player, suiBox, cancel, args);
		break;
	case SuiWindowType::FISHING:
		handleFishingAction(player, suiBox, cancel, args);
		break;
	case SuiWindowType::GAMBLING_ROULETTE:
		handleGamblingRoulette(player, suiBox, cancel, args);
		break;
	case SuiWindowType::GAMBLING_SLOT:
		handleGamblingSlot(player, suiBox, cancel, args);
		break;
	case SuiWindowType::GAMBLING_SLOT_PAYOUT:
		handleGamblingSlotPayout(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CHARACTER_BUILDER_LIST:
		handleCharacterBuilderSelectItem(player, suiBox, cancel, args);
		break;
	case SuiWindowType::MEDIC_DIAGNOSE:
		handleDiagnose(player, suiBox, cancel, args);
		break;
	case SuiWindowType::FREE_RESOURCE:
		handleGiveFreeResource(player, suiBox, cancel, args);
		break;
	case SuiWindowType::TEACH_SKILL:
		handleTeachSkill(player, suiBox, cancel, args);
		break;
	case SuiWindowType::TEACH_PLAYER:
		handleTeachPlayer(player, suiBox, cancel, args);
		break;
	case SuiWindowType::OBJECT_NAME:
		handleSetObjectName(player, suiBox, cancel, args);
		break;
	case SuiWindowType::STRUCTURE_ADD_ENERGY:
		handleAddEnergy(player, suiBox, cancel, args);
		break;
	case SuiWindowType::FACTORY_SCHEMATIC2BUTTON:
		handleInsertFactorySchem2(player, suiBox, cancel, args);
		break;
	case SuiWindowType::FACTORY_SCHEMATIC3BUTTON:
		handleInsertFactorySchem3(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CITY_CREATE:
		handleCreateCity(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CITY_SET_NAME:
		handleChangeCityName(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CITY_ENABLE_ZONING:
		handleCityEnableZoning(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CITY_MILITIA:
		handleManageMilitia(player, suiBox, cancel, args);
		break;
	case SuiWindowType::CITY_ADD_MILITIA:
		handleAddMilitia(player, suiBox, cancel, args);
		break;
	case SuiWindowType::GUILD_CREATE_NAME:
		handleGuildCreateNameResponse(player, suiBox, cancel, args);
		break;
	case SuiWindowType::GUILD_CREATE_ABBREV:
		handleGuildCreateAbbrevResponse(player, suiBox, cancel, args);
		break;
	case SuiWindowType::COMMAND_FIND:
		handleFindCommand(player, suiBox, cancel, args);
		break;
	}
}

void SuiManager::handleSetObjectName(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isInputBox() || cancel != 0)
		return;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject();

	if (object == NULL)
		return;

	if (args->size() < 1)
		return;

	UnicodeString objectName = args->get(0);

	object->setCustomObjectName(objectName , true);
}

void SuiManager::handleManageMaintenance(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isTransferBox() || cancel != 0)
		return;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject();

	if (object == NULL || !object->isStructureObject())
		return;

	StructureObject* structureObject = (StructureObject*) object.get();

	if (args->size() < 1)
		return;

	int transferAmount = Integer::valueOf(args->get(0).toString());
	int currentCash = player->getCashCredits();

	if (transferAmount > currentCash) {
		//Send a message ot the player, and return.
		return;
	}

	if (transferAmount < 0) {
		//Send a message to the player, and return.
		return;
	}

	Locker _lock(structureObject, player);

	int transferTotal = currentCash - transferAmount;

	//TODO: Handlle this in StructureManager.
	//ManagedReference<StructureManager*> structureManager = structureObject->getZone()->getPlanetManager()->getStructureManager();
	//structureManager->depositMaintenance(player, structureObject, transferTotal);

	structureObject->addMaintenance(transferTotal);
	player->substractCashCredits(transferTotal);

	ParameterizedStringId stringId("base_player", "prose_pay_success");
	stringId.setTT(structureObject->getObjectID());
	stringId.setDI(transferTotal);

	player->sendSystemMessage(stringId);
	structureObject->updateToDatabase();

	player->updateToDatabase();
}


void SuiManager::handleAddEnergy(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isTransferBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int newEnergyVal = Integer::valueOf(args->get(0).toString());

	ManagedReference<SceneObject*> object = suiBox->getUsingObject();

	if (object == NULL || !object->isInstallationObject())
		return;

	InstallationObject* installation = (InstallationObject*) object.get();

	ManagedReference<ResourceManager*> resourceManager = player->getZoneServer()->getResourceManager();

	//TODO: This should be handled in StructureManager
	try {
		installation->wlock(player);

		uint32 energyFromPlayer = resourceManager->getAvailablePowerFromPlayer(player);
		uint32 energy = energyFromPlayer - newEnergyVal;

		if (energy > energyFromPlayer) {
			installation->unlock();
			return;
		}

		installation->addPower(energy);
		resourceManager->removePowerFromPlayer(player, energy);

		ParameterizedStringId stringId("player_structure", "deposit_successful");
		stringId.setDI(energy);

		player->sendSystemMessage(stringId);

		stringId.setStringId("player_structure", "reserve_report");
		stringId.setDI(energy);

		player->sendSystemMessage(stringId);

		installation->updateToDatabase();

		installation->unlock();
	} catch (...) {
		installation->unlock();
	}

}

void SuiManager::handleStartDancing(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 2)
		return;

	int index = Integer::valueOf(args->get(0).toString());
	bool change = Bool::valueOf(args->get(1).toString());

	SuiListBox* listBox = (SuiListBox*) suiBox;

	try {
		String dance = listBox->getMenuItemName(index);

		if (!change)
			player->executeObjectControllerAction(String("startdance").hashCode(), 0, dance);
		else
			player->executeObjectControllerAction(String("changedance").hashCode(), 0, dance);
	} catch (...) {

	}
}

void SuiManager::handleSurveyToolRange(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (cancel != 0)
		return;

	if (args->size() < 1)
		return;

	ManagedReference<SurveyTool*> surveyTool =  player->getSurveyTool();

	if (surveyTool == NULL)
		return;

	int range = Integer::valueOf(args->get(0).toString());

	Locker _lock(surveyTool);

	surveyTool->setRange(range);
}

void SuiManager::handleSampleRadioactiveConfirm(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (cancel != 0)
		return;

	ManagedReference<SurveyTool*> surveyTool =  player->getSurveyTool();

	if (surveyTool == NULL)
		return;

	Locker _lock(surveyTool);
	surveyTool->consentRadioactiveSample(player);
}

void SuiManager::handleSurveyConcentratedMinigame(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int value = Integer::valueOf(args->get(0).toString());

	ManagedReference<SurveyTool*> surveyTool =  player->getSurveyTool();

	if (surveyTool == NULL)
		return;

	Locker _lock(surveyTool);
	surveyTool->surveyCnodeMinigame(player, value);
}

void SuiManager::handleSurveyConcentratedMinigame2(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int value = Integer::valueOf(args->get(0).toString());

	ManagedReference<SurveyTool*> surveyTool =  player->getSurveyTool();

	if (surveyTool == NULL)
		return;

	Locker _lock(surveyTool);
	surveyTool->surveyGnodeMinigame(player, value);
}



void SuiManager::handleTicketCollectorResponse(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	SuiListBox* listBox = (SuiListBox*) suiBox;

	int index = Integer::valueOf(args->get(0).toString());

	uint64 ticketObjectID = listBox->getMenuObjectID(index);

	if (ticketObjectID == 0)
		return;

	ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");

	if (inventory == NULL)
		return;

	ManagedReference<SceneObject*> obj = inventory->getContainerObject(ticketObjectID);

	if (obj == NULL || !obj->isTangibleObject())
		return;

	TangibleObject* tano = (TangibleObject*) obj.get();

	if (!tano->isTicketObject())
		return;

	TicketObject* ticket = (TicketObject*) tano;
	ticket->handleObjectMenuSelect(player, 20);
}

void SuiManager::handleBankTransfer(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isBankTransferBox() || cancel != 0)
		return;

	if (args->size() < 2)
		return;

	int cash = Integer::valueOf(args->get(0).toString());
	int bank = Integer::valueOf(args->get(1).toString());

	SuiBankTransferBox* suiBank = (SuiBankTransferBox*) suiBox;

	ManagedReference<SceneObject*> bankObject = suiBank->getBank();

	if (bankObject == NULL)
		return;

	if (!player->isInRange(bankObject, 5))
		return;

	uint32 currentCash = player->getCashCredits();
	uint32 currentBank = player->getBankCredits();

	if ((currentCash + currentBank) == ((uint32) cash + (uint32) bank)) {
		player->setCashCredits(cash);
		player->setBankCredits(bank);
	}

}

void SuiManager::handleGamblingRoulette(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	GamblingManager* manager = player->getZone()->getZoneServer()->getGamblingManager();

	if (cancel != 0)
		manager->leaveTerminal(player, 0);
	else
		manager->refreshRouletteMenu(player);

	//TODO: This might resend suis.
}
void SuiManager::handleGamblingSlot(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (args->size() < 1)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());

	GamblingManager* manager = player->getZone()->getZoneServer()->getGamblingManager();
	manager->handleSlot(player, (bool) cancel, otherPressed);

	//TODO: This might resend suis.
}

void SuiManager::handleGamblingSlotPayout(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	player->sendMessage(suiBox->generateCloseMessage());
}

void SuiManager::handleFishingAction(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	FishingManager* manager = player->getZone()->getZoneServer()->getFishingManager();

	manager->setNextAction(player, index + 1);

	uint32 newBoxID = 0;

	switch (index + 1) {
		case FishingManager::TUGUP:
			newBoxID = manager->createWindow(player, suiBox->getBoxID());
			break;
		case FishingManager::TUGRIGHT:
			newBoxID = manager->createWindow(player, suiBox->getBoxID());
			break;
		case FishingManager::TUGLEFT:
			newBoxID = manager->createWindow(player, suiBox->getBoxID());
			break;
		case FishingManager::REEL:
			newBoxID = manager->createWindow(player, suiBox->getBoxID());
			break;
		case FishingManager::STOPFISHING:
			player->sendSystemMessage("@fishing:stop_fishing"); //You reel-in your line and stop fishing...
			manager->stopFishing(player, suiBox->getBoxID(), true);
			return;
			break;
		default:
			newBoxID = manager->createWindow(player, suiBox->getBoxID());
			break;
	}

	manager->setFishBoxID(player, suiBox->getBoxID());
}

void SuiManager::handleCharacterBuilderSelectItem(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	ZoneServer* zserv = player->getZoneServer();

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (!suiBox->isCharacterBuilderBox())
		return;

	ManagedReference<SuiCharacterBuilderBox*> cbSui = (SuiCharacterBuilderBox*) suiBox;

	CharacterBuilderMenuNode* currentNode = cbSui->getCurrentNode();

	//If cancel was pressed and there is no parent node to backup too, then we kill the box/menu.
	if (currentNode == NULL || (cancel != 0 && !currentNode->hasParentNode()))
		return;

	//Back was pressed. Send the node above it.
	if (cancel != 0) {
		CharacterBuilderMenuNode* parentNode = currentNode->getParentNode();
		cbSui->setCurrentNode(parentNode);

		player->addSuiBox(cbSui);
		player->sendMessage(cbSui->generateMessage());
		return;
	}

	CharacterBuilderMenuNode* node = currentNode->getChildNodeAt(index);

	//Node doesn't exist or the index was out of bounds. Should probably resend the menu here.
	if (node == NULL) {
		player->addSuiBox(cbSui);
		player->sendMessage(cbSui->generateMessage());
		return;
	}

	if (node->hasChildNodes()) {
		//If it has child nodes, display them.
		cbSui->setCurrentNode(node);
		player->addSuiBox(cbSui);
		player->sendMessage(cbSui->generateMessage());
	} else {

		String templatePath = node->getTemplatePath();

		if (templatePath.indexOf(".iff") < 0) { // Non-item selections

			if (templatePath == "unlearn_all_skills") {

				player->sendSystemMessage("All skills unlearned.");
				server->getProfessionManager()->surrenderAll(player);

			} else if (templatePath == "cleanse_character") {

				if (!player->isInCombat()) {
					player->sendSystemMessage("You have been cleansed from the signs of previous battles.");

					for (int i=0; i<9; i++) {
						player->setWounds(i, 0);
					}

					player->setShockWounds(0);
				} else {
					player->sendSystemMessage("Not within combat.");
				}

			} else if (templatePath == "enhance_character") {

				SceneObject* scob = cbSui->getUsingObject();
				if (scob != NULL) {

					if (scob->getGameObjectType() == SceneObjectImplementation::CHARACTERBUILDERTERMINAL) {
						CharacterBuilderTerminal* bluefrog = (CharacterBuilderTerminal*) scob;
						bluefrog->enhanceCharacter(player);
					}
				}

			} else if (templatePath == "credits") {

				player->addCashCredits(50000, true);
				player->sendSystemMessage("You have received 50.000 Credits");

			} else if (templatePath == "language") {

				SceneObject* scob = cbSui->getUsingObject();
				if (scob != NULL) {

					if (scob->getGameObjectType() == SceneObjectImplementation::CHARACTERBUILDERTERMINAL) {
						CharacterBuilderTerminal* bluefrog = (CharacterBuilderTerminal*) scob;
						bluefrog->giveLanguages(player);
					}
				}

			} else {

				if (templatePath.length() > 0) {

					server->getProfessionManager()->awardSkillBox(templatePath, player, true, true);
					if (player->hasSkillBox(templatePath))
						player->sendSystemMessage("You have learned a skill.");

				} else {

					player->sendSystemMessage("Unknown selection.");

				}
			}

			player->addSuiBox(cbSui);
			player->sendMessage(cbSui->generateMessage());
		} else { // Items

			ManagedReference<SceneObject*> item = zserv->createObject(node->getTemplateCRC(), 1);

			if (item == NULL) {
				player->sendSystemMessage("There was an error creating the requested item. Please contact customer support with this issue.");
				player->addSuiBox(cbSui);
				player->sendMessage(cbSui->generateMessage());
				return;
			}

			ManagedReference<SceneObject*> inventory = player->getSlottedObject("inventory");
			item->sendTo(player, true);
			inventory->addObject(item, -1, true);

			ParameterizedStringId stringId;
			stringId.setStringId("@faction_perk:bonus_base_name"); //You received a: %TO.
			stringId.setTO(item);
			player->sendSystemMessage(stringId);

			player->addSuiBox(cbSui);
			player->sendMessage(cbSui->generateMessage());
		}
	}
}

void SuiManager::handleCloneRequest(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	info("activating sui cloner option");

	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	ZoneServer* zoneServer = server->getZoneServer();
	PlayerManager* playerManager = zoneServer->getPlayerManager();

	if (index >= 0) {
		if (!player->isDead()) {
			player->sendSystemMessage("You must be dead to activate your clone.");
		} else {
			SuiListBox* suiListBox = (SuiListBox*) suiBox;
			playerManager->sendPlayerToCloner(player, suiListBox->getMenuObjectID(index));
		}
	} else {
		if (player->isDead())
			player->sendSystemMessage("You will remain dead until you choose a location to clone or you are revived. Type /activateClone to restore the clone window.");
	}
}

void SuiManager::handleDiagnose(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
}

void SuiManager::handleGiveFreeResource(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (args->size() < 2)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());
	int index = Integer::valueOf(args->get(1).toString());

	ResourceDeedListBox* suiListBox = dynamic_cast<ResourceDeedListBox*>(suiBox);

	if (suiListBox == NULL)
		return;

	ManagedReference<SceneObject*> deedObject = suiListBox->getUsingObject();

	if (deedObject == NULL)
		return;

	ManagedReference<ResourceManager*> resourceManager = server->getZoneServer()->getResourceManager();
	ManagedReference<ResourceSpawn*> spawn = NULL;

	String nodeName = "";

	if (otherPressed) {
		suiListBox->removeBox();
	} else {

		if (suiListBox->getPromptTitle() != "Resources") {

			resourceManager->givePlayerResource(player, suiListBox->getPromptTitle(),
				ResourceManagerImplementation::RESOURCE_DEED_QUANTITY);

			if (deedObject != NULL && deedObject->getGameObjectType() == SceneObjectImplementation::RESOURCEDEED) {
				ResourceDeed* deed = (ResourceDeed*) deedObject.get();

				Locker cLocker(deed, player);
				deed->destroyDeed();
			}

			return;

		}
		/// If nothing was chosen
		if (index < 0) {
			player->addSuiBox(suiListBox);
			player->sendMessage(suiListBox->generateMessage());
			return;
		}

		nodeName = suiListBox->getMenuItemName(index);

		spawn = resourceManager->getResourceSpawn(nodeName);

		if (spawn != NULL)
			suiListBox->addBox(spawn->getName());
		else
			suiListBox->addBox(nodeName);

	}

	suiListBox->clearOptions();
	suiListBox->removeAllMenuItems();

	if (spawn != NULL) {

		suiListBox->setPromptTitle(spawn->getName());
		suiListBox->setPromptText("@veteran:confirm_choose_type");

		spawn->addStatsToDeedListBox(suiListBox);

	} else {

		suiListBox->setPromptTitle("Resources");
		suiListBox->setPromptText("Choose resource.");

		resourceManager->addChildrenToDeedListBox(suiListBox->getCurrentBox(), suiListBox);
	}

	suiListBox->setCancelButton(true, "@cancel");
	suiListBox->setOtherButton(true, "@back");

	suiListBox->setUsingObject(deedObject);

	player->addSuiBox(suiListBox);
	player->sendMessage(suiListBox->generateMessage());
}

void SuiManager::handleConsentBox(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	if (index == -1)
		return;

	SuiListBox* suiList = (SuiListBox*) suiBox;

	String name = suiList->getMenuItemName(index);
	UnconsentCommand::unconscent(player, name);
}

void SuiManager::handleTeachPlayer(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	player->setTeachingOrLearning(false);

	if (suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int value = Integer::valueOf(args->get(0).toString());

	if (value == -1)
		return;

	TeachPlayerListBox* listBox = dynamic_cast<TeachPlayerListBox*>(suiBox);

	if (listBox == NULL)
		return;

	ManagedReference<PlayerCreature*> student = listBox->getStudent();

	if (student == NULL)
		return;

	Locker _lock(student);

	//if they are no longer in the same group we cancel
	ManagedReference<GroupObject*> group = player->getGroup();

	if (group == NULL || !group->hasMember(student)) {
		player->sendSystemMessage("@teaching:not_in_same_group");
		return;
	}

	//student->setTeachingOffer(listBox->getTeachingSkillOption(value));

	ParameterizedStringId message("teaching","offer_given");
	message.setTT(student->getFirstName());
	message.setTO("skl_n", listBox->getTeachingSkillOption(value));
	player->sendSystemMessage(message);

	ManagedReference<PlayerLearnListBox*> mbox = new PlayerLearnListBox(student);

	student->setTeachingOrLearning(true);

	// TODO: redo this after I find the proper String
	StringBuffer prompt, skillname;
	skillname << "@skl_n:" << listBox->getTeachingSkillOption(value);
	prompt << "Do you wish to learn the following from " << player->getFirstName() << "?";
	mbox->setPromptTitle("@sui:teach");
	mbox->setPromptText(prompt.toString());
	mbox->addMenuItem(skillname.toString());
	mbox->setCancelButton(true, "");
	mbox->setTeacher(player);
	mbox->setTeachingOffer(listBox->getTeachingSkillOption(value));

	student->addSuiBox(mbox);
	student->sendMessage(mbox->generateMessage());
}

void SuiManager::handleTeachSkill(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	player->setTeachingOrLearning(false);

	if (suiBox->isListBox())
		return;

	PlayerLearnListBox* listBox = dynamic_cast<PlayerLearnListBox*>(suiBox);

	if (listBox == NULL)
		return;

	String teachingOffer = listBox->getTeachingOffer();

	if (cancel != 0) {
		ParameterizedStringId message("teaching","offer_refused");
		message.setTT(player->getObjectID());
		message.setTO("skl_n", teachingOffer);
		listBox->getTeacher()->sendSystemMessage(message);

		return;
	}

	ManagedReference<PlayerCreature*> teacher = listBox->getTeacher();

	if (teacher == NULL) {
		player->sendSystemMessage("teaching","teacher_too_far");
		return;
	}


	if (!player->isInRange(teacher, 128)) {
		ParameterizedStringId message("teaching","teacher_too_far_target");
		message.setTT(teacher->getObjectID());
		message.setTO("skl_n", teachingOffer);
		player->sendSystemMessage(message);

		teacher->sendSystemMessage("teaching","teaching_failed");

		return;
	}

	ManagedReference<GroupObject*> group = player->getGroup();

	if (group == NULL || !group->hasMember(teacher)) {
		ParameterizedStringId message("teaching","not_in_same_group");
		message.setTT(listBox->getTeacher()->getObjectID());
		player->sendSystemMessage(message);

		teacher->sendSystemMessage("teaching","teaching_failed");
		return;
	}

	server->getProfessionManager()->playerTeachSkill(teachingOffer, player, teacher);
}

void SuiManager::handleInsertFactorySchem2(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = (SuiListBox*) suiBox;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject();

	if (object == NULL || !object->isFactory())
		return;

	FactoryObject* factory = (FactoryObject*) object.get();

	Locker _lock(factory, player);

	ManagedReference<ManufactureSchematic*> schematic = dynamic_cast<ManufactureSchematic*>(server->getZoneServer()->getObject(listBox->getMenuObjectID(index)));
	factory->handleInsertFactorySchem(player, schematic);
}

void SuiManager::handleInsertFactorySchem3(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 2)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());
	int index = Integer::valueOf(args->get(1).toString());

	SuiListBox* listBox = (SuiListBox*) suiBox;

	ManagedReference<SceneObject*> object = suiBox->getUsingObject();

	if (object == NULL || !object->isFactory())
		return;

	FactoryObject* factory = (FactoryObject*) object.get();

	Locker _lock(factory, player);

	factory->handleRemoveFactorySchem(player);

	if (!otherPressed) {
		ManagedReference<ManufactureSchematic*> schematic = dynamic_cast<ManufactureSchematic*>(server->getZoneServer()->getObject(listBox->getMenuObjectID(index)));
		factory->handleInsertFactorySchem(player, schematic);
	}
}

void SuiManager::handleSellJunkLootSelection(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 2)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());
	int index = Integer::valueOf(args->get(1).toString());

	if (otherPressed)
		info("Sell All",true);
	else if (cancel == 0)
		info("Sell",true);

	//player->sendSystemMessage("Index: " + String::valueOf(index) + " Cancel: " + String::valueOf(cancel) + " Other: " + String::valueOf(otherPressed));
	/*try {
		player->wlock();

		SuiListBox* listbox = (SuiListBox*) player->getSuiBox(boxid);

		if (listbox == NULL) {
			player->unlock();
			return;
		}

		if (cancel != 1 && index != -1) {
			Zone* zone = player->getZone();

			if (zone == NULL || zone->getZoneServer() == NULL) {
				player->removeSuiBox(boxid);
				listbox->finalize();
				player->unlock();
				return;
			}

			ZoneServer* zoneserver = zone->getZoneServer();

			ItemManager* itemmanager = zoneserver->getItemManager();

			if (itemmanager == NULL) {
				player->removeSuiBox(boxid);
				listbox->finalize();
				player->unlock();
				return;
			}

			uint64 junkdealerid = listbox->getUsingObjectID();
			JunkDealer* junkdealer = (JunkDealer*) zone->lookupObject(junkdealerid);

			if (junkdealer == NULL) {
				player->sendSystemMessage("An error has occurred, preventing you from selling your junk to the junk dealer.");
				player->removeSuiBox(boxid);
				listbox->finalize();
				player->unlock();
				return;
			}

			uint64 itemid = listbox->getMenuObjectID(index);
			TangibleObject* item = (TangibleObject*) player->getInventoryItem(itemid);

			if (item == NULL) {
				player->sendSystemMessage("An error has occurred, preventing you from selling your junk to the junk dealer.");
				player->removeSuiBox(boxid);
				listbox->finalize();
				player->unlock();
				return;
			}

			int lootvalue = item->getLootValue();

			if (lootvalue <= 0) {
				StfParameter* params = new StfParameter();
				params->addTU(junkdealerid);
				params->addTT(itemid);
				player->sendSystemMessage("junk_dealer", "prose_no_buy", params); //%TU shows no interest in purchasing %TT.
				delete params;

				player->removeSuiBox(boxid);
				listbox->finalize();
				player->unlock();
				return;
			}

			player->removeInventoryItem(itemid);
			item->sendDestroyTo(player);
			itemmanager->deletePlayerItem(player, item, false);
			item->finalize();

			player->addCashCredits(lootvalue);

			StfParameter* params = new StfParameter();
			params->addTT(itemid);
			params->addDI(lootvalue);
			player->sendSystemMessage("junk_dealer", "prose_sold_junk", params);
			delete params;

			//Send the list again.
			junkdealer->sendSellJunkListTo(player);
		}

		player->removeSuiBox(boxid);
		listbox->finalize();
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleSellJunkLootSelection");
		player->unlock();
	}*/
}

void SuiManager::handleStructureStatus(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {

}

void SuiManager::handleStructureDestroyConfirm(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	ManagedReference<SceneObject*> usingObject = suiBox->getUsingObject();

	if (usingObject == NULL || !usingObject->isStructureObject())
		return;

	StructureObject* structureObject = (StructureObject*) usingObject.get();

	Locker _lock(structureObject, player);
	structureObject->sendDestroyCodeTo(player);
}

void SuiManager::handleStructureDestroyCode(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isInputBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int destroyCode = Integer::valueOf(args->get(0).toString());

	ManagedReference<SceneObject*> usingObject = suiBox->getUsingObject();

	if (usingObject == NULL || !usingObject->isStructureObject())
		return;

	ManagedReference<StructureObject*> structureObject = (StructureObject*) usingObject.get();

	Zone* zone = structureObject->getZone();

	if (zone == NULL)
		return;

	PlanetManager* planetManager = zone->getPlanetManager();

	if (planetManager == NULL)
		return;

	StructureManager* structureManager = planetManager->getStructureManager();

	if (structureManager == NULL)
		return;

	Locker _lock(structureObject, player);

	if (structureObject->getDestroyCode() == destroyCode) {
		structureManager->redeedStructure(player, structureObject);
	} else {
		player->sendSystemMessage("@player_structure:incorrect_destroy_code"); //You have entered an incorrect code. You will have to issue the /destroyStructure again if you wish to continue.
		return;
	}
}

void SuiManager::handleCityEnableZoning(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isMessageBox() || cancel != 0)
		return;

	ManagedReference<SceneObject*> usingObject = suiBox->getUsingObject();

	if (usingObject == NULL || !usingObject->isBuildingObject())
		return;

	BuildingObject* buildingObject = (BuildingObject*) usingObject.get();

	if (!buildingObject->isCityHallBuilding())
		return;

	CityHallObject* cityHall = (CityHallObject*) buildingObject;

	Locker _lock(cityHall, player);
	cityHall->toggleZoningEnabled(player);
}

void SuiManager::handleChangeCityName(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isInputBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	String cityName = args->get(0).toString();

	ManagedReference<SceneObject*> usingObject = suiBox->getUsingObject();

	if (usingObject == NULL || !usingObject->isBuildingObject())
		return;

	BuildingObject* building = (BuildingObject*) usingObject.get();

	if (!building->isCityHallBuilding())
		return;

	CityHallObject* cityHall = (CityHallObject*) building;

	Locker _lock(cityHall, player);

	ManagedReference<CityManager*> cityManager = player->getZone()->getCityManager();

	if (cityManager->validateCityName(cityName)) {
		cityManager->changeCityName(cityHall, player, cityName);
	} else {
		player->sendSystemMessage("Invalid name specified for city.");
		player->addSuiBox(suiBox);
		player->sendMessage(suiBox->generateMessage());
	}
}

void SuiManager::handleCreateCity(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isInputBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	String cityName = args->get(0).toString();

	ManagedReference<SceneObject*> usingObject = suiBox->getUsingObject();

	if (usingObject == NULL || !usingObject->isBuildingObject())
		return;

	BuildingObject* building = (BuildingObject*) usingObject.get();

	if (!building->isCityHallBuilding())
		return;

	CityHallObject* cityHall = (CityHallObject*) building;

	Locker _lock(cityHall, player);

	ManagedReference<CityManager*> cityManager = player->getZone()->getCityManager();

	if (cityManager->validateCityName(cityName)) {
		cityManager->createNewCity(cityHall, player, cityName);
	} else {
		player->sendSystemMessage("Invalid name specified for city.");
		player->addSuiBox(suiBox);
		player->sendMessage(suiBox->generateMessage());
	}
}

void SuiManager::handleManageMilitia(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 2)
		return;

	bool otherPressed = Bool::valueOf(args->get(0).toString());
	int index = Integer::valueOf(args->get(1).toString());

	SuiListBox* listBox = (SuiListBox*) suiBox;

	ManagedReference<SceneObject*> obj = listBox->getUsingObject();

	if (obj == NULL || !obj->isBuildingObject())
		return;

	BuildingObject* building = (BuildingObject*) obj.get();

	if (!building->isCityHallBuilding())
		return;

	CityHallObject* city = (CityHallObject*) building;

	Locker _lock(city, player);

	ManagedReference<Zone*> zone = city->getZone();

	if (zone == NULL)
		return;

	if (otherPressed) {
		city->sendAddMilitiaMemberTo(player);
	} else {
		if (index != -1) {
			ManagedReference<CityManager*> cityManager = zone->getCityManager();

			uint64 playerID = listBox->getMenuObjectID(index);
			cityManager->removeMilitiaMember(city, player, playerID);
		}
	}
}

void SuiManager::handleAddMilitia(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isInputBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	String playerName = args->get(0).toString();

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject();

	if (obj == NULL || !obj->isBuildingObject())
		return;

	BuildingObject* building = (BuildingObject*) obj.get();

	if (!building->isCityHallBuilding())
		return;

	CityHallObject* city = (CityHallObject*) building;

	Locker _lock(city, player);

	ManagedReference<Zone*> zone = city->getZone();

	if (zone == NULL)
		return;

	ManagedReference<CityManager*> cityManager = zone->getCityManager();
	cityManager->addMilitiaMember(city, player, playerName);
}

void SuiManager::handleFindCommand(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (!suiBox->isListBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	int index = Integer::valueOf(args->get(0).toString());

	SuiListBox* listBox = (SuiListBox*) suiBox;

	uint8 maploctype = listBox->getMenuObjectID(index);

	FindCommand::findPlanetaryObject(player, maploctype);
}

void SuiManager::handleGuildCreateNameResponse(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	if (player->isInGuild()) {
		player->sendSystemMessage("@guild:create_fail_in_guild"); //You cannot create a guild while already in a guild.
		return;
	}

	if (!suiBox->isInputBox() || cancel != 0)
		return;

	if (args->size() < 1)
		return;

	String guildName = args->get(0).toString();

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject();

	if (obj == NULL || !obj->isTerminal())
		return;

	Terminal* terminal = (Terminal*) obj.get();

	if (!terminal->isGuildTerminal())
		return;

	GuildTerminal* guildTerminal = (GuildTerminal*) terminal;

	ManagedReference<GuildManager*> guildManager = server->getZoneServer()->getGuildManager();

	uint64 playerID = player->getObjectID();

	//Check if this player is already creating a guild...
	if (guildManager->isCreatingGuild(playerID))
		return;

	if (guildManager->validateGuildName(player, guildName)) {
		guildManager->addPendingGuild(playerID, guildName);
		guildManager->sendGuildCreateAbbrevTo(player, guildTerminal);
		return;
	}

	//Resend the create name box.
	player->addSuiBox(suiBox);
	player->sendMessage(suiBox->generateMessage());
}

void SuiManager::handleGuildCreateAbbrevResponse(PlayerCreature* player, SuiBox* suiBox, uint32 cancel, Vector<UnicodeString>* args) {
	uint64 playerID = player->getObjectID();

	ManagedReference<GuildManager*> guildManager = server->getZoneServer()->getGuildManager();

	//If the player isn't already creating a guild, then exit.
	if (!guildManager->isCreatingGuild(playerID))
		return;

	//After this point, we have to removePendingGuild anywhere we return, since they have to be creating a guild at this point.

	if (player->isInGuild()) {
		guildManager->removePendingGuild(playerID);
		player->sendSystemMessage("@guild:create_fail_in_guild"); //You cannot create a guild while already in a guild.
		return;
	}

	if (!suiBox->isInputBox()) {
		guildManager->removePendingGuild(playerID);
		return;
	}

	if (args->size() < 1) {
		guildManager->removePendingGuild(playerID);
		return;
	}

	String guildAbbrev = args->get(0).toString();

	ManagedReference<SceneObject*> obj = suiBox->getUsingObject();

	if (obj == NULL || !obj->isTerminal()) {
		guildManager->removePendingGuild(playerID);
		return;
	}

	Terminal* terminal = (Terminal*) obj.get();

	if (!terminal->isGuildTerminal()) {
		guildManager->removePendingGuild(playerID);
		return;
	}

	GuildTerminal* guildTerminal = (GuildTerminal*) terminal;

	if (guildManager->validateGuildAbbrev(player, guildAbbrev)) {
		String guildName = guildManager->getPendingGuildName(playerID);
		guildManager->createGuild(player, guildTerminal, guildName, guildAbbrev); //Handles the removing of the pending guild.
		return;
	}

	//Resend the create abbrev box.
	player->addSuiBox(suiBox);
	player->sendMessage(suiBox->generateMessage());
}
