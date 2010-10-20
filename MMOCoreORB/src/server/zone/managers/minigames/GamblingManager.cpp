/*
 *	server/zone/managers/minigames/GamblingManager.cpp generated by engine3 IDL compiler 0.61
 */

#include "GamblingManager.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/tangible/terminal/gambling/GamblingTerminal.h"

#include "server/zone/managers/minigames/events/GamblingEvent.h"

/*
 *	GamblingManagerStub
 */

GamblingManager::GamblingManager(ZoneServer* server) : Observer(DummyConstructorParameter::instance()) {
	GamblingManagerImplementation* _implementation = new GamblingManagerImplementation(server);
	_impl = _implementation;
	_impl->_setStub(this);
}

GamblingManager::GamblingManager(DummyConstructorParameter* param) : Observer(param) {
}

GamblingManager::~GamblingManager() {
}


Vector<String>* GamblingManager::getRoulette() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getRoulette();
}

void GamblingManager::initializeSlotTimer() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeSlotTimer();
}

void GamblingManager::initializeRouletteTimer() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeRouletteTimer();
}

void GamblingManager::initializeSlots() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeSlots();
}

void GamblingManager::initializeRouletteRed() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeRouletteRed();
}

void GamblingManager::initializeRoulette() {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeRoulette();
}

int GamblingManager::notify(SceneObject* sceneObject) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(sceneObject);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notify(sceneObject);
}

bool GamblingManager::isHigh(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isHigh(value);
}

bool GamblingManager::isLow(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isLow(value);
}

bool GamblingManager::isEven(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isEven(value);
}

bool GamblingManager::isOdd(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isOdd(value);
}

bool GamblingManager::isBlack(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isBlack(value);
}

bool GamblingManager::isRed(int value) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addSignedIntParameter(value);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRed(value);
}

void GamblingManager::handleSlot(PlayerCreature* player, bool cancel, bool other) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(player);
		method.addBooleanParameter(cancel);
		method.addBooleanParameter(other);

		method.executeWithVoidReturn();
	} else
		_implementation->handleSlot(player, cancel, other);
}

void GamblingManager::bet(PlayerCreature* player, int amount, int target, int machineType) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addObjectParameter(player);
		method.addSignedIntParameter(amount);
		method.addSignedIntParameter(target);
		method.addSignedIntParameter(machineType);

		method.executeWithVoidReturn();
	} else
		_implementation->bet(player, amount, target, machineType);
}

void GamblingManager::bet(GamblingTerminal* terminal, PlayerCreature* player, int amount, int target) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addObjectParameter(terminal);
		method.addObjectParameter(player);
		method.addSignedIntParameter(amount);
		method.addSignedIntParameter(target);

		method.executeWithVoidReturn();
	} else
		_implementation->bet(terminal, player, amount, target);
}

void GamblingManager::startGame(PlayerCreature* player, int machineType) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(player);
		method.addSignedIntParameter(machineType);

		method.executeWithVoidReturn();
	} else
		_implementation->startGame(player, machineType);
}

void GamblingManager::startGame(GamblingTerminal* terminal) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->startGame(terminal);
}

void GamblingManager::leaveTerminal(PlayerCreature* player, int machineType) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addObjectParameter(player);
		method.addSignedIntParameter(machineType);

		method.executeWithVoidReturn();
	} else
		_implementation->leaveTerminal(player, machineType);
}

void GamblingManager::registerPlayer(GamblingTerminal* terminal, PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addObjectParameter(terminal);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->registerPlayer(terminal, player);
}

void GamblingManager::refreshRouletteMenu(PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->refreshRouletteMenu(player);
}

void GamblingManager::continueGame(GamblingTerminal* terminal) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->continueGame(terminal);
}

void GamblingManager::stopGame(GamblingTerminal* terminal, bool cancel) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(terminal);
		method.addBooleanParameter(cancel);

		method.executeWithVoidReturn();
	} else
		_implementation->stopGame(terminal, cancel);
}

void GamblingManager::calculateOutcome(GamblingTerminal* terminal) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->calculateOutcome(terminal);
}

unsigned int GamblingManager::createWindow(GamblingTerminal* terminal, PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addObjectParameter(terminal);
		method.addObjectParameter(player);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->createWindow(terminal, player);
}

unsigned int GamblingManager::createPayoutWindow(PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addObjectParameter(player);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->createPayoutWindow(player);
}

unsigned int GamblingManager::createSlotWindow(PlayerCreature* player, unsigned int payoutBoxID) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(payoutBoxID);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->createSlotWindow(player, payoutBoxID);
}

unsigned int GamblingManager::createRouletteWindow(PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addObjectParameter(player);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->createRouletteWindow(player);
}

void GamblingManager::createEvent(GamblingTerminal* terminal, int time) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addObjectParameter(terminal);
		method.addSignedIntParameter(time);

		method.executeWithVoidReturn();
	} else
		_implementation->createEvent(terminal, time);
}

bool GamblingManager::isPlaying(PlayerCreature* player) {
	GamblingManagerImplementation* _implementation = (GamblingManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isPlaying(player);
}

DistributedObjectServant* GamblingManager::_getImplementation() {
	return _impl;}

void GamblingManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	GamblingManagerImplementation
 */

GamblingManagerImplementation::GamblingManagerImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


GamblingManagerImplementation::~GamblingManagerImplementation() {
}


void GamblingManagerImplementation::finalize() {
}

void GamblingManagerImplementation::_initializeImplementation() {
	_setClassHelper(GamblingManagerHelper::instance());

	_serializationHelperMethod();
}

void GamblingManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GamblingManager*) stub;
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* GamblingManagerImplementation::_getStub() {
	return _this;
}

GamblingManagerImplementation::operator const GamblingManager*() {
	return _this;
}

void GamblingManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GamblingManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GamblingManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GamblingManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GamblingManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GamblingManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GamblingManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GamblingManagerImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("GamblingManager");

	addSerializableVariable("zoneServer", &zoneServer);
	addSerializableVariable("slotGames", &slotGames);
	addSerializableVariable("rouletteGames", &rouletteGames);
	addSerializableVariable("roulette", &roulette);
	addSerializableVariable("red", &red);
	addSerializableVariable("slot", &slot);
	addSerializableVariable("slotTimer", &slotTimer);
	addSerializableVariable("rouletteTimer", &rouletteTimer);
}

GamblingManagerImplementation::GamblingManagerImplementation(ZoneServer* server) {
	_initializeImplementation();
	// server/zone/managers/minigames/GamblingManager.idl(91):  		zoneServer = server;
	zoneServer = server;
	// server/zone/managers/minigames/GamblingManager.idl(93):  		initializeRoulette();
	initializeRoulette();
	// server/zone/managers/minigames/GamblingManager.idl(94):  		initializeRouletteRed();
	initializeRouletteRed();
	// server/zone/managers/minigames/GamblingManager.idl(95):  		initializeSlots();
	initializeSlots();
	// server/zone/managers/minigames/GamblingManager.idl(97):  		initializeSlotTimer();
	initializeSlotTimer();
	// server/zone/managers/minigames/GamblingManager.idl(99):  		initializeRouletteTimer();
	initializeRouletteTimer();
	// server/zone/managers/minigames/GamblingManager.idl(101):  		Logger.setLoggingName("GamblingManager");
	Logger::setLoggingName("GamblingManager");
	// server/zone/managers/minigames/GamblingManager.idl(102):  		Logger.setLogging(true);
	Logger::setLogging(true);
}

Vector<String>* GamblingManagerImplementation::getRoulette() {
	// server/zone/managers/minigames/GamblingManager.idl(107):  		return roulette;
	return (&roulette);
}

void GamblingManagerImplementation::initializeSlotTimer() {
	// server/zone/managers/minigames/GamblingManager.idl(111):  		slotTimer.add(6);
	(&slotTimer)->add(6);
	// server/zone/managers/minigames/GamblingManager.idl(112):  		slotTimer.add(4);
	(&slotTimer)->add(4);
	// server/zone/managers/minigames/GamblingManager.idl(113):  		slotTimer.add(4);
	(&slotTimer)->add(4);
	// server/zone/managers/minigames/GamblingManager.idl(114):  		slotTimer.add(4);
	(&slotTimer)->add(4);
	// server/zone/managers/minigames/GamblingManager.idl(115):  		slotTimer.add(1);
	(&slotTimer)->add(1);
	// server/zone/managers/minigames/GamblingManager.idl(116):  		slotTimer.add(1);
	(&slotTimer)->add(1);
}

void GamblingManagerImplementation::initializeRouletteTimer() {
	// server/zone/managers/minigames/GamblingManager.idl(120):  		rouletteTimer.add(30);
	(&rouletteTimer)->add(30);
	// server/zone/managers/minigames/GamblingManager.idl(121):  		rouletteTimer.add(30);
	(&rouletteTimer)->add(30);
	// server/zone/managers/minigames/GamblingManager.idl(122):  		rouletteTimer.add(30);
	(&rouletteTimer)->add(30);
	// server/zone/managers/minigames/GamblingManager.idl(123):  		rouletteTimer.add(10);
	(&rouletteTimer)->add(10);
	// server/zone/managers/minigames/GamblingManager.idl(124):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(125):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(126):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(127):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(128):  		rouletteTimer.add(10);
	(&rouletteTimer)->add(10);
	// server/zone/managers/minigames/GamblingManager.idl(129):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(130):  		rouletteTimer.add(5);
	(&rouletteTimer)->add(5);
	// server/zone/managers/minigames/GamblingManager.idl(131):  		rouletteTimer.add(2);
	(&rouletteTimer)->add(2);
}

void GamblingManagerImplementation::initializeSlots() {
	// server/zone/managers/minigames/GamblingManager.idl(135):  		slot.add(4);
	(&slot)->add(4);
	// server/zone/managers/minigames/GamblingManager.idl(136):  		slot.add(50);
	(&slot)->add(50);
	// server/zone/managers/minigames/GamblingManager.idl(137):  		slot.add(75);
	(&slot)->add(75);
	// server/zone/managers/minigames/GamblingManager.idl(138):  		slot.add(100);
	(&slot)->add(100);
	// server/zone/managers/minigames/GamblingManager.idl(139):  		slot.add(250);
	(&slot)->add(250);
	// server/zone/managers/minigames/GamblingManager.idl(140):  		slot.add(500);
	(&slot)->add(500);
	// server/zone/managers/minigames/GamblingManager.idl(141):  		slot.add(1000);
	(&slot)->add(1000);
	// server/zone/managers/minigames/GamblingManager.idl(142):  		slot.add(1500);
	(&slot)->add(1500);
}

void GamblingManagerImplementation::initializeRouletteRed() {
	// server/zone/managers/minigames/GamblingManager.idl(146):  		red.add("1");
	(&red)->add("1");
	// server/zone/managers/minigames/GamblingManager.idl(147):  		red.add("3");
	(&red)->add("3");
	// server/zone/managers/minigames/GamblingManager.idl(148):  		red.add("5");
	(&red)->add("5");
	// server/zone/managers/minigames/GamblingManager.idl(149):  		red.add("7");
	(&red)->add("7");
	// server/zone/managers/minigames/GamblingManager.idl(150):  		red.add("9");
	(&red)->add("9");
	// server/zone/managers/minigames/GamblingManager.idl(151):  		red.add("12");
	(&red)->add("12");
	// server/zone/managers/minigames/GamblingManager.idl(152):  		red.add("14");
	(&red)->add("14");
	// server/zone/managers/minigames/GamblingManager.idl(153):  		red.add("16");
	(&red)->add("16");
	// server/zone/managers/minigames/GamblingManager.idl(154):  		red.add("18");
	(&red)->add("18");
	// server/zone/managers/minigames/GamblingManager.idl(155):  		red.add("19");
	(&red)->add("19");
	// server/zone/managers/minigames/GamblingManager.idl(156):  		red.add("21");
	(&red)->add("21");
	// server/zone/managers/minigames/GamblingManager.idl(157):  		red.add("23");
	(&red)->add("23");
	// server/zone/managers/minigames/GamblingManager.idl(158):  		red.add("25");
	(&red)->add("25");
	// server/zone/managers/minigames/GamblingManager.idl(159):  		red.add("27");
	(&red)->add("27");
	// server/zone/managers/minigames/GamblingManager.idl(160):  		red.add("30");
	(&red)->add("30");
	// server/zone/managers/minigames/GamblingManager.idl(161):  		red.add("32");
	(&red)->add("32");
	// server/zone/managers/minigames/GamblingManager.idl(162):  		red.add("34");
	(&red)->add("34");
	// server/zone/managers/minigames/GamblingManager.idl(163):  		red.add("36");
	(&red)->add("36");
}

void GamblingManagerImplementation::initializeRoulette() {
	// server/zone/managers/minigames/GamblingManager.idl(167):  		roulette.add("0");
	(&roulette)->add("0");
	// server/zone/managers/minigames/GamblingManager.idl(168):  		roulette.add("1");
	(&roulette)->add("1");
	// server/zone/managers/minigames/GamblingManager.idl(169):  		roulette.add("2");
	(&roulette)->add("2");
	// server/zone/managers/minigames/GamblingManager.idl(170):  		roulette.add("3");
	(&roulette)->add("3");
	// server/zone/managers/minigames/GamblingManager.idl(171):  		roulette.add("4");
	(&roulette)->add("4");
	// server/zone/managers/minigames/GamblingManager.idl(172):  		roulette.add("5");
	(&roulette)->add("5");
	// server/zone/managers/minigames/GamblingManager.idl(173):  		roulette.add("6");
	(&roulette)->add("6");
	// server/zone/managers/minigames/GamblingManager.idl(174):  		roulette.add("7");
	(&roulette)->add("7");
	// server/zone/managers/minigames/GamblingManager.idl(175):  		roulette.add("8");
	(&roulette)->add("8");
	// server/zone/managers/minigames/GamblingManager.idl(176):  		roulette.add("9");
	(&roulette)->add("9");
	// server/zone/managers/minigames/GamblingManager.idl(177):  		roulette.add("10");
	(&roulette)->add("10");
	// server/zone/managers/minigames/GamblingManager.idl(178):  		roulette.add("11");
	(&roulette)->add("11");
	// server/zone/managers/minigames/GamblingManager.idl(179):  		roulette.add("12");
	(&roulette)->add("12");
	// server/zone/managers/minigames/GamblingManager.idl(180):  		roulette.add("13");
	(&roulette)->add("13");
	// server/zone/managers/minigames/GamblingManager.idl(181):  		roulette.add("14");
	(&roulette)->add("14");
	// server/zone/managers/minigames/GamblingManager.idl(182):  		roulette.add("15");
	(&roulette)->add("15");
	// server/zone/managers/minigames/GamblingManager.idl(183):  		roulette.add("16");
	(&roulette)->add("16");
	// server/zone/managers/minigames/GamblingManager.idl(184):  		roulette.add("17");
	(&roulette)->add("17");
	// server/zone/managers/minigames/GamblingManager.idl(185):  		roulette.add("18");
	(&roulette)->add("18");
	// server/zone/managers/minigames/GamblingManager.idl(186):  		roulette.add("19");
	(&roulette)->add("19");
	// server/zone/managers/minigames/GamblingManager.idl(187):  		roulette.add("20");
	(&roulette)->add("20");
	// server/zone/managers/minigames/GamblingManager.idl(188):  		roulette.add("21");
	(&roulette)->add("21");
	// server/zone/managers/minigames/GamblingManager.idl(189):  		roulette.add("22");
	(&roulette)->add("22");
	// server/zone/managers/minigames/GamblingManager.idl(190):  		roulette.add("23");
	(&roulette)->add("23");
	// server/zone/managers/minigames/GamblingManager.idl(191):  		roulette.add("24");
	(&roulette)->add("24");
	// server/zone/managers/minigames/GamblingManager.idl(192):  		roulette.add("25");
	(&roulette)->add("25");
	// server/zone/managers/minigames/GamblingManager.idl(193):  		roulette.add("26");
	(&roulette)->add("26");
	// server/zone/managers/minigames/GamblingManager.idl(194):  		roulette.add("27");
	(&roulette)->add("27");
	// server/zone/managers/minigames/GamblingManager.idl(195):  		roulette.add("28");
	(&roulette)->add("28");
	// server/zone/managers/minigames/GamblingManager.idl(196):  		roulette.add("29");
	(&roulette)->add("29");
	// server/zone/managers/minigames/GamblingManager.idl(197):  		roulette.add("30");
	(&roulette)->add("30");
	// server/zone/managers/minigames/GamblingManager.idl(198):  		roulette.add("31");
	(&roulette)->add("31");
	// server/zone/managers/minigames/GamblingManager.idl(199):  		roulette.add("32");
	(&roulette)->add("32");
	// server/zone/managers/minigames/GamblingManager.idl(200):  		roulette.add("33");
	(&roulette)->add("33");
	// server/zone/managers/minigames/GamblingManager.idl(201):  		roulette.add("34");
	(&roulette)->add("34");
	// server/zone/managers/minigames/GamblingManager.idl(202):  		roulette.add("35");
	(&roulette)->add("35");
	// server/zone/managers/minigames/GamblingManager.idl(203):  		roulette.add("36");
	(&roulette)->add("36");
	// server/zone/managers/minigames/GamblingManager.idl(204):  		roulette.add("00");
	(&roulette)->add("00");
	// server/zone/managers/minigames/GamblingManager.idl(205):  		roulette.add("odd");
	(&roulette)->add("odd");
	// server/zone/managers/minigames/GamblingManager.idl(206):  		roulette.add("even");
	(&roulette)->add("even");
	// server/zone/managers/minigames/GamblingManager.idl(207):  		roulette.add("high");
	(&roulette)->add("high");
	// server/zone/managers/minigames/GamblingManager.idl(208):  		roulette.add("low");
	(&roulette)->add("low");
	// server/zone/managers/minigames/GamblingManager.idl(209):  		roulette.add("red");
	(&roulette)->add("red");
	// server/zone/managers/minigames/GamblingManager.idl(210):  		roulette.add("black");
	(&roulette)->add("black");
}

int GamblingManagerImplementation::notify(SceneObject* sceneObject) {
	// server/zone/managers/minigames/GamblingManager.idl(214):  		return 
	if (sceneObject->isPlayerCreature())	// server/zone/managers/minigames/GamblingManager.idl(215):  			return 1;
	return 1;
	// server/zone/managers/minigames/GamblingManager.idl(217):  0;
	return 0;
}

bool GamblingManagerImplementation::isHigh(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(221):  		return 
	if ((value > 18) && (value != 37))	// server/zone/managers/minigames/GamblingManager.idl(222):  			return true;
	return true;
	// server/zone/managers/minigames/GamblingManager.idl(223):  false;
	return false;
}

bool GamblingManagerImplementation::isLow(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(227):  		return 
	if ((value > 0) && (value < 19))	// server/zone/managers/minigames/GamblingManager.idl(228):  			return true;
	return true;
	// server/zone/managers/minigames/GamblingManager.idl(229):  false;
	return false;
}

bool GamblingManagerImplementation::isEven(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(233):  		if 
	if ((value == 0) || (value == 37))	// server/zone/managers/minigames/GamblingManager.idl(234):  			return false;
	return false;
	// server/zone/managers/minigames/GamblingManager.idl(235):  		return 
	if ((value % 2) == 0)	// server/zone/managers/minigames/GamblingManager.idl(236):  			return true;
	return true;
	// server/zone/managers/minigames/GamblingManager.idl(237):  false;
	return false;
}

bool GamblingManagerImplementation::isOdd(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(241):  		if 
	if ((value == 0) || (value == 37))	// server/zone/managers/minigames/GamblingManager.idl(242):  			return false;
	return false;
	// server/zone/managers/minigames/GamblingManager.idl(243):  		return 
	if ((value % 2) == 1)	// server/zone/managers/minigames/GamblingManager.idl(244):  			return true;
	return true;
	// server/zone/managers/minigames/GamblingManager.idl(245):  false;
	return false;
}

bool GamblingManagerImplementation::isBlack(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(249):  		if 
	if ((&roulette)->get(value) == "0" || (&roulette)->get(value) == "00")	// server/zone/managers/minigames/GamblingManager.idl(250):  			return false;
	return false;
	// server/zone/managers/minigames/GamblingManager.idl(251):  		return 
	if (isRed(value))	// server/zone/managers/minigames/GamblingManager.idl(252):  			return false;
	return false;
	// server/zone/managers/minigames/GamblingManager.idl(253):  true;
	return true;
}

bool GamblingManagerImplementation::isRed(int value) {
	// server/zone/managers/minigames/GamblingManager.idl(257):  		for 
	if ((&roulette)->get(value) == "0" || (&roulette)->get(value) == "00")	// server/zone/managers/minigames/GamblingManager.idl(258):  			return false;
	return false;
	// server/zone/managers/minigames/GamblingManager.idl(259):  
	for (	// server/zone/managers/minigames/GamblingManager.idl(259):  (int i = 0;
	int i = 0;
	i < (&red)->size();
 ++i) {
	// server/zone/managers/minigames/GamblingManager.idl(260):  		}
	if ((&red)->get(i) == (&roulette)->get(value)){
	// server/zone/managers/minigames/GamblingManager.idl(261):  				return true;
	return true;
}
}
	// server/zone/managers/minigames/GamblingManager.idl(264):  		return false;
	return false;
}

bool GamblingManagerImplementation::isPlaying(PlayerCreature* player) {
	// server/zone/managers/minigames/GamblingManager.idl(430):  		return (slotGames.contains(player) || rouletteGames.contains(player));
	return ((&slotGames)->contains(player) || (&rouletteGames)->contains(player));
}

/*
 *	GamblingManagerAdapter
 */

GamblingManagerAdapter::GamblingManagerAdapter(GamblingManagerImplementation* obj) : ObserverAdapter(obj) {
}

Packet* GamblingManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeSlotTimer();
		break;
	case 7:
		initializeRouletteTimer();
		break;
	case 8:
		initializeSlots();
		break;
	case 9:
		initializeRouletteRed();
		break;
	case 10:
		initializeRoulette();
		break;
	case 11:
		resp->insertSignedInt(notify((SceneObject*) inv->getObjectParameter()));
		break;
	case 12:
		resp->insertBoolean(isHigh(inv->getSignedIntParameter()));
		break;
	case 13:
		resp->insertBoolean(isLow(inv->getSignedIntParameter()));
		break;
	case 14:
		resp->insertBoolean(isEven(inv->getSignedIntParameter()));
		break;
	case 15:
		resp->insertBoolean(isOdd(inv->getSignedIntParameter()));
		break;
	case 16:
		resp->insertBoolean(isBlack(inv->getSignedIntParameter()));
		break;
	case 17:
		resp->insertBoolean(isRed(inv->getSignedIntParameter()));
		break;
	case 18:
		handleSlot((PlayerCreature*) inv->getObjectParameter(), inv->getBooleanParameter(), inv->getBooleanParameter());
		break;
	case 19:
		bet((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 20:
		bet((GamblingTerminal*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 21:
		startGame((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 22:
		startGame((GamblingTerminal*) inv->getObjectParameter());
		break;
	case 23:
		leaveTerminal((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 24:
		registerPlayer((GamblingTerminal*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case 25:
		refreshRouletteMenu((PlayerCreature*) inv->getObjectParameter());
		break;
	case 26:
		continueGame((GamblingTerminal*) inv->getObjectParameter());
		break;
	case 27:
		stopGame((GamblingTerminal*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 28:
		calculateOutcome((GamblingTerminal*) inv->getObjectParameter());
		break;
	case 29:
		resp->insertInt(createWindow((GamblingTerminal*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter()));
		break;
	case 30:
		resp->insertInt(createPayoutWindow((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 31:
		resp->insertInt(createSlotWindow((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedIntParameter()));
		break;
	case 32:
		resp->insertInt(createRouletteWindow((PlayerCreature*) inv->getObjectParameter()));
		break;
	case 33:
		createEvent((GamblingTerminal*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 34:
		resp->insertBoolean(isPlaying((PlayerCreature*) inv->getObjectParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void GamblingManagerAdapter::initializeSlotTimer() {
	((GamblingManagerImplementation*) impl)->initializeSlotTimer();
}

void GamblingManagerAdapter::initializeRouletteTimer() {
	((GamblingManagerImplementation*) impl)->initializeRouletteTimer();
}

void GamblingManagerAdapter::initializeSlots() {
	((GamblingManagerImplementation*) impl)->initializeSlots();
}

void GamblingManagerAdapter::initializeRouletteRed() {
	((GamblingManagerImplementation*) impl)->initializeRouletteRed();
}

void GamblingManagerAdapter::initializeRoulette() {
	((GamblingManagerImplementation*) impl)->initializeRoulette();
}

int GamblingManagerAdapter::notify(SceneObject* sceneObject) {
	return ((GamblingManagerImplementation*) impl)->notify(sceneObject);
}

bool GamblingManagerAdapter::isHigh(int value) {
	return ((GamblingManagerImplementation*) impl)->isHigh(value);
}

bool GamblingManagerAdapter::isLow(int value) {
	return ((GamblingManagerImplementation*) impl)->isLow(value);
}

bool GamblingManagerAdapter::isEven(int value) {
	return ((GamblingManagerImplementation*) impl)->isEven(value);
}

bool GamblingManagerAdapter::isOdd(int value) {
	return ((GamblingManagerImplementation*) impl)->isOdd(value);
}

bool GamblingManagerAdapter::isBlack(int value) {
	return ((GamblingManagerImplementation*) impl)->isBlack(value);
}

bool GamblingManagerAdapter::isRed(int value) {
	return ((GamblingManagerImplementation*) impl)->isRed(value);
}

void GamblingManagerAdapter::handleSlot(PlayerCreature* player, bool cancel, bool other) {
	((GamblingManagerImplementation*) impl)->handleSlot(player, cancel, other);
}

void GamblingManagerAdapter::bet(PlayerCreature* player, int amount, int target, int machineType) {
	((GamblingManagerImplementation*) impl)->bet(player, amount, target, machineType);
}

void GamblingManagerAdapter::bet(GamblingTerminal* terminal, PlayerCreature* player, int amount, int target) {
	((GamblingManagerImplementation*) impl)->bet(terminal, player, amount, target);
}

void GamblingManagerAdapter::startGame(PlayerCreature* player, int machineType) {
	((GamblingManagerImplementation*) impl)->startGame(player, machineType);
}

void GamblingManagerAdapter::startGame(GamblingTerminal* terminal) {
	((GamblingManagerImplementation*) impl)->startGame(terminal);
}

void GamblingManagerAdapter::leaveTerminal(PlayerCreature* player, int machineType) {
	((GamblingManagerImplementation*) impl)->leaveTerminal(player, machineType);
}

void GamblingManagerAdapter::registerPlayer(GamblingTerminal* terminal, PlayerCreature* player) {
	((GamblingManagerImplementation*) impl)->registerPlayer(terminal, player);
}

void GamblingManagerAdapter::refreshRouletteMenu(PlayerCreature* player) {
	((GamblingManagerImplementation*) impl)->refreshRouletteMenu(player);
}

void GamblingManagerAdapter::continueGame(GamblingTerminal* terminal) {
	((GamblingManagerImplementation*) impl)->continueGame(terminal);
}

void GamblingManagerAdapter::stopGame(GamblingTerminal* terminal, bool cancel) {
	((GamblingManagerImplementation*) impl)->stopGame(terminal, cancel);
}

void GamblingManagerAdapter::calculateOutcome(GamblingTerminal* terminal) {
	((GamblingManagerImplementation*) impl)->calculateOutcome(terminal);
}

unsigned int GamblingManagerAdapter::createWindow(GamblingTerminal* terminal, PlayerCreature* player) {
	return ((GamblingManagerImplementation*) impl)->createWindow(terminal, player);
}

unsigned int GamblingManagerAdapter::createPayoutWindow(PlayerCreature* player) {
	return ((GamblingManagerImplementation*) impl)->createPayoutWindow(player);
}

unsigned int GamblingManagerAdapter::createSlotWindow(PlayerCreature* player, unsigned int payoutBoxID) {
	return ((GamblingManagerImplementation*) impl)->createSlotWindow(player, payoutBoxID);
}

unsigned int GamblingManagerAdapter::createRouletteWindow(PlayerCreature* player) {
	return ((GamblingManagerImplementation*) impl)->createRouletteWindow(player);
}

void GamblingManagerAdapter::createEvent(GamblingTerminal* terminal, int time) {
	((GamblingManagerImplementation*) impl)->createEvent(terminal, time);
}

bool GamblingManagerAdapter::isPlaying(PlayerCreature* player) {
	return ((GamblingManagerImplementation*) impl)->isPlaying(player);
}

/*
 *	GamblingManagerHelper
 */

GamblingManagerHelper* GamblingManagerHelper::staticInitializer = GamblingManagerHelper::instance();

GamblingManagerHelper::GamblingManagerHelper() {
	className = "GamblingManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GamblingManagerHelper::finalizeHelper() {
	GamblingManagerHelper::finalize();
}

DistributedObject* GamblingManagerHelper::instantiateObject() {
	return new GamblingManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* GamblingManagerHelper::instantiateServant() {
	return new GamblingManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GamblingManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GamblingManagerAdapter((GamblingManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

