trujhazii = Creature:new {
	objectName = "",
	socialGroup = "nightsister",
	pvpFaction = "nightsister",
	faction = "nightsister",
	level = 50,
	chanceHit = 10,
	damageMin = 280,
	damageMax = 390,
	baseXp = 100,
	baseHAM = 12000,
	baseHAMmax = 15000,
	armor = 1,
	resists = {10,10,10,10,10,10,10,10,-1},
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
	creatureBitmask = NONE,
	optionsBitmask = 264,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_dathomir_nightsister_stalker.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "singular_nak_mission_target_convotemplate",
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(trujhazii, "trujhazii")
