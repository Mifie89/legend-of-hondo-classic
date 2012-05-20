corsec_special_ops_trainee = Creature:new {
	objectName = "@mob/creature_names:corsec_cadet_aggro",
	socialGroup = "corsec",
	pvpFaction = "corsec",
	faction = "corsec",
	level = 71,
	chanceHit = 0.7,
	damageMin = 495,
	damageMax = 700,
	baseXp = 6839,
	baseHAM = 12000,
	baseHAMmax = 15000,
	armor = 1,
	resists = {35,35,30,25,80,30,25,35,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_corsec_pilot_human_female_01.iff",
		"object/mobile/dressed_corsec_pilot_human_male_01.iff"},
	lootGroups = {
	  {
			groups = {
				{group = "clothing_attachments", chance = 500000},
				{group = "armor_attachments", chance = 500000},
				{group = "corsec_weapons", chance = 2500000},
				{group = "crystals_premium", chance = 500000},
				{group = "color_crystals", chance = 500000}
			},
			lootChance = 5000000
		}
	},
	weapons = {"corsec_police_weapons"},
	conversationTemplate = "",
	attacks = merge(brawlernovice,marksmannovice)
}

CreatureTemplates:addCreatureTemplate(corsec_special_ops_trainee, "corsec_special_ops_trainee")
