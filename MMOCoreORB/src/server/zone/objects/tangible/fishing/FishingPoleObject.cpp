/*
 *	server/zone/objects/tangible/fishing/FishingPoleObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "FishingPoleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

/*
 *	FishingPoleObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_GETQUALITY__,RPC_SETQUALITY__INT_,RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_CREATUREOBJECT_,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_CANADDOBJECT__SCENEOBJECT_INT_STRING_,RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_CREATUREOBJECT_,RPC_DOFISHING__CREATUREOBJECT_,RPC_GETTEXT__CREATUREOBJECT_,RPC_REMOVEOBJECT__SCENEOBJECT_SCENEOBJECT_BOOL_};

FishingPoleObject::FishingPoleObject() : TangibleObject(DummyConstructorParameter::instance()) {
	FishingPoleObjectImplementation* _implementation = new FishingPoleObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

FishingPoleObject::FishingPoleObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

FishingPoleObject::~FishingPoleObject() {
}



void FishingPoleObject::initializeTransientMembers() {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

int FishingPoleObject::getQuality() {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETQUALITY__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getQuality();
}

void FishingPoleObject::setQuality(int value) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETQUALITY__INT_);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->setQuality(value);
}

void FishingPoleObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_CREATUREOBJECT_);
		method.addObjectParameter(menuResponse);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int FishingPoleObject::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

int FishingPoleObject::canAddObject(SceneObject* object, int containmentType, String& errorDescription) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANADDOBJECT__SCENEOBJECT_INT_STRING_);
		method.addObjectParameter(object);
		method.addSignedIntParameter(containmentType);
		method.addAsciiParameter(errorDescription);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->canAddObject(object, containmentType, errorDescription);
}

void FishingPoleObject::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_CREATUREOBJECT_);
		method.addObjectParameter(msg);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->fillAttributeList(msg, object);
}

void FishingPoleObject::doFishing(CreatureObject* player) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOFISHING__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->doFishing(player);
}

String FishingPoleObject::getText(CreatureObject* player) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTEXT__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithAsciiReturn(_return_getText);
		return _return_getText;
	} else
		return _implementation->getText(player);
}

bool FishingPoleObject::removeObject(SceneObject* object, SceneObject* destination, bool notifyClient) {
	FishingPoleObjectImplementation* _implementation = static_cast<FishingPoleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEOBJECT__SCENEOBJECT_SCENEOBJECT_BOOL_);
		method.addObjectParameter(object);
		method.addObjectParameter(destination);
		method.addBooleanParameter(notifyClient);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->removeObject(object, destination, notifyClient);
}

DistributedObjectServant* FishingPoleObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void FishingPoleObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	FishingPoleObjectImplementation
 */

FishingPoleObjectImplementation::FishingPoleObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


FishingPoleObjectImplementation::~FishingPoleObjectImplementation() {
}


void FishingPoleObjectImplementation::finalize() {
}

void FishingPoleObjectImplementation::_initializeImplementation() {
	_setClassHelper(FishingPoleObjectHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void FishingPoleObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<FishingPoleObject*>(stub);
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FishingPoleObjectImplementation::_getStub() {
	return _this;
}

FishingPoleObjectImplementation::operator const FishingPoleObject*() {
	return _this;
}

void FishingPoleObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void FishingPoleObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void FishingPoleObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void FishingPoleObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void FishingPoleObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void FishingPoleObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void FishingPoleObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void FishingPoleObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("FishingPoleObject");

}

void FishingPoleObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(FishingPoleObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FishingPoleObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "quality") {
		TypeInfo<int >::parseFromBinaryStream(&quality, stream);
		return true;
	}


	return false;
}

void FishingPoleObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FishingPoleObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FishingPoleObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "quality";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&quality, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + TangibleObjectImplementation::writeObjectMembers(stream);
}

FishingPoleObjectImplementation::FishingPoleObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  		Logger.setLoggingName("FishingPoleObject");
	Logger::setLoggingName("FishingPoleObject");
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  		quality = 50;
	quality = 50;
}

void FishingPoleObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  		Logger.setLoggingName("FishingPoleObject");
	Logger::setLoggingName("FishingPoleObject");
}

int FishingPoleObjectImplementation::getQuality() {
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  		return quality;
	return quality;
}

void FishingPoleObjectImplementation::setQuality(int value) {
	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  	}
	if ((value > -1) && (value < 101))	// server/zone/objects/tangible/fishing/FishingPoleObject.idl():  			quality = value;
	quality = value;
}

/*
 *	FishingPoleObjectAdapter
 */

FishingPoleObjectAdapter::FishingPoleObjectAdapter(FishingPoleObject* obj) : TangibleObjectAdapter(obj) {
}

Packet* FishingPoleObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_GETQUALITY__:
		resp->insertSignedInt(getQuality());
		break;
	case RPC_SETQUALITY__INT_:
		setQuality(inv->getSignedIntParameter());
		break;
	case RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_CREATUREOBJECT_:
		fillObjectMenuResponse(static_cast<ObjectMenuResponse*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_CANADDOBJECT__SCENEOBJECT_INT_STRING_:
		resp->insertSignedInt(canAddObject(static_cast<SceneObject*>(inv->getObjectParameter()), inv->getSignedIntParameter(), inv->getAsciiParameter(_param2_canAddObject__SceneObject_int_String_)));
		break;
	case RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_CREATUREOBJECT_:
		fillAttributeList(static_cast<AttributeListMessage*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_DOFISHING__CREATUREOBJECT_:
		doFishing(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_GETTEXT__CREATUREOBJECT_:
		resp->insertAscii(getText(static_cast<CreatureObject*>(inv->getObjectParameter())));
		break;
	case RPC_REMOVEOBJECT__SCENEOBJECT_SCENEOBJECT_BOOL_:
		resp->insertBoolean(removeObject(static_cast<SceneObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()), inv->getBooleanParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void FishingPoleObjectAdapter::initializeTransientMembers() {
	(static_cast<FishingPoleObject*>(stub))->initializeTransientMembers();
}

int FishingPoleObjectAdapter::getQuality() {
	return (static_cast<FishingPoleObject*>(stub))->getQuality();
}

void FishingPoleObjectAdapter::setQuality(int value) {
	(static_cast<FishingPoleObject*>(stub))->setQuality(value);
}

void FishingPoleObjectAdapter::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	(static_cast<FishingPoleObject*>(stub))->fillObjectMenuResponse(menuResponse, player);
}

int FishingPoleObjectAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<FishingPoleObject*>(stub))->handleObjectMenuSelect(player, selectedID);
}

int FishingPoleObjectAdapter::canAddObject(SceneObject* object, int containmentType, String& errorDescription) {
	return (static_cast<FishingPoleObject*>(stub))->canAddObject(object, containmentType, errorDescription);
}

void FishingPoleObjectAdapter::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	(static_cast<FishingPoleObject*>(stub))->fillAttributeList(msg, object);
}

void FishingPoleObjectAdapter::doFishing(CreatureObject* player) {
	(static_cast<FishingPoleObject*>(stub))->doFishing(player);
}

String FishingPoleObjectAdapter::getText(CreatureObject* player) {
	return (static_cast<FishingPoleObject*>(stub))->getText(player);
}

bool FishingPoleObjectAdapter::removeObject(SceneObject* object, SceneObject* destination, bool notifyClient) {
	return (static_cast<FishingPoleObject*>(stub))->removeObject(object, destination, notifyClient);
}

/*
 *	FishingPoleObjectHelper
 */

FishingPoleObjectHelper* FishingPoleObjectHelper::staticInitializer = FishingPoleObjectHelper::instance();

FishingPoleObjectHelper::FishingPoleObjectHelper() {
	className = "FishingPoleObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void FishingPoleObjectHelper::finalizeHelper() {
	FishingPoleObjectHelper::finalize();
}

DistributedObject* FishingPoleObjectHelper::instantiateObject() {
	return new FishingPoleObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* FishingPoleObjectHelper::instantiateServant() {
	return new FishingPoleObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FishingPoleObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FishingPoleObjectAdapter(static_cast<FishingPoleObject*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

