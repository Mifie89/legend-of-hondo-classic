/*
 *	server/zone/objects/tangible/pharmaceutical/RevivePack.cpp generated by engine3 IDL compiler 0.60
 */

#include "RevivePack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

/*
 *	RevivePackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_GETHEALTHWOUNDHEALED__,RPC_GETHEALTHHEALED__,RPC_GETACTIONWOUNDHEALED__,RPC_GETACTIONHEALED__,RPC_GETMINDWOUNDHEALED__,RPC_GETMINDHEALED__,RPC_ISREVIVEPACK__};

RevivePack::RevivePack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	RevivePackImplementation* _implementation = new RevivePackImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

RevivePack::RevivePack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

RevivePack::~RevivePack() {
}



void RevivePack::updateCraftingValues(ManufactureSchematic* schematic) {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void RevivePack::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int RevivePack::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
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

float RevivePack::getHealthWoundHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETHEALTHWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthWoundHealed();
}

float RevivePack::getHealthHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETHEALTHHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getHealthHealed();
}

float RevivePack::getActionWoundHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACTIONWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionWoundHealed();
}

float RevivePack::getActionHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACTIONHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getActionHealed();
}

float RevivePack::getMindWoundHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMINDWOUNDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindWoundHealed();
}

float RevivePack::getMindHealed() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMINDHEALED__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getMindHealed();
}

bool RevivePack::isRevivePack() {
	RevivePackImplementation* _implementation = static_cast<RevivePackImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISREVIVEPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRevivePack();
}

DistributedObjectServant* RevivePack::_getImplementation() {

	_updated = true;
	return _impl;
}

void RevivePack::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	RevivePackImplementation
 */

RevivePackImplementation::RevivePackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


RevivePackImplementation::~RevivePackImplementation() {
}


void RevivePackImplementation::finalize() {
}

void RevivePackImplementation::_initializeImplementation() {
	_setClassHelper(RevivePackHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void RevivePackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<RevivePack*>(stub);
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* RevivePackImplementation::_getStub() {
	return _this;
}

RevivePackImplementation::operator const RevivePack*() {
	return _this;
}

void RevivePackImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void RevivePackImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void RevivePackImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void RevivePackImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void RevivePackImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void RevivePackImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void RevivePackImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void RevivePackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("RevivePack");

}

void RevivePackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RevivePackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RevivePackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "healthWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthWoundHealed, stream);
		return true;
	}

	if (_name == "healthHealed") {
		TypeInfo<float >::parseFromBinaryStream(&healthHealed, stream);
		return true;
	}

	if (_name == "actionWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionWoundHealed, stream);
		return true;
	}

	if (_name == "actionHealed") {
		TypeInfo<float >::parseFromBinaryStream(&actionHealed, stream);
		return true;
	}

	if (_name == "mindWoundHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindWoundHealed, stream);
		return true;
	}

	if (_name == "mindHealed") {
		TypeInfo<float >::parseFromBinaryStream(&mindHealed, stream);
		return true;
	}


	return false;
}

void RevivePackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RevivePackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RevivePackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "healthWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "healthHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&healthHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "actionHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&actionHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindWoundHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindWoundHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "mindHealed";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&mindHealed, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 6 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

RevivePackImplementation::RevivePackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		setLoggingName("RevivePack");
	setLoggingName("RevivePack");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthWoundHealed = 100;
	healthWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthHealed = 100;
	healthHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionWoundHealed = 100;
	actionWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionHealed = 100;
	actionHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindWoundHealed = 100;
	mindWoundHealed = 100;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindHealed = 100;
	mindHealed = 100;
}

void RevivePackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float effectiveness = craftingValues.getCurrentValue("power");
	float effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		craftingValues.setHidden("power");
	craftingValues->setHidden("power");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float health = 2 * effectiveness;
	float health = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthWoundHealed = health;
	healthWoundHealed = health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		healthHealed = 2 * effectiveness - health;
	healthHealed = 2 * effectiveness - health;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float action = 2 * effectiveness;
	float action = 2 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		action = System.random(action / 4);
	action = System::random(action / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		action = action + effectiveness / 2;
	action = action + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionWoundHealed = action;
	actionWoundHealed = action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		actionHealed = 2 * effectiveness - action;
	actionHealed = 2 * effectiveness - action;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		float mind = 1.5 * effectiveness;
	float mind = 1.5 * effectiveness;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mind = System.random(mind / 4);
	mind = System::random(mind / 4);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mind = mind + effectiveness / 2;
	mind = mind + effectiveness / 2;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindWoundHealed = mind;
	mindWoundHealed = mind;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		mindHealed = 1.5 * effectiveness - mind;
	mindHealed = 1.5 * effectiveness - mind;
}

void RevivePackImplementation::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_health", Math.getPrecision(healthWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_health", Math::getPrecision(healthWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(healthHealed, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(healthHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_mind", Math.getPrecision(mindWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_mind", Math::getPrecision(mindWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_mind", Math.getPrecision(mindHealed, 0));
	msg->insertAttribute("examine_heal_damage_mind", Math::getPrecision(mindHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_wound_action", Math.getPrecision(actionWoundHealed, 0));
	msg->insertAttribute("examine_heal_wound_action", Math::getPrecision(actionWoundHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(actionHealed, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(actionHealed, 0));
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		msg.insertAttribute("healing_ability", super.medicineUseRequired);
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::medicineUseRequired);
}

int RevivePackImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			string command = "/reviveplayer ";
	String command = "/reviveplayer ";
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			command = command + String.valueOf(super.getObjectID());
	command = command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID());
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			player.sendExecuteConsoleCommand(command);
	player->sendExecuteConsoleCommand(command);
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  			return 0;
	return 0;
}
}

float RevivePackImplementation::getHealthWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return healthWoundHealed;
	return healthWoundHealed;
}

float RevivePackImplementation::getHealthHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return healthHealed;
	return healthHealed;
}

float RevivePackImplementation::getActionWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return actionWoundHealed;
	return actionWoundHealed;
}

float RevivePackImplementation::getActionHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return actionHealed;
	return actionHealed;
}

float RevivePackImplementation::getMindWoundHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return mindWoundHealed;
	return mindWoundHealed;
}

float RevivePackImplementation::getMindHealed() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return mindHealed;
	return mindHealed;
}

bool RevivePackImplementation::isRevivePack() {
	// server/zone/objects/tangible/pharmaceutical/RevivePack.idl():  		return true;
	return true;
}

/*
 *	RevivePackAdapter
 */

RevivePackAdapter::RevivePackAdapter(RevivePackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* RevivePackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_GETHEALTHWOUNDHEALED__:
		resp->insertFloat(getHealthWoundHealed());
		break;
	case RPC_GETHEALTHHEALED__:
		resp->insertFloat(getHealthHealed());
		break;
	case RPC_GETACTIONWOUNDHEALED__:
		resp->insertFloat(getActionWoundHealed());
		break;
	case RPC_GETACTIONHEALED__:
		resp->insertFloat(getActionHealed());
		break;
	case RPC_GETMINDWOUNDHEALED__:
		resp->insertFloat(getMindWoundHealed());
		break;
	case RPC_GETMINDHEALED__:
		resp->insertFloat(getMindHealed());
		break;
	case RPC_ISREVIVEPACK__:
		resp->insertBoolean(isRevivePack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RevivePackAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<RevivePackImplementation*>(impl))->handleObjectMenuSelect(player, selectedID);
}

float RevivePackAdapter::getHealthWoundHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getHealthWoundHealed();
}

float RevivePackAdapter::getHealthHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getHealthHealed();
}

float RevivePackAdapter::getActionWoundHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getActionWoundHealed();
}

float RevivePackAdapter::getActionHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getActionHealed();
}

float RevivePackAdapter::getMindWoundHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getMindWoundHealed();
}

float RevivePackAdapter::getMindHealed() {
	return (static_cast<RevivePackImplementation*>(impl))->getMindHealed();
}

bool RevivePackAdapter::isRevivePack() {
	return (static_cast<RevivePackImplementation*>(impl))->isRevivePack();
}

/*
 *	RevivePackHelper
 */

RevivePackHelper* RevivePackHelper::staticInitializer = RevivePackHelper::instance();

RevivePackHelper::RevivePackHelper() {
	className = "RevivePack";

	Core::getObjectBroker()->registerClass(className, this);
}

void RevivePackHelper::finalizeHelper() {
	RevivePackHelper::finalize();
}

DistributedObject* RevivePackHelper::instantiateObject() {
	return new RevivePack(DummyConstructorParameter::instance());
}

DistributedObjectServant* RevivePackHelper::instantiateServant() {
	return new RevivePackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RevivePackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RevivePackAdapter(static_cast<RevivePackImplementation*>(obj->_getImplementation()));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

