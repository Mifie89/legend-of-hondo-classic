mummer_ruffian = Creature:new {
	objectName = "@mob/creature_names:mummer_ruffian",
	socialGroup = "Mumm. Gang",
	pvpFaction = "thug",
	faction = "",
	level = 9,
	chanceHit = 0.270000,
	damageMin = 80,
	damageMax = 90,
	baseXp = 292,
	baseHAM = 675,
	baseHAMmax = 825,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + HERD,
	diet = HERBIVORE,

	templates = {},
	lootGroups = {
		{
			groups = {
				{group = "loot_kit_items", chance = 10000000}
			},
			lootChance = 3500000
		}
	},
	weapons = {"pirate_weapons_light"},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(mummer_ruffian, "mummer_ruffian")