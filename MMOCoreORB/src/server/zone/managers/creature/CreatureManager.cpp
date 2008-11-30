/*
 *	server/zone/managers/creature/CreatureManager.cpp generated by engine3 IDL compiler 0.55
 */

#include "CreatureManager.h"

#include "CreatureManagerImplementation.h"

#include "server/zone/Zone.h"

#include "../../objects/creature/Creature.h"

#include "../../objects/creature/CreatureObject.h"

#include "../../objects/creature/CreatureGroup.h"

#include "../../objects/attackable/lair/LairObject.h"

#include "../../objects/creature/action/ActionCreature.h"

#include "../../objects/creature/trainer/TrainerCreature.h"

#include "../../objects/creature/recruiter/RecruiterCreature.h"

#include "../../objects/creature/shuttle/ShuttleCreature.h"

/*
 *	CreatureManagerStub
 */

CreatureManager::CreatureManager(Zone* zone, ZoneProcessServerImplementation* processor) {
	_impl = new CreatureManagerImplementation(zone, processor);
	_impl->_setStub(this);
}

CreatureManager::CreatureManager(DummyConstructorParameter* param) {
	_impl = NULL;
}

CreatureManager::~CreatureManager() {
}

void CreatureManager::init() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->init();
}

void CreatureManager::loadCreatures() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadCreatures();
}

void CreatureManager::start() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->start();
}

void CreatureManager::stop() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->stop();
}

void CreatureManager::loadTrainers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadTrainers();
}

void CreatureManager::loadRecruiters() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadRecruiters();
}

void CreatureManager::loadBlueFrogs() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadBlueFrogs();
}

void CreatureManager::load(Creature* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->load(creature);
}

void CreatureManager::unloadCreature(Creature* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->unloadCreature(creature);
}

bool CreatureManager::verifyCreatureSpawn(String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->verifyCreatureSpawn(name);
}

Creature* CreatureManager::spawnCreature(unsigned int objcrc, unsigned long long cellid, float x, float y, int bitmask, bool baby, bool doLock, float height) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addUnsignedIntParameter(objcrc);
		method.addUnsignedLongParameter(cellid);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addSignedIntParameter(bitmask);
		method.addBooleanParameter(baby);
		method.addBooleanParameter(doLock);
		method.addFloatParameter(height);

		return (Creature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnCreature(objcrc, cellid, x, y, bitmask, baby, doLock, height);
}

TrainerCreature* CreatureManager::spawnTrainer(const String& profession, const String& stfname, const String& name, int objCrc, unsigned long long cell, float x, float y, float z, float oy, float ow, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addAsciiParameter(profession);
		method.addAsciiParameter(stfname);
		method.addAsciiParameter(name);
		method.addSignedIntParameter(objCrc);
		method.addUnsignedLongParameter(cell);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(z);
		method.addFloatParameter(oy);
		method.addFloatParameter(ow);
		method.addBooleanParameter(doLock);

		return (TrainerCreature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnTrainer(profession, stfname, name, objCrc, cell, x, y, z, oy, ow, doLock);
}

ShuttleCreature* CreatureManager::spawnShuttle(const String& Planet, const String& City, Coordinate* playerSpawnPoint, unsigned long long cellid, float x, float y, float z, int tax, bool starport, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addAsciiParameter(Planet);
		method.addAsciiParameter(City);
		method.addObjectParameter(playerSpawnPoint);
		method.addUnsignedLongParameter(cellid);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(z);
		method.addSignedIntParameter(tax);
		method.addBooleanParameter(starport);
		method.addBooleanParameter(doLock);

		return (ShuttleCreature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnShuttle(Planet, City, playerSpawnPoint, cellid, x, y, z, tax, starport, doLock);
}

RecruiterCreature* CreatureManager::spawnRecruiter(float x, float y, float oY, float oW, unsigned char type, unsigned long long cellid, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(oY);
		method.addFloatParameter(oW);
		method.addUnsignedCharParameter(type);
		method.addUnsignedLongParameter(cellid);
		method.addBooleanParameter(doLock);

		return (RecruiterCreature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnRecruiter(x, y, oY, oW, type, cellid, doLock);
}

LairObject* CreatureManager::spawnLair(const String& type, float x, float y, float z, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addAsciiParameter(type);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(z);
		method.addBooleanParameter(doLock);

		return (LairObject*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnLair(type, x, y, z, doLock);
}

ActionCreature* CreatureManager::spawnActionCreature(String& name, String& stfname, unsigned int objCrc, const String& misoKey, float x, float y, float oY, float oW, unsigned long long cellid, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addAsciiParameter(name);
		method.addAsciiParameter(stfname);
		method.addUnsignedIntParameter(objCrc);
		method.addAsciiParameter(misoKey);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addFloatParameter(oY);
		method.addFloatParameter(oW);
		method.addUnsignedLongParameter(cellid);
		method.addBooleanParameter(doLock);

		return (ActionCreature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnActionCreature(name, stfname, objCrc, misoKey, x, y, oY, oW, cellid, doLock);
}

unsigned int CreatureManager::getCreatureCrc(String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addAsciiParameter(name);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->getCreatureCrc(name);
}

bool CreatureManager::hotLoadCreature(String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->hotLoadCreature(name);
}

void CreatureManager::registerFunctions() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->registerFunctions();
}

void CreatureManager::registerGlobals() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->registerGlobals();
}

void CreatureManager::loadCreatureFile() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadCreatureFile();
}

Creature* CreatureManager::getCreature(unsigned long long oid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addUnsignedLongParameter(oid);

		return (Creature*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->getCreature(oid);
}

void CreatureManager::addCreature(Creature* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->addCreature(creature);
}

/*
 *	CreatureManagerAdapter
 */

CreatureManagerAdapter::CreatureManagerAdapter(CreatureManagerImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* CreatureManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		init();
		break;
	case 7:
		loadCreatures();
		break;
	case 8:
		start();
		break;
	case 9:
		stop();
		break;
	case 10:
		loadTrainers();
		break;
	case 11:
		loadRecruiters();
		break;
	case 12:
		loadBlueFrogs();
		break;
	case 13:
		load((Creature*) inv->getObjectParameter());
		break;
	case 14:
		unloadCreature((Creature*) inv->getObjectParameter());
		break;
	case 15:
		resp->insertBoolean(verifyCreatureSpawn(inv->getAsciiParameter(_param0_verifyCreatureSpawn__String_)));
		break;
	case 16:
		resp->insertLong(spawnCreature(inv->getUnsignedIntParameter(), inv->getUnsignedLongParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter(), inv->getBooleanParameter(), inv->getFloatParameter())->_getObjectID());
		break;
	case 17:
		resp->insertLong(spawnTrainer(inv->getAsciiParameter(_param0_spawnTrainer__String_String_String_int_long_float_float_float_float_float_bool_), inv->getAsciiParameter(_param1_spawnTrainer__String_String_String_int_long_float_float_float_float_float_bool_), inv->getAsciiParameter(_param2_spawnTrainer__String_String_String_int_long_float_float_float_float_float_bool_), inv->getSignedIntParameter(), inv->getUnsignedLongParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 18:
		resp->insertLong(spawnShuttle(inv->getAsciiParameter(_param0_spawnShuttle__String_String_Coordinate_long_float_float_float_int_bool_bool_), inv->getAsciiParameter(_param1_spawnShuttle__String_String_Coordinate_long_float_float_float_int_bool_bool_), (Coordinate*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 19:
		resp->insertLong(spawnRecruiter(inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getUnsignedCharParameter(), inv->getUnsignedLongParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 20:
		resp->insertLong(spawnLair(inv->getAsciiParameter(_param0_spawnLair__String_float_float_float_bool_), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 21:
		resp->insertLong(spawnActionCreature(inv->getAsciiParameter(_param0_spawnActionCreature__String_String_int_String_float_float_float_float_long_bool_), inv->getAsciiParameter(_param1_spawnActionCreature__String_String_int_String_float_float_float_float_long_bool_), inv->getUnsignedIntParameter(), inv->getAsciiParameter(_param3_spawnActionCreature__String_String_int_String_float_float_float_float_long_bool_), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getUnsignedLongParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 22:
		resp->insertInt(getCreatureCrc(inv->getAsciiParameter(_param0_getCreatureCrc__String_)));
		break;
	case 23:
		resp->insertBoolean(hotLoadCreature(inv->getAsciiParameter(_param0_hotLoadCreature__String_)));
		break;
	case 24:
		registerFunctions();
		break;
	case 25:
		registerGlobals();
		break;
	case 26:
		loadCreatureFile();
		break;
	case 27:
		resp->insertLong(getCreature(inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case 28:
		addCreature((Creature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CreatureManagerAdapter::init() {
	return ((CreatureManagerImplementation*) impl)->init();
}

void CreatureManagerAdapter::loadCreatures() {
	return ((CreatureManagerImplementation*) impl)->loadCreatures();
}

void CreatureManagerAdapter::start() {
	return ((CreatureManagerImplementation*) impl)->start();
}

void CreatureManagerAdapter::stop() {
	return ((CreatureManagerImplementation*) impl)->stop();
}

void CreatureManagerAdapter::loadTrainers() {
	return ((CreatureManagerImplementation*) impl)->loadTrainers();
}

void CreatureManagerAdapter::loadRecruiters() {
	return ((CreatureManagerImplementation*) impl)->loadRecruiters();
}

void CreatureManagerAdapter::loadBlueFrogs() {
	return ((CreatureManagerImplementation*) impl)->loadBlueFrogs();
}

void CreatureManagerAdapter::load(Creature* creature) {
	return ((CreatureManagerImplementation*) impl)->load(creature);
}

void CreatureManagerAdapter::unloadCreature(Creature* creature) {
	return ((CreatureManagerImplementation*) impl)->unloadCreature(creature);
}

bool CreatureManagerAdapter::verifyCreatureSpawn(String& name) {
	return ((CreatureManagerImplementation*) impl)->verifyCreatureSpawn(name);
}

Creature* CreatureManagerAdapter::spawnCreature(unsigned int objcrc, unsigned long long cellid, float x, float y, int bitmask, bool baby, bool doLock, float height) {
	return ((CreatureManagerImplementation*) impl)->spawnCreature(objcrc, cellid, x, y, bitmask, baby, doLock, height);
}

TrainerCreature* CreatureManagerAdapter::spawnTrainer(const String& profession, const String& stfname, const String& name, int objCrc, unsigned long long cell, float x, float y, float z, float oy, float ow, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnTrainer(profession, stfname, name, objCrc, cell, x, y, z, oy, ow, doLock);
}

ShuttleCreature* CreatureManagerAdapter::spawnShuttle(const String& Planet, const String& City, Coordinate* playerSpawnPoint, unsigned long long cellid, float x, float y, float z, int tax, bool starport, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnShuttle(Planet, City, playerSpawnPoint, cellid, x, y, z, tax, starport, doLock);
}

RecruiterCreature* CreatureManagerAdapter::spawnRecruiter(float x, float y, float oY, float oW, unsigned char type, unsigned long long cellid, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnRecruiter(x, y, oY, oW, type, cellid, doLock);
}

LairObject* CreatureManagerAdapter::spawnLair(const String& type, float x, float y, float z, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnLair(type, x, y, z, doLock);
}

ActionCreature* CreatureManagerAdapter::spawnActionCreature(String& name, String& stfname, unsigned int objCrc, const String& misoKey, float x, float y, float oY, float oW, unsigned long long cellid, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnActionCreature(name, stfname, objCrc, misoKey, x, y, oY, oW, cellid, doLock);
}

unsigned int CreatureManagerAdapter::getCreatureCrc(String& name) {
	return ((CreatureManagerImplementation*) impl)->getCreatureCrc(name);
}

bool CreatureManagerAdapter::hotLoadCreature(String& name) {
	return ((CreatureManagerImplementation*) impl)->hotLoadCreature(name);
}

void CreatureManagerAdapter::registerFunctions() {
	return ((CreatureManagerImplementation*) impl)->registerFunctions();
}

void CreatureManagerAdapter::registerGlobals() {
	return ((CreatureManagerImplementation*) impl)->registerGlobals();
}

void CreatureManagerAdapter::loadCreatureFile() {
	return ((CreatureManagerImplementation*) impl)->loadCreatureFile();
}

Creature* CreatureManagerAdapter::getCreature(unsigned long long oid) {
	return ((CreatureManagerImplementation*) impl)->getCreature(oid);
}

void CreatureManagerAdapter::addCreature(Creature* creature) {
	return ((CreatureManagerImplementation*) impl)->addCreature(creature);
}

/*
 *	CreatureManagerHelper
 */

CreatureManagerHelper* CreatureManagerHelper::staticInitializer = CreatureManagerHelper::instance();

CreatureManagerHelper::CreatureManagerHelper() {
	className = "CreatureManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureManagerHelper::finalizeHelper() {
	CreatureManagerHelper::finalize();
}

DistributedObject* CreatureManagerHelper::instantiateObject() {
	return new CreatureManager(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CreatureManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CreatureManagerAdapter((CreatureManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CreatureManagerServant
 */

CreatureManagerServant::CreatureManagerServant() {
	_classHelper = CreatureManagerHelper::instance();
}

CreatureManagerServant::~CreatureManagerServant() {
}

void CreatureManagerServant::_setStub(DistributedObjectStub* stub) {
	_this = (CreatureManager*) stub;
}

DistributedObjectStub* CreatureManagerServant::_getStub() {
	return _this;
}

