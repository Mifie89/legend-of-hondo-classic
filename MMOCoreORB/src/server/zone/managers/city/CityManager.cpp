/*
 *	server/zone/managers/city/CityManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "CityManager.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/region/CityRegion.h"

/*
 *	CityManagerStub
 */

enum {RPC_LOADLUACONFIG__ = 6,RPC_LOADCITYREGIONS__,RPC_VALIDATECITYNAME__STRING_,RPC_CREATECITY__CREATUREOBJECT_STRING_FLOAT_FLOAT_,RPC_PROCESSCITYUPDATE__CITYREGION_,RPC_CONTRACTCITY__CITYREGION_,RPC_EXPANDCITY__CITYREGION_,RPC_DESTROYCITY__CITYREGION_,RPC_SENDSTATUSREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_PROMPTCITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_CHANGECITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_STRING_,RPC_PROMPTWITHDRAWCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_PROMPTDEPOSITCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_WITHDRAWFROMCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_SCENEOBJECT_,RPC_DEPOSITTOCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_,RPC_SENDTREASURYREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_SENDCITIZENSHIPREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_REGISTERCITIZEN__CITYREGION_CREATUREOBJECT_,RPC_UNREGISTERCITIZEN__CITYREGION_CREATUREOBJECT_BOOL_,RPC_SENDMANAGEMILITIA__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_PROMPTADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_ADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_STRING_,RPC_REMOVEMILITIAMEMBER__CITYREGION_CREATUREOBJECT_LONG_,RPC_SENDCITYADVANCEMENT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_,RPC_TOGGLEZONINGENABLED__CITYREGION_CREATUREOBJECT_,RPC_GETCITIESALLOWED__BYTE_,RPC_GETTOTALCITIES__};

CityManager::CityManager(Zone* zne) : ManagedService(DummyConstructorParameter::instance()) {
	CityManagerImplementation* _implementation = new CityManagerImplementation(zne);
	_impl = _implementation;
	_impl->_setStub(this);
}

CityManager::CityManager(DummyConstructorParameter* param) : ManagedService(param) {
}

CityManager::~CityManager() {
}



void CityManager::loadLuaConfig() {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_LOADLUACONFIG__);

		method.executeWithVoidReturn();
	} else
		_implementation->loadLuaConfig();
}

void CityManager::loadCityRegions() {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_LOADCITYREGIONS__);

		method.executeWithVoidReturn();
	} else
		_implementation->loadCityRegions();
}

bool CityManager::validateCityName(const String& name) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_VALIDATECITYNAME__STRING_);
		method.addAsciiParameter(name);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->validateCityName(name);
}

CityRegion* CityManager::createCity(CreatureObject* mayor, const String& cityName, float x, float y) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATECITY__CREATUREOBJECT_STRING_FLOAT_FLOAT_);
		method.addObjectParameter(mayor);
		method.addAsciiParameter(cityName);
		method.addFloatParameter(x);
		method.addFloatParameter(y);

		return static_cast<CityRegion*>(method.executeWithObjectReturn());
	} else
		return _implementation->createCity(mayor, cityName, x, y);
}

void CityManager::processCityUpdate(CityRegion* city) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PROCESSCITYUPDATE__CITYREGION_);
		method.addObjectParameter(city);

		method.executeWithVoidReturn();
	} else
		_implementation->processCityUpdate(city);
}

void CityManager::contractCity(CityRegion* city) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTRACTCITY__CITYREGION_);
		method.addObjectParameter(city);

		method.executeWithVoidReturn();
	} else
		_implementation->contractCity(city);
}

void CityManager::expandCity(CityRegion* city) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_EXPANDCITY__CITYREGION_);
		method.addObjectParameter(city);

		method.executeWithVoidReturn();
	} else
		_implementation->expandCity(city);
}

void CityManager::destroyCity(CityRegion* city) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DESTROYCITY__CITYREGION_);
		method.addObjectParameter(city);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyCity(city);
}

void CityManager::sendStatusReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDSTATUSREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->sendStatusReport(city, creature, terminal);
}

void CityManager::promptCitySpecialization(CityRegion* city, CreatureObject* mayor, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PROMPTCITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->promptCitySpecialization(city, mayor, terminal);
}

void CityManager::changeCitySpecialization(CityRegion* city, CreatureObject* mayor, const String& spec) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHANGECITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_STRING_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addAsciiParameter(spec);

		method.executeWithVoidReturn();
	} else
		_implementation->changeCitySpecialization(city, mayor, spec);
}

void CityManager::promptWithdrawCityTreasury(CityRegion* city, CreatureObject* mayor, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PROMPTWITHDRAWCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->promptWithdrawCityTreasury(city, mayor, terminal);
}

void CityManager::promptDepositCityTreasury(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PROMPTDEPOSITCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->promptDepositCityTreasury(city, creature, terminal);
}

void CityManager::withdrawFromCityTreasury(CityRegion* city, CreatureObject* mayor, int value, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_WITHDRAWFROMCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addSignedIntParameter(value);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->withdrawFromCityTreasury(city, mayor, value, terminal);
}

void CityManager::depositToCityTreasury(CityRegion* city, CreatureObject* creature, int value) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DEPOSITTOCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->depositToCityTreasury(city, creature, value);
}

void CityManager::sendTreasuryReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDTREASURYREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->sendTreasuryReport(city, creature, terminal);
}

void CityManager::sendCitizenshipReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDCITIZENSHIPREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->sendCitizenshipReport(city, creature, terminal);
}

void CityManager::registerCitizen(CityRegion* city, CreatureObject* creature) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REGISTERCITIZEN__CITYREGION_CREATUREOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);

		method.executeWithVoidReturn();
	} else
		_implementation->registerCitizen(city, creature);
}

void CityManager::unregisterCitizen(CityRegion* city, CreatureObject* creature, bool inactive) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_UNREGISTERCITIZEN__CITYREGION_CREATUREOBJECT_BOOL_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addBooleanParameter(inactive);

		method.executeWithVoidReturn();
	} else
		_implementation->unregisterCitizen(city, creature, inactive);
}

void CityManager::sendManageMilitia(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDMANAGEMILITIA__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->sendManageMilitia(city, creature, terminal);
}

void CityManager::promptAddMilitiaMember(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PROMPTADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->promptAddMilitiaMember(city, creature, terminal);
}

void CityManager::addMilitiaMember(CityRegion* city, CreatureObject* mayor, const String& playerName) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_STRING_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addAsciiParameter(playerName);

		method.executeWithVoidReturn();
	} else
		_implementation->addMilitiaMember(city, mayor, playerName);
}

void CityManager::removeMilitiaMember(CityRegion* city, CreatureObject* mayor, unsigned long long militiaid) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEMILITIAMEMBER__CITYREGION_CREATUREOBJECT_LONG_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);
		method.addUnsignedLongParameter(militiaid);

		method.executeWithVoidReturn();
	} else
		_implementation->removeMilitiaMember(city, mayor, militiaid);
}

void CityManager::sendCityAdvancement(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDCITYADVANCEMENT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(creature);
		method.addObjectParameter(terminal);

		method.executeWithVoidReturn();
	} else
		_implementation->sendCityAdvancement(city, creature, terminal);
}

void CityManager::toggleZoningEnabled(CityRegion* city, CreatureObject* mayor) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_TOGGLEZONINGENABLED__CITYREGION_CREATUREOBJECT_);
		method.addObjectParameter(city);
		method.addObjectParameter(mayor);

		method.executeWithVoidReturn();
	} else
		_implementation->toggleZoningEnabled(city, mayor);
}

byte CityManager::getCitiesAllowed(byte rank) {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCITIESALLOWED__BYTE_);
		method.addByteParameter(rank);

		return method.executeWithByteReturn();
	} else
		return _implementation->getCitiesAllowed(rank);
}

int CityManager::getTotalCities() {
	CityManagerImplementation* _implementation = static_cast<CityManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTOTALCITIES__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getTotalCities();
}

DistributedObjectServant* CityManager::_getImplementation() {

	_updated = true;
	return _impl;
}

void CityManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	CityManagerImplementation
 */

CityManagerImplementation::CityManagerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


CityManagerImplementation::~CityManagerImplementation() {
}


void CityManagerImplementation::finalize() {
}

void CityManagerImplementation::_initializeImplementation() {
	_setClassHelper(CityManagerHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void CityManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<CityManager*>(stub);
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* CityManagerImplementation::_getStub() {
	return _this;
}

CityManagerImplementation::operator const CityManager*() {
	return _this;
}

void CityManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void CityManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void CityManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void CityManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void CityManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void CityManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void CityManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void CityManagerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("CityManager");

}

void CityManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(CityManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CityManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedServiceImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "zone") {
		TypeInfo<ManagedWeakReference<Zone* > >::parseFromBinaryStream(&zone, stream);
		return true;
	}


	return false;
}

void CityManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CityManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CityManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "zone";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<Zone* > >::toBinaryStream(&zone, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ManagedServiceImplementation::writeObjectMembers(stream);
}

CityManagerImplementation::CityManagerImplementation(Zone* zne) {
	_initializeImplementation();
	// server/zone/managers/city/CityManager.idl():  		Logger.setLoggingName("CityManager");
	Logger::setLoggingName("CityManager");
	// server/zone/managers/city/CityManager.idl():  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/managers/city/CityManager.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
	// server/zone/managers/city/CityManager.idl():  		zone = zne;
	zone = zne;
	// server/zone/managers/city/CityManager.idl():  		cities.setNoDuplicateInsertPlan();
	(&cities)->setNoDuplicateInsertPlan();
	// server/zone/managers/city/CityManager.idl():  		cities.setNullValue(null);
	(&cities)->setNullValue(NULL);
	// server/zone/managers/city/CityManager.idl():  		configLoaded = false;
	configLoaded = false;
}

void CityManagerImplementation::toggleZoningEnabled(CityRegion* city, CreatureObject* mayor) {
	// server/zone/managers/city/CityManager.idl():  	}
	if (city->isMayor(mayor->getObjectID())){
	// server/zone/managers/city/CityManager.idl():  			boolean val = city.isZoningEnabled();
	bool val = city->isZoningEnabled();
	// server/zone/managers/city/CityManager.idl():  			city.setZoningEnabled(!val);
	city->setZoningEnabled(!val);
	// server/zone/managers/city/CityManager.idl():  			}
	if (!val){
	// server/zone/managers/city/CityManager.idl():  				mayor.sendSystemMessage("@city/city:zoning_enabled");
	mayor->sendSystemMessage("@city/city:zoning_enabled");
}

	else {
	// server/zone/managers/city/CityManager.idl():  				mayor.sendSystemMessage("@city/city:zoning_disabled");
	mayor->sendSystemMessage("@city/city:zoning_disabled");
}
}
}

byte CityManagerImplementation::getCitiesAllowed(byte rank) {
	// server/zone/managers/city/CityManager.idl():  		return citiesAllowedPerRank.get(rank);
	return (&citiesAllowedPerRank)->get(rank);
}

int CityManagerImplementation::getTotalCities() {
	// server/zone/managers/city/CityManager.idl():  		return cities.size();
	return (&cities)->size();
}

/*
 *	CityManagerAdapter
 */

CityManagerAdapter::CityManagerAdapter(CityManager* obj) : ManagedServiceAdapter(obj) {
}

Packet* CityManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_LOADLUACONFIG__:
		loadLuaConfig();
		break;
	case RPC_LOADCITYREGIONS__:
		loadCityRegions();
		break;
	case RPC_VALIDATECITYNAME__STRING_:
		resp->insertBoolean(validateCityName(inv->getAsciiParameter(_param0_validateCityName__String_)));
		break;
	case RPC_CREATECITY__CREATUREOBJECT_STRING_FLOAT_FLOAT_:
		resp->insertLong(createCity(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getAsciiParameter(_param1_createCity__CreatureObject_String_float_float_), inv->getFloatParameter(), inv->getFloatParameter())->_getObjectID());
		break;
	case RPC_PROCESSCITYUPDATE__CITYREGION_:
		processCityUpdate(static_cast<CityRegion*>(inv->getObjectParameter()));
		break;
	case RPC_CONTRACTCITY__CITYREGION_:
		contractCity(static_cast<CityRegion*>(inv->getObjectParameter()));
		break;
	case RPC_EXPANDCITY__CITYREGION_:
		expandCity(static_cast<CityRegion*>(inv->getObjectParameter()));
		break;
	case RPC_DESTROYCITY__CITYREGION_:
		destroyCity(static_cast<CityRegion*>(inv->getObjectParameter()));
		break;
	case RPC_SENDSTATUSREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		sendStatusReport(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_PROMPTCITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		promptCitySpecialization(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_CHANGECITYSPECIALIZATION__CITYREGION_CREATUREOBJECT_STRING_:
		changeCitySpecialization(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getAsciiParameter(_param2_changeCitySpecialization__CityRegion_CreatureObject_String_));
		break;
	case RPC_PROMPTWITHDRAWCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		promptWithdrawCityTreasury(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_PROMPTDEPOSITCITYTREASURY__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		promptDepositCityTreasury(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_WITHDRAWFROMCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_SCENEOBJECT_:
		withdrawFromCityTreasury(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getSignedIntParameter(), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_DEPOSITTOCITYTREASURY__CITYREGION_CREATUREOBJECT_INT_:
		depositToCityTreasury(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getSignedIntParameter());
		break;
	case RPC_SENDTREASURYREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		sendTreasuryReport(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_SENDCITIZENSHIPREPORT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		sendCitizenshipReport(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_REGISTERCITIZEN__CITYREGION_CREATUREOBJECT_:
		registerCitizen(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_UNREGISTERCITIZEN__CITYREGION_CREATUREOBJECT_BOOL_:
		unregisterCitizen(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getBooleanParameter());
		break;
	case RPC_SENDMANAGEMILITIA__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		sendManageMilitia(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_PROMPTADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		promptAddMilitiaMember(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_ADDMILITIAMEMBER__CITYREGION_CREATUREOBJECT_STRING_:
		addMilitiaMember(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getAsciiParameter(_param2_addMilitiaMember__CityRegion_CreatureObject_String_));
		break;
	case RPC_REMOVEMILITIAMEMBER__CITYREGION_CREATUREOBJECT_LONG_:
		removeMilitiaMember(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getUnsignedLongParameter());
		break;
	case RPC_SENDCITYADVANCEMENT__CITYREGION_CREATUREOBJECT_SCENEOBJECT_:
		sendCityAdvancement(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_TOGGLEZONINGENABLED__CITYREGION_CREATUREOBJECT_:
		toggleZoningEnabled(static_cast<CityRegion*>(inv->getObjectParameter()), static_cast<CreatureObject*>(inv->getObjectParameter()));
		break;
	case RPC_GETCITIESALLOWED__BYTE_:
		resp->insertByte(getCitiesAllowed(inv->getByteParameter()));
		break;
	case RPC_GETTOTALCITIES__:
		resp->insertSignedInt(getTotalCities());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CityManagerAdapter::loadLuaConfig() {
	(static_cast<CityManager*>(stub))->loadLuaConfig();
}

void CityManagerAdapter::loadCityRegions() {
	(static_cast<CityManager*>(stub))->loadCityRegions();
}

bool CityManagerAdapter::validateCityName(const String& name) {
	return (static_cast<CityManager*>(stub))->validateCityName(name);
}

CityRegion* CityManagerAdapter::createCity(CreatureObject* mayor, const String& cityName, float x, float y) {
	return (static_cast<CityManager*>(stub))->createCity(mayor, cityName, x, y);
}

void CityManagerAdapter::processCityUpdate(CityRegion* city) {
	(static_cast<CityManager*>(stub))->processCityUpdate(city);
}

void CityManagerAdapter::contractCity(CityRegion* city) {
	(static_cast<CityManager*>(stub))->contractCity(city);
}

void CityManagerAdapter::expandCity(CityRegion* city) {
	(static_cast<CityManager*>(stub))->expandCity(city);
}

void CityManagerAdapter::destroyCity(CityRegion* city) {
	(static_cast<CityManager*>(stub))->destroyCity(city);
}

void CityManagerAdapter::sendStatusReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->sendStatusReport(city, creature, terminal);
}

void CityManagerAdapter::promptCitySpecialization(CityRegion* city, CreatureObject* mayor, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->promptCitySpecialization(city, mayor, terminal);
}

void CityManagerAdapter::changeCitySpecialization(CityRegion* city, CreatureObject* mayor, const String& spec) {
	(static_cast<CityManager*>(stub))->changeCitySpecialization(city, mayor, spec);
}

void CityManagerAdapter::promptWithdrawCityTreasury(CityRegion* city, CreatureObject* mayor, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->promptWithdrawCityTreasury(city, mayor, terminal);
}

void CityManagerAdapter::promptDepositCityTreasury(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->promptDepositCityTreasury(city, creature, terminal);
}

void CityManagerAdapter::withdrawFromCityTreasury(CityRegion* city, CreatureObject* mayor, int value, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->withdrawFromCityTreasury(city, mayor, value, terminal);
}

void CityManagerAdapter::depositToCityTreasury(CityRegion* city, CreatureObject* creature, int value) {
	(static_cast<CityManager*>(stub))->depositToCityTreasury(city, creature, value);
}

void CityManagerAdapter::sendTreasuryReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->sendTreasuryReport(city, creature, terminal);
}

void CityManagerAdapter::sendCitizenshipReport(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->sendCitizenshipReport(city, creature, terminal);
}

void CityManagerAdapter::registerCitizen(CityRegion* city, CreatureObject* creature) {
	(static_cast<CityManager*>(stub))->registerCitizen(city, creature);
}

void CityManagerAdapter::unregisterCitizen(CityRegion* city, CreatureObject* creature, bool inactive) {
	(static_cast<CityManager*>(stub))->unregisterCitizen(city, creature, inactive);
}

void CityManagerAdapter::sendManageMilitia(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->sendManageMilitia(city, creature, terminal);
}

void CityManagerAdapter::promptAddMilitiaMember(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->promptAddMilitiaMember(city, creature, terminal);
}

void CityManagerAdapter::addMilitiaMember(CityRegion* city, CreatureObject* mayor, const String& playerName) {
	(static_cast<CityManager*>(stub))->addMilitiaMember(city, mayor, playerName);
}

void CityManagerAdapter::removeMilitiaMember(CityRegion* city, CreatureObject* mayor, unsigned long long militiaid) {
	(static_cast<CityManager*>(stub))->removeMilitiaMember(city, mayor, militiaid);
}

void CityManagerAdapter::sendCityAdvancement(CityRegion* city, CreatureObject* creature, SceneObject* terminal) {
	(static_cast<CityManager*>(stub))->sendCityAdvancement(city, creature, terminal);
}

void CityManagerAdapter::toggleZoningEnabled(CityRegion* city, CreatureObject* mayor) {
	(static_cast<CityManager*>(stub))->toggleZoningEnabled(city, mayor);
}

byte CityManagerAdapter::getCitiesAllowed(byte rank) {
	return (static_cast<CityManager*>(stub))->getCitiesAllowed(rank);
}

int CityManagerAdapter::getTotalCities() {
	return (static_cast<CityManager*>(stub))->getTotalCities();
}

/*
 *	CityManagerHelper
 */

CityManagerHelper* CityManagerHelper::staticInitializer = CityManagerHelper::instance();

CityManagerHelper::CityManagerHelper() {
	className = "CityManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void CityManagerHelper::finalizeHelper() {
	CityManagerHelper::finalize();
}

DistributedObject* CityManagerHelper::instantiateObject() {
	return new CityManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* CityManagerHelper::instantiateServant() {
	return new CityManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CityManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CityManagerAdapter(static_cast<CityManager*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

