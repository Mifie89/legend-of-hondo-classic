aakuan_sentinel = Creature:new {
	objectName = "@mob/creature_names:aakuan_sentinal",
	socialGroup = "aakuans",
	pvpFaction = "aakuans",
	faction = "aakuans",
	level = 17,
	chanceHit = 0.31,
	damageMin = 170,
	damageMax = 180,
	baseXp = 1257,
	baseHAM = 4100,
	baseHAMmax = 5000,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	templates = {
		"object/mobile/dressed_aakuan_sentinal_rodian_female_01.iff",
		"object/mobile/dressed_aakuan_sentinal_rodian_male_01.iff"},
	lootGroups = {
	    {
		    groups = {
				{group = "junk", chance = 3000000},
				{group = "aakuan_common", chance = 1500000},
				{group = "armor_attachments", chance = 500000},
				{group = "rifles", chance = 1000000},
				{group = "carbines", chance = 1000000},
				{group = "pistols", chance = 1000000}				
			},
		    lootChance = 3500000
		}	
	},
	weapons = {"melee_weapons"},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(aakuan_sentinel, "aakuan_sentinel")