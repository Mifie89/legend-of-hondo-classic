krahbu = Creature:new {
	objectName = "@mob/creature_names:krahbu",
	socialGroup = "krahbu",
	faction = "",
	level = 10,
	chanceHit = 0.27,
	damageMin = 80,
	damageMax = 90,
	baseXp = 292,
	baseHAM = 1000,
	baseHAMmax = 1200,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "meat_herbivore",
	meatAmount = 210,
	hideType = "hide_bristley",
	hideAmount = 135,
	boneType = "bone_mammal",
	boneAmount = 120,
	milk = 0,
	tamingChance = 0.25,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	optionsBitmask = 128,
	diet = CARNIVORE,

	templates = {"object/mobile/krahbu.iff"},
	controlDeviceTemplate = "object/intangible/pet/krahbu_hue.iff",
	lootGroups = {		{			groups = {				{group = "junk", chance = 7000000},				{group = "wearables_common", chance = 3000000},				{group = "weapons_all", chance = 1000000},			},		}	},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"intimidationattack",""}
	}
}

CreatureTemplates:addCreatureTemplate(krahbu, "krahbu")
