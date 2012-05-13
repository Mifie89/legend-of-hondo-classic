/*
 *	server/zone/managers/creature/LairObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "LairObserver.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/creature/HealLairObserverEvent.h"

/*
 *	LairObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6,RPC_NOTIFYDESTRUCTION__TANGIBLEOBJECT_TANGIBLEOBJECT_INT_,RPC_CHECKFORNEWSPAWNS__TANGIBLEOBJECT_BOOL_,RPC_HEALLAIR__TANGIBLEOBJECT_TANGIBLEOBJECT_,RPC_CHECKFORHEAL__TANGIBLEOBJECT_TANGIBLEOBJECT_BOOL_,RPC_SETDIFFICULTY__INT_INT_,RPC_ISLAIROBSERVER__};

LairObserver::LairObserver() : Observer(DummyConstructorParameter::instance()) {
	LairObserverImplementation* _implementation = new LairObserverImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("LairObserver");
}

LairObserver::LairObserver(DummyConstructorParameter* param) : Observer(param) {
	_setClassName("LairObserver");
}

LairObserver::~LairObserver() {
}



int LairObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void LairObserver::notifyDestruction(TangibleObject* lair, TangibleObject* attacker, int condition) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYDESTRUCTION__TANGIBLEOBJECT_TANGIBLEOBJECT_INT_);
		method.addObjectParameter(lair);
		method.addObjectParameter(attacker);
		method.addSignedIntParameter(condition);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyDestruction(lair, attacker, condition);
}

void LairObserver::checkForNewSpawns(TangibleObject* lair, bool forceSpawn) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKFORNEWSPAWNS__TANGIBLEOBJECT_BOOL_);
		method.addObjectParameter(lair);
		method.addBooleanParameter(forceSpawn);

		method.executeWithVoidReturn();
	} else
		_implementation->checkForNewSpawns(lair, forceSpawn);
}

void LairObserver::healLair(TangibleObject* lair, TangibleObject* attacker) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HEALLAIR__TANGIBLEOBJECT_TANGIBLEOBJECT_);
		method.addObjectParameter(lair);
		method.addObjectParameter(attacker);

		method.executeWithVoidReturn();
	} else
		_implementation->healLair(lair, attacker);
}

void LairObserver::checkForHeal(TangibleObject* lair, TangibleObject* attacker, bool forceNewUpdate) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKFORHEAL__TANGIBLEOBJECT_TANGIBLEOBJECT_BOOL_);
		method.addObjectParameter(lair);
		method.addObjectParameter(attacker);
		method.addBooleanParameter(forceNewUpdate);

		method.executeWithVoidReturn();
	} else
		_implementation->checkForHeal(lair, attacker, forceNewUpdate);
}

void LairObserver::setLairTemplate(LairTemplate* tmpl) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->setLairTemplate(tmpl);
}

void LairObserver::setDifficulty(int min, int max) {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETDIFFICULTY__INT_INT_);
		method.addSignedIntParameter(min);
		method.addSignedIntParameter(max);

		method.executeWithVoidReturn();
	} else
		_implementation->setDifficulty(min, max);
}

bool LairObserver::isLairObserver() {
	LairObserverImplementation* _implementation = static_cast<LairObserverImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISLAIROBSERVER__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isLairObserver();
}

DistributedObjectServant* LairObserver::_getImplementation() {

	_updated = true;
	return _impl;
}

void LairObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	LairObserverImplementation
 */

LairObserverImplementation::LairObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


LairObserverImplementation::~LairObserverImplementation() {
}


void LairObserverImplementation::finalize() {
}

void LairObserverImplementation::_initializeImplementation() {
	_setClassHelper(LairObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void LairObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<LairObserver*>(stub);
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* LairObserverImplementation::_getStub() {
	return _this;
}

LairObserverImplementation::operator const LairObserver*() {
	return _this;
}

void LairObserverImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void LairObserverImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void LairObserverImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void LairObserverImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void LairObserverImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void LairObserverImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void LairObserverImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void LairObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("LairObserver");

}

void LairObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(LairObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool LairObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "LairObserver.spawnedCreatures") {
		TypeInfo<Vector<ManagedReference<CreatureObject* > > >::parseFromBinaryStream(&spawnedCreatures, stream);
		return true;
	}

	if (_name == "LairObserver.minDifficulty") {
		TypeInfo<int >::parseFromBinaryStream(&minDifficulty, stream);
		return true;
	}

	if (_name == "LairObserver.maxDifficulty") {
		TypeInfo<int >::parseFromBinaryStream(&maxDifficulty, stream);
		return true;
	}


	return false;
}

void LairObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = LairObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int LairObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "LairObserver.spawnedCreatures";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Vector<ManagedReference<CreatureObject* > > >::toBinaryStream(&spawnedCreatures, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "LairObserver.minDifficulty";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&minDifficulty, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "LairObserver.maxDifficulty";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&maxDifficulty, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 3;
}

LairObserverImplementation::LairObserverImplementation() : ObserverImplementation() {
	_initializeImplementation();
	// server/zone/managers/creature/LairObserver.idl():  		Logger.setLoggingName("LairObserver");
	Logger::setLoggingName("LairObserver");
	// server/zone/managers/creature/LairObserver.idl():  		minDifficulty = 0;
	minDifficulty = 0;
	// server/zone/managers/creature/LairObserver.idl():  		maxDifficulty = 500;
	maxDifficulty = 500;
	// server/zone/managers/creature/LairObserver.idl():  		lairTemplate = null;
	lairTemplate = NULL;
	// server/zone/managers/creature/LairObserver.idl():  		healLairEvent = null;
	healLairEvent = NULL;
}

void LairObserverImplementation::setLairTemplate(LairTemplate* tmpl) {
	// server/zone/managers/creature/LairObserver.idl():  		lairTemplate = tmpl;
	lairTemplate = tmpl;
}

void LairObserverImplementation::setDifficulty(int min, int max) {
	// server/zone/managers/creature/LairObserver.idl():  		minDifficulty = min;
	minDifficulty = min;
	// server/zone/managers/creature/LairObserver.idl():  		maxDifficulty = max;
	maxDifficulty = max;
}

bool LairObserverImplementation::isLairObserver() {
	// server/zone/managers/creature/LairObserver.idl():  		return true;
	return true;
}

/*
 *	LairObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


LairObserverAdapter::LairObserverAdapter(LairObserver* obj) : ObserverAdapter(obj) {
}

void LairObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		{
			resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), static_cast<Observable*>(inv->getObjectParameter()), static_cast<ManagedObject*>(inv->getObjectParameter()), inv->getSignedLongParameter()));
		}
		break;
	case RPC_NOTIFYDESTRUCTION__TANGIBLEOBJECT_TANGIBLEOBJECT_INT_:
		{
			notifyDestruction(static_cast<TangibleObject*>(inv->getObjectParameter()), static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getSignedIntParameter());
		}
		break;
	case RPC_CHECKFORNEWSPAWNS__TANGIBLEOBJECT_BOOL_:
		{
			checkForNewSpawns(static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getBooleanParameter());
		}
		break;
	case RPC_HEALLAIR__TANGIBLEOBJECT_TANGIBLEOBJECT_:
		{
			healLair(static_cast<TangibleObject*>(inv->getObjectParameter()), static_cast<TangibleObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_CHECKFORHEAL__TANGIBLEOBJECT_TANGIBLEOBJECT_BOOL_:
		{
			checkForHeal(static_cast<TangibleObject*>(inv->getObjectParameter()), static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getBooleanParameter());
		}
		break;
	case RPC_SETDIFFICULTY__INT_INT_:
		{
			setDifficulty(inv->getSignedIntParameter(), inv->getSignedIntParameter());
		}
		break;
	case RPC_ISLAIROBSERVER__:
		{
			resp->insertBoolean(isLairObserver());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int LairObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return (static_cast<LairObserver*>(stub))->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void LairObserverAdapter::notifyDestruction(TangibleObject* lair, TangibleObject* attacker, int condition) {
	(static_cast<LairObserver*>(stub))->notifyDestruction(lair, attacker, condition);
}

void LairObserverAdapter::checkForNewSpawns(TangibleObject* lair, bool forceSpawn) {
	(static_cast<LairObserver*>(stub))->checkForNewSpawns(lair, forceSpawn);
}

void LairObserverAdapter::healLair(TangibleObject* lair, TangibleObject* attacker) {
	(static_cast<LairObserver*>(stub))->healLair(lair, attacker);
}

void LairObserverAdapter::checkForHeal(TangibleObject* lair, TangibleObject* attacker, bool forceNewUpdate) {
	(static_cast<LairObserver*>(stub))->checkForHeal(lair, attacker, forceNewUpdate);
}

void LairObserverAdapter::setDifficulty(int min, int max) {
	(static_cast<LairObserver*>(stub))->setDifficulty(min, max);
}

bool LairObserverAdapter::isLairObserver() {
	return (static_cast<LairObserver*>(stub))->isLairObserver();
}

/*
 *	LairObserverHelper
 */

LairObserverHelper* LairObserverHelper::staticInitializer = LairObserverHelper::instance();

LairObserverHelper::LairObserverHelper() {
	className = "LairObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void LairObserverHelper::finalizeHelper() {
	LairObserverHelper::finalize();
}

DistributedObject* LairObserverHelper::instantiateObject() {
	return new LairObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* LairObserverHelper::instantiateServant() {
	return new LairObserverImplementation();
}

DistributedObjectAdapter* LairObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new LairObserverAdapter(static_cast<LairObserver*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

