/*
 *	server/zone/objects/tangible/Container.cpp generated by engine3 IDL compiler 0.60
 */

#include "Container.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	ContainerStub
 */

Container::Container() : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ContainerImplementation();
	_impl->_setStub(this);
}

Container::Container(DummyConstructorParameter* param) : TangibleObject(param) {
}

Container::~Container() {
}


void Container::loadTemplateData(LuaObject* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ContainerImplementation*) _impl)->loadTemplateData(templateData);
}

void Container::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ContainerImplementation*) _impl)->initializeTransientMembers();
}

void Container::sendContainerObjectsTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ContainerImplementation*) _impl)->sendContainerObjectsTo(player);
}

/*
 *	ContainerImplementation
 */

ContainerImplementation::ContainerImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}

ContainerImplementation::~ContainerImplementation() {
}


void ContainerImplementation::finalize() {
}

void ContainerImplementation::_initializeImplementation() {
	_setClassHelper(ContainerHelper::instance());

	_serializationHelperMethod();
}

void ContainerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Container*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ContainerImplementation::_getStub() {
	return _this;
}

ContainerImplementation::operator const Container*() {
	return _this;
}

void ContainerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ContainerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ContainerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ContainerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ContainerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ContainerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ContainerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ContainerImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Container");

}

ContainerImplementation::ContainerImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/Container.idl(53):  		Logger.setLoggingName("Container");
	Logger::setLoggingName("Container");
}

/*
 *	ContainerAdapter
 */

ContainerAdapter::ContainerAdapter(ContainerImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ContainerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendContainerObjectsTo((SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ContainerAdapter::initializeTransientMembers() {
	((ContainerImplementation*) impl)->initializeTransientMembers();
}

void ContainerAdapter::sendContainerObjectsTo(SceneObject* player) {
	((ContainerImplementation*) impl)->sendContainerObjectsTo(player);
}

/*
 *	ContainerHelper
 */

ContainerHelper* ContainerHelper::staticInitializer = ContainerHelper::instance();

ContainerHelper::ContainerHelper() {
	className = "Container";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ContainerHelper::finalizeHelper() {
	ContainerHelper::finalize();
}

DistributedObject* ContainerHelper::instantiateObject() {
	return new Container(DummyConstructorParameter::instance());
}

DistributedObjectServant* ContainerHelper::instantiateServant() {
	return new ContainerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ContainerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ContainerAdapter((ContainerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

