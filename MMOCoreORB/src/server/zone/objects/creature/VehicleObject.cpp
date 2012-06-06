/*
 *	server/zone/objects/creature/VehicleObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "VehicleObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/intangible/VehicleControlDevice.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

/*
 *	VehicleObjectStub
 */

enum {RPC_CHECKINRANGEGARAGE__,RPC_NOTIFYINSERTTOZONE__ZONE_,RPC_SETPOSTURE__INT_BOOL_,RPC_SENDMESSAGE__BASEPACKET_,RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_BOOL_,RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_STRING_BOOL_,RPC_HEALDAMAGE__TANGIBLEOBJECT_INT_INT_BOOL_,RPC_ADDDEFENDER__SCENEOBJECT_,RPC_REMOVEDEFENDER__SCENEOBJECT_,RPC_SETDEFENDER__SCENEOBJECT_,RPC_ISATTACKABLEBY__CREATUREOBJECT_,RPC_NOTIFYOBJECTDESTRUCTIONOBSERVERS__TANGIBLEOBJECT_INT_,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_REPAIRVEHICLE__CREATUREOBJECT_,RPC_CALCULATEREPAIRCOST__CREATUREOBJECT_,RPC_SENDREPAIRCONFIRMTO__CREATUREOBJECT_,RPC_ISVEHICLEOBJECT__};

VehicleObject::VehicleObject() : CreatureObject(DummyConstructorParameter::instance()) {
	VehicleObjectImplementation* _implementation = new VehicleObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("VehicleObject");
}

VehicleObject::VehicleObject(DummyConstructorParameter* param) : CreatureObject(param) {
	_setClassName("VehicleObject");
}

VehicleObject::~VehicleObject() {
}



void VehicleObject::loadTemplateData(SharedObjectTemplate* templateData) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void VehicleObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

bool VehicleObject::checkInRangeGarage() {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKINRANGEGARAGE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->checkInRangeGarage();
}

void VehicleObject::notifyInsertToZone(Zone* zone) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYINSERTTOZONE__ZONE_);
		method.addObjectParameter(zone);

		method.executeWithVoidReturn();
	} else
		_implementation->notifyInsertToZone(zone);
}

void VehicleObject::setPosture(int newPosture, bool notifyClient) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETPOSTURE__INT_BOOL_);
		method.addSignedIntParameter(newPosture);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		_implementation->setPosture(newPosture, notifyClient);
}

void VehicleObject::sendMessage(BasePacket* msg) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDMESSAGE__BASEPACKET_);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		_implementation->sendMessage(msg);
}

int VehicleObject::inflictDamage(TangibleObject* attacker, int damageType, float damage, bool destroy, bool notifyClient) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_BOOL_);
		method.addObjectParameter(attacker);
		method.addSignedIntParameter(damageType);
		method.addFloatParameter(damage);
		method.addBooleanParameter(destroy);
		method.addBooleanParameter(notifyClient);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->inflictDamage(attacker, damageType, damage, destroy, notifyClient);
}

int VehicleObject::inflictDamage(TangibleObject* attacker, int damageType, float damage, bool destroy, const String& xp, bool notifyClient) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_STRING_BOOL_);
		method.addObjectParameter(attacker);
		method.addSignedIntParameter(damageType);
		method.addFloatParameter(damage);
		method.addBooleanParameter(destroy);
		method.addAsciiParameter(xp);
		method.addBooleanParameter(notifyClient);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->inflictDamage(attacker, damageType, damage, destroy, xp, notifyClient);
}

int VehicleObject::healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HEALDAMAGE__TANGIBLEOBJECT_INT_INT_BOOL_);
		method.addObjectParameter(healer);
		method.addSignedIntParameter(damageType);
		method.addSignedIntParameter(damageToHeal);
		method.addBooleanParameter(notifyClient);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->healDamage(healer, damageType, damageToHeal, notifyClient);
}

void VehicleObject::addDefender(SceneObject* defender) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDDEFENDER__SCENEOBJECT_);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		_implementation->addDefender(defender);
}

void VehicleObject::removeDefender(SceneObject* defender) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEDEFENDER__SCENEOBJECT_);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		_implementation->removeDefender(defender);
}

void VehicleObject::setDefender(SceneObject* defender) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETDEFENDER__SCENEOBJECT_);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		_implementation->setDefender(defender);
}

bool VehicleObject::isAttackableBy(CreatureObject* object) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISATTACKABLEBY__CREATUREOBJECT_);
		method.addObjectParameter(object);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isAttackableBy(object);
}

int VehicleObject::notifyObjectDestructionObservers(TangibleObject* attacker, int condition) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBJECTDESTRUCTIONOBSERVERS__TANGIBLEOBJECT_INT_);
		method.addObjectParameter(attacker);
		method.addSignedIntParameter(condition);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObjectDestructionObservers(attacker, condition);
}

int VehicleObject::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
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

void VehicleObject::repairVehicle(CreatureObject* player) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REPAIRVEHICLE__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->repairVehicle(player);
}

int VehicleObject::calculateRepairCost(CreatureObject* player) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEREPAIRCOST__CREATUREOBJECT_);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculateRepairCost(player);
}

void VehicleObject::sendRepairConfirmTo(CreatureObject* player) {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDREPAIRCONFIRMTO__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendRepairConfirmTo(player);
}

bool VehicleObject::isVehicleObject() {
	VehicleObjectImplementation* _implementation = static_cast<VehicleObjectImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISVEHICLEOBJECT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isVehicleObject();
}

DistributedObjectServant* VehicleObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void VehicleObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	VehicleObjectImplementation
 */

VehicleObjectImplementation::VehicleObjectImplementation(DummyConstructorParameter* param) : CreatureObjectImplementation(param) {
	_initializeImplementation();
}


VehicleObjectImplementation::~VehicleObjectImplementation() {
}


void VehicleObjectImplementation::finalize() {
}

void VehicleObjectImplementation::_initializeImplementation() {
	_setClassHelper(VehicleObjectHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void VehicleObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<VehicleObject*>(stub);
	CreatureObjectImplementation::_setStub(stub);
}

DistributedObjectStub* VehicleObjectImplementation::_getStub() {
	return _this.get();
}

VehicleObjectImplementation::operator const VehicleObject*() {
	return _this.get();
}

void VehicleObjectImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void VehicleObjectImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void VehicleObjectImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void VehicleObjectImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void VehicleObjectImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void VehicleObjectImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void VehicleObjectImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void VehicleObjectImplementation::_serializationHelperMethod() {
	CreatureObjectImplementation::_serializationHelperMethod();

	_setClassName("VehicleObject");

}

void VehicleObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(VehicleObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool VehicleObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (CreatureObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "VehicleObject.vehicleType") {
		TypeInfo<int >::parseFromBinaryStream(&vehicleType, stream);
		return true;
	}


	return false;
}

void VehicleObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = VehicleObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int VehicleObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = CreatureObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "VehicleObject.vehicleType";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&vehicleType, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

VehicleObjectImplementation::VehicleObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/VehicleObject.idl():  		vehicleType = SceneObjectType.HOVERVEHICLE;
	vehicleType = SceneObjectType::HOVERVEHICLE;
	// server/zone/objects/creature/VehicleObject.idl():  		Logger.setLoggingName("VehicleObject");
	Logger::setLoggingName("VehicleObject");
	// server/zone/objects/creature/VehicleObject.idl():  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/creature/VehicleObject.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

void VehicleObjectImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/creature/VehicleObject.idl():  		super.loadTemplateData(templateData);
	CreatureObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/creature/VehicleObject.idl():  		super.optionsBitmask = 0x1080;
	CreatureObjectImplementation::optionsBitmask = 0x1080;
	// server/zone/objects/creature/VehicleObject.idl():  		super.pvpStatusBitmask = 0;
	CreatureObjectImplementation::pvpStatusBitmask = 0;
}

void VehicleObjectImplementation::setPosture(int newPosture, bool notifyClient) {
	// server/zone/objects/creature/VehicleObject.idl():  		return;
	return;
}

void VehicleObjectImplementation::addDefender(SceneObject* defender) {
}

void VehicleObjectImplementation::removeDefender(SceneObject* defender) {
}

void VehicleObjectImplementation::setDefender(SceneObject* defender) {
}

bool VehicleObjectImplementation::isAttackableBy(CreatureObject* object) {
	// server/zone/objects/creature/VehicleObject.idl():  		return 
	if (CreatureObjectImplementation::linkedCreature.getForUpdate() == NULL)	// server/zone/objects/creature/VehicleObject.idl():  			return false;
	return false;
	// server/zone/objects/creature/VehicleObject.idl():  		return super.linkedCreature.isAttackableBy(object);
	return CreatureObjectImplementation::linkedCreature.getForUpdate().get()->isAttackableBy(object);
}

bool VehicleObjectImplementation::isVehicleObject() {
	// server/zone/objects/creature/VehicleObject.idl():  		return true;
	return true;
}

/*
 *	VehicleObjectAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


VehicleObjectAdapter::VehicleObjectAdapter(VehicleObject* obj) : CreatureObjectAdapter(obj) {
}

void VehicleObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_CHECKINRANGEGARAGE__:
		{
			resp->insertBoolean(checkInRangeGarage());
		}
		break;
	case RPC_NOTIFYINSERTTOZONE__ZONE_:
		{
			notifyInsertToZone(static_cast<Zone*>(inv->getObjectParameter()));
		}
		break;
	case RPC_SETPOSTURE__INT_BOOL_:
		{
			setPosture(inv->getSignedIntParameter(), inv->getBooleanParameter());
		}
		break;
	case RPC_SENDMESSAGE__BASEPACKET_:
		{
			sendMessage(static_cast<BasePacket*>(inv->getObjectParameter()));
		}
		break;
	case RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_BOOL_:
		{
			resp->insertSignedInt(inflictDamage(static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getBooleanParameter(), inv->getBooleanParameter()));
		}
		break;
	case RPC_INFLICTDAMAGE__TANGIBLEOBJECT_INT_FLOAT_BOOL_STRING_BOOL_:
		{
			String xp; 
			resp->insertSignedInt(inflictDamage(static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getBooleanParameter(), inv->getAsciiParameter(xp), inv->getBooleanParameter()));
		}
		break;
	case RPC_HEALDAMAGE__TANGIBLEOBJECT_INT_INT_BOOL_:
		{
			resp->insertSignedInt(healDamage(static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter()));
		}
		break;
	case RPC_ADDDEFENDER__SCENEOBJECT_:
		{
			addDefender(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_REMOVEDEFENDER__SCENEOBJECT_:
		{
			removeDefender(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_SETDEFENDER__SCENEOBJECT_:
		{
			setDefender(static_cast<SceneObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_ISATTACKABLEBY__CREATUREOBJECT_:
		{
			resp->insertBoolean(isAttackableBy(static_cast<CreatureObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_NOTIFYOBJECTDESTRUCTIONOBSERVERS__TANGIBLEOBJECT_INT_:
		{
			resp->insertSignedInt(notifyObjectDestructionObservers(static_cast<TangibleObject*>(inv->getObjectParameter()), inv->getSignedIntParameter()));
		}
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		{
			resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		}
		break;
	case RPC_REPAIRVEHICLE__CREATUREOBJECT_:
		{
			repairVehicle(static_cast<CreatureObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_CALCULATEREPAIRCOST__CREATUREOBJECT_:
		{
			resp->insertSignedInt(calculateRepairCost(static_cast<CreatureObject*>(inv->getObjectParameter())));
		}
		break;
	case RPC_SENDREPAIRCONFIRMTO__CREATUREOBJECT_:
		{
			sendRepairConfirmTo(static_cast<CreatureObject*>(inv->getObjectParameter()));
		}
		break;
	case RPC_ISVEHICLEOBJECT__:
		{
			resp->insertBoolean(isVehicleObject());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

bool VehicleObjectAdapter::checkInRangeGarage() {
	return (static_cast<VehicleObject*>(stub))->checkInRangeGarage();
}

void VehicleObjectAdapter::notifyInsertToZone(Zone* zone) {
	(static_cast<VehicleObject*>(stub))->notifyInsertToZone(zone);
}

void VehicleObjectAdapter::setPosture(int newPosture, bool notifyClient) {
	(static_cast<VehicleObject*>(stub))->setPosture(newPosture, notifyClient);
}

void VehicleObjectAdapter::sendMessage(BasePacket* msg) {
	(static_cast<VehicleObject*>(stub))->sendMessage(msg);
}

int VehicleObjectAdapter::inflictDamage(TangibleObject* attacker, int damageType, float damage, bool destroy, bool notifyClient) {
	return (static_cast<VehicleObject*>(stub))->inflictDamage(attacker, damageType, damage, destroy, notifyClient);
}

int VehicleObjectAdapter::inflictDamage(TangibleObject* attacker, int damageType, float damage, bool destroy, const String& xp, bool notifyClient) {
	return (static_cast<VehicleObject*>(stub))->inflictDamage(attacker, damageType, damage, destroy, xp, notifyClient);
}

int VehicleObjectAdapter::healDamage(TangibleObject* healer, int damageType, int damageToHeal, bool notifyClient) {
	return (static_cast<VehicleObject*>(stub))->healDamage(healer, damageType, damageToHeal, notifyClient);
}

void VehicleObjectAdapter::addDefender(SceneObject* defender) {
	(static_cast<VehicleObject*>(stub))->addDefender(defender);
}

void VehicleObjectAdapter::removeDefender(SceneObject* defender) {
	(static_cast<VehicleObject*>(stub))->removeDefender(defender);
}

void VehicleObjectAdapter::setDefender(SceneObject* defender) {
	(static_cast<VehicleObject*>(stub))->setDefender(defender);
}

bool VehicleObjectAdapter::isAttackableBy(CreatureObject* object) {
	return (static_cast<VehicleObject*>(stub))->isAttackableBy(object);
}

int VehicleObjectAdapter::notifyObjectDestructionObservers(TangibleObject* attacker, int condition) {
	return (static_cast<VehicleObject*>(stub))->notifyObjectDestructionObservers(attacker, condition);
}

int VehicleObjectAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<VehicleObject*>(stub))->handleObjectMenuSelect(player, selectedID);
}

void VehicleObjectAdapter::repairVehicle(CreatureObject* player) {
	(static_cast<VehicleObject*>(stub))->repairVehicle(player);
}

int VehicleObjectAdapter::calculateRepairCost(CreatureObject* player) {
	return (static_cast<VehicleObject*>(stub))->calculateRepairCost(player);
}

void VehicleObjectAdapter::sendRepairConfirmTo(CreatureObject* player) {
	(static_cast<VehicleObject*>(stub))->sendRepairConfirmTo(player);
}

bool VehicleObjectAdapter::isVehicleObject() {
	return (static_cast<VehicleObject*>(stub))->isVehicleObject();
}

/*
 *	VehicleObjectHelper
 */

VehicleObjectHelper* VehicleObjectHelper::staticInitializer = VehicleObjectHelper::instance();

VehicleObjectHelper::VehicleObjectHelper() {
	className = "VehicleObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void VehicleObjectHelper::finalizeHelper() {
	VehicleObjectHelper::finalize();
}

DistributedObject* VehicleObjectHelper::instantiateObject() {
	return new VehicleObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* VehicleObjectHelper::instantiateServant() {
	return new VehicleObjectImplementation();
}

DistributedObjectAdapter* VehicleObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new VehicleObjectAdapter(static_cast<VehicleObject*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

