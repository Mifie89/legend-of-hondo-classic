/*
 *	server/zone/objects/mission/ReconMissionObjective.cpp generated by engine3 IDL compiler 0.61
 */

#include "ReconMissionObjective.h"

#include "server/zone/objects/scene/Observer.h"

#include "server/zone/objects/scene/Observable.h"

#include "server/zone/objects/mission/MissionObject.h"

#include "server/zone/objects/mission/MissionObserver.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/area/MissionReconActiveArea.h"

/*
 *	ReconMissionObjectiveStub
 */

ReconMissionObjective::ReconMissionObjective(MissionObject* mission) : MissionObjective(DummyConstructorParameter::instance()) {
	ReconMissionObjectiveImplementation* _implementation = new ReconMissionObjectiveImplementation(mission);
	_impl = _implementation;
	_impl->_setStub(this);
}

ReconMissionObjective::ReconMissionObjective(DummyConstructorParameter* param) : MissionObjective(param) {
}

ReconMissionObjective::~ReconMissionObjective() {
}


void ReconMissionObjective::initializeTransientMembers() {
	ReconMissionObjectiveImplementation* _implementation = (ReconMissionObjectiveImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void ReconMissionObjective::activate() {
	ReconMissionObjectiveImplementation* _implementation = (ReconMissionObjectiveImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->activate();
}

void ReconMissionObjective::abort() {
	ReconMissionObjectiveImplementation* _implementation = (ReconMissionObjectiveImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		_implementation->abort();
}

void ReconMissionObjective::complete() {
	ReconMissionObjectiveImplementation* _implementation = (ReconMissionObjectiveImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		_implementation->complete();
}

DistributedObjectServant* ReconMissionObjective::_getImplementation() {
	return _impl;}

void ReconMissionObjective::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	ReconMissionObjectiveImplementation
 */

ReconMissionObjectiveImplementation::ReconMissionObjectiveImplementation(DummyConstructorParameter* param) : MissionObjectiveImplementation(param) {
	_initializeImplementation();
}


ReconMissionObjectiveImplementation::~ReconMissionObjectiveImplementation() {
	ReconMissionObjectiveImplementation::finalize();
}


void ReconMissionObjectiveImplementation::_initializeImplementation() {
	_setClassHelper(ReconMissionObjectiveHelper::instance());

	_serializationHelperMethod();
}

void ReconMissionObjectiveImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ReconMissionObjective*) stub;
	MissionObjectiveImplementation::_setStub(stub);
}

DistributedObjectStub* ReconMissionObjectiveImplementation::_getStub() {
	return _this;
}

ReconMissionObjectiveImplementation::operator const ReconMissionObjective*() {
	return _this;
}

void ReconMissionObjectiveImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ReconMissionObjectiveImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ReconMissionObjectiveImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ReconMissionObjectiveImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ReconMissionObjectiveImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ReconMissionObjectiveImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ReconMissionObjectiveImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ReconMissionObjectiveImplementation::_serializationHelperMethod() {
	MissionObjectiveImplementation::_serializationHelperMethod();

	_setClassName("ReconMissionObjective");

	addSerializableVariable("locationActiveArea", &locationActiveArea);
}

ReconMissionObjectiveImplementation::ReconMissionObjectiveImplementation(MissionObject* mission) : MissionObjectiveImplementation(mission) {
	_initializeImplementation();
	// server/zone/objects/mission/ReconMissionObjective.idl(63):  		Logger.setLoggingName("ReconMissionObjective");
	Logger::setLoggingName("ReconMissionObjective");
}

void ReconMissionObjectiveImplementation::finalize() {
	// server/zone/objects/mission/ReconMissionObjective.idl(67):  		Logger.info("deleting from memory", true);
	Logger::info("deleting from memory", true);
}

void ReconMissionObjectiveImplementation::initializeTransientMembers() {
	// server/zone/objects/mission/ReconMissionObjective.idl(71):  		super.initializeTransientMembers();
	MissionObjectiveImplementation::initializeTransientMembers();
	// server/zone/objects/mission/ReconMissionObjective.idl(73):  		Logger.setLoggingName("MissionObject");
	Logger::setLoggingName("MissionObject");
	// server/zone/objects/mission/ReconMissionObjective.idl(75):  		activate();
	activate();
}

/*
 *	ReconMissionObjectiveAdapter
 */

ReconMissionObjectiveAdapter::ReconMissionObjectiveAdapter(ReconMissionObjectiveImplementation* obj) : MissionObjectiveAdapter(obj) {
}

Packet* ReconMissionObjectiveAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		finalize();
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		activate();
		break;
	case 9:
		abort();
		break;
	case 10:
		complete();
		break;
	default:
		return NULL;
	}

	return resp;
}

void ReconMissionObjectiveAdapter::finalize() {
	((ReconMissionObjectiveImplementation*) impl)->finalize();
}

void ReconMissionObjectiveAdapter::initializeTransientMembers() {
	((ReconMissionObjectiveImplementation*) impl)->initializeTransientMembers();
}

void ReconMissionObjectiveAdapter::activate() {
	((ReconMissionObjectiveImplementation*) impl)->activate();
}

void ReconMissionObjectiveAdapter::abort() {
	((ReconMissionObjectiveImplementation*) impl)->abort();
}

void ReconMissionObjectiveAdapter::complete() {
	((ReconMissionObjectiveImplementation*) impl)->complete();
}

/*
 *	ReconMissionObjectiveHelper
 */

ReconMissionObjectiveHelper* ReconMissionObjectiveHelper::staticInitializer = ReconMissionObjectiveHelper::instance();

ReconMissionObjectiveHelper::ReconMissionObjectiveHelper() {
	className = "ReconMissionObjective";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ReconMissionObjectiveHelper::finalizeHelper() {
	ReconMissionObjectiveHelper::finalize();
}

DistributedObject* ReconMissionObjectiveHelper::instantiateObject() {
	return new ReconMissionObjective(DummyConstructorParameter::instance());
}

DistributedObjectServant* ReconMissionObjectiveHelper::instantiateServant() {
	return new ReconMissionObjectiveImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ReconMissionObjectiveHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ReconMissionObjectiveAdapter((ReconMissionObjectiveImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

