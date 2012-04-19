/*
 *	server/zone/objects/area/StaticSpawnArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "StaticSpawnArea.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/objects/creature/aigroup/AiGroup.h"

#include "server/zone/objects/area/SpawnObserver.h"

/*
 *	StaticSpawnAreaStub
 */

enum {RPC_SPAWNCREATURES__ = 6,RPC_ISSTATICAREA__};

StaticSpawnArea::StaticSpawnArea() : SpawnArea(DummyConstructorParameter::instance()) {
	StaticSpawnAreaImplementation* _implementation = new StaticSpawnAreaImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("StaticSpawnArea");
}

StaticSpawnArea::StaticSpawnArea(DummyConstructorParameter* param) : SpawnArea(param) {
	_setClassName("StaticSpawnArea");
}

StaticSpawnArea::~StaticSpawnArea() {
}



void StaticSpawnArea::spawnCreatures() {
	StaticSpawnAreaImplementation* _implementation = static_cast<StaticSpawnAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SPAWNCREATURES__);

		method.executeWithVoidReturn();
	} else
		_implementation->spawnCreatures();
}

bool StaticSpawnArea::isStaticArea() {
	StaticSpawnAreaImplementation* _implementation = static_cast<StaticSpawnAreaImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISSTATICAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStaticArea();
}

DistributedObjectServant* StaticSpawnArea::_getImplementation() {

	_updated = true;
	return _impl;
}

void StaticSpawnArea::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	StaticSpawnAreaImplementation
 */

StaticSpawnAreaImplementation::StaticSpawnAreaImplementation(DummyConstructorParameter* param) : SpawnAreaImplementation(param) {
	_initializeImplementation();
}


StaticSpawnAreaImplementation::~StaticSpawnAreaImplementation() {
}


void StaticSpawnAreaImplementation::finalize() {
}

void StaticSpawnAreaImplementation::_initializeImplementation() {
	_setClassHelper(StaticSpawnAreaHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void StaticSpawnAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<StaticSpawnArea*>(stub);
	SpawnAreaImplementation::_setStub(stub);
}

DistributedObjectStub* StaticSpawnAreaImplementation::_getStub() {
	return _this;
}

StaticSpawnAreaImplementation::operator const StaticSpawnArea*() {
	return _this;
}

void StaticSpawnAreaImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void StaticSpawnAreaImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void StaticSpawnAreaImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void StaticSpawnAreaImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void StaticSpawnAreaImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void StaticSpawnAreaImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void StaticSpawnAreaImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void StaticSpawnAreaImplementation::_serializationHelperMethod() {
	SpawnAreaImplementation::_serializationHelperMethod();

	_setClassName("StaticSpawnArea");

}

void StaticSpawnAreaImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(StaticSpawnAreaImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StaticSpawnAreaImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SpawnAreaImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "StaticSpawnArea.groups") {
		TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::parseFromBinaryStream(&groups, stream);
		return true;
	}


	return false;
}

void StaticSpawnAreaImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StaticSpawnAreaImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StaticSpawnAreaImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = SpawnAreaImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "StaticSpawnArea.groups";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<SortedVector<ManagedReference<AiGroup* > > >::toBinaryStream(&groups, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

StaticSpawnAreaImplementation::StaticSpawnAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/StaticSpawnArea.idl():  		Logger.setLoggingName("StaticSpawnArea");
	Logger::setLoggingName("StaticSpawnArea");
}

bool StaticSpawnAreaImplementation::isStaticArea() {
	// server/zone/objects/area/StaticSpawnArea.idl():  		return true;
	return true;
}

/*
 *	StaticSpawnAreaAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


StaticSpawnAreaAdapter::StaticSpawnAreaAdapter(StaticSpawnArea* obj) : SpawnAreaAdapter(obj) {
}

void StaticSpawnAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_SPAWNCREATURES__:
		spawnCreatures();
		break;
	case RPC_ISSTATICAREA__:
		resp->insertBoolean(isStaticArea());
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void StaticSpawnAreaAdapter::spawnCreatures() {
	(static_cast<StaticSpawnArea*>(stub))->spawnCreatures();
}

bool StaticSpawnAreaAdapter::isStaticArea() {
	return (static_cast<StaticSpawnArea*>(stub))->isStaticArea();
}

/*
 *	StaticSpawnAreaHelper
 */

StaticSpawnAreaHelper* StaticSpawnAreaHelper::staticInitializer = StaticSpawnAreaHelper::instance();

StaticSpawnAreaHelper::StaticSpawnAreaHelper() {
	className = "StaticSpawnArea";

	Core::getObjectBroker()->registerClass(className, this);
}

void StaticSpawnAreaHelper::finalizeHelper() {
	StaticSpawnAreaHelper::finalize();
}

DistributedObject* StaticSpawnAreaHelper::instantiateObject() {
	return new StaticSpawnArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* StaticSpawnAreaHelper::instantiateServant() {
	return new StaticSpawnAreaImplementation();
}

DistributedObjectAdapter* StaticSpawnAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StaticSpawnAreaAdapter(static_cast<StaticSpawnArea*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

