--Automatically generated by SWGEmu Spawn Tool v0.12 loot editor.

rifle_tusken = {
	minimumLevel = 0,
	maximumLevel = -1,
	customObjectName = "",
	directObjectTemplate = "object/weapon/ranged/rifle/rifle_tusken.iff",
	craftingValues = {
		{"mindamage",64,123,0},
		{"maxdamage",124,188,0},
		{"attackspeed",9.6,6.7,0},
		{"woundchance",5.4,11.7,0},
		{"hitpoints",750,750,0},
		{"attackhealthcost",17,9,0},
		{"attackactioncost",27,16,0},
		{"attackmindcost",61,36,0},
	},
	customizationStringNames = {},
	customizationValues = {},

	-- dotChance: The chance of this weapon object dropping with a dot on it. Higher number means less chance. Set to 0 for static.
	dotChance = 10,

	-- dotValues: Object map that can randomly or statically generate a dot (used for weapon objects.)
	dotValues = {
		{"type", 1, 3}, -- 1 = Poison, 2 = Disease, 3 = Fire.
		{"attribute", 0, 8}, -- See CreatureAttributes.h in src for numbers.
		{"strength", 10, 200}, -- set for disease. Fire will be x1.5, poison x2.
		{"duration", 30, 240}, -- set for poison. Fire will be x1.5, disease x5.
		{"potency", 1, 100},
		{"uses", 250, 9999}
	}

}

addLootItemTemplate("rifle_tusken", rifle_tusken)
