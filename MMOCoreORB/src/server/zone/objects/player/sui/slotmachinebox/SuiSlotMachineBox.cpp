/*
 *	server/zone/objects/player/sui/slotmachinebox/SuiSlotMachineBox.cpp generated by engine3 IDL compiler 0.60
 */

#include "SuiSlotMachineBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/sui/SuiBox.h"

/*
 *	SuiSlotMachineBoxStub
 */

enum {RPC_GETPAYOUTBOXID__ = 6};

SuiSlotMachineBox::SuiSlotMachineBox(CreatureObject* player, unsigned int windowType, unsigned int payoutBox, unsigned int listBoxType) : SuiListBox(DummyConstructorParameter::instance()) {
	SuiSlotMachineBoxImplementation* _implementation = new SuiSlotMachineBoxImplementation(player, windowType, payoutBox, listBoxType);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("SuiSlotMachineBox");
}

SuiSlotMachineBox::SuiSlotMachineBox(DummyConstructorParameter* param) : SuiListBox(param) {
	_setClassName("SuiSlotMachineBox");
}

SuiSlotMachineBox::~SuiSlotMachineBox() {
}



unsigned int SuiSlotMachineBox::getPayoutBoxID() {
	SuiSlotMachineBoxImplementation* _implementation = static_cast<SuiSlotMachineBoxImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPAYOUTBOXID__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getPayoutBoxID();
}

DistributedObjectServant* SuiSlotMachineBox::_getImplementation() {

	_updated = true;
	return _impl;
}

void SuiSlotMachineBox::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SuiSlotMachineBoxImplementation
 */

SuiSlotMachineBoxImplementation::SuiSlotMachineBoxImplementation(DummyConstructorParameter* param) : SuiListBoxImplementation(param) {
	_initializeImplementation();
}


SuiSlotMachineBoxImplementation::~SuiSlotMachineBoxImplementation() {
}


void SuiSlotMachineBoxImplementation::finalize() {
}

void SuiSlotMachineBoxImplementation::_initializeImplementation() {
	_setClassHelper(SuiSlotMachineBoxHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void SuiSlotMachineBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<SuiSlotMachineBox*>(stub);
	SuiListBoxImplementation::_setStub(stub);
}

DistributedObjectStub* SuiSlotMachineBoxImplementation::_getStub() {
	return _this;
}

SuiSlotMachineBoxImplementation::operator const SuiSlotMachineBox*() {
	return _this;
}

void SuiSlotMachineBoxImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void SuiSlotMachineBoxImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void SuiSlotMachineBoxImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void SuiSlotMachineBoxImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void SuiSlotMachineBoxImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void SuiSlotMachineBoxImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void SuiSlotMachineBoxImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void SuiSlotMachineBoxImplementation::_serializationHelperMethod() {
	SuiListBoxImplementation::_serializationHelperMethod();

	_setClassName("SuiSlotMachineBox");

}

void SuiSlotMachineBoxImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(SuiSlotMachineBoxImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SuiSlotMachineBoxImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SuiListBoxImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "SuiSlotMachineBox.payoutBoxID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&payoutBoxID, stream);
		return true;
	}


	return false;
}

void SuiSlotMachineBoxImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SuiSlotMachineBoxImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SuiSlotMachineBoxImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = SuiListBoxImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "SuiSlotMachineBox.payoutBoxID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<unsigned int >::toBinaryStream(&payoutBoxID, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

SuiSlotMachineBoxImplementation::SuiSlotMachineBoxImplementation(CreatureObject* player, unsigned int windowType, unsigned int payoutBox, unsigned int listBoxType) : SuiListBoxImplementation(player, windowType, listBoxType) {
	_initializeImplementation();
	// server/zone/objects/player/sui/slotmachinebox/SuiSlotMachineBox.idl():  		payoutBoxID = payoutBox;
	payoutBoxID = payoutBox;
}

unsigned int SuiSlotMachineBoxImplementation::getPayoutBoxID() {
	// server/zone/objects/player/sui/slotmachinebox/SuiSlotMachineBox.idl():  		return payoutBoxID;
	return payoutBoxID;
}

/*
 *	SuiSlotMachineBoxAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


SuiSlotMachineBoxAdapter::SuiSlotMachineBoxAdapter(SuiSlotMachineBox* obj) : SuiListBoxAdapter(obj) {
}

void SuiSlotMachineBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_GETPAYOUTBOXID__:
		{
			resp->insertInt(getPayoutBoxID());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

unsigned int SuiSlotMachineBoxAdapter::getPayoutBoxID() {
	return (static_cast<SuiSlotMachineBox*>(stub))->getPayoutBoxID();
}

/*
 *	SuiSlotMachineBoxHelper
 */

SuiSlotMachineBoxHelper* SuiSlotMachineBoxHelper::staticInitializer = SuiSlotMachineBoxHelper::instance();

SuiSlotMachineBoxHelper::SuiSlotMachineBoxHelper() {
	className = "SuiSlotMachineBox";

	Core::getObjectBroker()->registerClass(className, this);
}

void SuiSlotMachineBoxHelper::finalizeHelper() {
	SuiSlotMachineBoxHelper::finalize();
}

DistributedObject* SuiSlotMachineBoxHelper::instantiateObject() {
	return new SuiSlotMachineBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiSlotMachineBoxHelper::instantiateServant() {
	return new SuiSlotMachineBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiSlotMachineBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiSlotMachineBoxAdapter(static_cast<SuiSlotMachineBox*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

