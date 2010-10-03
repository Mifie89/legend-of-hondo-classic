/*
 *	server/zone/objects/tangible/deed/building/BuildingDeed.cpp generated by engine3 IDL compiler 0.60
 */

#include "BuildingDeed.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/scene/AttributeListMessage.h"


// Imported class dependencies

#include "system/lang/Time.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "engine/util/QuadTree.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "engine/util/Quaternion.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/ZoneServer.h"

#include "system/util/SortedVector.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

/*
 *	BuildingDeedStub
 */

BuildingDeed::BuildingDeed() : Deed(DummyConstructorParameter::instance()) {
	BuildingDeedImplementation* _implementation = new BuildingDeedImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

BuildingDeed::BuildingDeed(DummyConstructorParameter* param) : Deed(param) {
}

BuildingDeed::~BuildingDeed() {
}


void BuildingDeed::fillAttributeList(AttributeListMessage* alm, PlayerCreature* object) {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(alm, object);
}

void BuildingDeed::initializeTransientMembers() {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

int BuildingDeed::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void BuildingDeed::setSurplusMaintenance(unsigned int surplusMaint) {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addUnsignedIntParameter(surplusMaint);

		method.executeWithVoidReturn();
	} else
		_implementation->setSurplusMaintenance(surplusMaint);
}

unsigned int BuildingDeed::getSurplusMaintenance() {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getSurplusMaintenance();
}

bool BuildingDeed::isBuildingDeed() {
	BuildingDeedImplementation* _implementation = (BuildingDeedImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isBuildingDeed();
}

DistributedObjectServant* BuildingDeed::_getImplementation() {
	return getForUpdate();}

void BuildingDeed::_setImplementation(DistributedObjectServant* servant) {
	setObject((ManagedObjectImplementation*) servant);}

/*
 *	BuildingDeedImplementation
 */

BuildingDeedImplementation::BuildingDeedImplementation(DummyConstructorParameter* param) : DeedImplementation(param) {
	_initializeImplementation();
}


BuildingDeedImplementation::~BuildingDeedImplementation() {
}


void BuildingDeedImplementation::finalize() {
}

void BuildingDeedImplementation::_initializeImplementation() {
	_setClassHelper(BuildingDeedHelper::instance());

	_serializationHelperMethod();
}

void BuildingDeedImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BuildingDeed*) stub;
	DeedImplementation::_setStub(stub);
}

DistributedObjectStub* BuildingDeedImplementation::_getStub() {
	return _this;
}

BuildingDeedImplementation::operator const BuildingDeed*() {
	return _this;
}

TransactionalObject* BuildingDeedImplementation::clone() {
	return (TransactionalObject*) new BuildingDeedImplementation(*this);
}


void BuildingDeedImplementation::lock(bool doLock) {
}

void BuildingDeedImplementation::lock(ManagedObject* obj) {
}

void BuildingDeedImplementation::rlock(bool doLock) {
}

void BuildingDeedImplementation::wlock(bool doLock) {
}

void BuildingDeedImplementation::wlock(ManagedObject* obj) {
}

void BuildingDeedImplementation::unlock(bool doLock) {
}

void BuildingDeedImplementation::runlock(bool doLock) {
}

void BuildingDeedImplementation::_serializationHelperMethod() {
	DeedImplementation::_serializationHelperMethod();

	_setClassName("BuildingDeed");

	addSerializableVariable("surplusMaintenance", &surplusMaintenance);
}

BuildingDeedImplementation::BuildingDeedImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(58):  		Logger.setLoggingName("BuildingDeed");
	Logger::setLoggingName("BuildingDeed");
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(60):  		surplusMaintenance = 0;
	surplusMaintenance = 0;
}

void BuildingDeedImplementation::setSurplusMaintenance(unsigned int surplusMaint) {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(77):  		surplusMaintenance = surplusMaint;
	surplusMaintenance = surplusMaint;
}

unsigned int BuildingDeedImplementation::getSurplusMaintenance() {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(81):  		return surplusMaintenance;
	return surplusMaintenance;
}

bool BuildingDeedImplementation::isBuildingDeed() {
	// server/zone/objects/tangible/deed/building/BuildingDeed.idl(85):  		return true;
	return true;
}

/*
 *	BuildingDeedAdapter
 */

BuildingDeedAdapter::BuildingDeedAdapter(BuildingDeedImplementation* obj) : DeedAdapter(obj) {
}

Packet* BuildingDeedAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 8:
		setSurplusMaintenance(inv->getUnsignedIntParameter());
		break;
	case 9:
		resp->insertInt(getSurplusMaintenance());
		break;
	case 10:
		resp->insertBoolean(isBuildingDeed());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BuildingDeedAdapter::initializeTransientMembers() {
	((BuildingDeedImplementation*) impl)->initializeTransientMembers();
}

int BuildingDeedAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((BuildingDeedImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void BuildingDeedAdapter::setSurplusMaintenance(unsigned int surplusMaint) {
	((BuildingDeedImplementation*) impl)->setSurplusMaintenance(surplusMaint);
}

unsigned int BuildingDeedAdapter::getSurplusMaintenance() {
	return ((BuildingDeedImplementation*) impl)->getSurplusMaintenance();
}

bool BuildingDeedAdapter::isBuildingDeed() {
	return ((BuildingDeedImplementation*) impl)->isBuildingDeed();
}

/*
 *	BuildingDeedHelper
 */

BuildingDeedHelper* BuildingDeedHelper::staticInitializer = BuildingDeedHelper::instance();

BuildingDeedHelper::BuildingDeedHelper() {
	className = "BuildingDeed";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BuildingDeedHelper::finalizeHelper() {
	BuildingDeedHelper::finalize();
}

DistributedObject* BuildingDeedHelper::instantiateObject() {
	return new BuildingDeed(DummyConstructorParameter::instance());
}

DistributedObjectServant* BuildingDeedHelper::instantiateServant() {
	return new BuildingDeedImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BuildingDeedHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BuildingDeedAdapter((BuildingDeedImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

