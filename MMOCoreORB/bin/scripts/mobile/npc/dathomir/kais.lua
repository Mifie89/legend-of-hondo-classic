kais = Creature:new {
	objectName = "@mob/creature_names:kais",
	socialGroup = "Nightsister",
	pvpFaction = "Nightsister",
	faction = "",
	level = 21,
	chanceHit = 0.330000,
	damageMin = 190,
	damageMax = 200,
	baseXp = 1609,
	baseHAM = 5000-6100,
	armor = 0,
	resists = {0,0,0,45,45,45,0,-1,-1},
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
	creatureBitmask = NONE,
	diet = HERBIVORE,

	templates = {},
	lootgroups = {},
	weapons = {""},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(kais, "kais")