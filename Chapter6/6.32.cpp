#include <iostream>

using namespace std;

int& get(int* array, int index)
{
	return array[index];
}

int main()
{
	int a[10];
	for (int i = 0; i != 10; ++i)
	{
		get(a, i) = i;
		cout << a[i] << endl;
	}

	return 0;
}