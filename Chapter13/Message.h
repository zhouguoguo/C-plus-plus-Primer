#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <set>
#include <string>
#include "Folder.h"
using namespace std;

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	Message(const string& s = "") : contents(s) {}
	Message(const Message&); // value
	Message& operator=(const Message&); // 
	~Message();

	void save(Folder&);
	void remove(Folder&);

	void addFolder(Folder*);
	void remFolder(Folder*);
private:
	string contents;
	set<Folder*> folders;

	
	void add_to_Folders(const Message&);
	void remove_from_folders();
};

#endif