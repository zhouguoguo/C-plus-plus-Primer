#include "Folder.h"

void Folder::addMsg(Message* msg)
{
	messages.insert(msg);
}

void Folder::remMsg(Message* msg)
{
	messages.erase(msg);
}