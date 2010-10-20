/*
 *	server/zone/objects/building/cloning/CloningBuildingObject.h generated by engine3 IDL compiler 0.61
 */

#ifndef CLONINGBUILDINGOBJECT_H_
#define CLONINGBUILDINGOBJECT_H_

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
namespace cell {

class CellObject;

} // namespace cell
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::cell;

#include "server/zone/templates/tangible/CloningBuildingObjectTemplate.h"

#include "server/zone/objects/building/cloning/CloneSpawnPoint.h"

#include "server/zone/managers/templates/TemplateManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace cloning {

class CloningBuildingObject : public BuildingObject {
public:
	CloningBuildingObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	bool isCloningBuildingObject();

	CloneSpawnPoint* getRandomSpawnPoint();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CloningBuildingObject(DummyConstructorParameter* param);

	virtual ~CloningBuildingObject();

	friend class CloningBuildingObjectHelper;
};

} // namespace cloning
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::cloning;

namespace server {
namespace zone {
namespace objects {
namespace building {
namespace cloning {

class CloningBuildingObjectImplementation : public BuildingObjectImplementation {

public:
	CloningBuildingObjectImplementation();

	CloningBuildingObjectImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	bool isCloningBuildingObject();

	CloneSpawnPoint* getRandomSpawnPoint();

	CloningBuildingObject* _this;

	operator const CloningBuildingObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~CloningBuildingObjectImplementation();

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

	friend class CloningBuildingObject;
};

class CloningBuildingObjectAdapter : public BuildingObjectAdapter {
public:
	CloningBuildingObjectAdapter(CloningBuildingObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool isCloningBuildingObject();

};

class CloningBuildingObjectHelper : public DistributedObjectClassHelper, public Singleton<CloningBuildingObjectHelper> {
	static CloningBuildingObjectHelper* staticInitializer;

public:
	CloningBuildingObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CloningBuildingObjectHelper>;
};

} // namespace cloning
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::cloning;

#endif /*CLONINGBUILDINGOBJECT_H_*/
