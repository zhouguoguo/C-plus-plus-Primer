#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};

	int *start = begin(a);
	int *ends = end(a);
	int *p = start;

	while (p != ends) {
		*p = 0;
		++p;
	}
	for (p = start; p != ends; ++p) {
		cout << *p << " ";
	}
}