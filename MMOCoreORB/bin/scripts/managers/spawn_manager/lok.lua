-- Generated by SWGEmu Spawn Tool v0.12
-- {"regionName", xCenter, yCenter, radius, tier, spawnConstant, "spawnGroup1", [...]}
-- Tier is a bit mask with the following possible values where each hexadecimal position is one possible configuration.
-- That means that it is not possible to have both a world spawn area and imperial spawn area in the same region, but
-- a dynamic rebel spawn area that is also a no build zone is possible.
UNDEFINEDAREA     = 0x0000
WORLDSPAWNAREA    = 0x0001
REBELSPAWNAREA    = 0x0002
IMPERIALSPAWNAREA = 0x0004
NEUTRALSPAWNAREA  = 0x0008
STATICSPAWNAREA   = 0x0010
DYNAMICSPAWNAREA  = 0x0020
LAIRSPAWNAREA     = 0x0040
NOSPAWNAREA       = 0x0100
NOBUILDZONEAREA   = 0x1000

lok_regions = {
	{"an_imperial_outpost",0,0,{1,0},UNDEFINEDAREA,1},
        {"awning_and_debris",-3890,-4497,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"badlands_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"badlands_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"blood_razer_transport",3633,2184,{1,280},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"broken_wall",-444,-5749,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"building_ruins",-226,-448,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"building_ruins_2",-2204,-4558,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"building_ruins_3",1469,-4457,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"buried_at_st",-6304,2423,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"corsair_lane",-3792,-3904,{1,236},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"debris",3895,595,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"debris_2",-2591,6187,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"debris_3",-3503,990,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"debris_4",-3637,-2018,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"destroyed_building",4486,-2834,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"destroyed_homestead",2722,-3293,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"destroyed_houses",3259,-1440,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"destroyed_outpost",-6219,3381,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"east_sulphur_flats",0,0,{1,0},UNDEFINEDAREA,1},
	{"eastern_mountains",0,0,{1,0},UNDEFINEDAREA,1},
	{"easy_gurnaset_nw",0,0,{1,0},UNDEFINEDAREA,1},
        {"farm",584,-2161,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"four_arches_and_pillar",281,-5599,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"four_pillars",-5190,-4823,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"four_pillars_and_flagpole",-320,-3223,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"generator",3883,-5512,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"grendin_waste_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"grendin_waste_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_canyon_corsair_se",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_canyon_corsair_sw",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_kimogilla_nw",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_kimogilla_sw",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_kusak_ne",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_langlatch_ne",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_langlatch_se",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_nym_nw",0,0,{1,0},UNDEFINEDAREA,1},
	{"hard_nym_se",0,0,{1,0},UNDEFINEDAREA,1},
	{"hills_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"hills_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"hills_3",0,0,{1,0},UNDEFINEDAREA,1},
	{"hills_4",0,0,{1,0},UNDEFINEDAREA,1},
	{"hills_5",0,0,{1,0},UNDEFINEDAREA,1},
        {"house",5879,-1127,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"house_ruins",5844,1675,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"house_ruins_2",-3455,912,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"house_ruins_3",2709,-5380,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"imperial_camp_ruins",5036,4323,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"imperial_wind_farm",-2100,-2633,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"kedarin_highlands",0,0,{1,0},UNDEFINEDAREA,1},
        {"kimo_skeleton",4970,-2080,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"lok_imperial_outpost_1",-1921,-3079,{1,500},STATICSPAWNAREA + NOBUILDZONEAREA,1},
	{"lok_imperial_outpost_2",-1921,-3079,{1,300},STATICSPAWNAREA + NOSPAWNAREA,1},
	{"lok_imperial_outpost_3",-2091,-2641,{1,60},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"lok_nyms_stronghold",0,0,{1,0},UNDEFINEDAREA,1},
	{"medium_vesp_ne",0,0,{1,0},UNDEFINEDAREA,1},
	{"medium_vesp_sw",0,0,{1,0},UNDEFINEDAREA,1},
	{"mosseru_hills_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"mosseru_hills_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"mount_chaolt",0,0,{1,0},UNDEFINEDAREA,1},
	{"mountains_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"mountains_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"mountains_3",0,0,{1,0},UNDEFINEDAREA,1},
	{"mountains_4",0,0,{1,0},UNDEFINEDAREA,1},
	{"mountains_5",0,0,{1,0},UNDEFINEDAREA,1},
        {"nine_burning_stones",-6296,4085,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"north_sulphur_flats",0,0,{1,0},UNDEFINEDAREA,1},
	{"northern_mountains",0,0,{1,0},UNDEFINEDAREA,1},
	{"northern_plains",0,0,{1,0},UNDEFINEDAREA,1},
	{"nym_protectorate",0,0,{1,0},UNDEFINEDAREA,1},
	{"nyms_stronghold",0,0,{1,0},UNDEFINEDAREA,1},
	{"oasis",0,0,{1,0},UNDEFINEDAREA,1},
        {"odd_building",210,-5972,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"outpost",-6162,6206,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"pillar_arrangement",3641,-4132,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"pillars_and_electricity",6183,-5552,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"plains_of_dust_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"plains_of_dust_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"plains_of_dust_3",0,0,{1,0},UNDEFINEDAREA,1},
        {"ranch",6115,-3176,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"rebel_outpost",476,4027,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"rebel_outpost_2",-4739,3529,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"research_facility",894,-4196,{1,200},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"river_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"river_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"river_3",0,0,{1,0},UNDEFINEDAREA,1},
	{"river_4",0,0,{1,0},UNDEFINEDAREA,1},
	{"river_5",0,0,{1,0},UNDEFINEDAREA,1},
        {"rock_fountain",6388,5131,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"ruins",-6417,5739,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"southeast_sulphur_flats",0,0,{1,0},UNDEFINEDAREA,1},
	{"southern_mountains",0,0,{1,0},UNDEFINEDAREA,1},
	{"southern_plains",0,0,{1,0},UNDEFINEDAREA,1},
	{"southwest_sulphur_flats",0,0,{1,0},UNDEFINEDAREA,1},
        {"statue_and_boxes",-1051,3560,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"stone_tower",3457,-375,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"sulphur_hills_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"sulphur_hills_2",0,0,{1,0},UNDEFINEDAREA,1},
        {"tent_and_garden",-6030,-286,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"three_houses",6205,911,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"torches_and_arches",720,-3389,{1,25},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"tower",1559,-6420,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"trees_and_arches",5544,-5998,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"trees_and_pillars",5071,-5126,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"two_arches",-3320,-5639,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"two_houses",-4867,-1052,{1,50},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
        {"two_huts",2956,3947,{1,30},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"volcano",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_1",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_10",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_11",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_12",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_13",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_2",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_3",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_4",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_5",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_6",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_7",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_8",0,0,{1,0},UNDEFINEDAREA,1},
	{"wasteland_9",0,0,{1,0},UNDEFINEDAREA,1},
	{"westerly",0,0,{1,0},UNDEFINEDAREA,1},
	{"western_mountains",0,0,{1,0},UNDEFINEDAREA,1},
	{"western_plains",0,0,{1,0},UNDEFINEDAREA,1},
        {"wind_farm",-2883,-236,{1,75},STATICSPAWNAREA + NOSPAWNAREA + NOBUILDZONEAREA,1},
	{"world_factional_imperial",0,0,{1,-1},LAIRSPAWNAREA + IMPERIALSPAWNAREA,1,"factional_imperial"},
	{"world_factional_neutral",0,0,{1,-1},LAIRSPAWNAREA + NEUTRALSPAWNAREA,1,"factional_neutral"},
	{"world_factional_rebel",0,0,{1,-1},LAIRSPAWNAREA + REBELSPAWNAREA,1,"factional_rebel"},
	{"world_spawner",0,0,{1,-1},LAIRSPAWNAREA + WORLDSPAWNAREA,1,"lok_world_creatures"},
}

lok_static_spawns = {
	{"agriculturalist",60,16.74,14.26,-2.05184,56.8997,2745876, "calm", ""},
	{"agriculturalist",60,7.54821,-0.894991,-7.47564,180.006,8145378, "conversation", ""},
	{"artisan",60,-13.7191,0.26,-9.38652,179.996,2745870, "conversation", ""},
	{"artisan",60,-29.0395,0.26,8.63541,0,2745870, "conversation", ""},
	{"artisan",60,-24.251,-0.894991,23.6325,180,8145387, "conversation", ""},
	{"artisan",60,6.44821,-0.894991,-7.47564,135.005,8145378, "conversation", ""},
	{"artisan",60,-23.8096,1.6,-5.16968,180.005,8145362, "conversation", ""},
	{"bapibac",60,14.5598,0.26,3.77176,360.011,2745866, "conversation", "Bapibac One-Oesp"},
	{"bartender",60,-11.2794,-0.894992,1.36624,33.4279,8145378, "neutral", ""},
	{"bodyguard",60,15.64,14.26,-0.951844,303.334,2745876, "calm", ""},
	{"bodyguard",60,3.95102,7.26,9.58572,179.998,2745872, "conversation", ""},
	{"bodyguard",60,-1.26922,0.999998,-0.973796,180.006,8145356, "conversation", ""},
	{"bodyguard",60,4.27638,1.00001,-7.08525,134.999,8145356, "conversation", ""},
	{"bodyguard",60,-3.37845,0.999947,7.55641,135,8145356, "conversation", ""},
	{"bodyguard",60,-23.1849,1.58923,0.850721,0.0559546,8145358, "conversation", ""},
	{"bothan_diplomat",60,18.7783,1.28309,9.1449,135.004,8145357, "conversation", ""},
	{"bothan_information_broker",60,-0.243796,7.26,-12.1226,135.01,2745872, "conversation", ""},
	{"bothan_information_broker",60,-25.6603,0.26,-0.532375,135.011,2745870, "conversation", ""},
	{"bothan_information_broker",60,19.6068,1.28309,-14.4961,180.006,8145357, "conversation", ""},
	{"bothan_information_broker",60,-11.545,1,-3.99877,45.0052,8145358, "conversation", ""},
	{"bounty_hunter",60,16.74,14.26,-0.951844,283.416,2745876, "calm", ""},
	{"bounty_hunter",60,29.0555,0.26,7.22789,360.011,2745866, "conversation", ""},
	{"brawler",60,4.19353,13.5019,8.75924,180,2745876, "conversation", ""},
	{"brawler",60,32.2156,14.26,-9.06471,0.0395659,2745876, "conversation", ""},
	{"brawler",60,9.48372,0.26,-7.07547,135.009,2745866, "conversation", ""},
	{"brawler",60,-4.95629,-0.894992,-6.53149,360.011,8145378, "conversation", ""},
	{"brawler",60,5.37638,1,-8.18525,360.011,8145356, "conversation", ""},
	{"businessman",60,372.58,12.0976,5003.43,336.419,0, "calm", ""},
	{"businessman",60,514.113,11.4851,5196.38,105.024,0, "calm", ""},
	{"businessman",60,-2.13049,-0.894991,8.0956,179.998,8145378, "conversation", ""},
	{"businessman",60,19.8783,1.28309,8.0449,360.011,8145357, "conversation", ""},
	{"ciwi_mosregri",60,31.1714,7.25,12.3841,180.018,2745874, "conversation", "Ciwi Mo-sregri"},
	{"comm_operator",60,432.639,12,5219.48,180.005,0, "conversation", ""},
	{"commoner",60,31.1714,7.25,11.2841,0,2745874, "conversation", ""},
	{"commoner",60,29.0555,0.26,8.32789,179.999,2745866, "conversation", ""},
	{"commoner",60,618.591,11.8421,5013.77,225.688,0, "calm", ""},
	{"commoner",60,6.78896,1.00001,8.59957,0,8145356, "conversation", ""},
	{"commoner",60,-11.545,1.00022,-2.89877,134.998,8145358, "conversation", ""},
	{"commoner_fat",60,562.914,11.8302,5171.75,43.747,0, "calm", ""},
	{"commoner_fat",60,11.63,-0.894992,-16.56,277.008,8145381, "neutral", "Choster (Retired Engineer)"},
	{"commoner_fat",60,6.44821,-0.894991,-8.57564,45.0004,8145378, "conversation", ""},
	{"commoner_naboo",60,360.315,11.9448,4966.58,287.085,0, "calm", ""},
	{"commoner_naboo",60,371.229,12.06,5167.84,53.0347,0, "calm", ""},
	{"commoner_naboo",60,545.596,11.959,5081.45,126.924,0, "calm", ""},
	{"commoner_naboo",60,449.967,12,5141.31,112.766,0, "calm", ""},
	{"commoner_old",60,535.709,11.9925,5135.86,230.158,0, "calm", ""},
	{"commoner_old",60,522.568,11.8075,4964.65,304.378,0, "calm", ""},
	{"commoner_old",60,-36.21,0.10501,-13.93,87.0026,8145389, "neutral", "Sergeant Moore (Retired)"},
	{"commoner_old",60,43.6331,0.104999,1.36432,180.09,8145376, "conversation", ""},
	{"commoner_tatooine",60,280.329,11.9265,5027.91,218.008,0, "calm", ""},
	{"commoner_tatooine",60,285.432,11.9758,5117.33,85.567,0, "calm", ""},
	{"commoner_tatooine",60,332.33,12.0215,5159.29,135.281,0, "calm", ""},
	{"commoner_tatooine",60,356.668,12.0208,4918.65,342.78,0, "calm", ""},
	{"commoner_tatooine",60,342.313,11.9993,5024.26,97.0775,0, "calm", ""},
	{"commoner_tatooine",60,462.534,11.8294,5148.35,23.6115,0, "calm", ""},
	{"commoner_tatooine",60,462.685,11.9861,5192.39,127.19,0, "calm", ""},
	{"commoner_tatooine",60,429.839,13,5136.92,340.915,0, "calm", ""},
	{"commoner_tatooine",60,14.3,-0.9,23.3,181,8145380, "npc_sitting_chair", "Berema"},
	{"commoner_tatooine",60,-2.27845,0.999959,6.45641,0,8145356, "conversation", ""},
	{"commoner_technician",60,0.856204,7.26,-13.2226,0,2745872, "conversation", ""},
	{"criminal",60,226.672,12.0826,4954.08,267.001,0, "calm", ""},
	{"criminal",60,221.718,11.9626,4987.57,135.742,0, "calm", ""},
	{"criminal",60,525.319,11.8584,5156.53,159.79,0, "calm", ""},
	{"entertainer",60,30.0714,7.25,12.3841,135.011,2745874, "conversation", ""},
	{"entertainer",60,-30.1395,0.25801,9.73541,135.01,2745870, "conversation", ""},
	{"entertainer",60,-5.72977,-0.894994,22.9507,180.008,8145384, "conversation", ""},
	{"entertainer",60,-6.82977,-0.894994,22.9507,135.007,8145384, "conversation", ""},
	{"entertainer",60,18.2791,-0.894996,-13.3794,180.008,8145379, "conversation", ""},
	{"entertainer",60,6.78896,1.00001,9.69957,180.005,8145356, "conversation", ""},
	{"evathm",60,4.84117,-0.894992,20.6966,45.0006,8145382, "conversation", "Evathm Av'Tvo"},
	{"explorer",60,-24.5603,0.26,-1.63238,0,2745870, "conversation", ""},
	{"explorer",60,23.1893,-0.894994,8.7231,0,8145378, "conversation", ""},
	{"explorer",60,19.6068,1.28309,-15.5961,360.011,8145357, "conversation", ""},
	{"farmer",60,391.143,12,5057.74,180.005,0, "conversation", ""},
	{"farmer",60,29.5658,13.25,10.7188,180.002,2745876, "conversation", ""},
	{"farmer",60,-2.27845,0.999949,7.55641,180.005,8145356, "conversation", ""},
	{"farmer",60,-14.6521,1.0008,7.50857,0,8145358, "conversation", ""},
	{"farmer",60,484.493,11.8719,5090.56,2.49081,0, "conversation", ""},
	{"farmer_rancher",60,18.1642,-0.894992,19.3991,79.3056,8145380, "calm", ""},
	{"fringer",60,10.5837,0.26,-7.07547,180.014,2745866, "conversation", ""},
	{"gambler",60,0.856204,7.26,-12.1226,180.015,2745872, "conversation", ""},
	{"gambler",60,43.6314,0.104999,0.264886,0.0791317,8145376, "conversation", ""},
	{"gambler",60,19.8783,1.28309,9.1449,180.006,8145357, "conversation", ""},
	{"gambler",60,-10.445,1.00009,-2.89877,180.006,8145358, "conversation", ""},
	{"gurk",900,-3754.7,63.2,-3477.6,150,0, "", ""},
	{"gurk",900,-3763.7,62,-3485.9,170,0, "", ""},
	{"gurk",900,731.6,11.9,-3382,142,0, "", ""},
	{"gurk",900,708,12,-3397,131,0, "", ""},
	{"gurk",900,699,12,-3384,-97,0, "", ""},
	{"gurk",900,704.1,12.1,-3359,16,0, "", ""},
	{"idhak_ipath",60,28.4658,13.25,10.7188,135.001,2745876, "conversation", "Idhak Ipath"},
	{"ifoja_lico",60,552.494,11.89,5111.84,180.005,0, "conversation", "Ifoja Lico"},
	{"info_broker",60,-15.7521,1.00122,8.60857,134.998,8145358, "conversation", ""},
	{"lok_herald_01",60,371.717,11.8618,5179.1,286.408,0, "calm", ""},
	{"lok_herald_02",60,221.864,17.0919,5154.99,342.34,0, "calm", ""},
	{"medic",60,32.2166,14.26,-7.96455,180.055,2745876, "conversation", ""},
	{"medic",60,-29.0395,0.26,9.73541,180.016,2745870, "conversation", ""},
	{"medic",60,14.5598,0.26,4.87176,180.004,2745866, "conversation", ""},
	{"medic",60,552.494,11.89,5110.84,0,0, "conversation", ""},
	{"medic",60,-3.23049,-0.894991,8.0956,134.996,8145378, "conversation", ""},
	{"medic",60,-1.26922,1,-2.0738,360.011,8145356, "conversation", ""},
	{"medic",60,-10.445,1,-3.99877,360.011,8145358, "conversation", ""},
	{"melo",60,32.2502,7.25,-2.56477,360.011,2745874, "conversation", "Melo"},
	{"mercenary",60,25.7848,-0.894993,-8.75091,180.009,8145378, "conversation", ""},
	{"mercenary",60,24.6848,-0.894992,-8.75091,135.009,8145378, "conversation", ""},
	{"mercenary",60,432.639,12,5218.48,0,0, "conversation", ""},
	{"mercenary_weak",60,5.94117,-0.894992,21.7966,180.007,8145382, "conversation", ""},
	{"mercenary_weak",60,23.1893,-0.894993,9.8231,180.01,8145378, "conversation", ""},
	{"miner",60,4.19353,13.5019,7.65925,360.011,2745876, "conversation", ""},
	{"miner",60,-13.7191,0.26,-10.4865,360.011,2745870, "conversation", ""},
	{"miner",60,-14.4486,0.26,6.76362,134.998,2745870, "conversation", ""},
	{"noble",60,-24.5603,0.26,-0.532375,180.016,2745870, "conversation", ""},
	{"noble",60,5.94117,-0.894992,20.6966,0,8145382, "conversation", ""},
	{"noble",60,-14.6521,1.00101,8.60857,180.005,8145358, "conversation", ""},
	{"nym",60,0,3.27819,-22.9,0,6595511, "npc_sitting_chair", ""},
	{"nym_kusak_guardian",60,-3.62,3.27819,-25.44,39.0011,6595511, "calm", "Scourge"},
	{"nym_kusak_guardian",60,3.62,3.27819,-25.44,325.01,6595511, "bored", "Razor"},
	{"pilot",60,31.1166,14.26,-9.06455,44.9979,2745876, "conversation", ""},
	{"pilot",60,18.2791,-0.894996,-14.4794,0,8145379, "conversation", ""},
	{"pilot",60,-23.8096,1.6,-6.26968,0,8145362, "conversation", ""},
	{"protocol_droid_3po",60,630,12.7003,5055,150.762,0, "calm", "Race Coordinator"},
	{"reclusive_gurk_king",1200,-3763.4,62.5,-3477.2,160,0, "", ""},
	{"reclusive_gurk_king",1200,720.3,11.9,-3396.6,130,0, "", ""},
	{"rifea_eicik",60,-23.1848,1.58812,1.95072,180.005,8145358, "conversation", "Rifea Eicik"},
	{"rorha_wahe",60,7.54821,-0.894991,-8.57564,0,8145378, "conversation", "Rorha Wahe"},
	{"scientist",60,363.384,11.8774,5104.73,315.983,0, "calm", ""},
	{"scientist",60,-13.3486,0.26,5.66362,360.011,2745870, "conversation", ""},
	{"scientist",60,25.7848,-0.894993,-9.85091,0,8145378, "conversation", ""},
	{"scientist",60,5.37638,1.00001,-7.08525,180.006,8145356, "conversation", ""},
	{"scoundrel",60,-30.1395,0.259061,8.63541,45.0015,2745870, "conversation", ""},
	{"scoundrel",60,-24.251,-0.894991,22.5325,360.011,8145387, "conversation", ""},
	{"smuggler",60,3.95102,7.26,8.48572,360.011,2745872, "conversation", ""},
	{"smuggler",60,10.5837,0.26,-8.17547,0,2745866, "conversation", ""},
	{"smuggler",60,4.84117,-0.894992,21.7966,135.006,8145382, "conversation", ""},
	{"smuggler",60,-4.95629,-0.894992,-5.43149,179.998,8145378, "conversation", ""},
	{"spacer",60,391.143,12,5056.74,0,0, "conversation", ""},
	{"spacer",60,31.1166,14.26,-7.96455,135.032,2745876, "conversation", ""},
	{"spacer",60,-13.3486,0.26,6.76362,179.996,2745870, "conversation", ""},
	{"spacer",60,9.48372,0.26,-8.17547,45.0031,2745866, "conversation", ""},
	{"spacer",60,1.83273,-0.894992,-15.3461,0,8145381, "conversation", ""},
	{"spacer",60,-5.72977,-0.894996,21.8507,0,8145384, "conversation", ""},
	{"spacer",60,-3.37845,0.999956,6.45641,44.9954,8145356, "conversation", ""},
	{"surgical_droid_21b",60,-25.52,0.26,-3.48,159.753,2745870, "calm", ""},
	{"vendor",60,29.5658,13.25,9.61881,360.011,2745876, "conversation", ""},
	{"vendor",60,32.2502,7.25,-1.46477,179.999,2745874, "conversation", ""},
	{"vixur_webb",60,-13.2,-0.9,-20.2,22,8145383, "npc_sitting_chair", "Vixur Webb (a musician)"},
}

lok_badges = {
	{"badge_imp_outpost",-1814,-3086,10,98},
	{"badge_kimogila_skeleton",4562,-1156,10,99},
	{"badge_volcano",3091,-4638,10,24},
}
