/*
 *	server/zone/objects/building/hospital/HospitalBuildingObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "HospitalBuildingObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/cell/CellObject.h"

/*
 *	HospitalBuildingObjectStub
 */

enum {RPC_ISHOSPITALBUILDINGOBJECT__ = 6,RPC_ONENTER__CREATUREOBJECT_,RPC_ONEXIT__CREATUREOBJECT_};

HospitalBuildingObject::HospitalBuildingObject() : BuildingObject(DummyConstructorParameter::instance()) {
	HospitalBuildingObjectImplementation* _implementation = new HospitalBuildingObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

HospitalBuildingObject::HospitalBuildingObject(DummyConstructorParameter* param) : BuildingObject(param) {
}

HospitalBuildingObject::~HospitalBuildingObject() {
}



bool HospitalBuildingObject::isHospitalBuildingObject() {
	HospitalBuildingObjectImplementation* _implementation = static_cast<HospitalBuildingObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISHOSPITALBUILDINGOBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isHospitalBuildingObject();
}

void HospitalBuildingObject::onEnter(CreatureObject* player) {
	HospitalBuildingObjectImplementation* _implementation = static_cast<HospitalBuildingObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ONENTER__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->onEnter(player);
}

void HospitalBuildingObject::onExit(CreatureObject* player) {
	HospitalBuildingObjectImplementation* _implementation = static_cast<HospitalBuildingObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ONEXIT__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->onExit(player);
}

DistributedObjectServant* HospitalBuildingObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void HospitalBuildingObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	HospitalBuildingObjectImplementation
 */

HospitalBuildingObjectImplementation::HospitalBuildingObjectImplementation(DummyConstructorParameter* param) : BuildingObjectImplementation(param) {
	_initializeImplementation();
}


HospitalBuildingObjectImplementation::~HospitalBuildingObjectImplementation() {
}


void HospitalBuildingObjectImplementation::finalize() {
}

void HospitalBuildingObjectImplementation::_initializeImplementation() {
	_setClassHelper(HospitalBuildingObjectHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void HospitalBuildingObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<HospitalBuildingObject*>(stub);
	BuildingObjectImplementation::_setStub(stub);
}

DistributedObjectStub* HospitalBuildingObjectImplementation::_getStub() {
	return _this;
}

HospitalBuildingObjectImplementation::operator const HospitalBuildingObject*() {
	return _this;
}

void HospitalBuildingObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void HospitalBuildingObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void HospitalBuildingObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void HospitalBuildingObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void HospitalBuildingObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void HospitalBuildingObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void HospitalBuildingObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void HospitalBuildingObjectImplementation::_serializationHelperMethod() {
	BuildingObjectImplementation::_serializationHelperMethod();

	_setClassName("HospitalBuildingObject");

}

void HospitalBuildingObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(HospitalBuildingObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool HospitalBuildingObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (BuildingObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void HospitalBuildingObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = HospitalBuildingObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int HospitalBuildingObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + BuildingObjectImplementation::writeObjectMembers(stream);
}

HospitalBuildingObjectImplementation::HospitalBuildingObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  		Logger.setLoggingName("HospitalBuildingObject");
	Logger::setLoggingName("HospitalBuildingObject");
}

bool HospitalBuildingObjectImplementation::isHospitalBuildingObject() {
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  		return true;
	return true;
}

void HospitalBuildingObjectImplementation::onEnter(CreatureObject* player) {
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  		HospitalBuildingObjectTemplate hospitalTemplate = null;
	HospitalBuildingObjectTemplate* hospitalTemplate = NULL;
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  	}
	if (BuildingObjectImplementation::templateObject->isHospitalBuildingObjectTemplate()){
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			hospitalTemplate = (HospitalBuildingObjectTemplate) super.getObjectTemplate();
	hospitalTemplate = (HospitalBuildingObjectTemplate*) BuildingObjectImplementation::getObjectTemplate();
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_health", hospitalTemplate.getHealthWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_health", hospitalTemplate->getHealthWoundRegenRate(), false);
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_action", hospitalTemplate.getActionWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_action", hospitalTemplate->getActionWoundRegenRate(), false);
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_mind", hospitalTemplate.getMindWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_mind", hospitalTemplate->getMindWoundRegenRate(), false);
}
}

void HospitalBuildingObjectImplementation::onExit(CreatureObject* player) {
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  		HospitalBuildingObjectTemplate hospitalTemplate = null;
	HospitalBuildingObjectTemplate* hospitalTemplate = NULL;
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  	}
	if (BuildingObjectImplementation::templateObject->isHospitalBuildingObjectTemplate()){
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			hospitalTemplate = (HospitalBuildingObjectTemplate) super.getObjectTemplate();
	hospitalTemplate = (HospitalBuildingObjectTemplate*) BuildingObjectImplementation::getObjectTemplate();
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_health", -1 * hospitalTemplate.getHealthWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_health", -1 * hospitalTemplate->getHealthWoundRegenRate(), false);
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_action", -1 * hospitalTemplate.getActionWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_action", -1 * hospitalTemplate->getActionWoundRegenRate(), false);
	// server/zone/objects/building/hospital/HospitalBuildingObject.idl():  			player.addSkillMod("private_med_wound_mind", -1 * hospitalTemplate.getMindWoundRegenRate(), false);
	player->addSkillMod("private_med_wound_mind", -1 * hospitalTemplate->getMindWoundRegenRate(), false);
}
}

/*
 *	HospitalBuildingObjectAdapter
 */

HospitalBuildingObjectAdapter::HospitalBuildingObjectAdapter(HospitalBuildingObject* obj) : BuildingObjectAdapter(obj) {
}

Packet* HospitalBuildingObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ISHOSPITALBUILDINGOBJECT__:
		resp->insertBoolean(isHospitalBuildingObject());
		break;
	case RPC_ONENTER__CREATUREOBJECT_:
		onEnter(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_ONEXIT__CREATUREOBJECT_:
		onExit(static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

bool HospitalBuildingObjectAdapter::isHospitalBuildingObject() {
	return (static_cast<HospitalBuildingObject*>(stub))->isHospitalBuildingObject();
}

void HospitalBuildingObjectAdapter::onEnter(CreatureObject* player) {
	(static_cast<HospitalBuildingObject*>(stub))->onEnter(player);
}

void HospitalBuildingObjectAdapter::onExit(CreatureObject* player) {
	(static_cast<HospitalBuildingObject*>(stub))->onExit(player);
}

/*
 *	HospitalBuildingObjectHelper
 */

HospitalBuildingObjectHelper* HospitalBuildingObjectHelper::staticInitializer = HospitalBuildingObjectHelper::instance();

HospitalBuildingObjectHelper::HospitalBuildingObjectHelper() {
	className = "HospitalBuildingObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void HospitalBuildingObjectHelper::finalizeHelper() {
	HospitalBuildingObjectHelper::finalize();
}

DistributedObject* HospitalBuildingObjectHelper::instantiateObject() {
	return new HospitalBuildingObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* HospitalBuildingObjectHelper::instantiateServant() {
	return new HospitalBuildingObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* HospitalBuildingObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new HospitalBuildingObjectAdapter(static_cast<HospitalBuildingObject*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

