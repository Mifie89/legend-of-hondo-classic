/*
 *	server/zone/objects/tangible/deed/vehicledeed/VehicleDeed.cpp generated by engine3 IDL compiler 0.55
 */

#include "VehicleDeed.h"

#include "VehicleDeedImplementation.h"

#include "../DeedObject.h"

#include "../../TangibleObject.h"

#include "../../../../packets.h"

#include "../../../player/Player.h"

#include "../../../creature/CreatureObject.h"

#include "../../../../packets/object/ObjectMenuResponse.h"

/*
 *	VehicleDeedStub
 */

VehicleDeed::VehicleDeed(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new VehicleDeedImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

VehicleDeed::VehicleDeed(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn) : DeedObject(DummyConstructorParameter::instance()) {
	_impl = new VehicleDeedImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

VehicleDeed::VehicleDeed(DummyConstructorParameter* param) : DeedObject(param) {
}

VehicleDeed::~VehicleDeed() {
}

int VehicleDeed::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((VehicleDeedImplementation*) _impl)->useObject(player);
}

void VehicleDeed::sendRadialResponseTo(Player* player, ObjectMenuResponse* omr) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addObjectParameter(omr);

		method.executeWithVoidReturn();
	} else
		((VehicleDeedImplementation*) _impl)->sendRadialResponseTo(player, omr);
}

/*
 *	VehicleDeedAdapter
 */

VehicleDeedAdapter::VehicleDeedAdapter(VehicleDeedImplementation* obj) : DeedObjectAdapter(obj) {
}

Packet* VehicleDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		sendRadialResponseTo((Player*) inv->getObjectParameter(), (ObjectMenuResponse*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

int VehicleDeedAdapter::useObject(Player* player) {
	return ((VehicleDeedImplementation*) impl)->useObject(player);
}

void VehicleDeedAdapter::sendRadialResponseTo(Player* player, ObjectMenuResponse* omr) {
	return ((VehicleDeedImplementation*) impl)->sendRadialResponseTo(player, omr);
}

/*
 *	VehicleDeedHelper
 */

VehicleDeedHelper* VehicleDeedHelper::staticInitializer = VehicleDeedHelper::instance();

VehicleDeedHelper::VehicleDeedHelper() {
	className = "VehicleDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void VehicleDeedHelper::finalizeHelper() {
	VehicleDeedHelper::finalize();
}

DistributedObject* VehicleDeedHelper::instantiateObject() {
	return new VehicleDeed(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* VehicleDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new VehicleDeedAdapter((VehicleDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	VehicleDeedServant
 */

VehicleDeedServant::VehicleDeedServant(CreatureObject* creature, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(creature, tempCRC, n, tempn, tp) {
	_classHelper = VehicleDeedHelper::instance();
}

VehicleDeedServant::VehicleDeedServant(unsigned long long oid, int tempCRC, const unicode& n, const string& tempn, int tp) : DeedObjectImplementation(oid, tempCRC, n, tempn, tp) {
	_classHelper = VehicleDeedHelper::instance();
}

VehicleDeedServant::~VehicleDeedServant() {
}

void VehicleDeedServant::_setStub(DistributedObjectStub* stub) {
	_this = (VehicleDeed*) stub;
	DeedObjectServant::_setStub(stub);
}

DistributedObjectStub* VehicleDeedServant::_getStub() {
	return _this;
}

