/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef POWERBOOSTCOMMAND_H_
#define POWERBOOSTCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/player/PlayerManager.h"
#include "server/zone/objects/creature/CreatureAttribute.h"

#include "server/zone/objects/creature/buffs/PowerBoostBuff.h"

class PowerBoostCommand : public QueueCommand {
public:

	PowerBoostCommand(const String& name, ZoneProcessServerImplementation* server)
		: QueueCommand(name, server) {
	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		if(!creature->isMeditating()){
			creature->sendSystemMessage("teraskasi", "powerboost_fail");
			return GENERALERROR;
		}

		PlayerCreature* player = (PlayerCreature*) creature;

		uint32 buffcrc = BuffCRC::SKILL_BUFF_POWERBOOST;

		if(player->hasBuff(buffcrc)){
			if(player->isMeditating()){
				player->sendSystemMessage("teraskasi", "powerboost_active");
				return GENERALERROR;
			}
		}

		if(player->isMeditating()){
			int baseMind = player->getBaseHAM(CreatureAttribute::MIND);

			float hamBonus = (float)baseMind * 0.5;
			int pbBonus = (int)hamBonus;

			int meditateMod = player->getSkillMod("meditate");
			int duration = 300 + (3 * meditateMod);

			if(player->getHAM(CreatureAttribute::MIND) <= pbBonus){
				player->sendSystemMessage("teraskasi", "powerboost_mind");
				return GENERALERROR;
			}

			player->addMaxHAM(CreatureAttribute::MIND, -pbBonus, true);
			const String buffname = "skill.buff.powerboost";
			ManagedReference<Buff*> buff = new PowerBoostBuff(player, buffname, buffname.hashCode(), pbBonus, duration);
			player->addBuff(buff);
		}

		return SUCCESS;
	}

};

#endif //POWERBOOSTCOMMAND_H_
