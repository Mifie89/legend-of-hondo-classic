/*
 *	server/zone/objects/tangible/weapon/TwoHandMeleeWeapon.h generated by engine3 IDL compiler 0.60
 */

#ifndef TWOHANDMELEEWEAPON_H_
#define TWOHANDMELEEWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

#include "server/zone/objects/tangible/weapon/MeleeWeaponObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class TwoHandMeleeWeapon : public MeleeWeaponObject {
public:
	TwoHandMeleeWeapon();

	void initializeTransientMembers();

	bool isTwoHandMeleeWeapon();

protected:
	TwoHandMeleeWeapon(DummyConstructorParameter* param);

	virtual ~TwoHandMeleeWeapon();

	friend class TwoHandMeleeWeaponHelper;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class TwoHandMeleeWeaponImplementation : public MeleeWeaponObjectImplementation {

public:
	TwoHandMeleeWeaponImplementation();

	TwoHandMeleeWeaponImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	bool isTwoHandMeleeWeapon();

	TwoHandMeleeWeapon* _this;

	operator const TwoHandMeleeWeapon*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~TwoHandMeleeWeaponImplementation();

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

	friend class TwoHandMeleeWeapon;
};

class TwoHandMeleeWeaponAdapter : public MeleeWeaponObjectAdapter {
public:
	TwoHandMeleeWeaponAdapter(TwoHandMeleeWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	bool isTwoHandMeleeWeapon();

};

class TwoHandMeleeWeaponHelper : public DistributedObjectClassHelper, public Singleton<TwoHandMeleeWeaponHelper> {
	static TwoHandMeleeWeaponHelper* staticInitializer;

public:
	TwoHandMeleeWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<TwoHandMeleeWeaponHelper>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

#endif /*TWOHANDMELEEWEAPON_H_*/
