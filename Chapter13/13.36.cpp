#include <set>
#include <iostream>
#include "Folder.h"
#include "Message.h"
using namespace std;

void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders) {
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->addMsg(&rhs);
	}
}



int main()
{
	Folder f;
	Message m;
	m.save(f);

	return 0;
}