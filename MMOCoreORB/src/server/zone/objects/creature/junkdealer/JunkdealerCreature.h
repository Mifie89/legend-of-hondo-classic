/*
 *	server/zone/objects/creature/junkdealer/JunkdealerCreature.h generated by engine3 IDL compiler 0.61
 */

#ifndef JUNKDEALERCREATURE_H_
#define JUNKDEALERCREATURE_H_

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
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "server/zone/objects/creature/professions/Profession.h"

#include "server/zone/objects/creature/professions/ProfessionReference.h"

#include "engine/core/ManagedObject.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace junkdealer {

class JunkdealerCreature : public CreatureObject {
public:
	static const int BLUERUG = 0xFC9F6877;

	static const int ORANGERUG = 0xEF7647E0;

	static const int SCULPTURE = 0x5000DA81;

	static const int TABLE = 0x4674A1B6;

	static const int GONG = 0xB26210DB;

	JunkdealerCreature();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void activateRecovery();

	void sendInitialMessage(PlayerCreature* player);

	void sendInitialChoices(PlayerCreature* player);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	String getLocation();

	void setLocation(const String& loc);

	bool isAttackableBy(CreatureObject* object);

	void createSellJunkLootSelection(PlayerCreature* player);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	JunkdealerCreature(DummyConstructorParameter* param);

	virtual ~JunkdealerCreature();

	String _return_getLocation;

	friend class JunkdealerCreatureHelper;
};

} // namespace junkdealer
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::junkdealer;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace junkdealer {

class JunkdealerCreatureImplementation : public CreatureObjectImplementation {
protected:
	String location;

public:
	static const int BLUERUG = 0xFC9F6877;

	static const int ORANGERUG = 0xEF7647E0;

	static const int SCULPTURE = 0x5000DA81;

	static const int TABLE = 0x4674A1B6;

	static const int GONG = 0xB26210DB;

	JunkdealerCreatureImplementation();

	JunkdealerCreatureImplementation(DummyConstructorParameter* param);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void activateRecovery();

	void sendInitialMessage(PlayerCreature* player);

	void sendInitialChoices(PlayerCreature* player);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	String getLocation();

	void setLocation(const String& loc);

	bool isAttackableBy(CreatureObject* object);

	void createSellJunkLootSelection(PlayerCreature* player);

	JunkdealerCreature* _this;

	operator const JunkdealerCreature*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~JunkdealerCreatureImplementation();

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

	friend class JunkdealerCreature;
};

class JunkdealerCreatureAdapter : public CreatureObjectAdapter {
public:
	JunkdealerCreatureAdapter(JunkdealerCreatureImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void activateRecovery();

	void sendInitialMessage(PlayerCreature* player);

	void sendInitialChoices(PlayerCreature* player);

	void sendConversationStartTo(SceneObject* obj);

	void selectConversationOption(int option, SceneObject* obj);

	String getLocation();

	void setLocation(const String& loc);

	bool isAttackableBy(CreatureObject* object);

	void createSellJunkLootSelection(PlayerCreature* player);

protected:
	String _param0_setLocation__String_;
};

class JunkdealerCreatureHelper : public DistributedObjectClassHelper, public Singleton<JunkdealerCreatureHelper> {
	static JunkdealerCreatureHelper* staticInitializer;

public:
	JunkdealerCreatureHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<JunkdealerCreatureHelper>;
};

} // namespace junkdealer
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::junkdealer;

#endif /*JUNKDEALERCREATURE_H_*/
