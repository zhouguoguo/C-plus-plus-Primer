#ifndef _FOLDER_H_
#define _FOLDER_H_
#include <set>
#include "Folder.h"
using std::set;
class Message;

class Folder {
public:
	Folder() {};

	void addMsg(Message*);
	void remMsg(Message*);
private:
	set<Message*> messages;
};


#endif