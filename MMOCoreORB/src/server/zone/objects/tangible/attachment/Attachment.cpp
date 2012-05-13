/*
 *	server/zone/objects/tangible/attachment/Attachment.cpp generated by engine3 IDL compiler 0.60
 */

#include "Attachment.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/Zone.h"

/*
 *	AttachmentStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_INITIALIZEMEMBERS__,RPC_ISATTACHMENT__,RPC_ISARMORATTACHMENT__,RPC_ISCLOTHINGATTACHMENT__,};

Attachment::Attachment() : TangibleObject(DummyConstructorParameter::instance()) {
	AttachmentImplementation* _implementation = new AttachmentImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("Attachment");
}

Attachment::Attachment(DummyConstructorParameter* param) : TangibleObject(param) {
	_setClassName("Attachment");
}

Attachment::~Attachment() {
}



void Attachment::initializeTransientMembers() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void Attachment::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(values, firstUpdate);
}

void Attachment::initializeMembers() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZEMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeMembers();
}

void Attachment::loadTemplateData(SharedObjectTemplate* templateData) {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void Attachment::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

bool Attachment::isAttachment() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isAttachment();
}

bool Attachment::isArmorAttachment() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISARMORATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArmorAttachment();
}

bool Attachment::isClothingAttachment() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCLOTHINGATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isClothingAttachment();
}

VectorMap<String, int>* Attachment::getSkillMods() {
	AttachmentImplementation* _implementation = static_cast<AttachmentImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getSkillMods();
}

DistributedObjectServant* Attachment::_getImplementation() {

	_updated = true;
	return _impl;
}

void Attachment::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AttachmentImplementation
 */

AttachmentImplementation::AttachmentImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


AttachmentImplementation::~AttachmentImplementation() {
}


void AttachmentImplementation::finalize() {
}

void AttachmentImplementation::_initializeImplementation() {
	_setClassHelper(AttachmentHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void AttachmentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<Attachment*>(stub);
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AttachmentImplementation::_getStub() {
	return _this;
}

AttachmentImplementation::operator const Attachment*() {
	return _this;
}

void AttachmentImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AttachmentImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AttachmentImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AttachmentImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AttachmentImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AttachmentImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AttachmentImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AttachmentImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Attachment");

}

void AttachmentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(AttachmentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AttachmentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "Attachment.attachmentType") {
		TypeInfo<int >::parseFromBinaryStream(&attachmentType, stream);
		return true;
	}

	if (_name == "Attachment.skillModMap") {
		TypeInfo<VectorMap<String, int> >::parseFromBinaryStream(&skillModMap, stream);
		return true;
	}


	return false;
}

void AttachmentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AttachmentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AttachmentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = TangibleObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "Attachment.attachmentType";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&attachmentType, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);

	_name = "Attachment.skillModMap";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<VectorMap<String, int> >::toBinaryStream(&skillModMap, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 2;
}

AttachmentImplementation::AttachmentImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/attachment/Attachment.idl():  		Logger.setLoggingName("Attachment");
	Logger::setLoggingName("Attachment");
	// server/zone/objects/tangible/attachment/Attachment.idl():  		skillModMap.setNullValue(0);
	(&skillModMap)->setNullValue(0);
	// server/zone/objects/tangible/attachment/Attachment.idl():  		skillModMap.setNoDuplicateInsertPlan();
	(&skillModMap)->setNoDuplicateInsertPlan();
}

void AttachmentImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		super.loadTemplateData(templateData);
	TangibleObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/attachment/Attachment.idl():  		initializeMembers();
	initializeMembers();
}

bool AttachmentImplementation::isAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return true;
	return true;
}

bool AttachmentImplementation::isArmorAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return super.gameObjectType == SceneObjectType.ARMORATTACHMENT;
	return TangibleObjectImplementation::gameObjectType == SceneObjectType::ARMORATTACHMENT;
}

bool AttachmentImplementation::isClothingAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return super.gameObjectType == SceneObjectType.CLOTHINGATTACHMENT;
	return TangibleObjectImplementation::gameObjectType == SceneObjectType::CLOTHINGATTACHMENT;
}

VectorMap<String, int>* AttachmentImplementation::getSkillMods() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return skillModMap;
	return (&skillModMap);
}

/*
 *	AttachmentAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


AttachmentAdapter::AttachmentAdapter(Attachment* obj) : TangibleObjectAdapter(obj) {
}

void AttachmentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		{
			initializeTransientMembers();
		}
		break;
	case RPC_INITIALIZEMEMBERS__:
		{
			initializeMembers();
		}
		break;
	case RPC_ISATTACHMENT__:
		{
			resp->insertBoolean(isAttachment());
		}
		break;
	case RPC_ISARMORATTACHMENT__:
		{
			resp->insertBoolean(isArmorAttachment());
		}
		break;
	case RPC_ISCLOTHINGATTACHMENT__:
		{
			resp->insertBoolean(isClothingAttachment());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

void AttachmentAdapter::initializeTransientMembers() {
	(static_cast<Attachment*>(stub))->initializeTransientMembers();
}

void AttachmentAdapter::initializeMembers() {
	(static_cast<Attachment*>(stub))->initializeMembers();
}

bool AttachmentAdapter::isAttachment() {
	return (static_cast<Attachment*>(stub))->isAttachment();
}

bool AttachmentAdapter::isArmorAttachment() {
	return (static_cast<Attachment*>(stub))->isArmorAttachment();
}

bool AttachmentAdapter::isClothingAttachment() {
	return (static_cast<Attachment*>(stub))->isClothingAttachment();
}

/*
 *	AttachmentHelper
 */

AttachmentHelper* AttachmentHelper::staticInitializer = AttachmentHelper::instance();

AttachmentHelper::AttachmentHelper() {
	className = "Attachment";

	Core::getObjectBroker()->registerClass(className, this);
}

void AttachmentHelper::finalizeHelper() {
	AttachmentHelper::finalize();
}

DistributedObject* AttachmentHelper::instantiateObject() {
	return new Attachment(DummyConstructorParameter::instance());
}

DistributedObjectServant* AttachmentHelper::instantiateServant() {
	return new AttachmentImplementation();
}

DistributedObjectAdapter* AttachmentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AttachmentAdapter(static_cast<Attachment*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

