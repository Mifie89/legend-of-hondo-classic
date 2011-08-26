/*
 *	server/zone/objects/tangible/pharmaceutical/CurePack.cpp generated by engine3 IDL compiler 0.60
 */

#include "CurePack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

/*
 *	CurePackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_CALCULATEPOWER__CREATUREOBJECT_,RPC_ISAREA__,RPC_GETAREA__,RPC_GETSTATE__,RPC_GETEFFECTIVENESS__,RPC_ISCUREPACK__};

CurePack::CurePack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	CurePackImplementation* _implementation = new CurePackImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

CurePack::CurePack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

CurePack::~CurePack() {
}


void CurePack::updateCraftingValues(ManufactureSchematic* schematic) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void CurePack::loadTemplateData(SharedObjectTemplate* templateData) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

int CurePack::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
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

void CurePack::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int CurePack::calculatePower(CreatureObject* creature) {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEPOWER__CREATUREOBJECT_);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculatePower(creature);
}

bool CurePack::isArea() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArea();
}

float CurePack::getArea() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAREA__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getArea();
}

unsigned long long CurePack::getState() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSTATE__);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getState();
}

float CurePack::getEffectiveness() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

bool CurePack::isCurePack() {
	CurePackImplementation* _implementation = (CurePackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCUREPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isCurePack();
}

DistributedObjectServant* CurePack::_getImplementation() {

	_updated = true;
	return _impl;
}

void CurePack::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	CurePackImplementation
 */

CurePackImplementation::CurePackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


CurePackImplementation::~CurePackImplementation() {
}


void CurePackImplementation::finalize() {
}

void CurePackImplementation::_initializeImplementation() {
	_setClassHelper(CurePackHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void CurePackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CurePack*) stub;
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CurePackImplementation::_getStub() {
	return _this;
}

CurePackImplementation::operator const CurePack*() {
	return _this;
}

void CurePackImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CurePackImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CurePackImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CurePackImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CurePackImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CurePackImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CurePackImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CurePackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("CurePack");

}

void CurePackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(CurePackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CurePackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "effectiveness") {
		TypeInfo<float >::parseFromBinaryStream(&effectiveness, stream);
		return true;
	}

	if (_name == "area") {
		TypeInfo<float >::parseFromBinaryStream(&area, stream);
		return true;
	}

	if (_name == "state") {
		TypeInfo<unsigned long long >::parseFromBinaryStream(&state, stream);
		return true;
	}

	if (_name == "commandToExecute") {
		TypeInfo<String >::parseFromBinaryStream(&commandToExecute, stream);
		return true;
	}


	return false;
}

void CurePackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CurePackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CurePackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
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

	_name = "area";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&area, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "state";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned long long >::toBinaryStream(&state, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "commandToExecute";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&commandToExecute, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

CurePackImplementation::CurePackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		setLoggingName("CurePack");
	setLoggingName("CurePack");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = 0;
	effectiveness = 0;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		area = 0;
	area = 0;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		state = 0;
	state = 0;
}

void CurePackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = craftingValues.getCurrentValue("power");
	effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  	}
	if (craftingValues->hasProperty("area")){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			area = craftingValues.getCurrentValue("area");
	area = craftingValues->getCurrentValue("area");
}
}

void CurePackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.loadTemplateData(templateData);
	PharmaceuticalObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CurePackTemplate 
	if (!templateData->isCurePackTemplate())	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		CurePackTemplate stimPackTemplate = (CurePackTemplate) templateData;
	CurePackTemplate* stimPackTemplate = (CurePackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	PharmaceuticalObjectImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		area = stimPackTemplate.getArea();
	area = stimPackTemplate->getArea();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		state = stimPackTemplate.getState();
	state = stimPackTemplate->getState();
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		commandToExecute = stimPackTemplate.getCommandToExecute();
	commandToExecute = stimPackTemplate->getCommandToExecute();
}

int CurePackImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			string command = commandToExecute + " ";
	String command = commandToExecute + " ";
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			return 0;
	return 0;
}
}

void CurePackImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		string eff = "@obj_attr_n:dot_type_";
	String eff = "@obj_attr_n:dot_type_";
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		msg.insertAttribute("examine_dot_cure", eff + CreatureState.instance().getSpecialName(state));
	msg->insertAttribute("examine_dot_cure", eff + CreatureState::instance()->getSpecialName(state));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		msg.insertAttribute("examine_dot_cure_power", effectiveness);
	msg->insertAttribute("examine_dot_cure_power", effectiveness);
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		}
	if (isArea()){
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("examine_heal_area", Math.getPrecision(area, 0));
	msg->insertAttribute("examine_heal_area", Math::getPrecision(area, 0));
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}

	else {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  			msg.insertAttribute("healing_ability", super.getMedicineUseRequired());
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::getMedicineUseRequired());
}
}

int CurePackImplementation::calculatePower(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		float modSkill = (float) creature.getSkillMod("healing_wound_treatment");
	float modSkill = (float) creature->getSkillMod("healing_wound_treatment");
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return ((100 + modSkill) / 100 * effectiveness);
	return ((100 + modSkill) / 100 * effectiveness);
}

bool CurePackImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return area != 0;
	return area != 0;
}

float CurePackImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return area;
	return area;
}

unsigned long long CurePackImplementation::getState() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return state;
	return state;
}

float CurePackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return effectiveness;
	return effectiveness;
}

bool CurePackImplementation::isCurePack() {
	// server/zone/objects/tangible/pharmaceutical/CurePack.idl():  		return true;
	return true;
}

/*
 *	CurePackAdapter
 */

CurePackAdapter::CurePackAdapter(CurePackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* CurePackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((CreatureObject*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_CALCULATEPOWER__CREATUREOBJECT_:
		resp->insertSignedInt(calculatePower((CreatureObject*) inv->getObjectParameter()));
		break;
	case RPC_ISAREA__:
		resp->insertBoolean(isArea());
		break;
	case RPC_GETAREA__:
		resp->insertFloat(getArea());
		break;
	case RPC_GETSTATE__:
		resp->insertLong(getState());
		break;
	case RPC_GETEFFECTIVENESS__:
		resp->insertFloat(getEffectiveness());
		break;
	case RPC_ISCUREPACK__:
		resp->insertBoolean(isCurePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int CurePackAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return ((CurePackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

int CurePackAdapter::calculatePower(CreatureObject* creature) {
	return ((CurePackImplementation*) impl)->calculatePower(creature);
}

bool CurePackAdapter::isArea() {
	return ((CurePackImplementation*) impl)->isArea();
}

float CurePackAdapter::getArea() {
	return ((CurePackImplementation*) impl)->getArea();
}

unsigned long long CurePackAdapter::getState() {
	return ((CurePackImplementation*) impl)->getState();
}

float CurePackAdapter::getEffectiveness() {
	return ((CurePackImplementation*) impl)->getEffectiveness();
}

bool CurePackAdapter::isCurePack() {
	return ((CurePackImplementation*) impl)->isCurePack();
}

/*
 *	CurePackHelper
 */

CurePackHelper* CurePackHelper::staticInitializer = CurePackHelper::instance();

CurePackHelper::CurePackHelper() {
	className = "CurePack";

	Core::getObjectBroker()->registerClass(className, this);
}

void CurePackHelper::finalizeHelper() {
	CurePackHelper::finalize();
}

DistributedObject* CurePackHelper::instantiateObject() {
	return new CurePack(DummyConstructorParameter::instance());
}

DistributedObjectServant* CurePackHelper::instantiateServant() {
	return new CurePackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CurePackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CurePackAdapter((CurePackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

