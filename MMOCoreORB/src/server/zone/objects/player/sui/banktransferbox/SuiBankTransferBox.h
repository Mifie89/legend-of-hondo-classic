/*
 *	server/zone/objects/player/sui/banktransferbox/SuiBankTransferBox.h generated by engine3 IDL compiler 0.60
 */

#ifndef SUIBANKTRANSFERBOX_H_
#define SUIBANKTRANSFERBOX_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "server/zone/packets/ui/SuiCreatePageMessage.h"

#include "engine/lua/LuaObject.h"

#include "system/io/StringTokenizer.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "system/lang/String.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace banktransferbox {

class SuiBankTransferBox : public SuiBox {
public:
	SuiBankTransferBox(SceneObject* bankObject, PlayerCreature* player, unsigned int windowtype);

	void addCash(int cash);

	void addBank(int bank);

	SceneObject* getBank();

	BaseMessage* generateMessage();

protected:
	SuiBankTransferBox(DummyConstructorParameter* param);

	virtual ~SuiBankTransferBox();

	friend class SuiBankTransferBoxHelper;
};

} // namespace banktransferbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::banktransferbox;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sui {
namespace banktransferbox {

class SuiBankTransferBoxImplementation : public SuiBoxImplementation {
protected:
	String lblFrom;

	String lblStartingFrom;

	String lblInputFrom;

	String lblTo;

	String lblStartingTo;

	String lblInputTo;

	String convertRatioFrom;

	String convertRatioTo;

	ManagedReference<SceneObject* > bank;

public:
	SuiBankTransferBoxImplementation(SceneObject* bankObject, PlayerCreature* player, unsigned int windowtype);

	SuiBankTransferBoxImplementation(DummyConstructorParameter* param);

	void addCash(int cash);

	void addBank(int bank);

	SceneObject* getBank();

	BaseMessage* generateMessage();

	SuiBankTransferBox* _this;

	operator const SuiBankTransferBox*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~SuiBankTransferBoxImplementation();

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

	friend class SuiBankTransferBox;
};

class SuiBankTransferBoxAdapter : public SuiBoxAdapter {
public:
	SuiBankTransferBoxAdapter(SuiBankTransferBoxImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void addCash(int cash);

	void addBank(int bank);

	SceneObject* getBank();

	BaseMessage* generateMessage();

};

class SuiBankTransferBoxHelper : public DistributedObjectClassHelper, public Singleton<SuiBankTransferBoxHelper> {
	static SuiBankTransferBoxHelper* staticInitializer;

public:
	SuiBankTransferBoxHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SuiBankTransferBoxHelper>;
};

} // namespace banktransferbox
} // namespace sui
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sui::banktransferbox;

#endif /*SUIBANKTRANSFERBOX_H_*/
