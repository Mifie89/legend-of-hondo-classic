/*
 *	server/zone/objects/tangible/consumable/DelayedBuffObserver.cpp generated by engine3 IDL compiler 0.60
 */

#include "DelayedBuffObserver.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/creature/buffs/DelayedBuff.h"

/*
 *	DelayedBuffObserverStub
 */

enum {RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_ = 6};

DelayedBuffObserver::DelayedBuffObserver(DelayedBuff* b) : Observer(DummyConstructorParameter::instance()) {
	DelayedBuffObserverImplementation* _implementation = new DelayedBuffObserverImplementation(b);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("DelayedBuffObserver");
}

DelayedBuffObserver::DelayedBuffObserver(DummyConstructorParameter* param) : Observer(param) {
	_setClassName("DelayedBuffObserver");
}

DelayedBuffObserver::~DelayedBuffObserver() {
}



int DelayedBuffObserver::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	DelayedBuffObserverImplementation* _implementation = static_cast<DelayedBuffObserverImplementation*>(_getImplementation());
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

DistributedObjectServant* DelayedBuffObserver::_getImplementation() {

	_updated = true;
	return _impl;
}

void DelayedBuffObserver::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DelayedBuffObserverImplementation
 */

DelayedBuffObserverImplementation::DelayedBuffObserverImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


DelayedBuffObserverImplementation::~DelayedBuffObserverImplementation() {
}


void DelayedBuffObserverImplementation::finalize() {
}

void DelayedBuffObserverImplementation::_initializeImplementation() {
	_setClassHelper(DelayedBuffObserverHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DelayedBuffObserverImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<DelayedBuffObserver*>(stub);
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* DelayedBuffObserverImplementation::_getStub() {
	return _this.get();
}

DelayedBuffObserverImplementation::operator const DelayedBuffObserver*() {
	return _this.get();
}

void DelayedBuffObserverImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void DelayedBuffObserverImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void DelayedBuffObserverImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void DelayedBuffObserverImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void DelayedBuffObserverImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void DelayedBuffObserverImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void DelayedBuffObserverImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void DelayedBuffObserverImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("DelayedBuffObserver");

}

void DelayedBuffObserverImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(DelayedBuffObserverImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DelayedBuffObserverImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "DelayedBuffObserver.buff") {
		TypeInfo<ManagedWeakReference<DelayedBuff* > >::parseFromBinaryStream(&buff, stream);
		return true;
	}


	return false;
}

void DelayedBuffObserverImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DelayedBuffObserverImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DelayedBuffObserverImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ObserverImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "DelayedBuffObserver.buff";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<DelayedBuff* > >::toBinaryStream(&buff, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

DelayedBuffObserverImplementation::DelayedBuffObserverImplementation(DelayedBuff* b) : ObserverImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/consumable/DelayedBuffObserver.idl():  		Logger.setLoggingName("DelayedBuffObserver");
	Logger::setLoggingName("DelayedBuffObserver");
	// server/zone/objects/tangible/consumable/DelayedBuffObserver.idl():  		buff = b;
	buff = b;
}

/*
 *	DelayedBuffObserverAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


DelayedBuffObserverAdapter::DelayedBuffObserverAdapter(DelayedBuffObserver* obj) : ObserverAdapter(obj) {
}

void DelayedBuffObserverAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		{
			resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), static_cast<Observable*>(inv->getObjectParameter()), static_cast<ManagedObject*>(inv->getObjectParameter()), inv->getSignedLongParameter()));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int DelayedBuffObserverAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return (static_cast<DelayedBuffObserver*>(stub))->notifyObserverEvent(eventType, observable, arg1, arg2);
}

/*
 *	DelayedBuffObserverHelper
 */

DelayedBuffObserverHelper* DelayedBuffObserverHelper::staticInitializer = DelayedBuffObserverHelper::instance();

DelayedBuffObserverHelper::DelayedBuffObserverHelper() {
	className = "DelayedBuffObserver";

	Core::getObjectBroker()->registerClass(className, this);
}

void DelayedBuffObserverHelper::finalizeHelper() {
	DelayedBuffObserverHelper::finalize();
}

DistributedObject* DelayedBuffObserverHelper::instantiateObject() {
	return new DelayedBuffObserver(DummyConstructorParameter::instance());
}

DistributedObjectServant* DelayedBuffObserverHelper::instantiateServant() {
	return new DelayedBuffObserverImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DelayedBuffObserverHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DelayedBuffObserverAdapter(static_cast<DelayedBuffObserver*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

