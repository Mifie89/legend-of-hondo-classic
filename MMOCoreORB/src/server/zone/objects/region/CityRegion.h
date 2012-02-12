/*
 *	server/zone/objects/region/CityRegion.h generated by engine3 IDL compiler 0.60
 */

#ifndef CITYREGION_H_
#define CITYREGION_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "system/lang/String.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/ZoneReference.h"

#include "server/zone/objects/scene/variables/StringId.h"

namespace server {
namespace zone {
namespace objects {
namespace region {

class CityRegion : public ManagedObject {
public:
	static const byte RANK_CLIENT = 0;

	static const byte RANK_OUTPOST = 1;

	static const byte RANK_VILLAGE = 2;

	static const byte RANK_TOWNSHIP = 3;

	static const byte RANK_CITY = 4;

	static const byte RANK_METROPOLIS = 5;

	CityRegion(Zone* zne, const String& name);

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void addRegion(float x, float y, float radius);

	void addMilitiaMember(unsigned long long objectid);

	void removeMilitiaMember(unsigned long long objectid);

	bool isMilitiaMember(unsigned long long objectid);

	void addZoningRights(unsigned long long objectid, unsigned int duration = 86400);

	void removeZoningRights(unsigned long long objectid);

	bool hasZoningRights(unsigned long long objectid);

	bool toggleZoningEnabled();

	bool containsPoint(float x, float y);

	byte getCityRank();

	String getRegionName();

	unsigned long long getMayorID();

	bool isMayor(unsigned long long objectid);

	bool isZoningEnabled();

	bool isClientRegion();

	void setRegionName(const UnicodeString& name);

	void setRegionName(const String& fullPath);

	Vector<ManagedReference<SceneObject* > >* getVendorsInCity();

	void setRegionName(const StringId& name);

	void setCityRank(byte rank);

	void setMayorID(unsigned long long id);

	void setZoningEnabled(bool val);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CityRegion(DummyConstructorParameter* param);

	virtual ~CityRegion();

	String _return_getRegionName;

	friend class CityRegionHelper;
};

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;

namespace server {
namespace zone {
namespace objects {
namespace region {

class CityRegionImplementation : public ManagedObjectImplementation, public Logger {
protected:
	StringId regionName;

	ZoneReference zone;

	SortedVector<ManagedReference<Region* > > regions;

	VectorMap<unsigned long long, unsigned int> zoningRights;

	SortedVector<unsigned long long> militiaMembers;

	byte cityRank;

	unsigned long long mayorID;

	bool zoningEnabled;

	String citySpecialization;

public:
	static const byte RANK_CLIENT = 0;

	static const byte RANK_OUTPOST = 1;

	static const byte RANK_VILLAGE = 2;

	static const byte RANK_TOWNSHIP = 3;

	static const byte RANK_CITY = 4;

	static const byte RANK_METROPOLIS = 5;

	CityRegionImplementation(Zone* zne, const String& name);

	CityRegionImplementation(DummyConstructorParameter* param);

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void addRegion(float x, float y, float radius);

	void addMilitiaMember(unsigned long long objectid);

	void removeMilitiaMember(unsigned long long objectid);

	bool isMilitiaMember(unsigned long long objectid);

	void addZoningRights(unsigned long long objectid, unsigned int duration = 86400);

	void removeZoningRights(unsigned long long objectid);

	bool hasZoningRights(unsigned long long objectid);

	bool toggleZoningEnabled();

	bool containsPoint(float x, float y);

	byte getCityRank();

	String getRegionName();

	unsigned long long getMayorID();

	bool isMayor(unsigned long long objectid);

	bool isZoningEnabled();

	bool isClientRegion();

	void setRegionName(const UnicodeString& name);

	void setRegionName(const String& fullPath);

	Vector<ManagedReference<SceneObject* > >* getVendorsInCity();

	void setRegionName(const StringId& name);

	void setCityRank(byte rank);

	void setMayorID(unsigned long long id);

	void setZoningEnabled(bool val);

	WeakReference<CityRegion*> _this;

	operator const CityRegion*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~CityRegionImplementation();

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
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class CityRegion;
};

class CityRegionAdapter : public ManagedObjectAdapter {
public:
	CityRegionAdapter(CityRegion* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void notifyEnter(SceneObject* object);

	void notifyExit(SceneObject* object);

	void addRegion(float x, float y, float radius);

	void addMilitiaMember(unsigned long long objectid);

	void removeMilitiaMember(unsigned long long objectid);

	bool isMilitiaMember(unsigned long long objectid);

	void addZoningRights(unsigned long long objectid, unsigned int duration);

	void removeZoningRights(unsigned long long objectid);

	bool hasZoningRights(unsigned long long objectid);

	bool toggleZoningEnabled();

	bool containsPoint(float x, float y);

	byte getCityRank();

	String getRegionName();

	unsigned long long getMayorID();

	bool isMayor(unsigned long long objectid);

	bool isZoningEnabled();

	bool isClientRegion();

	void setRegionName(const UnicodeString& name);

	void setRegionName(const String& fullPath);

	void setCityRank(byte rank);

	void setMayorID(unsigned long long id);

	void setZoningEnabled(bool val);

protected:
	UnicodeString _param0_setRegionName__UnicodeString_;
	String _param0_setRegionName__String_;
};

class CityRegionHelper : public DistributedObjectClassHelper, public Singleton<CityRegionHelper> {
	static CityRegionHelper* staticInitializer;

public:
	CityRegionHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CityRegionHelper>;
};

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;

#endif /*CITYREGION_H_*/
