/*
 *	server/zone/managers/gcw/GCWManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef GCWMANAGER_H_
#define GCWMANAGER_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace structure {

class StructureObject;

} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject;

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace installation {

class InstallationObject;

} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace deed {
namespace structure {

class StructureDeed;

} // namespace structure
} // namespace deed
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::deed::structure;

#include "server/zone/objects/building/components/DestructibleBuildingDataComponent.h"

#include "engine/core/ManagedService.h"

#include "engine/core/Task.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedObject.h"

#include "system/util/SortedVector.h"

#include "system/thread/Mutex.h"

namespace server {
namespace zone {
namespace managers {
namespace gcw {

class GCWManager : public ManagedService {
public:
	static const int IMPERIALHASH = 3679112276;

	static const int REBELHASH = 370444368;

	GCWManager(Zone* zne);

	void loadLuaConfig();

	void initialize();

	void start();

	void registerGCWBase(BuildingObject* building, bool initializeBase);

	void unregisterGCWBase(BuildingObject* building);

	void performGCWTasks();

	void startVulnerability(BuildingObject* building);

	void endVulnerability(BuildingObject* building);

	bool isBaseVulnerable(BuildingObject* building);

	bool isBandIdentified(BuildingObject* building);

	bool isUplinkJammed(BuildingObject* building);

	bool isShutdownSequenceStarted(BuildingObject* building);

	bool isSecurityTermSliced(BuildingObject* building);

	bool isPowerOverloaded(BuildingObject* building);

	void resetVulnerability(CreatureObject* creature, BuildingObject* building);

	void sendBaseDefenseStatus(CreatureObject* creature, BuildingObject* building);

	void doBaseDestruction(StructureObject* structure);

	void doBaseDestruction(BuildingObject* building);

	void sendResetVerification(CreatureObject* creature, BuildingObject* building);

	void sendJamUplinkMenu(CreatureObject* creature, BuildingObject* building);

	void verifyUplinkBand(CreatureObject* creature, BuildingObject* building, int band);

	bool canStartSlice(CreatureObject* creature, TangibleObject* terminal);

	void sendDNASampleMenu(CreatureObject* creature, BuildingObject* building);

	void completeSecuritySlice(CreatureObject* creature, TangibleObject* securityTerminal);

	void failSecuritySlice(TangibleObject* securityTerminal);

	bool isTerminalDamaged(TangibleObject* securityTerminal);

	bool isDNASampled(BuildingObject* building);

	void repairTerminal(CreatureObject* creature, TangibleObject* securityTerminal);

	void abortShutdownSequence(CreatureObject* creature, BuildingObject* building);

	void processDNASample(CreatureObject* creature, BuildingObject* building, int indx);

	void handlePowerRegulatorSwitch(CreatureObject* creature, BuildingObject* building, int indx);

	void sendPowerRegulatorControls(CreatureObject* creature, BuildingObject* building);

	String getDNAHash(const String& usersample);

	bool isPlanetCapped();

	void scheduleBaseDestruction(BuildingObject* building, CreatureObject* creature);

	void notifyTurretDestruction(InstallationObject* turret);

	void sendSelectTurretToDonate(BuildingObject* building, CreatureObject* creature);

	void sendSelectDeedToDonate(BuildingObject* building, CreatureObject* creature, int turretIndex);

	void sendRemoveDefenseConfirmation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

	void performDefenseDontation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID, int turretIndex);

	void sendStatus(BuildingObject* building, CreatureObject* creature);

	void addMinefield(BuildingObject* building, SceneObject* minefield);

	void addTurret(BuildingObject* building, SceneObject* turret);

	void addScanner(BuildingObject* building, SceneObject* scanner);

	void removeDefense(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

	bool canUseTerminals(CreatureObject* creature, BuildingObject* building, SceneObject* terminal);

	int getImperialBaseCount();

	int getRebelBaseCount();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	GCWManager(DummyConstructorParameter* param);

	virtual ~GCWManager();

	friend class GCWManagerHelper;
};

} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw;

namespace server {
namespace zone {
namespace managers {
namespace gcw {

class GCWManagerImplementation : public ManagedServiceImplementation, public Logger {
public:
	static const int IMPERIALHASH = 3679112276;

	static const int REBELHASH = 370444368;

private:
	ManagedReference<Zone* > zone;

protected:
	SortedVector<ManagedReference<BuildingObject* > > gcwBaseList;

	VectorMap<unsigned long long, Reference<Task*> > gcwStartTasks;

	VectorMap<unsigned long long, Reference<Task*> > gcwEndTasks;

	VectorMap<String, String> dnaHash;

	VectorMap<unsigned long long, Reference<Task*> > gcwDestroyTasks;

	Mutex baseMutex;

private:
	int rebelBases;

	int imperialBases;

public:
	static int gcwCheckTimer;

	static int vulnerabilityDuration;

	static int vulnerabilityFrequency;

	static int resetTimer;

	static int sliceCooldown;

	static int totalDNASamples;

	static int dnaMatchesRequired;

	static int destructionTimer;

	static int maxBases;

	static int overtCooldown;

	static int reactvationTimer;

	GCWManagerImplementation(Zone* zne);

	GCWManagerImplementation(DummyConstructorParameter* param);

	void loadLuaConfig();

	void initialize();

	void start();

	void registerGCWBase(BuildingObject* building, bool initializeBase);

	void unregisterGCWBase(BuildingObject* building);

	void performGCWTasks();

	void startVulnerability(BuildingObject* building);

	void endVulnerability(BuildingObject* building);

	bool isBaseVulnerable(BuildingObject* building);

	bool isBandIdentified(BuildingObject* building);

	bool isUplinkJammed(BuildingObject* building);

	bool isShutdownSequenceStarted(BuildingObject* building);

	bool isSecurityTermSliced(BuildingObject* building);

	bool isPowerOverloaded(BuildingObject* building);

	void resetVulnerability(CreatureObject* creature, BuildingObject* building);

	void sendBaseDefenseStatus(CreatureObject* creature, BuildingObject* building);

	void doBaseDestruction(StructureObject* structure);

	void doBaseDestruction(BuildingObject* building);

	void sendResetVerification(CreatureObject* creature, BuildingObject* building);

	void sendJamUplinkMenu(CreatureObject* creature, BuildingObject* building);

	void verifyUplinkBand(CreatureObject* creature, BuildingObject* building, int band);

	bool canStartSlice(CreatureObject* creature, TangibleObject* terminal);

	void sendDNASampleMenu(CreatureObject* creature, BuildingObject* building);

	void completeSecuritySlice(CreatureObject* creature, TangibleObject* securityTerminal);

	void failSecuritySlice(TangibleObject* securityTerminal);

	bool isTerminalDamaged(TangibleObject* securityTerminal);

	bool isDNASampled(BuildingObject* building);

	void repairTerminal(CreatureObject* creature, TangibleObject* securityTerminal);

	void abortShutdownSequence(CreatureObject* creature, BuildingObject* building);

	void processDNASample(CreatureObject* creature, BuildingObject* building, int indx);

	void handlePowerRegulatorSwitch(CreatureObject* creature, BuildingObject* building, int indx);

	void sendPowerRegulatorControls(CreatureObject* creature, BuildingObject* building);

	String getDNAHash(const String& usersample);

protected:
	void addDNAHash(const String& usersample, const String& systemsample);

	bool hasBase(BuildingObject* building);

	bool dropBase(BuildingObject* building);

	void addBase(BuildingObject* building);

	BuildingObject* getBase(int indx);

	bool hasStartTask(unsigned long long id);

	bool addStartTask(unsigned long long id, Reference<Task*> newTask);

	Reference<Task*> getStartTask(unsigned long long id);

	bool dropStartTask(unsigned long long id);

	bool hasEndTask(unsigned long long id);

	bool addEndTask(unsigned long long id, Reference<Task*> newTask);

	Reference<Task*> getEndTask(unsigned long long id);

	bool dropEndTask(unsigned long long id);

	bool hasDestroyTask(unsigned long long id);

	bool addDestroyTask(unsigned long long id, Reference<Task*> newTask);

	Reference<Task*> getDestroyTask(unsigned long long id);

	bool dropDestroyTask(unsigned long long id);

public:
	bool isPlanetCapped();

private:
	DestructibleBuildingDataComponent* getDestructibleBuildingData(BuildingObject* building);

	void checkVulnerabilityData(BuildingObject* building);

	void scheduleVulnerabilityStart(BuildingObject* building);

	void scheduleVulnerabilityEnd(BuildingObject* building);

public:
	void scheduleBaseDestruction(BuildingObject* building, CreatureObject* creature);

private:
	void initializeBaseTimers(BuildingObject* building);

	void renewUplinkBand(BuildingObject* building);

	void refreshExpiredVulnerability(BuildingObject* building);

	void initializeNewVulnerability(DestructibleBuildingDataComponent* data);

	void refreshDNA(DestructibleBuildingDataComponent* data);

public:
	void notifyTurretDestruction(InstallationObject* turret);

private:
	void destroyStandaloneTurret(InstallationObject* turret);

public:
	void sendSelectTurretToDonate(BuildingObject* building, CreatureObject* creature);

	void sendSelectDeedToDonate(BuildingObject* building, CreatureObject* creature, int turretIndex);

	void sendRemoveDefenseConfirmation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

	void performDefenseDontation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID, int turretIndex);

private:
	void performDonateMine(BuildingObject* building, CreatureObject* creature, SceneObject* sceneObject);

	void performDonateMinefield(BuildingObject* building, CreatureObject* creature, StructureDeed* deed);

	void performDonateTurret(BuildingObject* building, CreatureObject* creature, StructureDeed* deed);

public:
	void sendStatus(BuildingObject* building, CreatureObject* creature);

	void addMinefield(BuildingObject* building, SceneObject* minefield);

	void addTurret(BuildingObject* building, SceneObject* turret);

	void addScanner(BuildingObject* building, SceneObject* scanner);

	void removeDefense(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

private:
	void verifyTurrets(BuildingObject* building);

public:
	bool canUseTerminals(CreatureObject* creature, BuildingObject* building, SceneObject* terminal);

	int getImperialBaseCount();

	int getRebelBaseCount();

private:
	void setRebelBaseCount(int val);

	void setImperialBaseCount(int val);

public:
	WeakReference<GCWManager*> _this;

	operator const GCWManager*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~GCWManagerImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class GCWManager;
};

class GCWManagerAdapter : public ManagedServiceAdapter {
public:
	GCWManagerAdapter(GCWManager* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadLuaConfig();

	void initialize();

	void start();

	void registerGCWBase(BuildingObject* building, bool initializeBase);

	void unregisterGCWBase(BuildingObject* building);

	void performGCWTasks();

	void startVulnerability(BuildingObject* building);

	void endVulnerability(BuildingObject* building);

	bool isBaseVulnerable(BuildingObject* building);

	bool isBandIdentified(BuildingObject* building);

	bool isUplinkJammed(BuildingObject* building);

	bool isShutdownSequenceStarted(BuildingObject* building);

	bool isSecurityTermSliced(BuildingObject* building);

	bool isPowerOverloaded(BuildingObject* building);

	void resetVulnerability(CreatureObject* creature, BuildingObject* building);

	void sendBaseDefenseStatus(CreatureObject* creature, BuildingObject* building);

	void doBaseDestruction(StructureObject* structure);

	void doBaseDestruction(BuildingObject* building);

	void sendResetVerification(CreatureObject* creature, BuildingObject* building);

	void sendJamUplinkMenu(CreatureObject* creature, BuildingObject* building);

	void verifyUplinkBand(CreatureObject* creature, BuildingObject* building, int band);

	bool canStartSlice(CreatureObject* creature, TangibleObject* terminal);

	void sendDNASampleMenu(CreatureObject* creature, BuildingObject* building);

	void completeSecuritySlice(CreatureObject* creature, TangibleObject* securityTerminal);

	void failSecuritySlice(TangibleObject* securityTerminal);

	bool isTerminalDamaged(TangibleObject* securityTerminal);

	bool isDNASampled(BuildingObject* building);

	void repairTerminal(CreatureObject* creature, TangibleObject* securityTerminal);

	void abortShutdownSequence(CreatureObject* creature, BuildingObject* building);

	void processDNASample(CreatureObject* creature, BuildingObject* building, int indx);

	void handlePowerRegulatorSwitch(CreatureObject* creature, BuildingObject* building, int indx);

	void sendPowerRegulatorControls(CreatureObject* creature, BuildingObject* building);

	String getDNAHash(const String& usersample);

	bool isPlanetCapped();

	void scheduleBaseDestruction(BuildingObject* building, CreatureObject* creature);

	void notifyTurretDestruction(InstallationObject* turret);

	void sendSelectTurretToDonate(BuildingObject* building, CreatureObject* creature);

	void sendSelectDeedToDonate(BuildingObject* building, CreatureObject* creature, int turretIndex);

	void sendRemoveDefenseConfirmation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

	void performDefenseDontation(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID, int turretIndex);

	void sendStatus(BuildingObject* building, CreatureObject* creature);

	void addMinefield(BuildingObject* building, SceneObject* minefield);

	void addTurret(BuildingObject* building, SceneObject* turret);

	void addScanner(BuildingObject* building, SceneObject* scanner);

	void removeDefense(BuildingObject* building, CreatureObject* creature, unsigned long long deedOID);

	bool canUseTerminals(CreatureObject* creature, BuildingObject* building, SceneObject* terminal);

	int getImperialBaseCount();

	int getRebelBaseCount();

};

class GCWManagerHelper : public DistributedObjectClassHelper, public Singleton<GCWManagerHelper> {
	static GCWManagerHelper* staticInitializer;

public:
	GCWManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<GCWManagerHelper>;
};

} // namespace gcw
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::gcw;

#endif /*GCWMANAGER_H_*/
