/*
 *	server/zone/objects/player/sessions/EntertainingSession.h generated by engine3 IDL compiler 0.60
 */

#ifndef ENTERTAININGSESSION_H_
#define ENTERTAININGSESSION_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

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

class Instrument;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace events {

class EntertainingSessionTask;

} // namespace events
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::events;

namespace server {
namespace zone {
namespace objects {
namespace player {

class EntertainingObserver;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class Instrument;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

#include "engine/core/ManagedObject.h"

#include "server/zone/objects/player/EntertainingData.h"

#include "server/zone/objects/player/EntertainingDataMap.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedReference.h"

#include "engine/util/Facade.h"

#include "system/lang/ref/Reference.h"

#include "engine/core/Task.h"

#include "system/util/SortedVector.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class EntertainingSession : public Facade {
public:
	EntertainingSession(CreatureObject* ent);

	void doEntertainerPatronEffects();

	void doPerformanceAction();

	void addEntertainerFlourishBuff();

	void startDancing(const String& dance, const String& animation);

	void startPlayingMusic(const String& song, const String& instrumentAnimation, int instrid);

	void startEntertaining();

	void healWounds(CreatureObject* creature, float woundHeal, float shockHeal);

	bool isInEntertainingBuilding(CreatureObject* creature);

	void doFlourish(int flourishNumber);

	bool canHealBattleFatigue();

	bool canGiveEntertainBuff();

	void addFlourishXp(int xp);

	void addHealingXp(int xp);

	void addHealingXpGroup(int xp);

	int initializeSession();

	int cancelSession();

	int clearSession();

	void stopPlayingMusic();

	void stopDancing();

	void activateAction();

	void startTickTask();

	void addEntertainerBuffDuration(CreatureObject* creature, int performanceType, float duration);

	void addEntertainerBuffStrength(CreatureObject* creature, int performanceType, float strength);

	void setEntertainerBuffDuration(CreatureObject* creature, int performanceType, float duration);

	void setEntertainerBuffStrength(CreatureObject* creature, int performanceType, float strength);

	int getEntertainerBuffStrength(CreatureObject* creature, int performanceType);

	int getEntertainerBuffDuration(CreatureObject* creature, int performanceType);

	int getEntertainerBuffStartTime(CreatureObject* creature, int performanceType);

	void sendEntertainingUpdate(CreatureObject* creature, float entval, const String& performance, unsigned int perfcntr, int instrid);

	void sendEntertainmentUpdate(CreatureObject* creature, unsigned long long entid, const String& mood, bool updateEntValue = false);

	void activateEntertainerBuff(CreatureObject* creature, int performanceType);

	Instrument* getInstrument(CreatureObject* creature);

	void addWatcher(CreatureObject* creature);

	void addListener(CreatureObject* listener);

	bool isDancing();

	bool isPlayingMusic();

	bool isAcceptingBandFlourishes();

	void setAcceptingBandFlourishes(bool val);

	void removeWatcher(CreatureObject* creature);

	void removeListener(CreatureObject* creature);

	void setPerformanceName(const String& name);

	void setDancing(bool val);

	void setTargetInstrument(bool var);

	void updateEntertainerMissionStatus(bool entertaining, const int missionType);

	bool isInDenyServiceList(CreatureObject* target);

	void addToDenyServiceList(CreatureObject* target);

	void removeFromDenyServiceList(CreatureObject* target);

	void increaseEntertainerBuff(CreatureObject* patron);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	EntertainingSession(DummyConstructorParameter* param);

	virtual ~EntertainingSession();

	friend class EntertainingSessionHelper;
};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace sessions {

class EntertainingSessionImplementation : public FacadeImplementation {
protected:
	ManagedWeakReference<CreatureObject* > entertainer;

	ManagedReference<EntertainingObserver* > observer;

	EntertainingDataMap watchers;

	EntertainingDataMap listeners;

	SortedVector<ManagedReference<CreatureObject* > > denyServiceList;

	Reference<EntertainingSessionTask* > tickTask;

	Time nextTick;

	String performanceName;

	bool dancing;

	bool playingMusic;

	int flourishXp;

	int healingXp;

	int flourishCount;

	bool acceptingBandFlourishes;

	bool targetInstrument;

	ManagedReference<Instrument* > externalInstrument;

public:
	EntertainingSessionImplementation(CreatureObject* ent);

	EntertainingSessionImplementation(DummyConstructorParameter* param);

	void doEntertainerPatronEffects();

	void doPerformanceAction();

	void addEntertainerFlourishBuff();

	void startDancing(const String& dance, const String& animation);

	void startPlayingMusic(const String& song, const String& instrumentAnimation, int instrid);

	void startEntertaining();

	void finalize();

	void healWounds(CreatureObject* creature, float woundHeal, float shockHeal);

	bool isInEntertainingBuilding(CreatureObject* creature);

	void doFlourish(int flourishNumber);

	bool canHealBattleFatigue();

	bool canGiveEntertainBuff();

	void addFlourishXp(int xp);

	void addHealingXp(int xp);

	void addHealingXpGroup(int xp);

	int initializeSession();

	int cancelSession();

	int clearSession();

	void stopPlayingMusic();

	void stopDancing();

	void activateAction();

	void startTickTask();

	void addEntertainerBuffDuration(CreatureObject* creature, int performanceType, float duration);

	void addEntertainerBuffStrength(CreatureObject* creature, int performanceType, float strength);

	void setEntertainerBuffDuration(CreatureObject* creature, int performanceType, float duration);

	void setEntertainerBuffStrength(CreatureObject* creature, int performanceType, float strength);

	int getEntertainerBuffStrength(CreatureObject* creature, int performanceType);

	int getEntertainerBuffDuration(CreatureObject* creature, int performanceType);

	int getEntertainerBuffStartTime(CreatureObject* creature, int performanceType);

	void sendEntertainingUpdate(CreatureObject* creature, float entval, const String& performance, unsigned int perfcntr, int instrid);

	void sendEntertainmentUpdate(CreatureObject* creature, unsigned long long entid, const String& mood, bool updateEntValue = false);

	void activateEntertainerBuff(CreatureObject* creature, int performanceType);

	Instrument* getInstrument(CreatureObject* creature);

	void addWatcher(CreatureObject* creature);

	void addListener(CreatureObject* listener);

	bool isDancing();

	bool isPlayingMusic();

	bool isAcceptingBandFlourishes();

	void setAcceptingBandFlourishes(bool val);

	void removeWatcher(CreatureObject* creature);

	void removeListener(CreatureObject* creature);

	void setPerformanceName(const String& name);

	void setDancing(bool val);

	void setTargetInstrument(bool var);

	void updateEntertainerMissionStatus(bool entertaining, const int missionType);

	bool isInDenyServiceList(CreatureObject* target);

	void addToDenyServiceList(CreatureObject* target);

	void removeFromDenyServiceList(CreatureObject* target);

	void increaseEntertainerBuff(CreatureObject* patron);

	WeakReference<EntertainingSession*> _this;

	operator const EntertainingSession*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~EntertainingSessionImplementation();

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

	friend class EntertainingSession;
};

class EntertainingSessionAdapter : public FacadeAdapter {
public:
	EntertainingSessionAdapter(EntertainingSession* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void doEntertainerPatronEffects();

	void doPerformanceAction();

	void addEntertainerFlourishBuff();

	void startDancing(const String& dance, const String& animation);

	void startPlayingMusic(const String& song, const String& instrumentAnimation, int instrid);

	void startEntertaining();

	void finalize();

	void healWounds(CreatureObject* creature, float woundHeal, float shockHeal);

	bool isInEntertainingBuilding(CreatureObject* creature);

	void doFlourish(int flourishNumber);

	bool canHealBattleFatigue();

	bool canGiveEntertainBuff();

	void addFlourishXp(int xp);

	void addHealingXp(int xp);

	void addHealingXpGroup(int xp);

	int initializeSession();

	int cancelSession();

	int clearSession();

	void stopPlayingMusic();

	void stopDancing();

	void activateAction();

	void startTickTask();

	int getEntertainerBuffStrength(CreatureObject* creature, int performanceType);

	int getEntertainerBuffDuration(CreatureObject* creature, int performanceType);

	int getEntertainerBuffStartTime(CreatureObject* creature, int performanceType);

	void sendEntertainingUpdate(CreatureObject* creature, float entval, const String& performance, unsigned int perfcntr, int instrid);

	void sendEntertainmentUpdate(CreatureObject* creature, unsigned long long entid, const String& mood, bool updateEntValue);

	void activateEntertainerBuff(CreatureObject* creature, int performanceType);

	Instrument* getInstrument(CreatureObject* creature);

	void addWatcher(CreatureObject* creature);

	void addListener(CreatureObject* listener);

	bool isDancing();

	bool isPlayingMusic();

	bool isAcceptingBandFlourishes();

	void setAcceptingBandFlourishes(bool val);

	void removeWatcher(CreatureObject* creature);

	void removeListener(CreatureObject* creature);

	void setPerformanceName(const String& name);

	void setDancing(bool val);

	void setTargetInstrument(bool var);

	void updateEntertainerMissionStatus(bool entertaining, const int missionType);

	bool isInDenyServiceList(CreatureObject* target);

	void addToDenyServiceList(CreatureObject* target);

	void removeFromDenyServiceList(CreatureObject* target);

	void increaseEntertainerBuff(CreatureObject* patron);

};

class EntertainingSessionHelper : public DistributedObjectClassHelper, public Singleton<EntertainingSessionHelper> {
	static EntertainingSessionHelper* staticInitializer;

public:
	EntertainingSessionHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<EntertainingSessionHelper>;
};

} // namespace sessions
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::sessions;

#endif /*ENTERTAININGSESSION_H_*/
