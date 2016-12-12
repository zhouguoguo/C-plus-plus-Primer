#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	int a = 0, b = 0;

	while (cin >> a >> b) {
		try {
			if (b == 0) {
				throw exception();
			}
			cout << a / b << endl;
		}
		catch (exception err){
			cout << err.what() << "\nTry again? Enter y or n:\n";
			char c;
			cin >> c;
			if (!cin || c != 'y') break;
		}
	}
	return 0;
}