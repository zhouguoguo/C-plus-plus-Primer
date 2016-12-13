#include <iostream>
#include <vector>
using namespace std;

int (*func)(int, int);

auto (*funca)(int, int) -> int;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int multip(int a, int b)
{
	return a * b;
}

int division(int a, int b)
{
	return a / b;
}

int main()
{
	funca = add;
	func = sub;
	vector<int(*)(int, int)> vecF;
	vecF.push_back(funca);
	cout << vecF[0](1, 2) << endl;
	vecF.push_back(func);
	cout << vecF[1](1, 2) << endl;

	funca = multip;
	vecF.push_back(funca);
	cout << vecF[2](1, 2) << endl;
	func = division;
	vecF.push_back(func);
	cout << vecF[3](1, 2) << endl;

	return 0;
}