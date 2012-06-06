/*
 *	server/zone/objects/player/sessions/survey/SurveySession.cpp generated by engine3 IDL compiler 0.60
 */

#include "SurveySession.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/PlayerObject.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/resource/ResourceManager.h"

/*
 *	SurveySessionStub
 */

enum {RPC_INITIALIZESESSION__SURVEYTOOL_ = 6,RPC_CANCELSESSION__,RPC_CLEARSESSION__,RPC_STARTSURVEY__STRING_,RPC_RESAMPLE__,RPC_STARTSAMPLE__STRING_,RPC_SURVEYCNODEMINIGAME__INT_,RPC_SURVEYGNODEMINIGAME__INT_,RPC_GETACTIVESURVEYTOOL__,RPC_SETACTIVESURVEYTOOL__SURVEYTOOL_,RPC_GETOPENSURVEYTOOL__,RPC_SETOPENSURVEYTOOL__SURVEYTOOL_,RPC_TRYGAMBLE__,RPC_CLEARGAMBLE__,RPC_CLEARRICHSAMPLELOCATION__};

SurveySession::SurveySession(CreatureObject* creature) : Facade(DummyConstructorParameter::instance()) {
	SurveySessionImplementation* _implementation = new SurveySessionImplementation(creature);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("SurveySession");
}

SurveySession::SurveySession(DummyConstructorParameter* param) : Facade(param) {
	_setClassName("SurveySession");
}

SurveySession::~SurveySession() {
}



int SurveySession::initializeSession(SurveyTool* tool) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__SURVEYTOOL_);
		method.addObjectParameter(tool);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession(tool);
}

int SurveySession::cancelSession() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int SurveySession::clearSession() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

void SurveySession::startSurvey(const String& resname) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_STARTSURVEY__STRING_);
		method.addAsciiParameter(resname);

		method.executeWithVoidReturn();
	} else
		_implementation->startSurvey(resname);
}

void SurveySession::reSample() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RESAMPLE__);

		method.executeWithVoidReturn();
	} else
		_implementation->reSample();
}

void SurveySession::startSample(const String& resname) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_STARTSAMPLE__STRING_);
		method.addAsciiParameter(resname);

		method.executeWithVoidReturn();
	} else
		_implementation->startSample(resname);
}

void SurveySession::surveyCnodeMinigame(int value) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SURVEYCNODEMINIGAME__INT_);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->surveyCnodeMinigame(value);
}

void SurveySession::surveyGnodeMinigame(int value) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SURVEYGNODEMINIGAME__INT_);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->surveyGnodeMinigame(value);
}

ManagedWeakReference<SurveyTool* > SurveySession::getActiveSurveyTool() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETACTIVESURVEYTOOL__);

		return static_cast<SurveyTool*>(method.executeWithObjectReturn());
	} else
		return _implementation->getActiveSurveyTool();
}

void SurveySession::setActiveSurveyTool(SurveyTool* tool) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETACTIVESURVEYTOOL__SURVEYTOOL_);
		method.addObjectParameter(tool);

		method.executeWithVoidReturn();
	} else
		_implementation->setActiveSurveyTool(tool);
}

ManagedWeakReference<SurveyTool* > SurveySession::getOpenSurveyTool() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETOPENSURVEYTOOL__);

		return static_cast<SurveyTool*>(method.executeWithObjectReturn());
	} else
		return _implementation->getOpenSurveyTool();
}

void SurveySession::setOpenSurveyTool(SurveyTool* tool) {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETOPENSURVEYTOOL__SURVEYTOOL_);
		method.addObjectParameter(tool);

		method.executeWithVoidReturn();
	} else
		_implementation->setOpenSurveyTool(tool);
}

bool SurveySession::tryGamble() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_TRYGAMBLE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->tryGamble();
}

void SurveySession::clearGamble() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARGAMBLE__);

		method.executeWithVoidReturn();
	} else
		_implementation->clearGamble();
}

Coordinate* SurveySession::getRichSampleLocation() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getRichSampleLocation();
}

void SurveySession::clearRichSampleLocation() {
	SurveySessionImplementation* _implementation = static_cast<SurveySessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARRICHSAMPLELOCATION__);

		method.executeWithVoidReturn();
	} else
		_implementation->clearRichSampleLocation();
}

DistributedObjectServant* SurveySession::_getImplementation() {

	_updated = true;
	return _impl;
}

void SurveySession::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	SurveySessionImplementation
 */

SurveySessionImplementation::SurveySessionImplementation(DummyConstructorParameter* param) : FacadeImplementation(param) {
	_initializeImplementation();
}


SurveySessionImplementation::~SurveySessionImplementation() {
}


void SurveySessionImplementation::finalize() {
}

void SurveySessionImplementation::_initializeImplementation() {
	_setClassHelper(SurveySessionHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void SurveySessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<SurveySession*>(stub);
	FacadeImplementation::_setStub(stub);
}

DistributedObjectStub* SurveySessionImplementation::_getStub() {
	return _this.get();
}

SurveySessionImplementation::operator const SurveySession*() {
	return _this.get();
}

void SurveySessionImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void SurveySessionImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void SurveySessionImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void SurveySessionImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void SurveySessionImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void SurveySessionImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void SurveySessionImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void SurveySessionImplementation::_serializationHelperMethod() {
	FacadeImplementation::_serializationHelperMethod();

	_setClassName("SurveySession");

}

void SurveySessionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(SurveySessionImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SurveySessionImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (FacadeImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SurveySessionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SurveySessionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SurveySessionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = FacadeImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

SurveySessionImplementation::SurveySessionImplementation(CreatureObject* creature) {
	_initializeImplementation();
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		Logger.setLoggingName("CraftingSession");
	Logger::setLoggingName("CraftingSession");
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		richSampleLocation = null;
	richSampleLocation = NULL;
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		doGamble = false;
	doGamble = false;
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		lastResourceSampleName = "";
	lastResourceSampleName = "";
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		surveyer = creature;
	surveyer = creature;
}

void SurveySessionImplementation::reSample() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		startSample(lastResourceSampleName);
	startSample(lastResourceSampleName);
}

ManagedWeakReference<SurveyTool* > SurveySessionImplementation::getActiveSurveyTool() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		return activeSurveyTool;
	return activeSurveyTool;
}

void SurveySessionImplementation::setActiveSurveyTool(SurveyTool* tool) {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		activeSurveyTool = tool;
	activeSurveyTool = tool;
}

ManagedWeakReference<SurveyTool* > SurveySessionImplementation::getOpenSurveyTool() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		return openSurveyTool;
	return openSurveyTool;
}

void SurveySessionImplementation::setOpenSurveyTool(SurveyTool* tool) {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		openSurveyTool = tool;
	openSurveyTool = tool;
}

bool SurveySessionImplementation::tryGamble() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		return doGamble == true;
	return doGamble == true;
}

void SurveySessionImplementation::clearGamble() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		doGamble = false;
	doGamble = false;
}

Coordinate* SurveySessionImplementation::getRichSampleLocation() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		return richSampleLocation;
	return richSampleLocation;
}

void SurveySessionImplementation::clearRichSampleLocation() {
	// server/zone/objects/player/sessions/survey/SurveySession.idl():  		richSampleLocation = null;
	richSampleLocation = NULL;
}

/*
 *	SurveySessionAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


SurveySessionAdapter::SurveySessionAdapter(SurveySession* obj) : FacadeAdapter(obj) {
}

void SurveySessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZESESSION__SURVEYTOOL_:
		{
			resp->insertSignedInt(initializeSession(static_cast<SurveyTool*>(inv->getObjectParameter())));
		}
		break;
	case RPC_CANCELSESSION__:
		{
			resp->insertSignedInt(cancelSession());
		}
		break;
	case RPC_CLEARSESSION__:
		{
			resp->insertSignedInt(clearSession());
		}
		break;
	case RPC_STARTSURVEY__STRING_:
		{
			String resname; 
			startSurvey(inv->getAsciiParameter(resname));
		}
		break;
	case RPC_RESAMPLE__:
		{
			reSample();
		}
		break;
	case RPC_STARTSAMPLE__STRING_:
		{
			String resname; 
			startSample(inv->getAsciiParameter(resname));
		}
		break;
	case RPC_SURVEYCNODEMINIGAME__INT_:
		{
			surveyCnodeMinigame(inv->getSignedIntParameter());
		}
		break;
	case RPC_SURVEYGNODEMINIGAME__INT_:
		{
			surveyGnodeMinigame(inv->getSignedIntParameter());
		}
		break;
	case RPC_GETACTIVESURVEYTOOL__:
		{
			resp->insertLong(getActiveSurveyTool().get()->_getObjectID());
		}
		break;
	case RPC_SETACTIVESURVEYTOOL__SURVEYTOOL_:
		{
			setActiveSurveyTool(static_cast<SurveyTool*>(inv->getObjectParameter()));
		}
		break;
	case RPC_GETOPENSURVEYTOOL__:
		{
			resp->insertLong(getOpenSurveyTool().get()->_getObjectID());
		}
		break;
	case RPC_SETOPENSURVEYTOOL__SURVEYTOOL_:
		{
			setOpenSurveyTool(static_cast<SurveyTool*>(inv->getObjectParameter()));
		}
		break;
	case RPC_TRYGAMBLE__:
		{
			resp->insertBoolean(tryGamble());
		}
		break;
	case RPC_CLEARGAMBLE__:
		{
			clearGamble();
		}
		break;
	case RPC_CLEARRICHSAMPLELOCATION__:
		{
			clearRichSampleLocation();
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int SurveySessionAdapter::initializeSession(SurveyTool* tool) {
	return (static_cast<SurveySession*>(stub))->initializeSession(tool);
}

int SurveySessionAdapter::cancelSession() {
	return (static_cast<SurveySession*>(stub))->cancelSession();
}

int SurveySessionAdapter::clearSession() {
	return (static_cast<SurveySession*>(stub))->clearSession();
}

void SurveySessionAdapter::startSurvey(const String& resname) {
	(static_cast<SurveySession*>(stub))->startSurvey(resname);
}

void SurveySessionAdapter::reSample() {
	(static_cast<SurveySession*>(stub))->reSample();
}

void SurveySessionAdapter::startSample(const String& resname) {
	(static_cast<SurveySession*>(stub))->startSample(resname);
}

void SurveySessionAdapter::surveyCnodeMinigame(int value) {
	(static_cast<SurveySession*>(stub))->surveyCnodeMinigame(value);
}

void SurveySessionAdapter::surveyGnodeMinigame(int value) {
	(static_cast<SurveySession*>(stub))->surveyGnodeMinigame(value);
}

ManagedWeakReference<SurveyTool* > SurveySessionAdapter::getActiveSurveyTool() {
	return (static_cast<SurveySession*>(stub))->getActiveSurveyTool();
}

void SurveySessionAdapter::setActiveSurveyTool(SurveyTool* tool) {
	(static_cast<SurveySession*>(stub))->setActiveSurveyTool(tool);
}

ManagedWeakReference<SurveyTool* > SurveySessionAdapter::getOpenSurveyTool() {
	return (static_cast<SurveySession*>(stub))->getOpenSurveyTool();
}

void SurveySessionAdapter::setOpenSurveyTool(SurveyTool* tool) {
	(static_cast<SurveySession*>(stub))->setOpenSurveyTool(tool);
}

bool SurveySessionAdapter::tryGamble() {
	return (static_cast<SurveySession*>(stub))->tryGamble();
}

void SurveySessionAdapter::clearGamble() {
	(static_cast<SurveySession*>(stub))->clearGamble();
}

void SurveySessionAdapter::clearRichSampleLocation() {
	(static_cast<SurveySession*>(stub))->clearRichSampleLocation();
}

/*
 *	SurveySessionHelper
 */

SurveySessionHelper* SurveySessionHelper::staticInitializer = SurveySessionHelper::instance();

SurveySessionHelper::SurveySessionHelper() {
	className = "SurveySession";

	Core::getObjectBroker()->registerClass(className, this);
}

void SurveySessionHelper::finalizeHelper() {
	SurveySessionHelper::finalize();
}

DistributedObject* SurveySessionHelper::instantiateObject() {
	return new SurveySession(DummyConstructorParameter::instance());
}

DistributedObjectServant* SurveySessionHelper::instantiateServant() {
	return new SurveySessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SurveySessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SurveySessionAdapter(static_cast<SurveySession*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

