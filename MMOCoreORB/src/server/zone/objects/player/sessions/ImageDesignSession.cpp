/*
 *	server/zone/objects/player/sessions/ImageDesignSession.cpp generated by engine3 IDL compiler 0.60
 */

#include "ImageDesignSession.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/player/events/ImageDesignTimeoutEvent.h"

/*
 *	ImageDesignSessionStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_INITIALIZESESSION__,RPC_DOPAYMENT__,RPC_CANCELSESSION__,RPC_CLEARSESSION__,RPC_CLEARIDTIMEOUTEVENT__,RPC_DEQUEUEIDTIMEOUTEVENT__,RPC_SESSIONTIMEOUT__};

ImageDesignSession::ImageDesignSession(CreatureObject* parent) : Facade(DummyConstructorParameter::instance()) {
	ImageDesignSessionImplementation* _implementation = new ImageDesignSessionImplementation(parent);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("ImageDesignSession");
}

ImageDesignSession::ImageDesignSession(DummyConstructorParameter* param) : Facade(param) {
	_setClassName("ImageDesignSession");
}

ImageDesignSession::~ImageDesignSession() {
}



void ImageDesignSession::initializeTransientMembers() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void ImageDesignSession::startImageDesign(CreatureObject* designer, CreatureObject* targetPlayer) {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->startImageDesign(designer, targetPlayer);
}

void ImageDesignSession::updateImageDesign(unsigned long long designer, unsigned long long targetPlayer, unsigned long long tent, int type, const ImageDesignData& data) {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateImageDesign(designer, targetPlayer, tent, type, data);
}

void ImageDesignSession::cancelImageDesign(unsigned long long designer, unsigned long long targetPlayer, unsigned long long tent, int type, const ImageDesignData& data) {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->cancelImageDesign(designer, targetPlayer, tent, type, data);
}

int ImageDesignSession::initializeSession() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZESESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession();
}

int ImageDesignSession::doPayment() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOPAYMENT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->doPayment();
}

int ImageDesignSession::cancelSession() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int ImageDesignSession::clearSession() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARSESSION__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

void ImageDesignSession::clearIdTimeoutEvent() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CLEARIDTIMEOUTEVENT__);

		method.executeWithVoidReturn();
	} else
		_implementation->clearIdTimeoutEvent();
}

void ImageDesignSession::dequeueIdTimeoutEvent() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEQUEUEIDTIMEOUTEVENT__);

		method.executeWithVoidReturn();
	} else
		_implementation->dequeueIdTimeoutEvent();
}

void ImageDesignSession::sessionTimeout() {
	ImageDesignSessionImplementation* _implementation = static_cast<ImageDesignSessionImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SESSIONTIMEOUT__);

		method.executeWithVoidReturn();
	} else
		_implementation->sessionTimeout();
}

DistributedObjectServant* ImageDesignSession::_getImplementation() {

	_updated = true;
	return _impl;
}

void ImageDesignSession::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ImageDesignSessionImplementation
 */

ImageDesignSessionImplementation::ImageDesignSessionImplementation(DummyConstructorParameter* param) : FacadeImplementation(param) {
	_initializeImplementation();
}


ImageDesignSessionImplementation::~ImageDesignSessionImplementation() {
}


void ImageDesignSessionImplementation::finalize() {
}

void ImageDesignSessionImplementation::_initializeImplementation() {
	_setClassHelper(ImageDesignSessionHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void ImageDesignSessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<ImageDesignSession*>(stub);
	FacadeImplementation::_setStub(stub);
}

DistributedObjectStub* ImageDesignSessionImplementation::_getStub() {
	return _this;
}

ImageDesignSessionImplementation::operator const ImageDesignSession*() {
	return _this;
}

void ImageDesignSessionImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ImageDesignSessionImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ImageDesignSessionImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ImageDesignSessionImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ImageDesignSessionImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ImageDesignSessionImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ImageDesignSessionImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ImageDesignSessionImplementation::_serializationHelperMethod() {
	FacadeImplementation::_serializationHelperMethod();

	_setClassName("ImageDesignSession");

}

void ImageDesignSessionImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(ImageDesignSessionImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ImageDesignSessionImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (FacadeImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "ImageDesignSession.imageDesignManager") {
		TypeInfo<Reference<ImageDesignManager* > >::parseFromBinaryStream(&imageDesignManager, stream);
		return true;
	}

	if (_name == "ImageDesignSession.designerCreature") {
		TypeInfo<ManagedWeakReference<CreatureObject* > >::parseFromBinaryStream(&designerCreature, stream);
		return true;
	}

	if (_name == "ImageDesignSession.targetCreature") {
		TypeInfo<ManagedWeakReference<CreatureObject* > >::parseFromBinaryStream(&targetCreature, stream);
		return true;
	}

	if (_name == "ImageDesignSession.imageDesignData") {
		TypeInfo<ImageDesignData >::parseFromBinaryStream(&imageDesignData, stream);
		return true;
	}

	if (_name == "ImageDesignSession.hairObject") {
		TypeInfo<ManagedWeakReference<TangibleObject* > >::parseFromBinaryStream(&hairObject, stream);
		return true;
	}


	return false;
}

void ImageDesignSessionImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ImageDesignSessionImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ImageDesignSessionImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = FacadeImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "ImageDesignSession.imageDesignManager";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<Reference<ImageDesignManager* > >::toBinaryStream(&imageDesignManager, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ImageDesignSession.designerCreature";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<CreatureObject* > >::toBinaryStream(&designerCreature, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ImageDesignSession.targetCreature";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<CreatureObject* > >::toBinaryStream(&targetCreature, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ImageDesignSession.imageDesignData";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ImageDesignData >::toBinaryStream(&imageDesignData, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "ImageDesignSession.hairObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<ManagedWeakReference<TangibleObject* > >::toBinaryStream(&hairObject, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 5;
}

ImageDesignSessionImplementation::ImageDesignSessionImplementation(CreatureObject* parent) {
	_initializeImplementation();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		Logger.setLoggingName("ImageDesignSession");
	Logger::setLoggingName("ImageDesignSession");
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		initializeSession();
	initializeSession();
}

int ImageDesignSessionImplementation::initializeSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		designerCreature = null;
	designerCreature = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		targetCreature = null;
	targetCreature = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		imageDesignManager = null;
	imageDesignManager = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		idTimeoutEvent = null;
	idTimeoutEvent = NULL;
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

int ImageDesignSessionImplementation::cancelSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		if 
	if (designerCreature != NULL)	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			designerCreature.dropActiveSession(SessionFacadeType.IMAGEDESIGN);
	designerCreature->dropActiveSession(SessionFacadeType::IMAGEDESIGN);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		dequeueIdTimeoutEvent(
	if (targetCreature != NULL)	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			targetCreature.dropActiveSession(SessionFacadeType.IMAGEDESIGN);
	targetCreature->dropActiveSession(SessionFacadeType::IMAGEDESIGN);
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		dequeueIdTimeoutEvent();
	dequeueIdTimeoutEvent();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

int ImageDesignSessionImplementation::clearSession() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		return 0;
	return 0;
}

void ImageDesignSessionImplementation::clearIdTimeoutEvent() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		idTimeoutEvent = null;
	idTimeoutEvent = NULL;
}

void ImageDesignSessionImplementation::dequeueIdTimeoutEvent() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  	}
	if (idTimeoutEvent != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			idTimeoutEvent.cancel();
	idTimeoutEvent->cancel();
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			idTimeoutEvent = null;
	idTimeoutEvent = NULL;
}
}

void ImageDesignSessionImplementation::sessionTimeout() {
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  		if 
	if (designerCreature != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			designerCreature.sendSystemMessage("Image Design session has timed out. Changes aborted.");
	designerCreature->sendSystemMessage("Image Design session has timed out. Changes aborted.");
}
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  	}
	if (targetCreature != NULL){
	// server/zone/objects/player/sessions/ImageDesignSession.idl():  			targetCreature.sendSystemMessage("Image Design session has timed out. Changes aborted.");
	targetCreature->sendSystemMessage("Image Design session has timed out. Changes aborted.");
}
}

/*
 *	ImageDesignSessionAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


ImageDesignSessionAdapter::ImageDesignSessionAdapter(ImageDesignSession* obj) : FacadeAdapter(obj) {
}

void ImageDesignSessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_INITIALIZESESSION__:
		resp->insertSignedInt(initializeSession());
		break;
	case RPC_DOPAYMENT__:
		resp->insertSignedInt(doPayment());
		break;
	case RPC_CANCELSESSION__:
		resp->insertSignedInt(cancelSession());
		break;
	case RPC_CLEARSESSION__:
		resp->insertSignedInt(clearSession());
		break;
	case RPC_CLEARIDTIMEOUTEVENT__:
		clearIdTimeoutEvent();
		break;
	case RPC_DEQUEUEIDTIMEOUTEVENT__:
		dequeueIdTimeoutEvent();
		break;
	case RPC_SESSIONTIMEOUT__:
		sessionTimeout();
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void ImageDesignSessionAdapter::initializeTransientMembers() {
	(static_cast<ImageDesignSession*>(stub))->initializeTransientMembers();
}

int ImageDesignSessionAdapter::initializeSession() {
	return (static_cast<ImageDesignSession*>(stub))->initializeSession();
}

int ImageDesignSessionAdapter::doPayment() {
	return (static_cast<ImageDesignSession*>(stub))->doPayment();
}

int ImageDesignSessionAdapter::cancelSession() {
	return (static_cast<ImageDesignSession*>(stub))->cancelSession();
}

int ImageDesignSessionAdapter::clearSession() {
	return (static_cast<ImageDesignSession*>(stub))->clearSession();
}

void ImageDesignSessionAdapter::clearIdTimeoutEvent() {
	(static_cast<ImageDesignSession*>(stub))->clearIdTimeoutEvent();
}

void ImageDesignSessionAdapter::dequeueIdTimeoutEvent() {
	(static_cast<ImageDesignSession*>(stub))->dequeueIdTimeoutEvent();
}

void ImageDesignSessionAdapter::sessionTimeout() {
	(static_cast<ImageDesignSession*>(stub))->sessionTimeout();
}

/*
 *	ImageDesignSessionHelper
 */

ImageDesignSessionHelper* ImageDesignSessionHelper::staticInitializer = ImageDesignSessionHelper::instance();

ImageDesignSessionHelper::ImageDesignSessionHelper() {
	className = "ImageDesignSession";

	Core::getObjectBroker()->registerClass(className, this);
}

void ImageDesignSessionHelper::finalizeHelper() {
	ImageDesignSessionHelper::finalize();
}

DistributedObject* ImageDesignSessionHelper::instantiateObject() {
	return new ImageDesignSession(DummyConstructorParameter::instance());
}

DistributedObjectServant* ImageDesignSessionHelper::instantiateServant() {
	return new ImageDesignSessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ImageDesignSessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ImageDesignSessionAdapter(static_cast<ImageDesignSession*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

