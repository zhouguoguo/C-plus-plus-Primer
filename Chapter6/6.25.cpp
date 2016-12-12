#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	char a[100] = "";
	cout << a << endl;
	strcat(a, argv[1]);
	strcat(a, argv[2]);

	cout << a << endl;

	while (*argv) {
		cout << *argv << endl;
		++argv;
	}

	return 0;
}