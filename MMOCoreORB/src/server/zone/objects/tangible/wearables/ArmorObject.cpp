/*
 *	server/zone/objects/tangible/wearables/ArmorObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "ArmorObject.h"

#include "server/zone/Zone.h"

/*
 *	ArmorObjectStub
 */

ArmorObject::ArmorObject() : WearableObject(DummyConstructorParameter::instance()) {
	_impl = new ArmorObjectImplementation();
	_impl->_setStub(this);
}

ArmorObject::ArmorObject(DummyConstructorParameter* param) : WearableObject(param) {
}

ArmorObject::~ArmorObject() {
}


void ArmorObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ArmorObjectImplementation*) _impl)->initializeTransientMembers();
}

void ArmorObject::loadTemplateData(SharedObjectTemplate* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ArmorObjectImplementation*) _impl)->loadTemplateData(templateData);
}

void ArmorObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ArmorObjectImplementation*) _impl)->fillAttributeList(msg, object);
}

bool ArmorObject::isSpecial(const String& special) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addAsciiParameter(special);

		return method.executeWithBooleanReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->isSpecial(special);
}

bool ArmorObject::isVulnerable(const String& vulnerability) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(vulnerability);

		return method.executeWithBooleanReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->isVulnerable(vulnerability);
}

bool ArmorObject::isArmorObject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->isArmorObject();
}

int ArmorObject::getRating() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithSignedIntReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getRating();
}

float ArmorObject::getKinetic() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getKinetic();
}

float ArmorObject::getEnergy() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getEnergy();
}

float ArmorObject::getElectricity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getElectricity();
}

float ArmorObject::getStun() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getStun();
}

float ArmorObject::getBlast() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getBlast();
}

float ArmorObject::getHeat() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getHeat();
}

float ArmorObject::getCold() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getCold();
}

float ArmorObject::getAcid() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getAcid();
}

float ArmorObject::getLightSaber() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithFloatReturn();
	} else
		return ((ArmorObjectImplementation*) _impl)->getLightSaber();
}

/*
 *	ArmorObjectImplementation
 */

ArmorObjectImplementation::ArmorObjectImplementation(DummyConstructorParameter* param) : WearableObjectImplementation(param) {
	_initializeImplementation();
}

ArmorObjectImplementation::~ArmorObjectImplementation() {
}


void ArmorObjectImplementation::finalize() {
}

void ArmorObjectImplementation::_initializeImplementation() {
	_setClassHelper(ArmorObjectHelper::instance());

	_serializationHelperMethod();
}

void ArmorObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ArmorObject*) stub;
	WearableObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ArmorObjectImplementation::_getStub() {
	return _this;
}

ArmorObjectImplementation::operator const ArmorObject*() {
	return _this;
}

void ArmorObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ArmorObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ArmorObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ArmorObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ArmorObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ArmorObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ArmorObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ArmorObjectImplementation::_serializationHelperMethod() {
	WearableObjectImplementation::_serializationHelperMethod();

	_setClassName("ArmorObject");

	addSerializableVariable("healthEncumbrance", &healthEncumbrance);
	addSerializableVariable("actionEncumbrance", &actionEncumbrance);
	addSerializableVariable("mindEncumbrance", &mindEncumbrance);
	addSerializableVariable("rating", &rating);
	addSerializableVariable("kinetic", &kinetic);
	addSerializableVariable("energy", &energy);
	addSerializableVariable("electricity", &electricity);
	addSerializableVariable("stun", &stun);
	addSerializableVariable("blast", &blast);
	addSerializableVariable("heat", &heat);
	addSerializableVariable("cold", &cold);
	addSerializableVariable("acid", &acid);
	addSerializableVariable("lightSaber", &lightSaber);
	addSerializableVariable("specialResistsVector", &specialResistsVector);
	addSerializableVariable("vulnerabilitesVector", &vulnerabilitesVector);
	addSerializableVariable("specialBase", &specialBase);
}

ArmorObjectImplementation::ArmorObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/wearables/ArmorObject.idl(81):  		healthEncumbrance = 100;
	healthEncumbrance = 100;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(82):  		actionEncumbrance = 100;
	actionEncumbrance = 100;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(83):  		mindEncumbrance = 100;
	mindEncumbrance = 100;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(85):  		rating = LIGHT;
	rating = LIGHT;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(87):  		kinetic = 0;
	kinetic = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(88):  		energy = 0;
	energy = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(89):  		electricity = 0;
	electricity = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(90):  		stun = 0;
	stun = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(91):  		blast = 0;
	blast = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(92):  		heat = 0;
	heat = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(93):  		cold = 0;
	cold = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(94):  		acid = 0;
	acid = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(95):  		lightSaber = 0;
	lightSaber = 0;
	// server/zone/objects/tangible/wearables/ArmorObject.idl(101):  		Logger.setLoggingName("ArmorObject");
	Logger::setLoggingName("ArmorObject");
}

bool ArmorObjectImplementation::isSpecial(const String& special) {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(126):  		return specialResistsVector.contains(special);
	return (&specialResistsVector)->contains(special);
}

bool ArmorObjectImplementation::isVulnerable(const String& vulnerability) {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(130):  		return vulnerabilitesVector.contains(vulnerability);
	return (&vulnerabilitesVector)->contains(vulnerability);
}

bool ArmorObjectImplementation::isArmorObject() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(134):  		return true;
	return true;
}

int ArmorObjectImplementation::getRating() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(138):  		return rating;
	return rating;
}

float ArmorObjectImplementation::getKinetic() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(142):  		return kinetic;
	return kinetic;
}

float ArmorObjectImplementation::getEnergy() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(146):  		return energy;
	return energy;
}

float ArmorObjectImplementation::getElectricity() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(150):  		return electricity;
	return electricity;
}

float ArmorObjectImplementation::getStun() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(154):  		return stun;
	return stun;
}

float ArmorObjectImplementation::getBlast() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(158):  		return blast;
	return blast;
}

float ArmorObjectImplementation::getHeat() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(162):  		return heat;
	return heat;
}

float ArmorObjectImplementation::getCold() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(166):  		return cold;
	return cold;
}

float ArmorObjectImplementation::getAcid() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(170):  		return acid;
	return acid;
}

float ArmorObjectImplementation::getLightSaber() {
	// server/zone/objects/tangible/wearables/ArmorObject.idl(174):  		return lightSaber;
	return lightSaber;
}

/*
 *	ArmorObjectAdapter
 */

ArmorObjectAdapter::ArmorObjectAdapter(ArmorObjectImplementation* obj) : WearableObjectAdapter(obj) {
}

Packet* ArmorObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertBoolean(isSpecial(inv->getAsciiParameter(_param0_isSpecial__String_)));
		break;
	case 8:
		resp->insertBoolean(isVulnerable(inv->getAsciiParameter(_param0_isVulnerable__String_)));
		break;
	case 9:
		resp->insertBoolean(isArmorObject());
		break;
	case 10:
		resp->insertSignedInt(getRating());
		break;
	case 11:
		resp->insertFloat(getKinetic());
		break;
	case 12:
		resp->insertFloat(getEnergy());
		break;
	case 13:
		resp->insertFloat(getElectricity());
		break;
	case 14:
		resp->insertFloat(getStun());
		break;
	case 15:
		resp->insertFloat(getBlast());
		break;
	case 16:
		resp->insertFloat(getHeat());
		break;
	case 17:
		resp->insertFloat(getCold());
		break;
	case 18:
		resp->insertFloat(getAcid());
		break;
	case 19:
		resp->insertFloat(getLightSaber());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ArmorObjectAdapter::initializeTransientMembers() {
	((ArmorObjectImplementation*) impl)->initializeTransientMembers();
}

bool ArmorObjectAdapter::isSpecial(const String& special) {
	return ((ArmorObjectImplementation*) impl)->isSpecial(special);
}

bool ArmorObjectAdapter::isVulnerable(const String& vulnerability) {
	return ((ArmorObjectImplementation*) impl)->isVulnerable(vulnerability);
}

bool ArmorObjectAdapter::isArmorObject() {
	return ((ArmorObjectImplementation*) impl)->isArmorObject();
}

int ArmorObjectAdapter::getRating() {
	return ((ArmorObjectImplementation*) impl)->getRating();
}

float ArmorObjectAdapter::getKinetic() {
	return ((ArmorObjectImplementation*) impl)->getKinetic();
}

float ArmorObjectAdapter::getEnergy() {
	return ((ArmorObjectImplementation*) impl)->getEnergy();
}

float ArmorObjectAdapter::getElectricity() {
	return ((ArmorObjectImplementation*) impl)->getElectricity();
}

float ArmorObjectAdapter::getStun() {
	return ((ArmorObjectImplementation*) impl)->getStun();
}

float ArmorObjectAdapter::getBlast() {
	return ((ArmorObjectImplementation*) impl)->getBlast();
}

float ArmorObjectAdapter::getHeat() {
	return ((ArmorObjectImplementation*) impl)->getHeat();
}

float ArmorObjectAdapter::getCold() {
	return ((ArmorObjectImplementation*) impl)->getCold();
}

float ArmorObjectAdapter::getAcid() {
	return ((ArmorObjectImplementation*) impl)->getAcid();
}

float ArmorObjectAdapter::getLightSaber() {
	return ((ArmorObjectImplementation*) impl)->getLightSaber();
}

/*
 *	ArmorObjectHelper
 */

ArmorObjectHelper* ArmorObjectHelper::staticInitializer = ArmorObjectHelper::instance();

ArmorObjectHelper::ArmorObjectHelper() {
	className = "ArmorObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ArmorObjectHelper::finalizeHelper() {
	ArmorObjectHelper::finalize();
}

DistributedObject* ArmorObjectHelper::instantiateObject() {
	return new ArmorObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* ArmorObjectHelper::instantiateServant() {
	return new ArmorObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ArmorObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ArmorObjectAdapter((ArmorObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

