rale_moonraiser = Creature:new {
	objectName = "",
	customName = "Rale Moonraiser",
	socialGroup = "darklighter",
	faction = "",
	level = 99,
	chanceHit = 0.99,
	damageMin = 640,
	damageMax = 990,
	baseXp = 9243,
	baseHAM = 24000,
	baseHAMmax = 29000,
	armor = 0,
	resists = {40,40,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = HERD,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {"object/mobile/darklight_guard.iff"},
	lootGroups = {		{			groups = {				{group = "junk", chance = 7000000},				{group = "wearables_common", chance = 3000000},				{group = "weapons_all", chance = 1000000},			},		}	},
	weapons = {},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pitoleermaster,carbineermaster)
}

CreatureTemplates:addCreatureTemplate(rale_moonraiser, "rale_moonraiser")