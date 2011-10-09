/*
 *	server/zone/objects/tangible/pharmaceutical/StimPack.cpp generated by engine3 IDL compiler 0.60
 */

#include "StimPack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

/*
 *	StimPackStub
 */

enum {RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_GETEFFECTIVENESS__,RPC_ISSTIMPACK__};

StimPack::StimPack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	StimPackImplementation* _implementation = new StimPackImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

StimPack::StimPack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

StimPack::~StimPack() {
}



void StimPack::updateCraftingValues(ManufactureSchematic* schematic) {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void StimPack::loadTemplateData(SharedObjectTemplate* templateData) {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

unsigned int StimPack::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_);
		method.addObjectParameter(healer);
		method.addObjectParameter(patient);
		method.addBooleanParameter(applyBattleFatigue);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->calculatePower(healer, patient, applyBattleFatigue);
}

int StimPack::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void StimPack::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

float StimPack::getEffectiveness() {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

bool StimPack::isStimPack() {
	StimPackImplementation* _implementation = static_cast<StimPackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISSTIMPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStimPack();
}

DistributedObjectServant* StimPack::_getImplementation() {

	_updated = true;
	return _impl;
}

void StimPack::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	StimPackImplementation
 */

StimPackImplementation::StimPackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


StimPackImplementation::~StimPackImplementation() {
}


void StimPackImplementation::finalize() {
}

void StimPackImplementation::_initializeImplementation() {
	_setClassHelper(StimPackHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void StimPackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<StimPack*>(stub);
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* StimPackImplementation::_getStub() {
	return _this;
}

StimPackImplementation::operator const StimPack*() {
	return _this;
}

void StimPackImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void StimPackImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void StimPackImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void StimPackImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void StimPackImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void StimPackImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void StimPackImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void StimPackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("StimPack");

}

void StimPackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(StimPackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StimPackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "effectiveness") {
		TypeInfo<float >::parseFromBinaryStream(&effectiveness, stream);
		return true;
	}


	return false;
}

void StimPackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StimPackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StimPackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "effectiveness";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&effectiveness, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

StimPackImplementation::StimPackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		setLoggingName("StimPack");
	setLoggingName("StimPack");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = 0;
	effectiveness = 0;
}

void StimPackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = craftingValues.getCurrentValue("power");
	effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
}

void StimPackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.loadTemplateData(templateData);
	PharmaceuticalObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		StimPackTemplate 
	if (!templateData->isStimPackTemplate())	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		StimPackTemplate stimPackTemplate = (StimPackTemplate) templateData;
	StimPackTemplate* stimPackTemplate = (StimPackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	PharmaceuticalObjectImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
}

unsigned int StimPackImplementation::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float power = getEffectiveness();
	float power = getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float 
	if (applyBattleFatigue){
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			power = power - power * patient.calculateBFRatio();
	power = power - power * patient->calculateBFRatio();
}
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float modSkill = (float) healer.getSkillMod("healing_injury_treatment");
	float modSkill = (float) healer->getSkillMod("healing_injury_treatment");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return (100 + modSkill) / 100 * power;
	return (100 + modSkill) / 100 * power;
}

int StimPackImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			string command = "/healdamage ";
	String command = "/healdamage ";
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			player.sendExecuteConsoleCommand(command + String.valueOf(super.getObjectID()));
	player->sendExecuteConsoleCommand(command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID()));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 0;
	return 0;
}
}

void StimPackImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("healing_ability", super.medicineUseRequired);
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::medicineUseRequired);
}

float StimPackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return effectiveness;
	return effectiveness;
}

bool StimPackImplementation::isStimPack() {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return true;
	return true;
}

/*
 *	StimPackAdapter
 */

StimPackAdapter::StimPackAdapter(StimPackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* StimPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_:
		resp->insertInt(calculatePower(static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getBooleanParameter()));
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_GETEFFECTIVENESS__:
		resp->insertFloat(getEffectiveness());
		break;
	case RPC_ISSTIMPACK__:
		resp->insertBoolean(isStimPack());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned int StimPackAdapter::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	return (static_cast<StimPackImplementation*>(impl))->calculatePower(healer, patient, applyBattleFatigue);
}

int StimPackAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<StimPackImplementation*>(impl))->handleObjectMenuSelect(player, selectedID);
}

float StimPackAdapter::getEffectiveness() {
	return (static_cast<StimPackImplementation*>(impl))->getEffectiveness();
}

bool StimPackAdapter::isStimPack() {
	return (static_cast<StimPackImplementation*>(impl))->isStimPack();
}

/*
 *	StimPackHelper
 */

StimPackHelper* StimPackHelper::staticInitializer = StimPackHelper::instance();

StimPackHelper::StimPackHelper() {
	className = "StimPack";

	Core::getObjectBroker()->registerClass(className, this);
}

void StimPackHelper::finalizeHelper() {
	StimPackHelper::finalize();
}

DistributedObject* StimPackHelper::instantiateObject() {
	return new StimPack(DummyConstructorParameter::instance());
}

DistributedObjectServant* StimPackHelper::instantiateServant() {
	return new StimPackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StimPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StimPackAdapter(static_cast<StimPackImplementation*>(obj->_getImplementation()));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

