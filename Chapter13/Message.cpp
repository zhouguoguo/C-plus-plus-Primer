#include "Message.h"

Message::Message(const Message& m) :
				contents(m.contents), 
				folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::~Message()
{
	remove_from_folders();
}

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFolder(Folder* f)
{
	folders.insert(f);
}

void Message::remFolder(Folder* f)
{
	folders.erase(f);
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

void Message::remove_from_folders()
{
	for (auto f : folders) {
		f->remMsg(this);
	}
}