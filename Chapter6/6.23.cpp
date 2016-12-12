#include <iostream>

using namespace std;

void print(int i, const int (&j)[3])
{
	cout << i << endl;
	cout << j[0] << endl;
}

int main(int argc, char **argv)
{
	int i = 0;
	int j[] = {1, 2, 3};
	print(i, j);
	return 0;
}