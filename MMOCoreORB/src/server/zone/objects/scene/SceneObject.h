/*
 *	server/zone/objects/scene/SceneObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {

class ZoneProcessServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

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
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

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
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

namespace server {
namespace zone {
namespace objects {
namespace area {

class ActiveArea;

} // namespace area
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::area;

namespace server {
namespace zone {
namespace objects {
namespace region {

class CityRegion;

} // namespace region
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::region;

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

#include "engine/core/ManagedObject.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/scene/ObserverEventType.h"

#include "server/zone/ZoneReference.h"

#include "server/zone/objects/scene/SceneObjectType.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/TransferErrorCode.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/SessionFacadeType.h"

#include "server/zone/objects/scene/ObserverType.h"

#include "server/zone/managers/templates/PlanetMapCategory.h"

#include "server/zone/managers/templates/TemplateManager.h"

#include "server/zone/objects/scene/components/ZoneComponent.h"

#include "server/zone/objects/scene/components/ObjectMenuComponent.h"

#include "server/zone/objects/scene/components/ContainerComponent.h"

#include "engine/log/Logger.h"

#include "engine/core/ManagedReference.h"

#include "engine/util/u3d/Coordinate.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "system/io/Serializable.h"

#include "engine/lua/Lua.h"

#include "engine/lua/LuaObject.h"

#include "system/util/Vector.h"

#include "system/util/VectorMap.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/service/proto/BasePacket.h"

#include "engine/service/proto/BaseMessage.h"

#include "system/util/SortedVector.h"

#include "system/lang/StackTrace.h"

#include "system/lang/ref/Reference.h"

#include "engine/core/Task.h"

#include "engine/util/u3d/Vector3.h"

#include "engine/util/Observable.h"

#include "engine/util/Observer.h"

#include "engine/util/u3d/Matrix4.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject : public QuadTreeEntry {
public:
	SceneObject();

	void initializePrivateData();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void createComponents();

	void createContainerComponent();

	void initializeTransientMembers();

	void notifyLoadFromDatabase();

	void info(const String& msg, bool forced = false);

	void error(const String& msg);

	int inRangeObjects(unsigned int gameObjectType, float range);

	bool isInRange(SceneObject* obj, float range);

	bool transferObject(SceneObject* object, int containmentType, bool notifyClient = false);

	bool removeObject(SceneObject* object, SceneObject* destination, bool notifyClient = false);

	void destroyObjectFromWorld(bool sendSelfDestroy);

	int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	int notifyObjectInsertedToChild(SceneObject* object, SceneObject* child, SceneObject* oldParent);

	int notifyObjectRemovedFromChild(SceneObject* object, SceneObject* child);

	void synchronizedUIListen(SceneObject* player, int value);

	void synchronizedUIStopListen(SceneObject* player, int value);

	void updateToDatabase();

	void updateToDatabaseWithoutChildren();

	void updateToDatabaseAllObjects(bool startTask);

	void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	int canBeDestroyed(CreatureObject* player);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void close(ZoneClientSession* client);

	void link(ZoneClientSession* client, unsigned int containmentType = 4);

	BaseMessage* link(unsigned long long objectID, unsigned int containmentType = 4);

	void sendTo(SceneObject* player, bool doClose);

	void sendWithoutParentTo(SceneObject* player);

	void sendWithoutContainerObjectsTo(SceneObject* player);

	void sendDestroyTo(SceneObject* player);

	void sendBaselinesTo(SceneObject* player);

	void sendContainerObjectsTo(SceneObject* player);

	void sendSlottedObjectsTo(SceneObject* player);

	void sendToOwner(bool doClose = true);

	void sendAttributeListTo(CreatureObject* object);

	void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	void openContainerTo(CreatureObject* player);

	void closeContainerTo(CreatureObject* player, bool notify = true);

	void notifyInsertToZone(Zone* zone);

	void switchZone(const String& newTerrainName, float newPostionX, float newPositionZ, float newPositionY, unsigned long long parentID = 0);

	void teleport(float newPositionX, float newPositionZ, float newPositionY, unsigned long long parentID = 0);

	void updateDirection(float fw, float fx, float fy, float fz);

	void updateDirection(float angleHeadingRadians);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	void notifyRemoveFromZone();

	void updateZone(bool lightUpdate, bool sendPackets = true);

	void updateZoneWithParent(SceneObject* newParent, bool lightUpdate, bool sendPackets = true);

	void broadcastMessage(BasePacket* message, bool sendSelf, bool lockZone = true);

	void broadcastObject(SceneObject* object, bool sendSelf);

	void broadcastDestroy(SceneObject* object, bool sendSelf);

	void broadcastMessages(Vector<BasePacket*>* messages, bool sendSelf);

	void sendMessage(BasePacket* msg);

	int compareTo(SceneObject* obj);

	void getSlottedObjects(VectorMap<String, ManagedReference<SceneObject* > >& objects);

	unsigned long long getParentID();

	void addPendingTask(const String& name, Task* task, int miliseconds);

	void removePendingTask(const String& name);

	Task* getPendingTask(const String& name);

	bool containsPendingTask(const String& name);

	void showFlyText(const String& file, const String& uax, byte red, byte green, byte blue);

	Facade* getActiveSession(unsigned int type);

	void addActiveSession(unsigned int type, Facade* session);

	bool containsActiveSession(unsigned int type);

	bool dropActiveSession(unsigned int type);

	int getActiveSessionsCount();

	VectorMap<unsigned int, ManagedReference<Facade* > >* getObjectActiveSessions();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	float getDistanceTo(SceneObject* object);

	float getDistanceTo(Coordinate* coordinate);

	void updateVehiclePosition();

	int notifyObjectInserted(SceneObject* object);

	int notifyObjectRemoved(SceneObject* object);

	void addActiveArea(ActiveArea* area);

	void dropActiveArea(ActiveArea* area);

	bool hasActiveArea(ActiveArea* area);

	Vector<ManagedReference<ActiveArea* > >* getActiveAreas();

	int getActiveAreasSize();

	ActiveArea* getActiveRegion();

	CityRegion* getCityRegion();

	void setCityRegion(CityRegion* region);

	Zone* getZone();

	Zone* getLocalZone();

	unsigned long long getObjectID();

	Vector3 getCoordinate(float distance, float angleDegrees);

	Vector3 getWorldCoordinate(float distance, float angleDegrees);

	float getWorldPositionX();

	float getWorldPositionY();

	float getWorldPositionZ();

	Vector3 getWorldPosition();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	Quaternion* getDirection();

	unsigned int getClientObjectCRC();

	unsigned int getServerObjectCRC();

	bool isWaypointObject();

	StringId* getObjectName();

	String getObjectNameStringIdFile();

	String getObjectNameStringIdName();

	String getDetailedDescription();

	void setDetailedDescription(const String& detail);

	int getArrangementDescriptorSize();

	String getArrangementDescriptor(int idx);

	String getSlotDescriptor(int idx);

	bool hasSlotDescriptor(const String& descr);

	VectorMap<String, ManagedReference<SceneObject* > >* getSlottedObjects();

	SceneObject* getSlottedObject(const String& slot);

	int getSlotDescriptorSize();

	SceneObject* getSlottedObject(int idx);

	void dropSlottedObject(const String& arrengementDescriptor);

	void removeSlottedObject(int index);

	int getContainerObjectsSize();

	int getSlottedObjectsSize();

	bool hasFullContainerObjects();

	unsigned int getContainerVolumeLimit();

	SceneObject* getContainerObject(int idx);

	VectorMap<unsigned long long, ManagedReference<SceneObject* > >* getContainerObjects();

	bool hasObjectInContainer(unsigned long long objectID);

	bool hasObjectInSlottedContainer(SceneObject* object);

	SceneObject* getContainerObject(unsigned long long objectID);

	void removeAllContainerObjects();

	void putInContainer(SceneObject* obj, unsigned long long key);

	void removeFromContainerObjects(int index);

	void setContainerVolumeLimit(int lim);

	void setContainerType(int type);

	unsigned int getContainerType();

	ZoneClientSession* getClient();

	unsigned int getGameObjectType();

	unsigned int getClientGameObjectType();

	unsigned int getContainmentType();

	float getDirectionAngle();

	float getSpecialDirectionAngle();

	void rotate(int degrees);

	void faceObject(SceneObject* obj);

	void notifySelfPositionUpdate();

	void notifyPositionUpdate(QuadTreeEntry* entry);

	void notifyCloseContainer(CreatureObject* player);

	unsigned int getMovementCounter();

	SceneObject* getParent();

	ZoneServer* getZoneServer();

	SceneObject* getRootParent();

	SceneObject* getParentRecursively(unsigned int gameObjectType);

	bool isASubChildOf(SceneObject* object);

	UnicodeString getCustomObjectName();

	String getLoggingName();

	bool isPlayerCreature();

	bool isVendor();

	ZoneComponent* getZoneComponent();

	ObjectMenuComponent* getObjectMenuComponent();

	bool isContainerFull();

	bool isShuttleInstallation();

	bool isPlayerObject();

	bool isActiveArea();

	bool isRegion();

	bool isCreatureObject();

	bool isShipObject();

	bool isVehicleObject();

	bool isBuildingObject();

	bool isCloningBuildingObject();

	bool isGarage();

	bool isWeaponObject();

	bool isWearableObject();

	bool isArmorObject();

	bool isPsgArmorObject();

	bool isLairObject();

	bool isCellObject();

	bool isTangibleObject();

	bool isResourceContainer();

	bool isComponent();

	bool isIntangibleObject();

	bool isInstrument();

	bool isInstallationObject();

	bool isGeneratorObject();

	bool isCityTerminal();

	bool isCityVoteTerminal();

	bool isFactory();

	bool isFactoryCrate();

	bool isFishingPoleObject();

	bool isDeedObject();

	bool isVehicleDeedObject();

	bool isBuildingDeed();

	bool isSignObject();

	bool isInstallationDeed();

	bool isCraftingTool();

	bool isCraftingStation();

	bool isManufactureSchematic();

	bool isStructureObject();

	bool isFishingBait();

	bool isAttachment();

	bool isCampKit();

	bool isCampStructure();

	void setGameObjectType(unsigned int type);

	void setClientObjectCRC(unsigned int objCRC);

	void setServerObjectCRC(unsigned int objCRC);

	void setZoneProcessServer(ZoneProcessServer* srv);

	void setZone(Zone* zone);

	void setObjectName(StringId& stringID);

	void setDirection(float fw, float fx, float fy, float fz);

	void setDirection(float headingAngleRadians);

	void setDirection(const Quaternion& dir);

	void setMovementCounter(unsigned int count);

	void incrementMovementCounter();

	void setContainmentType(unsigned int type);

	void setLoggingName(const String& name);

	void setClientObject(bool val);

	unsigned int getPlanetCRC();

	bool isStaticObject();

	bool isContainerObject();

	bool isTerminal();

	bool isGroupObject();

	bool isGuildObject();

	bool isControlDevice();

	bool isMissionTerminal();

	bool isMissionObject();

	int getPlanetMapCategoryCRC();

	int getPlanetMapSubCategoryCRC();

	void setPlanetMapCategory(PlanetMapCategory* pmc);

	void setPlanetMapSubCategory(PlanetMapCategory* pmc);

	PlanetMapCategory* getPlanetMapCategory();

	PlanetMapCategory* getPlanetMapSubCategory();

	SortedVector<ManagedReference<SceneObject* > >* getChildObjects();

	bool containsChildObject(SceneObject* obj);

	SharedObjectTemplate* getObjectTemplate();

	SortedVector<ManagedReference<Observer* > >* getObservers(unsigned int eventType);

	void createChildObjects();

	Matrix4* getTransformForCollisionMatrix();

	void setTransformForCollisionMatrix(Matrix4* mat);

	void initializeChildObject(SceneObject* controllerObject);

	bool isInWater();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	SceneObject(DummyConstructorParameter* param);

	virtual ~SceneObject();

	String _return_getArrangementDescriptor;
	String _return_getDetailedDescription;
	String _return_getLoggingName;
	String _return_getObjectNameStringIdFile;
	String _return_getObjectNameStringIdName;
	String _return_getSlotDescriptor;

	UnicodeString _return_getCustomObjectName;

	friend class SceneObjectHelper;
};

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObjectImplementation : public QuadTreeEntryImplementation, public Logger {
protected:
	ManagedReference<ZoneProcessServer* > server;

	Reference<ZoneComponent* > zoneComponent;

	Reference<ObjectMenuComponent* > objectMenuComponent;

	Reference<ContainerComponent* > containerComponent;

	Reference<Matrix4* > transformForCollisionMatrix;

	VectorMap<String, ManagedReference<SceneObject* > > slottedObjects;

	VectorMap<unsigned long long, ManagedReference<SceneObject* > > containerObjects;

	unsigned int containerType;

	unsigned int containerVolumeLimit;

	ZoneReference zone;

	ManagedWeakReference<CityRegion* > cityRegion;

	SortedVector<ManagedReference<ActiveArea* > > activeAreas;

	SortedVector<ManagedReference<SceneObject* > > childObjects;

	unsigned int serverObjectCRC;

	unsigned int clientObjectCRC;

	Quaternion direction;

	unsigned int movementCounter;

	StringId objectName;

	PendingTasksMap pendingTasks;

	bool staticObject;

	VectorMap<unsigned int, ManagedReference<Facade* > > objectActiveSessions;

	unsigned int gameObjectType;

	unsigned int clientGameObjectType;

	unsigned int containmentType;

	int planetMapCategory;

	int planetMapSubCategory;

	Reference<SharedObjectTemplate* > templateObject;

public:
	SceneObjectImplementation();

	SceneObjectImplementation(DummyConstructorParameter* param);

	void finalize();

	void initializePrivateData();

	virtual void loadTemplateData(SharedObjectTemplate* templateData);

	virtual void createComponents();

	virtual void createContainerComponent();

	void initializeTransientMembers();

	virtual void notifyLoadFromDatabase();

	void info(const String& msg, bool forced = false);

	void error(const String& msg);

	int inRangeObjects(unsigned int gameObjectType, float range);

	bool isInRange(SceneObject* obj, float range);

	virtual bool transferObject(SceneObject* object, int containmentType, bool notifyClient = false);

	virtual bool removeObject(SceneObject* object, SceneObject* destination, bool notifyClient = false);

	virtual void destroyObjectFromWorld(bool sendSelfDestroy);

	virtual int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	virtual int notifyObjectInsertedToChild(SceneObject* object, SceneObject* child, SceneObject* oldParent);

	virtual int notifyObjectRemovedFromChild(SceneObject* object, SceneObject* child);

	virtual void synchronizedUIListen(SceneObject* player, int value);

	virtual void synchronizedUIStopListen(SceneObject* player, int value);

	void updateToDatabase();

	void updateToDatabaseWithoutChildren();

	void updateToDatabaseAllObjects(bool startTask);

	virtual void destroyObjectFromDatabase(bool destroyContainedObjects = false);

	virtual int canBeDestroyed(CreatureObject* player);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void close(ZoneClientSession* client);

	void link(ZoneClientSession* client, unsigned int containmentType = 4);

	BaseMessage* link(unsigned long long objectID, unsigned int containmentType = 4);

	virtual void sendTo(SceneObject* player, bool doClose);

	virtual void sendWithoutParentTo(SceneObject* player);

	virtual void sendWithoutContainerObjectsTo(SceneObject* player);

	virtual void sendDestroyTo(SceneObject* player);

	virtual void sendBaselinesTo(SceneObject* player);

	virtual void sendContainerObjectsTo(SceneObject* player);

	virtual void sendSlottedObjectsTo(SceneObject* player);

	virtual void sendToOwner(bool doClose = true);

	virtual void sendAttributeListTo(CreatureObject* object);

	virtual void fillAttributeList(AttributeListMessage* msg, CreatureObject* object);

	virtual void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	virtual void fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player);

	virtual void openContainerTo(CreatureObject* player);

	virtual void closeContainerTo(CreatureObject* player, bool notify = true);

	virtual void notifyInsertToZone(Zone* zone);

	virtual void switchZone(const String& newTerrainName, float newPostionX, float newPositionZ, float newPositionY, unsigned long long parentID = 0);

	virtual void teleport(float newPositionX, float newPositionZ, float newPositionY, unsigned long long parentID = 0);

	void updateDirection(float fw, float fx, float fy, float fz);

	void updateDirection(float angleHeadingRadians);

	void notifyInsert(QuadTreeEntry* entry);

	void notifyDissapear(QuadTreeEntry* entry);

	virtual void notifyRemoveFromZone();

	virtual void updateZone(bool lightUpdate, bool sendPackets = true);

	virtual void updateZoneWithParent(SceneObject* newParent, bool lightUpdate, bool sendPackets = true);

	void broadcastMessage(BasePacket* message, bool sendSelf, bool lockZone = true);

	void broadcastObject(SceneObject* object, bool sendSelf);

	void broadcastDestroy(SceneObject* object, bool sendSelf);

	void broadcastMessages(Vector<BasePacket*>* messages, bool sendSelf);

	virtual void sendMessage(BasePacket* msg);

	int compareTo(SceneObject* obj);

	void getSlottedObjects(VectorMap<String, ManagedReference<SceneObject* > >& objects);

	unsigned long long getParentID();

	void addPendingTask(const String& name, Task* task, int miliseconds);

	void removePendingTask(const String& name);

	Task* getPendingTask(const String& name);

	bool containsPendingTask(const String& name);

	void showFlyText(const String& file, const String& uax, byte red, byte green, byte blue);

	Facade* getActiveSession(unsigned int type);

	void addActiveSession(unsigned int type, Facade* session);

	bool containsActiveSession(unsigned int type);

	bool dropActiveSession(unsigned int type);

	int getActiveSessionsCount();

	VectorMap<unsigned int, ManagedReference<Facade* > >* getObjectActiveSessions();

	virtual int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	float getDistanceTo(SceneObject* object);

	float getDistanceTo(Coordinate* coordinate);

	void updateVehiclePosition();

	virtual int notifyObjectInserted(SceneObject* object);

	virtual int notifyObjectRemoved(SceneObject* object);

	void addActiveArea(ActiveArea* area);

	void dropActiveArea(ActiveArea* area);

	bool hasActiveArea(ActiveArea* area);

	Vector<ManagedReference<ActiveArea* > >* getActiveAreas();

	int getActiveAreasSize();

	ActiveArea* getActiveRegion();

	virtual CityRegion* getCityRegion();

	void setCityRegion(CityRegion* region);

	Zone* getZone();

	Zone* getLocalZone();

	unsigned long long getObjectID();

	Vector3 getCoordinate(float distance, float angleDegrees);

	Vector3 getWorldCoordinate(float distance, float angleDegrees);

	float getWorldPositionX();

	float getWorldPositionY();

	float getWorldPositionZ();

	Vector3 getWorldPosition();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	Quaternion* getDirection();

	unsigned int getClientObjectCRC();

	unsigned int getServerObjectCRC();

	bool isWaypointObject();

	StringId* getObjectName();

	String getObjectNameStringIdFile();

	String getObjectNameStringIdName();

	virtual String getDetailedDescription();

	virtual void setDetailedDescription(const String& detail);

	int getArrangementDescriptorSize();

	String getArrangementDescriptor(int idx);

	String getSlotDescriptor(int idx);

	bool hasSlotDescriptor(const String& descr);

	VectorMap<String, ManagedReference<SceneObject* > >* getSlottedObjects();

	SceneObject* getSlottedObject(const String& slot);

	int getSlotDescriptorSize();

	SceneObject* getSlottedObject(int idx);

	void dropSlottedObject(const String& arrengementDescriptor);

	void removeSlottedObject(int index);

	int getContainerObjectsSize();

	int getSlottedObjectsSize();

	bool hasFullContainerObjects();

	unsigned int getContainerVolumeLimit();

	SceneObject* getContainerObject(int idx);

	VectorMap<unsigned long long, ManagedReference<SceneObject* > >* getContainerObjects();

	bool hasObjectInContainer(unsigned long long objectID);

	bool hasObjectInSlottedContainer(SceneObject* object);

	SceneObject* getContainerObject(unsigned long long objectID);

	void removeAllContainerObjects();

	void putInContainer(SceneObject* obj, unsigned long long key);

	void removeFromContainerObjects(int index);

	void setContainerVolumeLimit(int lim);

	void setContainerType(int type);

	unsigned int getContainerType();

	virtual ZoneClientSession* getClient();

	unsigned int getGameObjectType();

	unsigned int getClientGameObjectType();

	unsigned int getContainmentType();

	float getDirectionAngle();

	float getSpecialDirectionAngle();

	void rotate(int degrees);

	void faceObject(SceneObject* obj);

	virtual void notifySelfPositionUpdate();

	void notifyPositionUpdate(QuadTreeEntry* entry);

	virtual void notifyCloseContainer(CreatureObject* player);

	unsigned int getMovementCounter();

	SceneObject* getParent();

	ZoneServer* getZoneServer();

	SceneObject* getRootParent();

	SceneObject* getParentRecursively(unsigned int gameObjectType);

	bool isASubChildOf(SceneObject* object);

	UnicodeString getCustomObjectName();

	String getLoggingName();

	virtual bool isPlayerCreature();

	virtual bool isVendor();

	ZoneComponent* getZoneComponent();

	ObjectMenuComponent* getObjectMenuComponent();

	bool isContainerFull();

	bool isShuttleInstallation();

	bool isPlayerObject();

	virtual bool isActiveArea();

	virtual bool isRegion();

	virtual bool isCreatureObject();

	virtual bool isShipObject();

	virtual bool isVehicleObject();

	virtual bool isBuildingObject();

	virtual bool isCloningBuildingObject();

	bool isGarage();

	virtual bool isWeaponObject();

	virtual bool isWearableObject();

	virtual bool isArmorObject();

	virtual bool isPsgArmorObject();

	virtual bool isLairObject();

	virtual bool isCellObject();

	virtual bool isTangibleObject();

	virtual bool isResourceContainer();

	virtual bool isComponent();

	virtual bool isIntangibleObject();

	bool isInstrument();

	virtual bool isInstallationObject();

	virtual bool isGeneratorObject();

	virtual bool isCityTerminal();

	virtual bool isCityVoteTerminal();

	virtual bool isFactory();

	virtual bool isFactoryCrate();

	bool isFishingPoleObject();

	virtual bool isDeedObject();

	virtual bool isVehicleDeedObject();

	virtual bool isBuildingDeed();

	virtual bool isSignObject();

	virtual bool isInstallationDeed();

	virtual bool isCraftingTool();

	virtual bool isCraftingStation();

	virtual bool isManufactureSchematic();

	virtual bool isStructureObject();

	bool isFishingBait();

	virtual bool isAttachment();

	virtual bool isCampKit();

	virtual bool isCampStructure();

	void setGameObjectType(unsigned int type);

	void setClientObjectCRC(unsigned int objCRC);

	void setServerObjectCRC(unsigned int objCRC);

	void setZoneProcessServer(ZoneProcessServer* srv);

	void setZone(Zone* zone);

	void setObjectName(StringId& stringID);

	void setDirection(float fw, float fx, float fy, float fz);

	void setDirection(float headingAngleRadians);

	void setDirection(const Quaternion& dir);

	void setMovementCounter(unsigned int count);

	void incrementMovementCounter();

	void setContainmentType(unsigned int type);

	void setLoggingName(const String& name);

	void setClientObject(bool val);

	virtual unsigned int getPlanetCRC();

	bool isStaticObject();

	virtual bool isContainerObject();

	virtual bool isTerminal();

	virtual bool isGroupObject();

	virtual bool isGuildObject();

	virtual bool isControlDevice();

	virtual bool isMissionTerminal();

	virtual bool isMissionObject();

	int getPlanetMapCategoryCRC();

	int getPlanetMapSubCategoryCRC();

	void setPlanetMapCategory(PlanetMapCategory* pmc);

	void setPlanetMapSubCategory(PlanetMapCategory* pmc);

	PlanetMapCategory* getPlanetMapCategory();

	PlanetMapCategory* getPlanetMapSubCategory();

	SortedVector<ManagedReference<SceneObject* > >* getChildObjects();

	bool containsChildObject(SceneObject* obj);

	SharedObjectTemplate* getObjectTemplate();

	SortedVector<ManagedReference<Observer* > >* getObservers(unsigned int eventType);

	virtual void createChildObjects();

	Matrix4* getTransformForCollisionMatrix();

	void setTransformForCollisionMatrix(Matrix4* mat);

	virtual void initializeChildObject(SceneObject* controllerObject);

	bool isInWater();

	WeakReference<SceneObject*> _this;

	operator const SceneObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~SceneObjectImplementation();

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

	friend class SceneObject;
};

class SceneObjectAdapter : public QuadTreeEntryAdapter {
public:
	SceneObjectAdapter(SceneObject* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializePrivateData();

	void createComponents();

	void createContainerComponent();

	void initializeTransientMembers();

	void notifyLoadFromDatabase();

	void info(const String& msg, bool forced);

	void error(const String& msg);

	int inRangeObjects(unsigned int gameObjectType, float range);

	bool isInRange(SceneObject* obj, float range);

	bool transferObject(SceneObject* object, int containmentType, bool notifyClient);

	bool removeObject(SceneObject* object, SceneObject* destination, bool notifyClient);

	void destroyObjectFromWorld(bool sendSelfDestroy);

	int canAddObject(SceneObject* object, int containmentType, String& errorDescription);

	int notifyObjectInsertedToChild(SceneObject* object, SceneObject* child, SceneObject* oldParent);

	int notifyObjectRemovedFromChild(SceneObject* object, SceneObject* child);

	void synchronizedUIListen(SceneObject* player, int value);

	void synchronizedUIStopListen(SceneObject* player, int value);

	void updateToDatabase();

	void updateToDatabaseWithoutChildren();

	void updateToDatabaseAllObjects(bool startTask);

	void destroyObjectFromDatabase(bool destroyContainedObjects);

	int canBeDestroyed(CreatureObject* player);

	void create(ZoneClientSession* client);

	void destroy(ZoneClientSession* client);

	void close(ZoneClientSession* client);

	void link(ZoneClientSession* client, unsigned int containmentType);

	BaseMessage* link(unsigned long long objectID, unsigned int containmentType);

	void sendTo(SceneObject* player, bool doClose);

	void sendWithoutParentTo(SceneObject* player);

	void sendWithoutContainerObjectsTo(SceneObject* player);

	void sendDestroyTo(SceneObject* player);

	void sendBaselinesTo(SceneObject* player);

	void sendContainerObjectsTo(SceneObject* player);

	void sendSlottedObjectsTo(SceneObject* player);

	void sendToOwner(bool doClose);

	void sendAttributeListTo(CreatureObject* object);

	void setCustomObjectName(const UnicodeString& name, bool notifyClient);

	void openContainerTo(CreatureObject* player);

	void closeContainerTo(CreatureObject* player, bool notify);

	void notifyInsertToZone(Zone* zone);

	void switchZone(const String& newTerrainName, float newPostionX, float newPositionZ, float newPositionY, unsigned long long parentID);

	void teleport(float newPositionX, float newPositionZ, float newPositionY, unsigned long long parentID);

	void updateDirection(float fw, float fx, float fy, float fz);

	void updateDirection(float angleHeadingRadians);

	void notifyRemoveFromZone();

	void updateZone(bool lightUpdate, bool sendPackets);

	void updateZoneWithParent(SceneObject* newParent, bool lightUpdate, bool sendPackets);

	void broadcastMessage(BasePacket* message, bool sendSelf, bool lockZone);

	void broadcastObject(SceneObject* object, bool sendSelf);

	void broadcastDestroy(SceneObject* object, bool sendSelf);

	void sendMessage(BasePacket* msg);

	int compareTo(SceneObject* obj);

	unsigned long long getParentID();

	bool containsPendingTask(const String& name);

	void showFlyText(const String& file, const String& uax, byte red, byte green, byte blue);

	Facade* getActiveSession(unsigned int type);

	void addActiveSession(unsigned int type, Facade* session);

	bool containsActiveSession(unsigned int type);

	bool dropActiveSession(unsigned int type);

	int getActiveSessionsCount();

	int handleObjectMenuSelect(CreatureObject* player, byte selectedID);

	float getDistanceTo(SceneObject* object);

	void updateVehiclePosition();

	int notifyObjectInserted(SceneObject* object);

	int notifyObjectRemoved(SceneObject* object);

	void addActiveArea(ActiveArea* area);

	void dropActiveArea(ActiveArea* area);

	bool hasActiveArea(ActiveArea* area);

	int getActiveAreasSize();

	ActiveArea* getActiveRegion();

	CityRegion* getCityRegion();

	void setCityRegion(CityRegion* region);

	Zone* getZone();

	Zone* getLocalZone();

	unsigned long long getObjectID();

	float getWorldPositionX();

	float getWorldPositionY();

	float getWorldPositionZ();

	float getDirectionX();

	float getDirectionZ();

	float getDirectionY();

	float getDirectionW();

	unsigned int getClientObjectCRC();

	unsigned int getServerObjectCRC();

	bool isWaypointObject();

	String getObjectNameStringIdFile();

	String getObjectNameStringIdName();

	void setDetailedDescription(const String& detail);

	int getArrangementDescriptorSize();

	String getArrangementDescriptor(int idx);

	String getSlotDescriptor(int idx);

	bool hasSlotDescriptor(const String& descr);

	SceneObject* getSlottedObject(const String& slot);

	int getSlotDescriptorSize();

	SceneObject* getSlottedObject(int idx);

	void dropSlottedObject(const String& arrengementDescriptor);

	void removeSlottedObject(int index);

	int getContainerObjectsSize();

	int getSlottedObjectsSize();

	bool hasFullContainerObjects();

	unsigned int getContainerVolumeLimit();

	SceneObject* getContainerObject(int idx);

	bool hasObjectInContainer(unsigned long long objectID);

	bool hasObjectInSlottedContainer(SceneObject* object);

	SceneObject* getContainerObject(unsigned long long objectID);

	void removeAllContainerObjects();

	void putInContainer(SceneObject* obj, unsigned long long key);

	void removeFromContainerObjects(int index);

	void setContainerVolumeLimit(int lim);

	void setContainerType(int type);

	unsigned int getContainerType();

	ZoneClientSession* getClient();

	unsigned int getGameObjectType();

	unsigned int getClientGameObjectType();

	unsigned int getContainmentType();

	float getDirectionAngle();

	float getSpecialDirectionAngle();

	void rotate(int degrees);

	void faceObject(SceneObject* obj);

	void notifySelfPositionUpdate();

	void notifyPositionUpdate(QuadTreeEntry* entry);

	void notifyCloseContainer(CreatureObject* player);

	unsigned int getMovementCounter();

	SceneObject* getParent();

	ZoneServer* getZoneServer();

	SceneObject* getRootParent();

	SceneObject* getParentRecursively(unsigned int gameObjectType);

	bool isASubChildOf(SceneObject* object);

	UnicodeString getCustomObjectName();

	String getLoggingName();

	bool isPlayerCreature();

	bool isVendor();

	bool isContainerFull();

	bool isShuttleInstallation();

	bool isPlayerObject();

	bool isActiveArea();

	bool isRegion();

	bool isCreatureObject();

	bool isShipObject();

	bool isVehicleObject();

	bool isBuildingObject();

	bool isCloningBuildingObject();

	bool isGarage();

	bool isWeaponObject();

	bool isWearableObject();

	bool isArmorObject();

	bool isPsgArmorObject();

	bool isLairObject();

	bool isCellObject();

	bool isTangibleObject();

	bool isResourceContainer();

	bool isComponent();

	bool isIntangibleObject();

	bool isInstrument();

	bool isInstallationObject();

	bool isGeneratorObject();

	bool isCityTerminal();

	bool isCityVoteTerminal();

	bool isFactory();

	bool isFactoryCrate();

	bool isFishingPoleObject();

	bool isDeedObject();

	bool isVehicleDeedObject();

	bool isBuildingDeed();

	bool isSignObject();

	bool isInstallationDeed();

	bool isCraftingTool();

	bool isCraftingStation();

	bool isManufactureSchematic();

	bool isStructureObject();

	bool isFishingBait();

	bool isAttachment();

	bool isCampKit();

	bool isCampStructure();

	void setGameObjectType(unsigned int type);

	void setClientObjectCRC(unsigned int objCRC);

	void setServerObjectCRC(unsigned int objCRC);

	void setZone(Zone* zone);

	void setDirection(float fw, float fx, float fy, float fz);

	void setDirection(float headingAngleRadians);

	void setMovementCounter(unsigned int count);

	void incrementMovementCounter();

	void setContainmentType(unsigned int type);

	void setLoggingName(const String& name);

	void setClientObject(bool val);

	unsigned int getPlanetCRC();

	bool isStaticObject();

	bool isContainerObject();

	bool isTerminal();

	bool isGroupObject();

	bool isGuildObject();

	bool isControlDevice();

	bool isMissionTerminal();

	bool isMissionObject();

	int getPlanetMapCategoryCRC();

	int getPlanetMapSubCategoryCRC();

	bool containsChildObject(SceneObject* obj);

	void createChildObjects();

	void initializeChildObject(SceneObject* controllerObject);

	bool isInWater();

protected:
	String _param0_info__String_bool_;
	String _param0_error__String_;
	String _param2_canAddObject__SceneObject_int_String_;
	UnicodeString _param0_setCustomObjectName__UnicodeString_bool_;
	String _param0_switchZone__String_float_float_float_long_;
	String _param0_containsPendingTask__String_;
	String _param0_showFlyText__String_String_byte_byte_byte_;
	String _param1_showFlyText__String_String_byte_byte_byte_;
	String _param0_setDetailedDescription__String_;
	String _param0_hasSlotDescriptor__String_;
	String _param0_getSlottedObject__String_;
	String _param0_dropSlottedObject__String_;
	String _param0_setLoggingName__String_;
};

class SceneObjectHelper : public DistributedObjectClassHelper, public Singleton<SceneObjectHelper> {
	static SceneObjectHelper* staticInitializer;

public:
	SceneObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<SceneObjectHelper>;
};

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#endif /*SCENEOBJECT_H_*/
