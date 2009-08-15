/*
 *	server/zone/managers/player/PlayerManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "PlayerManager.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/packets/MessageCallback.h"

#include "server/zone/ZoneServer.h"

/*
 *	PlayerManagerStub
 */

PlayerManager::PlayerManager(ZoneServer* zoneServer, ZoneProcessServerImplementation* impl) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new PlayerManagerImplementation(zoneServer, impl);
	_impl->_setStub(this);

	((PlayerManagerImplementation*) _impl)->_serializationHelperMethod();
}

PlayerManager::PlayerManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

PlayerManager::~PlayerManager() {
}

bool PlayerManager::createPlayer(MessageCallback* callback) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerManagerImplementation*) _impl)->createPlayer(callback);
}

bool PlayerManager::checkPlayerName(MessageCallback* callback) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((PlayerManagerImplementation*) _impl)->checkPlayerName(callback);
}

bool PlayerManager::checkExistentNameInDatabase(const String& firstName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addAsciiParameter(firstName);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->checkExistentNameInDatabase(firstName);
}

TangibleObject* PlayerManager::createHairObject(const String& hairObjectFile, const String& hairCustomization) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(hairObjectFile);
		method.addAsciiParameter(hairCustomization);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->createHairObject(hairObjectFile, hairCustomization);
}

bool PlayerManager::createAllPlayerObjects(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return ((PlayerManagerImplementation*) _impl)->createAllPlayerObjects(player);
}

void PlayerManager::createTutorialBuilding(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PlayerManagerImplementation*) _impl)->createTutorialBuilding(player);
}

/*
 *	PlayerManagerImplementation
 */

PlayerManagerImplementation::~PlayerManagerImplementation() {
}

void PlayerManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (PlayerManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* PlayerManagerImplementation::_getStub() {
	return _this;
}

PlayerManagerImplementation::operator const PlayerManager*() {
	return _this;
}

void PlayerManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	addSerializableVariable("server", server);
}

/*
 *	PlayerManagerAdapter
 */

PlayerManagerAdapter::PlayerManagerAdapter(PlayerManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* PlayerManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(checkExistentNameInDatabase(inv->getAsciiParameter(_param0_checkExistentNameInDatabase__String_)));
		break;
	case 7:
		resp->insertLong(createHairObject(inv->getAsciiParameter(_param0_createHairObject__String_String_), inv->getAsciiParameter(_param1_createHairObject__String_String_))->_getObjectID());
		break;
	case 8:
		resp->insertBoolean(createAllPlayerObjects((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 9:
		createTutorialBuilding((PlayerCreature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool PlayerManagerAdapter::checkExistentNameInDatabase(const String& firstName) {
	return ((PlayerManagerImplementation*) impl)->checkExistentNameInDatabase(firstName);
}

TangibleObject* PlayerManagerAdapter::createHairObject(const String& hairObjectFile, const String& hairCustomization) {
	return ((PlayerManagerImplementation*) impl)->createHairObject(hairObjectFile, hairCustomization);
}

bool PlayerManagerAdapter::createAllPlayerObjects(PlayerCreature* player) {
	return ((PlayerManagerImplementation*) impl)->createAllPlayerObjects(player);
}

void PlayerManagerAdapter::createTutorialBuilding(PlayerCreature* player) {
	return ((PlayerManagerImplementation*) impl)->createTutorialBuilding(player);
}

/*
 *	PlayerManagerHelper
 */

PlayerManagerHelper* PlayerManagerHelper::staticInitializer = PlayerManagerHelper::instance();

PlayerManagerHelper::PlayerManagerHelper() {
	className = "PlayerManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PlayerManagerHelper::finalizeHelper() {
	PlayerManagerHelper::finalize();
}

DistributedObject* PlayerManagerHelper::instantiateObject() {
	return new PlayerManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PlayerManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PlayerManagerAdapter((PlayerManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

