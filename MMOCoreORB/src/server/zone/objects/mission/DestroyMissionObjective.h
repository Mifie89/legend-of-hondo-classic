/*
 *	server/zone/objects/mission/DestroyMissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef DESTROYMISSIONOBJECTIVE_H_
#define DESTROYMISSIONOBJECTIVE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObserver;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

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
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace objects {
namespace area {

class MissionSpawnActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace templates {
namespace mobile {

class LairTemplate;

} // namespace mobile
} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates::mobile;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/templates/TemplateReference.h"

#include "engine/util/Observer.h"

#include "engine/util/Observable.h"

#include "server/zone/objects/mission/MissionObjective.h"

namespace server {
namespace zone {
namespace objects {
namespace mission {

class DestroyMissionObjective : public MissionObjective {
public:
	DestroyMissionObjective(MissionObject* mission);

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	Vector3 findValidSpawnPosition(Zone* zone);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setLairTemplateToSpawn(const String& sp);

	void setDifficulty(int min, int max);

	Vector3 getEndPosition();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	DestroyMissionObjective(DummyConstructorParameter* param);

	virtual ~DestroyMissionObjective();

	friend class DestroyMissionObjectiveHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class DestroyMissionObjectiveImplementation : public MissionObjectiveImplementation {
protected:
	String lairTemplate;

	ManagedReference<MissionSpawnActiveArea* > spawnActiveArea;

	ManagedReference<TangibleObject* > lairObject;

private:
	int minDifficulty;

	int maxDifficulty;

public:
	DestroyMissionObjectiveImplementation(MissionObject* mission);

	DestroyMissionObjectiveImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	Vector3 findValidSpawnPosition(Zone* zone);

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setLairTemplateToSpawn(const String& sp);

	void setDifficulty(int min, int max);

	Vector3 getEndPosition();

	WeakReference<DestroyMissionObjective*> _this;

	operator const DestroyMissionObjective*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~DestroyMissionObjectiveImplementation();

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

	friend class DestroyMissionObjective;
};

class DestroyMissionObjectiveAdapter : public MissionObjectiveAdapter {
public:
	DestroyMissionObjectiveAdapter(DestroyMissionObjective* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void activate();

	void abort();

	void complete();

	void spawnLair();

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void setDifficulty(int min, int max);

};

class DestroyMissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<DestroyMissionObjectiveHelper> {
	static DestroyMissionObjectiveHelper* staticInitializer;

public:
	DestroyMissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<DestroyMissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*DESTROYMISSIONOBJECTIVE_H_*/
