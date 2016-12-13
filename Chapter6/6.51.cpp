#include <iostream>
using namespace std;

int f()
{
	cout << __FUNCTION__ << "1" << endl;
}

void f(int a)
{
	cout << __FUNCTION__ << "2" << endl;
}

void f(int a, int b)
{
	cout << __FUNCTION__ << "3" << endl;
}

void f(double a, double b = 3.14)
{
	cout << __FUNCTION__ << "4" << endl;
}

int main()
{
//	f(2.56, 42); //wrong
	f(42); //f2
	f(42, 0); //f3
	f(2.56, 3.14); //f4
	return 0;
}