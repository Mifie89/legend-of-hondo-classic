/*
 *	server/zone/managers/city/CityManager.h generated by engine3 IDL compiler 0.60
 */

#ifndef CITYMANAGER_H_
#define CITYMANAGER_H_

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
namespace building {
namespace city {

class CityHallObject;

} // namespace city
} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building::city;

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
namespace scene {
namespace variables {

class ParameterizedStringId;

} // namespace variables
} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene::variables;

#include "engine/core/ManagedService.h"

#include "engine/log/Logger.h"

#include "system/util/SortedVector.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace city {

class CityManager : public ManagedService {
public:
	static const byte NEWCITY = 0;

	static const byte OUTPOST = 1;

	static const byte VILLAGE = 2;

	static const byte TOWNSHIP = 3;

	static const byte CITY = 4;

	static const byte METROPOLIS = 5;

	CityManager(Zone* zne);

	void loadLuaConfig();

	void createNewCity(CityHallObject* city, PlayerCreature* player, const String& name);

	void changeCityName(CityHallObject* city, PlayerCreature* player, const String& name);

	bool validateCityName(const String& name);

	void sendMailToMayor(CityHallObject* city, const String& sendername, const UnicodeString& subject, ParameterizedStringId& body);

	void sendMailToAllCitizens(CityHallObject* city, const String& sendername, const UnicodeString& subject, ParameterizedStringId& body);

	void handleCityAdvancement(CityHallObject* city);

	void expandCity(CityHallObject* city);

	void contractCity(CityHallObject* city);

	void destroyCity(CityHallObject* city);

	void declareCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail = true);

	void revokeCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail = true);

	void addMilitiaMember(CityHallObject* city, PlayerCreature* player, const String& citizenName);

	void removeMilitiaMember(CityHallObject* city, PlayerCreature* player, unsigned long long playerID);

	bool checkCitiesCappedAtRank(byte rank);

	byte getCitiesAllowed(byte rank);

	void addCity(CityHallObject* city);

	int getTotalCities();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	CityManager(DummyConstructorParameter* param);

	virtual ~CityManager();

	friend class CityManagerHelper;
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

namespace server {
namespace zone {
namespace managers {
namespace city {

class CityManagerImplementation : public ManagedServiceImplementation, public Logger {
	ManagedWeakReference<Zone* > zone;

public:
	static Vector<byte> radiusPerRank;

	static Vector<byte> citizensPerRank;

	VectorMap<unsigned long long, ManagedReference<CityHallObject* > > cities;

	static int cityUpdateInterval;

	static int newCityGracePeriod;

private:
	Vector<byte> citiesAllowedPerRank;

public:
	static const byte NEWCITY = 0;

	static const byte OUTPOST = 1;

	static const byte VILLAGE = 2;

	static const byte TOWNSHIP = 3;

	static const byte CITY = 4;

	static const byte METROPOLIS = 5;

	CityManagerImplementation(Zone* zne);

	CityManagerImplementation(DummyConstructorParameter* param);

	void loadLuaConfig();

	void createNewCity(CityHallObject* city, PlayerCreature* player, const String& name);

	void changeCityName(CityHallObject* city, PlayerCreature* player, const String& name);

	bool validateCityName(const String& name);

	void sendMailToMayor(CityHallObject* city, const String& sendername, const UnicodeString& subject, ParameterizedStringId& body);

	void sendMailToAllCitizens(CityHallObject* city, const String& sendername, const UnicodeString& subject, ParameterizedStringId& body);

	void handleCityAdvancement(CityHallObject* city);

	void expandCity(CityHallObject* city);

	void contractCity(CityHallObject* city);

	void destroyCity(CityHallObject* city);

	void declareCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail = true);

	void revokeCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail = true);

	void addMilitiaMember(CityHallObject* city, PlayerCreature* player, const String& citizenName);

	void removeMilitiaMember(CityHallObject* city, PlayerCreature* player, unsigned long long playerID);

	bool checkCitiesCappedAtRank(byte rank);

	byte getCitiesAllowed(byte rank);

	void addCity(CityHallObject* city);

	int getTotalCities();

	CityManager* _this;

	operator const CityManager*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~CityManagerImplementation();

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

	friend class CityManager;
};

class CityManagerAdapter : public ManagedServiceAdapter {
public:
	CityManagerAdapter(CityManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadLuaConfig();

	void createNewCity(CityHallObject* city, PlayerCreature* player, const String& name);

	void changeCityName(CityHallObject* city, PlayerCreature* player, const String& name);

	bool validateCityName(const String& name);

	void handleCityAdvancement(CityHallObject* city);

	void expandCity(CityHallObject* city);

	void contractCity(CityHallObject* city);

	void destroyCity(CityHallObject* city);

	void declareCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail);

	void revokeCitizenship(CityHallObject* city, PlayerCreature* player, bool sendMail);

	void addMilitiaMember(CityHallObject* city, PlayerCreature* player, const String& citizenName);

	void removeMilitiaMember(CityHallObject* city, PlayerCreature* player, unsigned long long playerID);

	bool checkCitiesCappedAtRank(byte rank);

	byte getCitiesAllowed(byte rank);

	void addCity(CityHallObject* city);

	int getTotalCities();

protected:
	String _param2_createNewCity__CityHallObject_PlayerCreature_String_;
	String _param2_changeCityName__CityHallObject_PlayerCreature_String_;
	String _param0_validateCityName__String_;
	String _param2_addMilitiaMember__CityHallObject_PlayerCreature_String_;
};

class CityManagerHelper : public DistributedObjectClassHelper, public Singleton<CityManagerHelper> {
	static CityManagerHelper* staticInitializer;

public:
	CityManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<CityManagerHelper>;
};

} // namespace city
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::city;

#endif /*CITYMANAGER_H_*/
