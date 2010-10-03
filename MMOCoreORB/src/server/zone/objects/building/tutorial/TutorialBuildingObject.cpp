/*
 *	server/zone/objects/building/tutorial/TutorialBuildingObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "TutorialBuildingObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/building/tutorial/events/UnloadBuildingTask.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/cell/CellObject.h"


// Imported class dependencies

#include "system/lang/Time.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "engine/util/QuadTree.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/structure/StructurePermissionList.h"

#include "engine/util/Quaternion.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/structure/events/StructureMaintenanceTask.h"

#include "server/zone/objects/tangible/terminal/structure/StructureTerminal.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/util/SortedVector.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

/*
 *	TutorialBuildingObjectStub
 */

TutorialBuildingObject::TutorialBuildingObject() : BuildingObject(DummyConstructorParameter::instance()) {
	TutorialBuildingObjectImplementation* _implementation = new TutorialBuildingObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

TutorialBuildingObject::TutorialBuildingObject(DummyConstructorParameter* param) : BuildingObject(param) {
}

TutorialBuildingObject::~TutorialBuildingObject() {
}


void TutorialBuildingObject::removeFromZone() {
	TutorialBuildingObjectImplementation* _implementation = (TutorialBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->removeFromZone();
}

void TutorialBuildingObject::initializeTransientMembers() {
	TutorialBuildingObjectImplementation* _implementation = (TutorialBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void TutorialBuildingObject::onEnter(PlayerCreature* player) {
	TutorialBuildingObjectImplementation* _implementation = (TutorialBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->onEnter(player);
}

void TutorialBuildingObject::onExit(PlayerCreature* player) {
	TutorialBuildingObjectImplementation* _implementation = (TutorialBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->onExit(player);
}

void TutorialBuildingObject::clearUnloadEvent() {
	TutorialBuildingObjectImplementation* _implementation = (TutorialBuildingObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		_implementation->clearUnloadEvent();
}

DistributedObjectServant* TutorialBuildingObject::_getImplementation() {
	return getForUpdate();}

void TutorialBuildingObject::_setImplementation(DistributedObjectServant* servant) {
	setObject((ManagedObjectImplementation*) servant);}

/*
 *	TutorialBuildingObjectImplementation
 */

TutorialBuildingObjectImplementation::TutorialBuildingObjectImplementation(DummyConstructorParameter* param) : BuildingObjectImplementation(param) {
	_initializeImplementation();
}


TutorialBuildingObjectImplementation::~TutorialBuildingObjectImplementation() {
}


void TutorialBuildingObjectImplementation::finalize() {
}

void TutorialBuildingObjectImplementation::_initializeImplementation() {
	_setClassHelper(TutorialBuildingObjectHelper::instance());

	_serializationHelperMethod();
}

void TutorialBuildingObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (TutorialBuildingObject*) stub;
	BuildingObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TutorialBuildingObjectImplementation::_getStub() {
	return _this;
}

TutorialBuildingObjectImplementation::operator const TutorialBuildingObject*() {
	return _this;
}

TransactionalObject* TutorialBuildingObjectImplementation::clone() {
	return (TransactionalObject*) new TutorialBuildingObjectImplementation(*this);
}


void TutorialBuildingObjectImplementation::lock(bool doLock) {
}

void TutorialBuildingObjectImplementation::lock(ManagedObject* obj) {
}

void TutorialBuildingObjectImplementation::rlock(bool doLock) {
}

void TutorialBuildingObjectImplementation::wlock(bool doLock) {
}

void TutorialBuildingObjectImplementation::wlock(ManagedObject* obj) {
}

void TutorialBuildingObjectImplementation::unlock(bool doLock) {
}

void TutorialBuildingObjectImplementation::runlock(bool doLock) {
}

void TutorialBuildingObjectImplementation::_serializationHelperMethod() {
	BuildingObjectImplementation::_serializationHelperMethod();

	_setClassName("TutorialBuildingObject");

}

TutorialBuildingObjectImplementation::TutorialBuildingObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(59):  		initializeTransientMembers();
	initializeTransientMembers();
}

void TutorialBuildingObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(65):  		super.initializeTransientMembers();
	BuildingObjectImplementation::initializeTransientMembers();
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(67):  		unloadTask = null;
	unloadTask = NULL;
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(69):  		Logger.setLoggingName("TutorialBuildingObject");
	Logger::setLoggingName("TutorialBuildingObject");
}

void TutorialBuildingObjectImplementation::onEnter(PlayerCreature* player) {
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(73):  		dequeueUnloadEvent();
	dequeueUnloadEvent();
}

void TutorialBuildingObjectImplementation::onExit(PlayerCreature* player) {
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(77):  		enqueueUnloadEvent();
	enqueueUnloadEvent();
}

void TutorialBuildingObjectImplementation::clearUnloadEvent() {
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(81):  		unloadTask = null;
	unloadTask = NULL;
}

void TutorialBuildingObjectImplementation::dequeueUnloadEvent() {
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(85):  	}
	if (unloadTask){
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(86):  			unloadTask.cancel();
	unloadTask->cancel();
	// server/zone/objects/building/tutorial/TutorialBuildingObject.idl(87):  			clearUnloadEvent();
	clearUnloadEvent();
}
}

/*
 *	TutorialBuildingObjectAdapter
 */

TutorialBuildingObjectAdapter::TutorialBuildingObjectAdapter(TutorialBuildingObjectImplementation* obj) : BuildingObjectAdapter(obj) {
}

Packet* TutorialBuildingObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		removeFromZone();
		break;
	case 7:
		initializeTransientMembers();
		break;
	case 8:
		onEnter((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		onExit((PlayerCreature*) inv->getObjectParameter());
		break;
	case 10:
		clearUnloadEvent();
		break;
	default:
		return NULL;
	}

	return resp;
}

void TutorialBuildingObjectAdapter::removeFromZone() {
	((TutorialBuildingObjectImplementation*) impl)->removeFromZone();
}

void TutorialBuildingObjectAdapter::initializeTransientMembers() {
	((TutorialBuildingObjectImplementation*) impl)->initializeTransientMembers();
}

void TutorialBuildingObjectAdapter::onEnter(PlayerCreature* player) {
	((TutorialBuildingObjectImplementation*) impl)->onEnter(player);
}

void TutorialBuildingObjectAdapter::onExit(PlayerCreature* player) {
	((TutorialBuildingObjectImplementation*) impl)->onExit(player);
}

void TutorialBuildingObjectAdapter::clearUnloadEvent() {
	((TutorialBuildingObjectImplementation*) impl)->clearUnloadEvent();
}

/*
 *	TutorialBuildingObjectHelper
 */

TutorialBuildingObjectHelper* TutorialBuildingObjectHelper::staticInitializer = TutorialBuildingObjectHelper::instance();

TutorialBuildingObjectHelper::TutorialBuildingObjectHelper() {
	className = "TutorialBuildingObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void TutorialBuildingObjectHelper::finalizeHelper() {
	TutorialBuildingObjectHelper::finalize();
}

DistributedObject* TutorialBuildingObjectHelper::instantiateObject() {
	return new TutorialBuildingObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* TutorialBuildingObjectHelper::instantiateServant() {
	return new TutorialBuildingObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TutorialBuildingObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TutorialBuildingObjectAdapter((TutorialBuildingObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

