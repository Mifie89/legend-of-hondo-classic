cowardly_gurreck = Creature:new {
	objectName = "@mob/creature_names:cowardly_gurreck",
	socialGroup = "Gurreck",
	pvpFaction = "",
	faction = "",
	level = 15,
	chanceHit = 0.310000,
	damageMin = 150,
	damageMax = 160,
	baseXp = 831,
	baseHAM = 3200,
	armor = 0,
	resists = {10,10,0,-1,-1,0,-1,-1,-1},
	meatType = "meat_carnivore",
	meatAmount = 0,
	hideType = "hide_wooly",
	hideAmount = 0,
	boneType = "bone_",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.250000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK,
	diet = CARNIVORE,

	templates = {},
	lootgroups = {},
	weapons = {},
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(cowardly_gurreck, "cowardly_gurreck")
