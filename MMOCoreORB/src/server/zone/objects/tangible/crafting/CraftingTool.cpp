/*
 *	server/zone/objects/tangible/crafting/CraftingTool.cpp generated by engine3 IDL compiler 0.55
 */

#include "CraftingTool.h"

#include "CraftingToolImplementation.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

#include "../../scene/SceneObject.h"

#include "../Container.h"

#include "../../../packets.h"

#include "../../player/Player.h"

#include "../../draftschematic/DraftSchematic.h"

#include "CraftingStation.h"

/*
 *	CraftingToolStub
 */

CraftingTool::CraftingTool(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new CraftingToolImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

CraftingTool::CraftingTool(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new CraftingToolImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

CraftingTool::CraftingTool(DummyConstructorParameter* param) : TangibleObject(param) {
}

CraftingTool::~CraftingTool() {
}

void CraftingTool::sendTo(Player* player, bool doClose) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);
		method.addBooleanParameter(doClose);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->sendTo(player, doClose);
}

void CraftingTool::generateAttributes(SceneObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->generateAttributes(obj);
}

void CraftingTool::resetSlots() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->resetSlots();
}

void CraftingTool::retriveHopperItem(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->retriveHopperItem(player);
}

void CraftingTool::cleanUp(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->cleanUp(player);
}

int CraftingTool::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->useObject(player);
}

void CraftingTool::sendToolStart(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->sendToolStart(player);
}

void CraftingTool::setToolEffectiveness(float eff) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addFloatParameter(eff);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setToolEffectiveness(eff);
}

void CraftingTool::setCraftingState(int s) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addSignedIntParameter(s);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setCraftingState(s);
}

void CraftingTool::setWorkingTano(TangibleObject* tano) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addObjectParameter(tano);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setWorkingTano(tano);
}

void CraftingTool::setWorkingDraftSchematic(DraftSchematic* draftSchematic) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(draftSchematic);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setWorkingDraftSchematic(draftSchematic);
}

void CraftingTool::setInsertCount(int count) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setInsertCount(count);
}

void CraftingTool::setStatusReady() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setStatusReady();
}

void CraftingTool::setStatusWorking() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setStatusWorking();
}

void CraftingTool::setStatusFinished() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setStatusFinished();
}

void CraftingTool::setAssemblyResults(int results) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addSignedIntParameter(results);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setAssemblyResults(results);
}

void CraftingTool::setRecoverResources(bool in) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addBooleanParameter(in);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setRecoverResources(in);
}

void CraftingTool::setToolType(int in) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addSignedIntParameter(in);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->setToolType(in);
}

void CraftingTool::increaseInsertCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->increaseInsertCount();
}

bool CraftingTool::addIngredientToSlot(int slot, TangibleObject* tano) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addSignedIntParameter(slot);
		method.addObjectParameter(tano);

		return method.executeWithBooleanReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->addIngredientToSlot(slot, tano);
}

void CraftingTool::clearIngredientInSlot(int slot) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addSignedIntParameter(slot);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->clearIngredientInSlot(slot);
}

void CraftingTool::addTempIngredient(TangibleObject* tano) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(tano);

		method.executeWithVoidReturn();
	} else
		((CraftingToolImplementation*) _impl)->addTempIngredient(tano);
}

float CraftingTool::getToolEffectiveness() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		return method.executeWithFloatReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getToolEffectiveness();
}

int CraftingTool::getCraftingState() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getCraftingState();
}

TangibleObject* CraftingTool::getWorkingTano() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getWorkingTano();
}

DraftSchematic* CraftingTool::getWorkingDraftSchematic() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);

		return (DraftSchematic*) method.executeWithObjectReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getWorkingDraftSchematic();
}

int CraftingTool::getInsertCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getInsertCount();
}

TangibleObject* CraftingTool::getIngredientInSlot(int slot) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addSignedIntParameter(slot);

		return (TangibleObject*) method.executeWithObjectReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getIngredientInSlot(slot);
}

int CraftingTool::getIngredientInSlotQuantity(int slot) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);
		method.addSignedIntParameter(slot);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getIngredientInSlotQuantity(slot);
}

int CraftingTool::getSlotCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getSlotCount();
}

Container* CraftingTool::getHopper(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);
		method.addObjectParameter(player);

		return (Container*) method.executeWithObjectReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getHopper(player);
}

int CraftingTool::getAssemblyResults() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getAssemblyResults();
}

float CraftingTool::getCraftingToolModifier() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);

		return method.executeWithFloatReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getCraftingToolModifier();
}

int CraftingTool::getToolType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);

		return method.executeWithSignedIntReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getToolType();
}

DraftSchematic* CraftingTool::getCurrentDraftSchematic(int slot) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);
		method.addSignedIntParameter(slot);

		return (DraftSchematic*) method.executeWithObjectReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->getCurrentDraftSchematic(slot);
}

bool CraftingTool::isExperimenting() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);

		return method.executeWithBooleanReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->isExperimenting();
}

bool CraftingTool::isReady() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 42);

		return method.executeWithBooleanReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->isReady();
}

bool CraftingTool::isFinished() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 43);

		return method.executeWithBooleanReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->isFinished();
}

bool CraftingTool::isWorking() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 44);

		return method.executeWithBooleanReturn();
	} else
		return ((CraftingToolImplementation*) _impl)->isWorking();
}

/*
 *	CraftingToolAdapter
 */

CraftingToolAdapter::CraftingToolAdapter(CraftingToolImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* CraftingToolAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 7:
		generateAttributes((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		resetSlots();
		break;
	case 9:
		retriveHopperItem((Player*) inv->getObjectParameter());
		break;
	case 10:
		cleanUp((Player*) inv->getObjectParameter());
		break;
	case 11:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 12:
		sendToolStart((Player*) inv->getObjectParameter());
		break;
	case 13:
		setToolEffectiveness(inv->getFloatParameter());
		break;
	case 14:
		setCraftingState(inv->getSignedIntParameter());
		break;
	case 15:
		setWorkingTano((TangibleObject*) inv->getObjectParameter());
		break;
	case 16:
		setWorkingDraftSchematic((DraftSchematic*) inv->getObjectParameter());
		break;
	case 17:
		setInsertCount(inv->getSignedIntParameter());
		break;
	case 18:
		setStatusReady();
		break;
	case 19:
		setStatusWorking();
		break;
	case 20:
		setStatusFinished();
		break;
	case 21:
		setAssemblyResults(inv->getSignedIntParameter());
		break;
	case 22:
		setRecoverResources(inv->getBooleanParameter());
		break;
	case 23:
		setToolType(inv->getSignedIntParameter());
		break;
	case 24:
		increaseInsertCount();
		break;
	case 25:
		resp->insertBoolean(addIngredientToSlot(inv->getSignedIntParameter(), (TangibleObject*) inv->getObjectParameter()));
		break;
	case 26:
		clearIngredientInSlot(inv->getSignedIntParameter());
		break;
	case 27:
		addTempIngredient((TangibleObject*) inv->getObjectParameter());
		break;
	case 28:
		resp->insertFloat(getToolEffectiveness());
		break;
	case 29:
		resp->insertSignedInt(getCraftingState());
		break;
	case 30:
		resp->insertLong(getWorkingTano()->_getObjectID());
		break;
	case 31:
		resp->insertLong(getWorkingDraftSchematic()->_getObjectID());
		break;
	case 32:
		resp->insertSignedInt(getInsertCount());
		break;
	case 33:
		resp->insertLong(getIngredientInSlot(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 34:
		resp->insertSignedInt(getIngredientInSlotQuantity(inv->getSignedIntParameter()));
		break;
	case 35:
		resp->insertSignedInt(getSlotCount());
		break;
	case 36:
		resp->insertLong(getHopper((Player*) inv->getObjectParameter())->_getObjectID());
		break;
	case 37:
		resp->insertSignedInt(getAssemblyResults());
		break;
	case 38:
		resp->insertFloat(getCraftingToolModifier());
		break;
	case 39:
		resp->insertSignedInt(getToolType());
		break;
	case 40:
		resp->insertLong(getCurrentDraftSchematic(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 41:
		resp->insertBoolean(isExperimenting());
		break;
	case 42:
		resp->insertBoolean(isReady());
		break;
	case 43:
		resp->insertBoolean(isFinished());
		break;
	case 44:
		resp->insertBoolean(isWorking());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CraftingToolAdapter::sendTo(Player* player, bool doClose) {
	return ((CraftingToolImplementation*) impl)->sendTo(player, doClose);
}

void CraftingToolAdapter::generateAttributes(SceneObject* obj) {
	return ((CraftingToolImplementation*) impl)->generateAttributes(obj);
}

void CraftingToolAdapter::resetSlots() {
	return ((CraftingToolImplementation*) impl)->resetSlots();
}

void CraftingToolAdapter::retriveHopperItem(Player* player) {
	return ((CraftingToolImplementation*) impl)->retriveHopperItem(player);
}

void CraftingToolAdapter::cleanUp(Player* player) {
	return ((CraftingToolImplementation*) impl)->cleanUp(player);
}

int CraftingToolAdapter::useObject(Player* player) {
	return ((CraftingToolImplementation*) impl)->useObject(player);
}

void CraftingToolAdapter::sendToolStart(Player* player) {
	return ((CraftingToolImplementation*) impl)->sendToolStart(player);
}

void CraftingToolAdapter::setToolEffectiveness(float eff) {
	return ((CraftingToolImplementation*) impl)->setToolEffectiveness(eff);
}

void CraftingToolAdapter::setCraftingState(int s) {
	return ((CraftingToolImplementation*) impl)->setCraftingState(s);
}

void CraftingToolAdapter::setWorkingTano(TangibleObject* tano) {
	return ((CraftingToolImplementation*) impl)->setWorkingTano(tano);
}

void CraftingToolAdapter::setWorkingDraftSchematic(DraftSchematic* draftSchematic) {
	return ((CraftingToolImplementation*) impl)->setWorkingDraftSchematic(draftSchematic);
}

void CraftingToolAdapter::setInsertCount(int count) {
	return ((CraftingToolImplementation*) impl)->setInsertCount(count);
}

void CraftingToolAdapter::setStatusReady() {
	return ((CraftingToolImplementation*) impl)->setStatusReady();
}

void CraftingToolAdapter::setStatusWorking() {
	return ((CraftingToolImplementation*) impl)->setStatusWorking();
}

void CraftingToolAdapter::setStatusFinished() {
	return ((CraftingToolImplementation*) impl)->setStatusFinished();
}

void CraftingToolAdapter::setAssemblyResults(int results) {
	return ((CraftingToolImplementation*) impl)->setAssemblyResults(results);
}

void CraftingToolAdapter::setRecoverResources(bool in) {
	return ((CraftingToolImplementation*) impl)->setRecoverResources(in);
}

void CraftingToolAdapter::setToolType(int in) {
	return ((CraftingToolImplementation*) impl)->setToolType(in);
}

void CraftingToolAdapter::increaseInsertCount() {
	return ((CraftingToolImplementation*) impl)->increaseInsertCount();
}

bool CraftingToolAdapter::addIngredientToSlot(int slot, TangibleObject* tano) {
	return ((CraftingToolImplementation*) impl)->addIngredientToSlot(slot, tano);
}

void CraftingToolAdapter::clearIngredientInSlot(int slot) {
	return ((CraftingToolImplementation*) impl)->clearIngredientInSlot(slot);
}

void CraftingToolAdapter::addTempIngredient(TangibleObject* tano) {
	return ((CraftingToolImplementation*) impl)->addTempIngredient(tano);
}

float CraftingToolAdapter::getToolEffectiveness() {
	return ((CraftingToolImplementation*) impl)->getToolEffectiveness();
}

int CraftingToolAdapter::getCraftingState() {
	return ((CraftingToolImplementation*) impl)->getCraftingState();
}

TangibleObject* CraftingToolAdapter::getWorkingTano() {
	return ((CraftingToolImplementation*) impl)->getWorkingTano();
}

DraftSchematic* CraftingToolAdapter::getWorkingDraftSchematic() {
	return ((CraftingToolImplementation*) impl)->getWorkingDraftSchematic();
}

int CraftingToolAdapter::getInsertCount() {
	return ((CraftingToolImplementation*) impl)->getInsertCount();
}

TangibleObject* CraftingToolAdapter::getIngredientInSlot(int slot) {
	return ((CraftingToolImplementation*) impl)->getIngredientInSlot(slot);
}

int CraftingToolAdapter::getIngredientInSlotQuantity(int slot) {
	return ((CraftingToolImplementation*) impl)->getIngredientInSlotQuantity(slot);
}

int CraftingToolAdapter::getSlotCount() {
	return ((CraftingToolImplementation*) impl)->getSlotCount();
}

Container* CraftingToolAdapter::getHopper(Player* player) {
	return ((CraftingToolImplementation*) impl)->getHopper(player);
}

int CraftingToolAdapter::getAssemblyResults() {
	return ((CraftingToolImplementation*) impl)->getAssemblyResults();
}

float CraftingToolAdapter::getCraftingToolModifier() {
	return ((CraftingToolImplementation*) impl)->getCraftingToolModifier();
}

int CraftingToolAdapter::getToolType() {
	return ((CraftingToolImplementation*) impl)->getToolType();
}

DraftSchematic* CraftingToolAdapter::getCurrentDraftSchematic(int slot) {
	return ((CraftingToolImplementation*) impl)->getCurrentDraftSchematic(slot);
}

bool CraftingToolAdapter::isExperimenting() {
	return ((CraftingToolImplementation*) impl)->isExperimenting();
}

bool CraftingToolAdapter::isReady() {
	return ((CraftingToolImplementation*) impl)->isReady();
}

bool CraftingToolAdapter::isFinished() {
	return ((CraftingToolImplementation*) impl)->isFinished();
}

bool CraftingToolAdapter::isWorking() {
	return ((CraftingToolImplementation*) impl)->isWorking();
}

/*
 *	CraftingToolHelper
 */

CraftingToolHelper* CraftingToolHelper::staticInitializer = CraftingToolHelper::instance();

CraftingToolHelper::CraftingToolHelper() {
	className = "CraftingTool";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CraftingToolHelper::finalizeHelper() {
	CraftingToolHelper::finalize();
}

DistributedObject* CraftingToolHelper::instantiateObject() {
	return new CraftingTool(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CraftingToolHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CraftingToolAdapter((CraftingToolImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CraftingToolServant
 */

CraftingToolServant::CraftingToolServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int type) : TangibleObjectImplementation(oid, tempCRC, n, tempn, type) {
	_classHelper = CraftingToolHelper::instance();
}

CraftingToolServant::CraftingToolServant(CreatureObject* creature, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int type) : TangibleObjectImplementation(creature, tempCRC, n, tempn, type) {
	_classHelper = CraftingToolHelper::instance();
}

CraftingToolServant::~CraftingToolServant() {
}

void CraftingToolServant::_setStub(DistributedObjectStub* stub) {
	_this = (CraftingTool*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* CraftingToolServant::_getStub() {
	return _this;
}

