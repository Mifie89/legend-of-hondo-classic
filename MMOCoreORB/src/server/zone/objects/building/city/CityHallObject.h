/*
 *	server/zone/objects/building/city/CityHallObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef CITYHALLOBJECT_H_
#define CITYHALLOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

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
namespace objects {
namespace region {

class Region;

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace city {

class CityTerminal;

} // namespace city
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::city;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace city {

class CityVoteTerminal;

} // namespace city
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::city;

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/SortedVector.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace city {

class CityHallObject : public BuildingObject {
public:
	CityHallObject();

	void insertToZone(Zone* zone);

	void removeFromZone();

	void spawnCityHallObjects();

	void despawnCityHallObjects();

	void trySetCityName(PlayerCreature* player, const String& name);

	bool checkRequisitesForPlacement(PlayerCreature* player);

	void setCityName(const String& name);

	String getCityName();

	void sendStatusTo(PlayerCreature* player);

	void sendCitizenshipReportTo(PlayerCreature* player);

	void sendStructureReportTo(PlayerCreature* player);

	void sendTreasuryReportTo(PlayerCreature* player);

	void sendChangeCityNameTo(PlayerCreature* player);

	void sendManageMilitiaTo(PlayerCreature* player);

	void sendAdjustTaxesTo(PlayerCreature* player);

	void sendTreasuryDepositTo(PlayerCreature* player);

	void sendTreasuryWithdrawalTo(PlayerCreature* player);

	void sendCitySpecializationSelectionTo(PlayerCreature* player);

	void toggleCityRegistration();

	int notifyStructurePlaced(PlayerCreature* player);

	bool isCityHallBuilding();

	void declareCitizenship(PlayerCreature* player);

	void declareCitizenship(unsigned long long playerID);

	void revokeCitizenship(PlayerCreature* player);

	void revokeCitizenship(unsigned long long playerID);

	unsigned long long getMayorObjectID();

	void setMayorObjectID(unsigned long long oid);

	bool isMayorOf(PlayerCreature* player);

	bool isMayorOf(unsigned long long playerID);

	bool isCitizenOf(PlayerCreature* player);

	bool isCitizenOf(unsigned long long playerID);

	CityTerminal* getCityTerminal();

	CityVoteTerminal* getCityVoteTerminal();

	Region* getCityRegion();

	void setCityRegion(Region* region);

protected:
	CityHallObject(DummyConstructorParameter* param);

	virtual ~CityHallObject();

	String _return_getCityName;

	friend class CityHallObjectHelper;
};

} // namespace city
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::city;

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace city {

class CityHallObjectImplementation : public BuildingObjectImplementation {
protected:
	SortedVector<unsigned long long> declaredCitizens;

	ManagedReference<Region* > cityRegion;

	String cityName;

	unsigned long long mayorObjectID;

	ManagedReference<CityTerminal* > cityTerminal;

	ManagedReference<CityVoteTerminal* > cityVoteTerminal;

public:
	CityHallObjectImplementation();

	CityHallObjectImplementation(DummyConstructorParameter* param);

	void insertToZone(Zone* zone);

	void removeFromZone();

	void spawnCityHallObjects();

	void despawnCityHallObjects();

	void trySetCityName(PlayerCreature* player, const String& name);

	bool checkRequisitesForPlacement(PlayerCreature* player);

	void setCityName(const String& name);

	String getCityName();

	void sendStatusTo(PlayerCreature* player);

	void sendCitizenshipReportTo(PlayerCreature* player);

	void sendStructureReportTo(PlayerCreature* player);

	void sendTreasuryReportTo(PlayerCreature* player);

	void sendChangeCityNameTo(PlayerCreature* player);

	void sendManageMilitiaTo(PlayerCreature* player);

	void sendAdjustTaxesTo(PlayerCreature* player);

	void sendTreasuryDepositTo(PlayerCreature* player);

	void sendTreasuryWithdrawalTo(PlayerCreature* player);

	void sendCitySpecializationSelectionTo(PlayerCreature* player);

	void toggleCityRegistration();

	int notifyStructurePlaced(PlayerCreature* player);

	bool isCityHallBuilding();

	void declareCitizenship(PlayerCreature* player);

	void declareCitizenship(unsigned long long playerID);

	void revokeCitizenship(PlayerCreature* player);

	void revokeCitizenship(unsigned long long playerID);

	unsigned long long getMayorObjectID();

	void setMayorObjectID(unsigned long long oid);

	bool isMayorOf(PlayerCreature* player);

	bool isMayorOf(unsigned long long playerID);

	bool isCitizenOf(PlayerCreature* player);

	bool isCitizenOf(unsigned long long playerID);

	CityTerminal* getCityTerminal();

	CityVoteTerminal* getCityVoteTerminal();

	Region* getCityRegion();

	void setCityRegion(Region* region);

	CityHallObject* _this;

	operator const CityHallObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~CityHallObjectImplementation();

	void finalize();

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

	friend class CityHallObject;
};

class CityHallObjectAdapter : public BuildingObjectAdapter {
public:
	CityHallObjectAdapter(CityHallObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void insertToZone(Zone* zone);

	void removeFromZone();

	void spawnCityHallObjects();

	void despawnCityHallObjects();

	void trySetCityName(PlayerCreature* player, const String& name);

	bool checkRequisitesForPlacement(PlayerCreature* player);

	void setCityName(const String& name);

	String getCityName();

	void sendStatusTo(PlayerCreature* player);

	void sendCitizenshipReportTo(PlayerCreature* player);

	void sendStructureReportTo(PlayerCreature* player);

	void sendTreasuryReportTo(PlayerCreature* player);

	void sendChangeCityNameTo(PlayerCreature* player);

	void sendManageMilitiaTo(PlayerCreature* player);

	void sendAdjustTaxesTo(PlayerCreature* player);

	void sendTreasuryDepositTo(PlayerCreature* player);

	void sendTreasuryWithdrawalTo(PlayerCreature* player);

	void sendCitySpecializationSelectionTo(PlayerCreature* player);

	void toggleCityRegistration();

	int notifyStructurePlaced(PlayerCreature* player);

	bool isCityHallBuilding();

	void declareCitizenship(PlayerCreature* player);

	void declareCitizenship(unsigned long long playerID);

	void revokeCitizenship(PlayerCreature* player);

	void revokeCitizenship(unsigned long long playerID);

	unsigned long long getMayorObjectID();

	void setMayorObjectID(unsigned long long oid);

	bool isMayorOf(PlayerCreature* player);

	bool isMayorOf(unsigned long long playerID);

	bool isCitizenOf(PlayerCreature* player);

	bool isCitizenOf(unsigned long long playerID);

	CityTerminal* getCityTerminal();

	CityVoteTerminal* getCityVoteTerminal();

	Region* getCityRegion();

	void setCityRegion(Region* region);

protected:
	String _param1_trySetCityName__PlayerCreature_String_;
	String _param0_setCityName__String_;
};

class CityHallObjectHelper : public DistributedObjectClassHelper, public Singleton<CityHallObjectHelper> {
	static CityHallObjectHelper* staticInitializer;

public:
	CityHallObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CityHallObjectHelper>;
};

} // namespace city
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::city;

#endif /*CITYHALLOBJECT_H_*/
