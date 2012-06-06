/*
 *	server/zone/objects/tangible/terminal/vendor/VendorTerminal.h generated by engine3 IDL compiler 0.60
 */

#ifndef VENDORTERMINAL_H_
#define VENDORTERMINAL_H_

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

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

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
namespace managers {
namespace planet {

class PlanetManager;

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;

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

#include "server/zone/objects/auction/Vendor.h"

#include "server/zone/objects/region/CityRegion.h"

#include "engine/core/ManagedObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/tangible/terminal/Terminal.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {

class VendorTerminal : public Terminal {
public:
	VendorTerminal();

	void initializeTransientMembers();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void addVendorToMap();

	void setOwnerID(unsigned long long ownerID);

	Vendor* getVendor();

	bool isVendor();

	bool isVendorTerminal();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	VendorTerminal(DummyConstructorParameter* param);

	virtual ~VendorTerminal();

	friend class VendorTerminalHelper;
};

} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace vendor {

class VendorTerminalImplementation : public TerminalImplementation {
protected:
	Vendor vendor;

public:
	VendorTerminalImplementation();

	VendorTerminalImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void finalize();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	void addVendorToMap();

	void setOwnerID(unsigned long long ownerID);

	Vendor* getVendor();

	bool isVendor();

	bool isVendorTerminal();

	WeakReference<VendorTerminal*> _this;

	operator const VendorTerminal*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~VendorTerminalImplementation();

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

	friend class VendorTerminal;
};

class VendorTerminalAdapter : public TerminalAdapter {
public:
	VendorTerminalAdapter(VendorTerminal* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void finalize();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	void destroyObjectFromDatabase(bool destroyContainedObjects);

	void addVendorToMap();

	void setOwnerID(unsigned long long ownerID);

	bool isVendor();

	bool isVendorTerminal();

};

class VendorTerminalHelper : public DistributedObjectClassHelper, public Singleton<VendorTerminalHelper> {
	static VendorTerminalHelper* staticInitializer;

public:
	VendorTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<VendorTerminalHelper>;
};

} // namespace vendor
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::vendor;

#endif /*VENDORTERMINAL_H_*/
