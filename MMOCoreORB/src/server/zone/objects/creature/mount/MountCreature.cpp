/*
 *	server/zone/objects/creature/mount/MountCreature.cpp generated by engine3 IDL compiler 0.55
 */

#include "MountCreature.h"

#include "MountCreatureImplementation.h"

#include "../Creature.h"

#include "../CreatureObject.h"

#include "../../player/Player.h"

#include "../../intangible/IntangibleObject.h"

/*
 *	MountCreatureStub
 */

MountCreature::MountCreature(CreatureObject* linkCreature, const String& name, const String& stf, unsigned int itnocrc, unsigned int objCRC, unsigned long long oid) : Creature(DummyConstructorParameter::instance()) {
	_impl = new MountCreatureImplementation(linkCreature, name, stf, itnocrc, objCRC, oid);
	_impl->_setStub(this);
}

MountCreature::MountCreature(DummyConstructorParameter* param) : Creature(param) {
}

MountCreature::~MountCreature() {
}

void MountCreature::setMountType(int type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addSignedIntParameter(type);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->setMountType(type);
}

int MountCreature::getMountType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->getMountType();
}

bool MountCreature::isVehicle() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithBooleanReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->isVehicle();
}

bool MountCreature::isPet() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->isPet();
}

bool MountCreature::isDisabled() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->isDisabled();
}

bool MountCreature::isJetpack() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->isJetpack();
}

CreatureObject* MountCreature::getLinkedCreature() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return (CreatureObject*) method.executeWithObjectReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->getLinkedCreature();
}

IntangibleObject* MountCreature::getITNO() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return (IntangibleObject*) method.executeWithObjectReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->getITNO();
}

void MountCreature::call() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->call();
}

void MountCreature::store(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->store(doLock);
}

int MountCreature::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->useObject(player);
}

void MountCreature::addToDatapad() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->addToDatapad();
}

void MountCreature::setInstantMount(bool val) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addBooleanParameter(val);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->setInstantMount(val);
}

bool MountCreature::isInWorld() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithBooleanReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->isInWorld();
}

unsigned int MountCreature::getItnocrc() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((MountCreatureImplementation*) _impl)->getItnocrc();
}

void MountCreature::parseItemAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->parseItemAttributes();
}

void MountCreature::setAttributes(String& attributeString) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addAsciiParameter(attributeString);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->setAttributes(attributeString);
}

String& MountCreature::getAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		method.executeWithAsciiReturn(_return_getAttributes);
		return _return_getAttributes;
	} else
		return ((MountCreatureImplementation*) _impl)->getAttributes();
}

void MountCreature::repair() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithVoidReturn();
	} else
		((MountCreatureImplementation*) _impl)->repair();
}

/*
 *	MountCreatureAdapter
 */

MountCreatureAdapter::MountCreatureAdapter(MountCreatureImplementation* obj) : CreatureAdapter(obj) {
}

Packet* MountCreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		setMountType(inv->getSignedIntParameter());
		break;
	case 7:
		resp->insertSignedInt(getMountType());
		break;
	case 8:
		resp->insertBoolean(isVehicle());
		break;
	case 9:
		resp->insertBoolean(isPet());
		break;
	case 10:
		resp->insertBoolean(isDisabled());
		break;
	case 11:
		resp->insertBoolean(isJetpack());
		break;
	case 12:
		resp->insertLong(getLinkedCreature()->_getObjectID());
		break;
	case 13:
		resp->insertLong(getITNO()->_getObjectID());
		break;
	case 14:
		call();
		break;
	case 15:
		store(inv->getBooleanParameter());
		break;
	case 16:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 17:
		addToDatapad();
		break;
	case 18:
		setInstantMount(inv->getBooleanParameter());
		break;
	case 19:
		resp->insertBoolean(isInWorld());
		break;
	case 20:
		resp->insertInt(getItnocrc());
		break;
	case 21:
		parseItemAttributes();
		break;
	case 22:
		setAttributes(inv->getAsciiParameter(_param0_setAttributes__String_));
		break;
	case 23:
		resp->insertAscii(getAttributes());
		break;
	case 24:
		repair();
		break;
	default:
		return NULL;
	}

	return resp;
}

void MountCreatureAdapter::setMountType(int type) {
	return ((MountCreatureImplementation*) impl)->setMountType(type);
}

int MountCreatureAdapter::getMountType() {
	return ((MountCreatureImplementation*) impl)->getMountType();
}

bool MountCreatureAdapter::isVehicle() {
	return ((MountCreatureImplementation*) impl)->isVehicle();
}

bool MountCreatureAdapter::isPet() {
	return ((MountCreatureImplementation*) impl)->isPet();
}

bool MountCreatureAdapter::isDisabled() {
	return ((MountCreatureImplementation*) impl)->isDisabled();
}

bool MountCreatureAdapter::isJetpack() {
	return ((MountCreatureImplementation*) impl)->isJetpack();
}

CreatureObject* MountCreatureAdapter::getLinkedCreature() {
	return ((MountCreatureImplementation*) impl)->getLinkedCreature();
}

IntangibleObject* MountCreatureAdapter::getITNO() {
	return ((MountCreatureImplementation*) impl)->getITNO();
}

void MountCreatureAdapter::call() {
	return ((MountCreatureImplementation*) impl)->call();
}

void MountCreatureAdapter::store(bool doLock) {
	return ((MountCreatureImplementation*) impl)->store(doLock);
}

int MountCreatureAdapter::useObject(Player* player) {
	return ((MountCreatureImplementation*) impl)->useObject(player);
}

void MountCreatureAdapter::addToDatapad() {
	return ((MountCreatureImplementation*) impl)->addToDatapad();
}

void MountCreatureAdapter::setInstantMount(bool val) {
	return ((MountCreatureImplementation*) impl)->setInstantMount(val);
}

bool MountCreatureAdapter::isInWorld() {
	return ((MountCreatureImplementation*) impl)->isInWorld();
}

unsigned int MountCreatureAdapter::getItnocrc() {
	return ((MountCreatureImplementation*) impl)->getItnocrc();
}

void MountCreatureAdapter::parseItemAttributes() {
	return ((MountCreatureImplementation*) impl)->parseItemAttributes();
}

void MountCreatureAdapter::setAttributes(String& attributeString) {
	return ((MountCreatureImplementation*) impl)->setAttributes(attributeString);
}

String& MountCreatureAdapter::getAttributes() {
	return ((MountCreatureImplementation*) impl)->getAttributes();
}

void MountCreatureAdapter::repair() {
	return ((MountCreatureImplementation*) impl)->repair();
}

/*
 *	MountCreatureHelper
 */

MountCreatureHelper* MountCreatureHelper::staticInitializer = MountCreatureHelper::instance();

MountCreatureHelper::MountCreatureHelper() {
	className = "MountCreature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MountCreatureHelper::finalizeHelper() {
	MountCreatureHelper::finalize();
}

DistributedObject* MountCreatureHelper::instantiateObject() {
	return new MountCreature(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MountCreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MountCreatureAdapter((MountCreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	MountCreatureServant
 */

MountCreatureServant::MountCreatureServant(unsigned long long oid) : CreatureImplementation(oid) {
	_classHelper = MountCreatureHelper::instance();
}

MountCreatureServant::~MountCreatureServant() {
}

void MountCreatureServant::_setStub(DistributedObjectStub* stub) {
	_this = (MountCreature*) stub;
	CreatureServant::_setStub(stub);
}

DistributedObjectStub* MountCreatureServant::_getStub() {
	return _this;
}

