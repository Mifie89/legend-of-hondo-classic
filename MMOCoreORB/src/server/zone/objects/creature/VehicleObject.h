/*
 *	server/zone/objects/creature/VehicleObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef VEHICLEOBJECT_H_
#define VEHICLEOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace intangible {

class VehicleControlDevice;

} // namespace intangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::intangible;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "engine/core/ManagedObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {

class VehicleObject : public CreatureObject {
public:
	VehicleObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	bool checkInRangeGarage();

	void notifyInsertToZone(Zone* zone);

	void setPosture(int newPosture, bool notifyClient = true);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient = true);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDefender(SceneObject* defender);

	bool isAttackableBy(CreatureObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void repairVehicle(CreatureObject* player);

	int calculateRepairCost(CreatureObject* player);

	void sendRepairConfirmTo(CreatureObject* player);

	bool isVehicleObject();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	VehicleObject(DummyConstructorParameter* param);

	virtual ~VehicleObject();

	friend class VehicleObjectHelper;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class VehicleObjectImplementation : public CreatureObjectImplementation {
protected:
	int vehicleType;

public:
	VehicleObjectImplementation();

	VehicleObjectImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	bool checkInRangeGarage();

	void notifyInsertToZone(Zone* zone);

	void setPosture(int newPosture, bool notifyClient = true);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient = true);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDefender(SceneObject* defender);

	bool isAttackableBy(CreatureObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void repairVehicle(CreatureObject* player);

	int calculateRepairCost(CreatureObject* player);

	void sendRepairConfirmTo(CreatureObject* player);

	bool isVehicleObject();

	WeakReference<VehicleObject*> _this;

	operator const VehicleObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~VehicleObjectImplementation();

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

	friend class VehicleObject;
};

class VehicleObjectAdapter : public CreatureObjectAdapter {
public:
	VehicleObjectAdapter(VehicleObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	bool checkInRangeGarage();

	void notifyInsertToZone(Zone* zone);

	void setPosture(int newPosture, bool notifyClient);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient);

	int healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDefender(SceneObject* defender);

	bool isAttackableBy(CreatureObject* object);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void repairVehicle(CreatureObject* player);

	int calculateRepairCost(CreatureObject* player);

	void sendRepairConfirmTo(CreatureObject* player);

	bool isVehicleObject();

};

class VehicleObjectHelper : public DistributedObjectClassHelper, public Singleton<VehicleObjectHelper> {
	static VehicleObjectHelper* staticInitializer;

public:
	VehicleObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<VehicleObjectHelper>;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

#endif /*VEHICLEOBJECT_H_*/
