region_area = SharedObjectTemplate:new {
	clientTemplateFileName = "", 
	planetMapCategory = "city",
	planetMapSubCategory = "",
	autoRegisterWithPlanetMap = 0,
	 
	zoneComponent = "ZoneComponent",
	objectMenuComponent = {"cpp", "ObjectMenuComponent"},
	containerComponent = {"cpp", "ContainerComponent"},
	gameObjectType = 33554433
}
	
ObjectTemplates:addTemplate(region_area, "object/region_area.iff")
