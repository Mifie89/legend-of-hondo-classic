/*
 * TangibleObject.cpp
 *
 *  Created on: Sep 6, 2009
 *      Author: theanswer
 */

#include "TangibleObject.h"

TangibleObject::TangibleObject(LuaObject* templateData) : SceneObject(templateData) {

}

void TangibleObject::parseBaseline3(Message* message) {
	complexity = message->parseFloat();

	objectName.parse(message);

	volume = message->parseInt();

	message->parseAscii(custString);

	message->parseInt();
	message->parseInt();

	optionsBitmask = message->parseInt();
	count = message->parseInt();
	conditionDamage = message->parseInt(),
	maxCondition = message->parseInt();

	unknown = message->parseByte();

	String fullPath;
	objectName.getFullPath(fullPath);
	UnicodeString customName;
	customName = objectName.getCustomString();

	if (customName.length() > 0)
		setLoggingName(getLoggingName() + " [" + customName.toString() + "]");

	info("parsed tano baseline 3 " + fullPath + " " + customName.toString(), true);
}

void TangibleObject::parseBaseline6(Message* message) {

}
