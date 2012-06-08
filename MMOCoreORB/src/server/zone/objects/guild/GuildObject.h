/*
 *	server/zone/objects/guild/GuildObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef GUILDOBJECT_H_
#define GUILDOBJECT_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace chat {
namespace room {

class ChatRoom;

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace guild {

class GuildTerminal;

} // namespace guild
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::guild;

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

#include "server/zone/objects/guild/GuildMemberList.h"

#include "server/zone/objects/guild/GuildMemberInfo.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/lang/String.h"

#include "system/util/SortedVector.h"

namespace server {
namespace zone {
namespace objects {
namespace guild {

class GuildObject : public SceneObject {
public:
	static const byte PERMISSION_NONE = 0x00;

	static const byte PERMISSION_MAIL = 0x01;

	static const byte PERMISSION_SPONSOR = 0x02;

	static const byte PERMISSION_TITLE = 0x04;

	static const byte PERMISSION_ACCEPT = 0x08;

	static const byte PERMISSION_KICK = 0x10;

	static const byte PERMISSION_WAR = 0x20;

	static const byte PERMISSION_NAME = 0x40;

	static const byte PERMISSION_DISBAND = 0x80;

	static const byte PERMISSION_ALL = 0xFF;

	static const byte WAR_NONE = 0;

	static const byte WAR_MUTUAL = 0x3D;

	static const byte WAR_IN = 0x3C;

	static const byte WAR_OUT = 0x3E;

	GuildObject();

	void sendBaselinesTo(SceneObject* player);

	void broadcastMessage(BaseMessage* msg);

	void broadcastMessage(CreatureObject* player, BaseMessage* msg, bool sendSelf = false);

	void addMember(unsigned long long playerID);

	void removeMember(unsigned long long playerID);

	bool hasMember(unsigned long long playerID);

	GuildMemberInfo* getMember(unsigned long long playerID);

	unsigned long long getMember(int index);

	void addSponsoredPlayer(unsigned long long playerID);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool hasSponsoredPlayer(unsigned long long playerID);

	unsigned long long getSponsoredPlayer(int idx);

	int getSponsoredPlayerCount();

	void setChatRoom(ChatRoom* room);

	ChatRoom* getChatRoom();

	int getTotalMembers();

	unsigned long long getGuildLeaderID();

	GuildMemberList* getGuildMemberList();

	String getGuildAbbrev();

	void setGuildAbbrev(const String& abbrev);

	void setGuildLeaderID(unsigned long long leaderID);

	void setGuildID(unsigned int id);

	unsigned int getGuildID();

	void setGuildName(const String& gname);

	String getGuildName();

	String getGuildKey();

	bool isGuildObject();

	bool isGuildLeader(CreatureObject* player);

	byte getWarStatus(unsigned long long guildoid);

	void setWarStatus(unsigned long long guildoid, byte status);

	bool isInWaringGuild(CreatureObject* creature);

	bool isAtWarWith(unsigned long long guildoid);

	bool hasDeclaredWarOn(unsigned long long guildoid);

	bool hasDeclaredWarBy(unsigned long long guildoid);

	VectorMap<unsigned long long, byte>* getWaringGuilds();

	bool hasMailPermission(unsigned long long playerID);

	bool hasSponsorPermission(unsigned long long playerID);

	bool hasAcceptPermission(unsigned long long playerID);

	bool hasDisbandPermission(unsigned long long playerID);

	bool hasKickPermission(unsigned long long playerID);

	bool hasNamePermission(unsigned long long playerID);

	bool hasTitlePermission(unsigned long long playerID);

	bool hasWarPermission(unsigned long long playerID);

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	GuildObject(DummyConstructorParameter* param);

	virtual ~GuildObject();

	friend class GuildObjectHelper;
};

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;

namespace server {
namespace zone {
namespace objects {
namespace guild {

class GuildObjectImplementation : public SceneObjectImplementation {
protected:
	ManagedReference<ChatRoom* > chatRoom;

	GuildMemberList guildMembers;

	SortedVector<unsigned long long> sponsoredPlayers;

	VectorMap<unsigned long long, byte> waringGuilds;

	unsigned int guildID;

	String guildName;

	String guildAbbrev;

	unsigned long long guildLeaderID;

public:
	static const byte PERMISSION_NONE = 0x00;

	static const byte PERMISSION_MAIL = 0x01;

	static const byte PERMISSION_SPONSOR = 0x02;

	static const byte PERMISSION_TITLE = 0x04;

	static const byte PERMISSION_ACCEPT = 0x08;

	static const byte PERMISSION_KICK = 0x10;

	static const byte PERMISSION_WAR = 0x20;

	static const byte PERMISSION_NAME = 0x40;

	static const byte PERMISSION_DISBAND = 0x80;

	static const byte PERMISSION_ALL = 0xFF;

	static const byte WAR_NONE = 0;

	static const byte WAR_MUTUAL = 0x3D;

	static const byte WAR_IN = 0x3C;

	static const byte WAR_OUT = 0x3E;

	GuildObjectImplementation();

	GuildObjectImplementation(DummyConstructorParameter* param);

	void sendBaselinesTo(SceneObject* player);

	void broadcastMessage(BaseMessage* msg);

	void broadcastMessage(CreatureObject* player, BaseMessage* msg, bool sendSelf = false);

	void addMember(unsigned long long playerID);

	void removeMember(unsigned long long playerID);

	bool hasMember(unsigned long long playerID);

	GuildMemberInfo* getMember(unsigned long long playerID);

	unsigned long long getMember(int index);

	void addSponsoredPlayer(unsigned long long playerID);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool hasSponsoredPlayer(unsigned long long playerID);

	unsigned long long getSponsoredPlayer(int idx);

	int getSponsoredPlayerCount();

	void setChatRoom(ChatRoom* room);

	ChatRoom* getChatRoom();

	int getTotalMembers();

	unsigned long long getGuildLeaderID();

	GuildMemberList* getGuildMemberList();

	String getGuildAbbrev();

	void setGuildAbbrev(const String& abbrev);

	void setGuildLeaderID(unsigned long long leaderID);

	void setGuildID(unsigned int id);

	unsigned int getGuildID();

	void setGuildName(const String& gname);

	String getGuildName();

	String getGuildKey();

	bool isGuildObject();

	bool isGuildLeader(CreatureObject* player);

	byte getWarStatus(unsigned long long guildoid);

	void setWarStatus(unsigned long long guildoid, byte status);

	bool isInWaringGuild(CreatureObject* creature);

	bool isAtWarWith(unsigned long long guildoid);

	bool hasDeclaredWarOn(unsigned long long guildoid);

	bool hasDeclaredWarBy(unsigned long long guildoid);

	VectorMap<unsigned long long, byte>* getWaringGuilds();

	bool hasMailPermission(unsigned long long playerID);

	bool hasSponsorPermission(unsigned long long playerID);

	bool hasAcceptPermission(unsigned long long playerID);

	bool hasDisbandPermission(unsigned long long playerID);

	bool hasKickPermission(unsigned long long playerID);

	bool hasNamePermission(unsigned long long playerID);

	bool hasTitlePermission(unsigned long long playerID);

	bool hasWarPermission(unsigned long long playerID);

	WeakReference<GuildObject*> _this;

	operator const GuildObject*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~GuildObjectImplementation();

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

	friend class GuildObject;
};

class GuildObjectAdapter : public SceneObjectAdapter {
public:
	GuildObjectAdapter(GuildObject* impl);

	void invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void sendBaselinesTo(SceneObject* player);

	void broadcastMessage(BaseMessage* msg);

	void broadcastMessage(CreatureObject* player, BaseMessage* msg, bool sendSelf);

	void addMember(unsigned long long playerID);

	void removeMember(unsigned long long playerID);

	bool hasMember(unsigned long long playerID);

	unsigned long long getMember(int index);

	void addSponsoredPlayer(unsigned long long playerID);

	void removeSponsoredPlayer(unsigned long long playerID);

	bool hasSponsoredPlayer(unsigned long long playerID);

	unsigned long long getSponsoredPlayer(int idx);

	int getSponsoredPlayerCount();

	void setChatRoom(ChatRoom* room);

	ChatRoom* getChatRoom();

	int getTotalMembers();

	unsigned long long getGuildLeaderID();

	String getGuildAbbrev();

	void setGuildAbbrev(const String& abbrev);

	void setGuildLeaderID(unsigned long long leaderID);

	void setGuildID(unsigned int id);

	unsigned int getGuildID();

	void setGuildName(const String& gname);

	String getGuildName();

	String getGuildKey();

	bool isGuildObject();

	bool isGuildLeader(CreatureObject* player);

	byte getWarStatus(unsigned long long guildoid);

	void setWarStatus(unsigned long long guildoid, byte status);

	bool isInWaringGuild(CreatureObject* creature);

	bool isAtWarWith(unsigned long long guildoid);

	bool hasDeclaredWarOn(unsigned long long guildoid);

	bool hasDeclaredWarBy(unsigned long long guildoid);

	bool hasMailPermission(unsigned long long playerID);

	bool hasSponsorPermission(unsigned long long playerID);

	bool hasAcceptPermission(unsigned long long playerID);

	bool hasDisbandPermission(unsigned long long playerID);

	bool hasKickPermission(unsigned long long playerID);

	bool hasNamePermission(unsigned long long playerID);

	bool hasTitlePermission(unsigned long long playerID);

	bool hasWarPermission(unsigned long long playerID);

};

class GuildObjectHelper : public DistributedObjectClassHelper, public Singleton<GuildObjectHelper> {
	static GuildObjectHelper* staticInitializer;

public:
	GuildObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<GuildObjectHelper>;
};

} // namespace guild
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::guild;

#endif /*GUILDOBJECT_H_*/
