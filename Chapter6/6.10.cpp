#include <iostream>

using namespace std;

void swap(int* a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int i = 10, j = 22;
	cout << i << " " << j << endl;
	swap(&i, &j);
	cout << i << " " << j << endl;
	return 0;
}