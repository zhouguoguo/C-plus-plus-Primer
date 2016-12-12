#include <iostream>

using namespace std;

int main()
{
	char ch;
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spCnt = 0;
	while (cin >> ch) {
		switch (ch) {
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++spCnt;
			break;
		}
	}
	cout << aCnt << endl;
	cout << eCnt << endl;
	cout << iCnt << endl;
	cout << oCnt << endl;
	cout << uCnt << endl;
	cout << spCnt << endl;
	return 0;
}