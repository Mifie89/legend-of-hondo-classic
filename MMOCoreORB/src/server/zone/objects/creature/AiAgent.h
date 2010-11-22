/*
 *	server/zone/objects/creature/AiAgent.h generated by engine3 IDL compiler 0.60
 */

#ifndef AIAGENT_H_
#define AIAGENT_H_

#include "engine/orb/DistributedObjectBroker.h"

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
namespace creature {
namespace events {

class AiThinkEvent;

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class AiMoveEvent;

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class AiWaitEvent;

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class AiAwarenessEvent;

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class WeaponObject;

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

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
namespace tangible {
namespace weapon {

class WeaponObject;

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace managers {
namespace creature {

class CreatureTemplate;

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class DespawnCreatureOnPlayerDissappear;

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class QueueCommand;

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class Observable;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiObserver;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

#include "server/zone/objects/creature/PatrolPointsVector.h"

#include "server/zone/objects/creature/PatrolPoint.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/creature/variables/CreatureAttackMap.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "system/lang/ref/Reference.h"

#include "engine/core/ManagedObject.h"

#include "engine/util/Coordinate.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgent : public CreatureObject {
public:
	static const int UPDATEMOVEMENTINTERVAL = 1000;

	unsigned static const int OBLIVIOUS = 0;

	unsigned static const int WATCHING = 1;

	unsigned static const int STALKING = 2;

	unsigned static const int FOLLOWING = 3;

	AiAgent();

	void initializeTransientMembers();

	void activateRecovery();

	void activateMovementEvent();

	void activateWaitEvent();

	void activateAwarenessEvent(CreatureObject* target);

	bool tryRetreat();

	void doRecovery();

	void doMovement();

	void doAwarenessCheck(Coordinate& start, unsigned long long time, CreatureObject* target);

	void checkNewAngle();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void setNextPosition(float x, float z, float y, SceneObject* cell = NULL);

	void updateCurrentPosition(PatrolPoint* point);

	void broadcastNextPositionUpdate(PatrolPoint* point);

	void clearPatrolPoints();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void loadTemplateData(CreatureTemplate* templateData);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	void sendConversationStartTo(SceneObject* player);

	void sendDefaultConversationTo(SceneObject* player);

	void selectConversationOption(int option, SceneObject* obj);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int notifyConverseObservers(CreatureObject* converser);

	int notifyAttack(Observable* observable);

	int notifyCallForHelp(Observable* observable, ManagedObject* arg1);

	void activatePostureRecovery();

	void clearCombatState(bool clearDefenders = true);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDespawnOnNoPlayerInRange(bool val);

	void notifyDespawn(Zone* zone);

	void scheduleDespawn();

	void respawn(Zone* zone, int level);

	void addPatrolPoint(PatrolPoint& point);

	void setHomeLocation(float x, float z, float y, SceneObject* cell = NULL);

	void setRespawnTimer(float resp);

	bool isAttackableBy(CreatureObject* object);

	bool isAggressiveTo(CreatureObject* object);

	void setOblivious();

	void setWatchObject(SceneObject* obj);

	void setStalkObject(SceneObject* obj);

	void setFollowObject(SceneObject* obj);

	void setTargetObject(SceneObject* obj);

	void selectWeapon();

	bool validateStateAttack(CreatureObject* target, String& args);

	bool isRetreating();

	bool isFleeing();

	void clearDespawnEvent();

	float getKinetic();

	float getEnergy();

	float getElectricity();

	float getStun();

	float getBlast();

	float getHeat();

	float getCold();

	float getAcid();

	float getLightSaber();

	bool isStalker();

	bool isKiller();

	unsigned int getFerocity();

	unsigned int getArmor();

	bool getDespawnOnNoPlayerInRange();

	int getNumberOfPlayersInRange();

	DamageMap* getDamageMap();

	String getFactionString();

	String getSocialGroup();

	float getChanceHit();

	int getDamageMin();

	int getDamageMax();

	int getBaseXp();

	unsigned int getDiet();

	CreatureAttackMap* getAttackMap();

	float getRespawnTimer();

	PatrolPoint* getHomeLocation();

	bool isAiAgent();

	void setLootOwner(CreatureObject* owner);

	CreatureObject* getLootOwner();

	bool hasLoot();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	AiAgent(DummyConstructorParameter* param);

	virtual ~AiAgent();

	String _return_getFactionString;
	String _return_getSocialGroup;

	friend class AiAgentHelper;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class AiAgentImplementation : public CreatureObjectImplementation {
protected:
	Reference<AiThinkEvent*> thinkEvent;

	Reference<AiMoveEvent*> moveEvent;

	Reference<AiWaitEvent*> waitEvent;

	Reference<AiAwarenessEvent*> awarenessEvent;

	Vector<String> skillCommands;

	PatrolPointsVector patrolPoints;

	PatrolPoint homeLocation;

	PatrolPoint nextStepPosition;

	DamageMap damageMap;

	SortedVector<ManagedReference<AiObserver* > > aiObserverMap;

	Vector<ManagedReference<WeaponObject* > > weapons;

	CreatureTemplate* npcTemplate;

	SharedObjectTemplate* objectTemplate;

	ManagedReference<CreatureObject* > lootOwner;

	bool baby;

	float currentSpeed;

	bool despawnOnNoPlayerInRange;

	ManagedWeakReference<SceneObject* > followObject;

	unsigned int followState;

	bool fleeing;

	float respawnTimer;

	int numberOfPlayersInRange;

	Reference<DespawnCreatureOnPlayerDissappear*> despawnEvent;

public:
	static const int UPDATEMOVEMENTINTERVAL = 1000;

	unsigned static const int OBLIVIOUS = 0;

	unsigned static const int WATCHING = 1;

	unsigned static const int STALKING = 2;

	unsigned static const int FOLLOWING = 3;

	AiAgentImplementation();

	AiAgentImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	virtual void activateRecovery();

	virtual void activateMovementEvent();

	virtual void activateWaitEvent();

	void activateAwarenessEvent(CreatureObject* target);

	bool tryRetreat();

	void doRecovery();

	void doMovement();

	virtual void doAwarenessCheck(Coordinate& start, unsigned long long time, CreatureObject* target);

	void checkNewAngle();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void setNextPosition(float x, float z, float y, SceneObject* cell = NULL);

	void updateCurrentPosition(PatrolPoint* point);

	void broadcastNextPositionUpdate(PatrolPoint* point);

	void clearPatrolPoints();

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void loadTemplateData(SharedObjectTemplate* templateData);

	void loadTemplateData(CreatureTemplate* templateData);

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient = true);

	void sendConversationStartTo(SceneObject* player);

	void sendDefaultConversationTo(SceneObject* player);

	void selectConversationOption(int option, SceneObject* obj);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int notifyConverseObservers(CreatureObject* converser);

	int notifyAttack(Observable* observable);

	int notifyCallForHelp(Observable* observable, ManagedObject* arg1);

	void activatePostureRecovery();

	void clearCombatState(bool clearDefenders = true);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDespawnOnNoPlayerInRange(bool val);

	void notifyDespawn(Zone* zone);

	virtual void scheduleDespawn();

	void respawn(Zone* zone, int level);

	void addPatrolPoint(PatrolPoint& point);

	void setHomeLocation(float x, float z, float y, SceneObject* cell = NULL);

	void setRespawnTimer(float resp);

	bool isAttackableBy(CreatureObject* object);

	bool isAggressiveTo(CreatureObject* object);

	void setOblivious();

	void setWatchObject(SceneObject* obj);

	void setStalkObject(SceneObject* obj);

	void setFollowObject(SceneObject* obj);

	void setTargetObject(SceneObject* obj);

	void selectWeapon();

	bool validateStateAttack(CreatureObject* target, String& args);

	bool isRetreating();

	bool isFleeing();

	void clearDespawnEvent();

	float getKinetic();

	float getEnergy();

	float getElectricity();

	float getStun();

	float getBlast();

	float getHeat();

	float getCold();

	float getAcid();

	float getLightSaber();

	bool isStalker();

	bool isKiller();

	unsigned int getFerocity();

	unsigned int getArmor();

	bool getDespawnOnNoPlayerInRange();

	int getNumberOfPlayersInRange();

	DamageMap* getDamageMap();

	String getFactionString();

	String getSocialGroup();

	float getChanceHit();

	int getDamageMin();

	int getDamageMax();

	int getBaseXp();

	unsigned int getDiet();

	CreatureAttackMap* getAttackMap();

	float getRespawnTimer();

	PatrolPoint* getHomeLocation();

	bool isAiAgent();

	void setLootOwner(CreatureObject* owner);

	CreatureObject* getLootOwner();

	bool hasLoot();

	AiAgent* _this;

	operator const AiAgent*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~AiAgentImplementation();

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

	friend class AiAgent;
};

class AiAgentAdapter : public CreatureObjectAdapter {
public:
	AiAgentAdapter(AiAgentImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void activateRecovery();

	void activateMovementEvent();

	void activateWaitEvent();

	void activateAwarenessEvent(CreatureObject* target);

	bool tryRetreat();

	void doRecovery();

	void doMovement();

	void checkNewAngle();

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void setNextPosition(float x, float z, float y, SceneObject* cell);

	void clearPatrolPoints();

	int inflictDamage(TangibleObject* attacker, int damageType, int damage, bool destroy, bool notifyClient);

	void sendConversationStartTo(SceneObject* player);

	void sendDefaultConversationTo(SceneObject* player);

	void selectConversationOption(int option, SceneObject* obj);

	int notifyObjectDestructionObservers(TangibleObject* attacker, int condition);

	int notifyConverseObservers(CreatureObject* converser);

	int notifyAttack(Observable* observable);

	int notifyCallForHelp(Observable* observable, ManagedObject* arg1);

	void activatePostureRecovery();

	void clearCombatState(bool clearDefenders);

	void setDefender(SceneObject* defender);

	void addDefender(SceneObject* defender);

	void removeDefender(SceneObject* defender);

	void setDespawnOnNoPlayerInRange(bool val);

	void notifyDespawn(Zone* zone);

	void scheduleDespawn();

	void respawn(Zone* zone, int level);

	void setHomeLocation(float x, float z, float y, SceneObject* cell);

	void setRespawnTimer(float resp);

	bool isAttackableBy(CreatureObject* object);

	bool isAggressiveTo(CreatureObject* object);

	void setOblivious();

	void setWatchObject(SceneObject* obj);

	void setStalkObject(SceneObject* obj);

	void setFollowObject(SceneObject* obj);

	void setTargetObject(SceneObject* obj);

	void selectWeapon();

	bool validateStateAttack(CreatureObject* target, String& args);

	bool isRetreating();

	bool isFleeing();

	void clearDespawnEvent();

	float getKinetic();

	float getEnergy();

	float getElectricity();

	float getStun();

	float getBlast();

	float getHeat();

	float getCold();

	float getAcid();

	float getLightSaber();

	bool isStalker();

	bool isKiller();

	unsigned int getFerocity();

	unsigned int getArmor();

	bool getDespawnOnNoPlayerInRange();

	int getNumberOfPlayersInRange();

	String getFactionString();

	String getSocialGroup();

	float getChanceHit();

	int getDamageMin();

	int getDamageMax();

	int getBaseXp();

	unsigned int getDiet();

	float getRespawnTimer();

	bool isAiAgent();

	void setLootOwner(CreatureObject* owner);

	CreatureObject* getLootOwner();

	bool hasLoot();

protected:
	String _param1_validateStateAttack__CreatureObject_String_;
};

class AiAgentHelper : public DistributedObjectClassHelper, public Singleton<AiAgentHelper> {
	static AiAgentHelper* staticInitializer;

public:
	AiAgentHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<AiAgentHelper>;
};

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

#endif /*AIAGENT_H_*/
