/*
 *	server/zone/ZoneProcessServer.cpp generated by engine3 IDL compiler 0.60
 */

#include "ZoneProcessServer.h"

#include "server/zone/managers/player/creation/PlayerCreationManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/skill/SkillManager.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

/*
 *	ZoneProcessServerStub
 */

enum {RPC_INITIALIZE__ = 6,RPC_FINALIZE__,RPC_GETZONESERVER__,RPC_GETPLAYERMANAGER__,RPC_GETCHATMANAGER__,};

ZoneProcessServer::ZoneProcessServer(ZoneServer* server) : ManagedService(DummyConstructorParameter::instance()) {
	ZoneProcessServerImplementation* _implementation = new ZoneProcessServerImplementation(server);
	_impl = _implementation;
	_impl->_setStub(this);
}

ZoneProcessServer::ZoneProcessServer(DummyConstructorParameter* param) : ManagedService(param) {
}

ZoneProcessServer::~ZoneProcessServer() {
}



void ZoneProcessServer::initialize() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize();
}

VendorManager* ZoneProcessServer::getVendorManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getVendorManager();
}

ZoneServer* ZoneProcessServer::getZoneServer() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETZONESERVER__);

		return static_cast<ZoneServer*>(method.executeWithObjectReturn());
	} else
		return _implementation->getZoneServer();
}

ZonePacketHandler* ZoneProcessServer::getPacketHandler() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getPacketHandler();
}

SkillManager* ZoneProcessServer::getSkillManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getSkillManager();
}

ObjectController* ZoneProcessServer::getObjectController() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getObjectController();
}

PlayerManager* ZoneProcessServer::getPlayerManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPLAYERMANAGER__);

		return static_cast<PlayerManager*>(method.executeWithObjectReturn());
	} else
		return _implementation->getPlayerManager();
}

NameManager* ZoneProcessServer::getNameManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getNameManager();
}

HolocronManager* ZoneProcessServer::getHolocronManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getHolocronManager();
}

ChatManager* ZoneProcessServer::getChatManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCHATMANAGER__);

		return static_cast<ChatManager*>(method.executeWithObjectReturn());
	} else
		return _implementation->getChatManager();
}

SuiManager* ZoneProcessServer::getSuiManager() {
	ZoneProcessServerImplementation* _implementation = static_cast<ZoneProcessServerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getSuiManager();
}

DistributedObjectServant* ZoneProcessServer::_getImplementation() {

	_updated = true;
	return _impl;
}

void ZoneProcessServer::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ZoneProcessServerImplementation
 */

ZoneProcessServerImplementation::ZoneProcessServerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


ZoneProcessServerImplementation::~ZoneProcessServerImplementation() {
	ZoneProcessServerImplementation::finalize();
}


void ZoneProcessServerImplementation::_initializeImplementation() {
	_setClassHelper(ZoneProcessServerHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ZoneProcessServerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<ZoneProcessServer*>(stub);
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* ZoneProcessServerImplementation::_getStub() {
	return _this;
}

ZoneProcessServerImplementation::operator const ZoneProcessServer*() {
	return _this;
}

void ZoneProcessServerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ZoneProcessServerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ZoneProcessServerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ZoneProcessServerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ZoneProcessServerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ZoneProcessServerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ZoneProcessServerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ZoneProcessServerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("ZoneProcessServer");

}

void ZoneProcessServerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ZoneProcessServerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ZoneProcessServerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedServiceImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void ZoneProcessServerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ZoneProcessServerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ZoneProcessServerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + ManagedServiceImplementation::writeObjectMembers(stream);
}

VendorManager* ZoneProcessServerImplementation::getVendorManager() {
	// server/zone/ZoneProcessServer.idl():  		return vendorManager;
	return vendorManager;
}

ZoneServer* ZoneProcessServerImplementation::getZoneServer() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer;
	return zoneServer;
}

ZonePacketHandler* ZoneProcessServerImplementation::getPacketHandler() {
	// server/zone/ZoneProcessServer.idl():  		return zonePacketHandler;
	return zonePacketHandler;
}

SkillManager* ZoneProcessServerImplementation::getSkillManager() {
	// server/zone/ZoneProcessServer.idl():  		return professionManager;
	return professionManager;
}

ObjectController* ZoneProcessServerImplementation::getObjectController() {
	// server/zone/ZoneProcessServer.idl():  		return objectController;
	return objectController;
}

PlayerManager* ZoneProcessServerImplementation::getPlayerManager() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer.getPlayerManager();
	return zoneServer->getPlayerManager();
}

NameManager* ZoneProcessServerImplementation::getNameManager() {
	// server/zone/ZoneProcessServer.idl():  		return nameManager;
	return nameManager;
}

HolocronManager* ZoneProcessServerImplementation::getHolocronManager() {
	// server/zone/ZoneProcessServer.idl():  		return holocronManager;
	return holocronManager;
}

ChatManager* ZoneProcessServerImplementation::getChatManager() {
	// server/zone/ZoneProcessServer.idl():  		return zoneServer.getChatManager();
	return zoneServer->getChatManager();
}

SuiManager* ZoneProcessServerImplementation::getSuiManager() {
	// server/zone/ZoneProcessServer.idl():  		return suiManager;
	return suiManager;
}

/*
 *	ZoneProcessServerAdapter
 */

ZoneProcessServerAdapter::ZoneProcessServerAdapter(ZoneProcessServerImplementation* obj) : ManagedServiceAdapter(obj) {
}

Packet* ZoneProcessServerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZE__:
		initialize();
		break;
	case RPC_FINALIZE__:
		finalize();
		break;
	case RPC_GETZONESERVER__:
		resp->insertLong(getZoneServer()->_getObjectID());
		break;
	case RPC_GETPLAYERMANAGER__:
		resp->insertLong(getPlayerManager()->_getObjectID());
		break;
	case RPC_GETCHATMANAGER__:
		resp->insertLong(getChatManager()->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ZoneProcessServerAdapter::initialize() {
	(static_cast<ZoneProcessServerImplementation*>(impl))->initialize();
}

void ZoneProcessServerAdapter::finalize() {
	(static_cast<ZoneProcessServerImplementation*>(impl))->finalize();
}

ZoneServer* ZoneProcessServerAdapter::getZoneServer() {
	return (static_cast<ZoneProcessServerImplementation*>(impl))->getZoneServer();
}

PlayerManager* ZoneProcessServerAdapter::getPlayerManager() {
	return (static_cast<ZoneProcessServerImplementation*>(impl))->getPlayerManager();
}

ChatManager* ZoneProcessServerAdapter::getChatManager() {
	return (static_cast<ZoneProcessServerImplementation*>(impl))->getChatManager();
}

/*
 *	ZoneProcessServerHelper
 */

ZoneProcessServerHelper* ZoneProcessServerHelper::staticInitializer = ZoneProcessServerHelper::instance();

ZoneProcessServerHelper::ZoneProcessServerHelper() {
	className = "ZoneProcessServer";

	Core::getObjectBroker()->registerClass(className, this);
}

void ZoneProcessServerHelper::finalizeHelper() {
	ZoneProcessServerHelper::finalize();
}

DistributedObject* ZoneProcessServerHelper::instantiateObject() {
	return new ZoneProcessServer(DummyConstructorParameter::instance());
}

DistributedObjectServant* ZoneProcessServerHelper::instantiateServant() {
	return new ZoneProcessServerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ZoneProcessServerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ZoneProcessServerAdapter(static_cast<ZoneProcessServerImplementation*>(obj->_getImplementation()));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

