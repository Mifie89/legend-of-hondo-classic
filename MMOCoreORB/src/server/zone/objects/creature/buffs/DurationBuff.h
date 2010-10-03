/*
 *	server/zone/objects/creature/buffs/DurationBuff.h generated by engine3 IDL compiler 0.60
 */

#ifndef DURATIONBUFF_H_
#define DURATIONBUFF_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

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
namespace creature {
namespace buffs {

class BuffDurationEvent;

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class SpiceDownerBuff;

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/creature/buffs/BuffType.h"

#include "server/zone/objects/creature/buffs/BuffCRC.h"

#include "server/zone/objects/scene/variables/ParameterizedStringId.h"

#include "engine/core/ManagedObject.h"

#include "system/util/VectorMap.h"

#include "system/lang/ref/Reference.h"

#include "system/lang/Time.h"

#include "server/zone/objects/creature/buffs/Buff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class DurationBuff : public Buff {
public:
	DurationBuff(CreatureObject* creo, unsigned int buffcrc, float duration);

	void activate(bool applyModifiers);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	DurationBuff(DummyConstructorParameter* param);

	virtual ~DurationBuff();

	friend class DurationBuffHelper;
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class DurationBuffImplementation : public BuffImplementation {

public:
	DurationBuffImplementation(CreatureObject* creo, unsigned int buffcrc, float duration);

	DurationBuffImplementation(DummyConstructorParameter* param);

	void activate(bool applyModifiers);

	DurationBuff* _this;

	operator const DurationBuff*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~DurationBuffImplementation();

	TransactionalObject* clone();

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

	friend class DurationBuff;
	friend class TransactionalObjectHandle<DurationBuffImplementation*>;
};

class DurationBuffAdapter : public BuffAdapter {
public:
	DurationBuffAdapter(DurationBuffImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void activate(bool applyModifiers);

};

class DurationBuffHelper : public DistributedObjectClassHelper, public Singleton<DurationBuffHelper> {
	static DurationBuffHelper* staticInitializer;

public:
	DurationBuffHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<DurationBuffHelper>;
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;

#endif /*DURATIONBUFF_H_*/
