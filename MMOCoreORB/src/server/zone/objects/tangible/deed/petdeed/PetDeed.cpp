/*
 *	server/zone/objects/tangible/deed/petdeed/PetDeed.cpp generated by engine3 IDL compiler 0.55
 */

#include "PetDeed.h"

#include "PetDeedImplementation.h"

#include "../DeedObject.h"

#include "../../../creature/CreatureObject.h"

#include "../../../player/Player.h"

#include "../../../scene/SceneObject.h"

/*
 *	PetDeedStub
 */

PetDeed::PetDeed(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new PetDeedImplementation(creature, objcrc, customname, stfname);
	_impl->_setStub(this);
}

PetDeed::PetDeed(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new PetDeedImplementation(objid, objcrc, customname, stfname);
	_impl->_setStub(this);
}

PetDeed::PetDeed(DummyConstructorParameter* param) : DeedObject(param) {
}

PetDeed::~PetDeed() {
}

int PetDeed::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((PetDeedImplementation*) _impl)->useObject(player);
}

SceneObject* PetDeed::generateObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((PetDeedImplementation*) _impl)->generateObject(player);
}

void PetDeed::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((PetDeedImplementation*) _impl)->parseItemAttributes();
}

/*
 *	PetDeedAdapter
 */

PetDeedAdapter::PetDeedAdapter(PetDeedImplementation* obj) : DeedObjectAdapter(obj) {
}

Packet* PetDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		resp->insertLong(generateObject((Player*) inv->getObjectParameter())->_getObjectID());
		break;
	case 8:
		parseItemAttributes();
		break;
	default:
		return NULL;
	}

	return resp;
}

int PetDeedAdapter::useObject(Player* player) {
	return ((PetDeedImplementation*) impl)->useObject(player);
}

SceneObject* PetDeedAdapter::generateObject(Player* player) {
	return ((PetDeedImplementation*) impl)->generateObject(player);
}

void PetDeedAdapter::parseItemAttributes() {
	return ((PetDeedImplementation*) impl)->parseItemAttributes();
}

/*
 *	PetDeedHelper
 */

PetDeedHelper* PetDeedHelper::staticInitializer = PetDeedHelper::instance();

PetDeedHelper::PetDeedHelper() {
	className = "PetDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PetDeedHelper::finalizeHelper() {
	PetDeedHelper::finalize();
}

DistributedObject* PetDeedHelper::instantiateObject() {
	return new PetDeed(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PetDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PetDeedAdapter((PetDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	PetDeedServant
 */

PetDeedServant::PetDeedServant(CreatureObject* creature, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObjectImplementation(creature, objcrc, customname, stfname) {
	_classHelper = PetDeedHelper::instance();
}

PetDeedServant::PetDeedServant(unsigned long long objid, unsigned int objcrc, const UnicodeString& customname, const String& stfname) : DeedObjectImplementation(objid, objcrc, customname, stfname) {
	_classHelper = PetDeedHelper::instance();
}

PetDeedServant::~PetDeedServant() {
}

void PetDeedServant::_setStub(DistributedObjectStub* stub) {
	_this = (PetDeed*) stub;
	DeedObjectServant::_setStub(stub);
}

DistributedObjectStub* PetDeedServant::_getStub() {
	return _this;
}

