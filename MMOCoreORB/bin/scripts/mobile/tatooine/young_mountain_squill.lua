young_mountain_squill = Creature:new {
	objectName = "@mob/creature_names:young_mountain_squill",
	socialGroup = "squill",
	faction = "",
	level = 10,
	chanceHit = 0.28,
	damageMin = 90,
	damageMax = 110,
	baseXp = 356,
	baseHAM = 810,
	baseHAMmax = 990,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "meat_carnivore",
	meatAmount = 2,
	hideType = "hide_leathery",
	hideAmount = 2,
	boneType = "bone_mammal",
	boneAmount = 1,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK + HERD,
	optionsBitmask = 0,
	diet = CARNIVORE,

	templates = {"object/mobile/mountain_squill.iff"},
	scale = 0.75,
	lootGroups = {		{			groups = {				{group = "junk", chance = 7000000},				{group = "wearables_common", chance = 3000000},				{group = "weapons_all", chance = 1000000},			},		}	},
	weapons = {},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(young_mountain_squill, "young_mountain_squill")
