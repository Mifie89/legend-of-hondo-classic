/*
 * ChatRequestPersistentMessageCallback.h
 *
 *  Created on: 13/03/2010
 *      Author: victor
 */

#ifndef CHATREQUESTPERSISTENTMESSAGECALLBACK_H_
#define CHATREQUESTPERSISTENTMESSAGECALLBACK_H_

#include "../MessageCallback.h"
#include "server/chat/ChatManager.h"

class ChatRequestPersistentMessageCallback : public MessageCallback {
	uint32 mailid;

public:
	ChatRequestPersistentMessageCallback(ZoneClientSession* client, ZoneProcessServerImplementation* server) :
		MessageCallback(client, server) {
	}

	void parse(Message* message) {
		message->shiftOffset(4); //skip spacer/unk
		mailid = message->parseInt();
	}

	void run() {
		ManagedReference<PlayerCreature*> player = (PlayerCreature*) client->getPlayer();

		if (player == NULL)
			return;

		ChatManager* chatManager = server->getChatManager();
		chatManager->handleRequestPersistentMsg(player, mailid);
	}

};


#endif /* CHATREQUESTPERSISTENTMESSAGECALLBACK_H_ */
