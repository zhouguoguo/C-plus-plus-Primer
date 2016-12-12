#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int aCnt = 0;
	unsigned int spaceCnt = 0, tCnt = 0, nCnt = 0;
	unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;

	string str;
	char c;
	while (cin.get(c)) {
			switch(c) {
			case 'a':
				++aCnt;
				break;
			case 'f':
				if (cin.peek() == 'f') {
					cin.get();
					++ffCnt;
				}
				else if (cin.peek() == 'i') {
					cin.get();
					++fiCnt;
				}
				else if (cin.peek() == 'l'){
					cin.get();
					++flCnt;
				}
				break;
			case ' ':
				++spaceCnt;
				break;
			case '\t':
				++tCnt;
				break;
			case '\n':
				++nCnt;
				break;
			}
	}
	cout << aCnt << endl;
	cout << spaceCnt << endl;
	cout << tCnt << endl;
	cout << nCnt << endl;
	cout << ffCnt << endl;
	cout << fiCnt << endl;
	cout << flCnt << endl;

	return 0;

}