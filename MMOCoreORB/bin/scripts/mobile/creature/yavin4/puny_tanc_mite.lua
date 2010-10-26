puny_tanc_mite = Creature:new {
	objectName = "@mob/creature_names:puny_tanc_mite",
	socialGroup = "Tancmite",
	pvpFaction = "",
	faction = "",
	level = 2,
	chanceHit = 0.210000,
	damageMin = 35,
	damageMax = 40,
	baseXp = 45,
	baseHAM = 75,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "meat_insect",
	meatAmount = 2,
	hideType = "hide_",
	hideAmount = 0,
	boneType = "bone_",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + HERD,
	diet = CARNIVORE,

	templates = {},
	lootgroups = {},
	weapons = {},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(puny_tanc_mite, "puny_tanc_mite")
