/*
 *	server/zone/managers/structure/StructureManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef STRUCTUREMANAGER_H_
#define STRUCTUREMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

class Zone;

class ZoneProcessServerImplementation;

class Player;

class BuildingObject;

class CellObject;

class DeedObject;

class StructureManager : public DistributedObjectStub {
public:
	StructureManager(Zone* zone, ZoneProcessServerImplementation* processor);

	void loadStructures();

	void unloadStructures();

	void saveStructures(bool refresh);

	BuildingObject* findBuildingType(const String& word, float targetX, float targetY);

	CellObject* getCell(unsigned long long id);

	BuildingObject* getBuilding(unsigned long long id);

	void spawnTempStructure(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnInstallation(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnHarvester(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnBuilding(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void error(const String& message);

	void info(const String& message);

protected:
	StructureManager(DummyConstructorParameter* param);

	virtual ~StructureManager();

	friend class StructureManagerHelper;
};

class StructureManagerImplementation;

class StructureManagerAdapter : public DistributedObjectAdapter {
public:
	StructureManagerAdapter(StructureManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadStructures();

	void unloadStructures();

	void saveStructures(bool refresh);

	BuildingObject* findBuildingType(const String& word, float targetX, float targetY);

	CellObject* getCell(unsigned long long id);

	BuildingObject* getBuilding(unsigned long long id);

	void spawnTempStructure(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnInstallation(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnHarvester(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void spawnBuilding(Player* player, DeedObject* deed, float x, float z, float y, float oX, float oZ, float oY, float oW);

	void error(const String& message);

	void info(const String& message);

protected:
	String _param0_findBuildingType__String_float_float_;
	String _param0_error__String_;
	String _param0_info__String_;
};

class StructureManagerHelper : public DistributedObjectClassHelper, public Singleton<StructureManagerHelper> {
	static StructureManagerHelper* staticInitializer;

public:
	StructureManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<StructureManagerHelper>;
};

class StructureManagerServant : public DistributedObjectServant {
public:
	StructureManager* _this;

public:
	StructureManagerServant();
	virtual ~StructureManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*STRUCTUREMANAGER_H_*/
