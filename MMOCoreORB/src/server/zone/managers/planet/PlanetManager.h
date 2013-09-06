/*
 *	server/zone/managers/planet/PlanetManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLANETMANAGER_H_
#define PLANETMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace region {

class CityRegion;

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;

namespace server {
namespace zone {
namespace objects {
namespace scene {
namespace variables {

class StringId;

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

namespace server {
namespace zone {
namespace managers {
namespace weather {

class WeatherManager;

} // namespace weather
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::weather;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

#include "server/zone/managers/planet/RegionMap.h"

#include "server/zone/managers/terrain/TerrainManager.h"

#include "server/zone/managers/planet/MissionTargetMap.h"

#include "server/zone/templates/snapshot/WorldSnapshotNode.h"

#include "server/zone/templates/snapshot/WorldSnapshotIff.h"

#include "server/zone/managers/planet/PlanetTravelPointList.h"

#include "server/zone/managers/planet/PlanetTravelPoint.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/building/ShuttleMap.h"

#include "server/zone/objects/building/tasks/ShuttleDepartureTask.h"

#include "server/zone/objects/creature/CreaturePosture.h"

#include "server/zone/managers/planet/ClientPoiDataTable.h"

#include "server/zone/managers/planet/TravelFare.h"

#include "server/zone/managers/collision/IntersectionResults.h"

#include "engine/core/ManagedService.h"

#include "engine/log/Logger.h"

#include "system/thread/Thread.h"

#include "system/util/SortedVector.h"

#include "system/util/VectorMap.h"

#include "system/util/HashTable.h"

#include "system/util/Vector.h"

#include "system/thread/Mutex.h"

#include "engine/util/u3d/CloseObjectsVector.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class PlanetManager : public ManagedService {
public:
	static const int SHUTTLEPORT = 0;

	static const int STARPORT = 1;

	PlanetManager(Zone* planet, ZoneProcessServer* srv);

	void initializeTransientMembers();

	void initialize();

	void loadClientRegions();

	void loadClientPoiData();

	void loadBadgeAreas();

	void loadPerformanceLocations();

	PlanetTravelPoint* getNearestPlanetTravelPoint(SceneObject* object, float range = 16000.0);

	PlanetTravelPoint* getNearestPlanetTravelPoint(const Vector3& position, float range = 16000.0);

	bool isBuildingPermittedAt(float x, float y, SceneObject* objectTryingToBuild = NULL);

	bool isCampingPermittedAt(float x, float y, float margin);

	SceneObject* findObjectTooCloseToDecoration(float x, float y, float margin);

	bool isInRangeWithPoi(float x, float y, float range);

	bool isInObjectsNoBuildZone(float x, float y, float extraMargin);

	int getTravelFare(const String& departurePlanet, const String& arrivalPlanet);

	void sendPlanetTravelPointListResponse(CreatureObject* player);

	SceneObject* createTicket(const String& departurePoint, const String& arrivalPlanet, const String& arrivalPoint);

	bool validateRegionName(const String& name);

	bool validateClientCityInRange(CreatureObject* creatureObject, float x, float y);

	WeatherManager* getWeatherManager();

	TerrainManager* getTerrainManager();

	int getRegionCount();

	int getNumberOfCities();

	void increaseNumberOfCities();

	CityRegion* getRegion(int index);

	CityRegion* getRegion(const String& region);

	CityRegion* getRegionAt(float x, float y);

	void addRegion(CityRegion* region);

	void dropRegion(const String& region);

	bool hasRegion(const String& name);

	void addPerformanceLocation(SceneObject* obj);

	MissionTargetMap* getPerformanceLocations();

	bool isExistingPlanetTravelPoint(const String& pointName);

	bool isInterplanetaryTravelAllowed(const String& pointName);

	bool isIncomingTravelAllowed(const String& pointName);

	PlanetTravelPoint* getPlanetTravelPoint(const String& pointName);

	bool isTravelToLocationPermitted(const String& destinationPoint, const String& arrivalPlanet, const String& arrivalPoint);

	void scheduleShuttle(CreatureObject* shuttle, int shuttleType);

	void removeShuttle(CreatureObject* shuttle);

	bool checkShuttleStatus(CreatureObject* creature, CreatureObject* shuttle);

	bool isInWater(float x, float y);

	float findClosestWorldFloor(float x, float y, float z, float swimHeight, IntersectionResults* intersections = NULL, CloseObjectsVector* closeObjects = NULL);

	void addPlayerCityTravelPoint(PlanetTravelPoint* ptp);

	void removePlayerCityTravelPoint(const String& cityName);

	DistributedObjectServant* _getImplementation();
	DistributedObjectServant* _getImplementationForRead();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PlanetManager(DummyConstructorParameter* param);

	virtual ~PlanetManager();

	friend class PlanetManagerHelper;
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

namespace server {
namespace zone {
namespace managers {
namespace planet {

class PlanetManagerImplementation : public ManagedServiceImplementation, public Logger {
protected:
	ManagedReference<Zone* > zone;

	RegionMap regionMap;

	ShuttleMap shuttleMap;

	TravelFare travelFares;

	Reference<PlanetTravelPointList* > planetTravelPointList;

	int shuttleportAwayTime;

	int shuttleportLandedTime;

	int shuttleportLandingTime;

	int starportAwayTime;

	int starportLandedTime;

	int starportLandingTime;

public:
	static const int SHUTTLEPORT = 0;

	static const int STARPORT = 1;

protected:
	ManagedReference<WeatherManager* > weatherManager;

	int numberOfCities;

	ManagedReference<ZoneProcessServer* > server;

	Reference<TerrainManager* > terrainManager;

	Reference<MissionTargetMap* > performanceLocations;

	static ClientPoiDataTable clientPoiDataTable;

	static Mutex poiMutex;

public:
	PlanetManagerImplementation(Zone* planet, ZoneProcessServer* srv);

	PlanetManagerImplementation(DummyConstructorParameter* param);

private:
	SceneObject* loadSnapshotObject(WorldSnapshotNode* node, WorldSnapshotIff* wsiff, int& totalObjects);

	void loadSnapshotObjects();

	void loadTravelFares();

	void loadPlanetObjects(LuaObject* lua);

	void loadLuaConfig();

public:
	void initializeTransientMembers();

	void finalize();

	void initialize();

	void loadClientRegions();

	void loadClientPoiData();

	void loadBadgeAreas();

	void loadPerformanceLocations();

protected:
	void loadStaticTangibleObjects();

public:
	PlanetTravelPoint* getNearestPlanetTravelPoint(SceneObject* object, float range = 16000.0);

	PlanetTravelPoint* getNearestPlanetTravelPoint(const Vector3& position, float range = 16000.0);

	bool isBuildingPermittedAt(float x, float y, SceneObject* objectTryingToBuild = NULL);

	bool isCampingPermittedAt(float x, float y, float margin);

	SceneObject* findObjectTooCloseToDecoration(float x, float y, float margin);

	bool isInRangeWithPoi(float x, float y, float range);

	bool isInObjectsNoBuildZone(float x, float y, float extraMargin);

	int getTravelFare(const String& departurePlanet, const String& arrivalPlanet);

	void sendPlanetTravelPointListResponse(CreatureObject* player);

	SceneObject* createTicket(const String& departurePoint, const String& arrivalPlanet, const String& arrivalPoint);

	bool validateRegionName(const String& name);

	bool validateClientCityInRange(CreatureObject* creatureObject, float x, float y);

	WeatherManager* getWeatherManager();

	TerrainManager* getTerrainManager();

	int getRegionCount();

	int getNumberOfCities();

	void increaseNumberOfCities();

	CityRegion* getRegion(int index);

	CityRegion* getRegion(const String& region);

	CityRegion* getRegionAt(float x, float y);

	void addRegion(CityRegion* region);

	void dropRegion(const String& region);

	bool hasRegion(const String& name);

	void addPerformanceLocation(SceneObject* obj);

	MissionTargetMap* getPerformanceLocations();

	bool isExistingPlanetTravelPoint(const String& pointName);

	bool isInterplanetaryTravelAllowed(const String& pointName);

	bool isIncomingTravelAllowed(const String& pointName);

	PlanetTravelPoint* getPlanetTravelPoint(const String& pointName);

	bool isTravelToLocationPermitted(const String& destinationPoint, const String& arrivalPlanet, const String& arrivalPoint);

	void scheduleShuttle(CreatureObject* shuttle, int shuttleType);

	void removeShuttle(CreatureObject* shuttle);

	bool checkShuttleStatus(CreatureObject* creature, CreatureObject* shuttle);

	bool isInWater(float x, float y);

	float findClosestWorldFloor(float x, float y, float z, float swimHeight, IntersectionResults* intersections = NULL, CloseObjectsVector* closeObjects = NULL);

	void addPlayerCityTravelPoint(PlanetTravelPoint* ptp);

	void removePlayerCityTravelPoint(const String& cityName);

	WeakReference<PlanetManager*> _this;

	operator const PlanetManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PlanetManagerImplementation();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const uint32& nameHashCode);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class PlanetManager;
};

class PlanetManagerAdapter : public ManagedServiceAdapter {
public:
	PlanetManagerAdapter(PlanetManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void finalize();

	void initialize();

	void loadClientRegions();

	void loadClientPoiData();

	void loadBadgeAreas();

	void loadPerformanceLocations();

	bool isBuildingPermittedAt(float x, float y, SceneObject* objectTryingToBuild);

	bool isCampingPermittedAt(float x, float y, float margin);

	SceneObject* findObjectTooCloseToDecoration(float x, float y, float margin);

	bool isInRangeWithPoi(float x, float y, float range);

	bool isInObjectsNoBuildZone(float x, float y, float extraMargin);

	int getTravelFare(const String& departurePlanet, const String& arrivalPlanet);

	void sendPlanetTravelPointListResponse(CreatureObject* player);

	SceneObject* createTicket(const String& departurePoint, const String& arrivalPlanet, const String& arrivalPoint);

	bool validateRegionName(const String& name);

	bool validateClientCityInRange(CreatureObject* creatureObject, float x, float y);

	WeatherManager* getWeatherManager();

	int getRegionCount();

	int getNumberOfCities();

	void increaseNumberOfCities();

	CityRegion* getRegion(int index);

	CityRegion* getRegion(const String& region);

	CityRegion* getRegionAt(float x, float y);

	void addRegion(CityRegion* region);

	void dropRegion(const String& region);

	bool hasRegion(const String& name);

	void addPerformanceLocation(SceneObject* obj);

	bool isExistingPlanetTravelPoint(const String& pointName);

	bool isInterplanetaryTravelAllowed(const String& pointName);

	bool isIncomingTravelAllowed(const String& pointName);

	bool isTravelToLocationPermitted(const String& destinationPoint, const String& arrivalPlanet, const String& arrivalPoint);

	void scheduleShuttle(CreatureObject* shuttle, int shuttleType);

	void removeShuttle(CreatureObject* shuttle);

	bool checkShuttleStatus(CreatureObject* creature, CreatureObject* shuttle);

	bool isInWater(float x, float y);

	void removePlayerCityTravelPoint(const String& cityName);

};

class PlanetManagerHelper : public DistributedObjectClassHelper, public Singleton<PlanetManagerHelper> {
	static PlanetManagerHelper* staticInitializer;

public:
	PlanetManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlanetManagerHelper>;
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

#endif /*PLANETMANAGER_H_*/
