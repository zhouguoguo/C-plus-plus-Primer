#include <iostream>
#include <string>

using namespace std;

typedef string strT[10];
using strarr = string[10];


string str[10] = {"ok", "baby"};

strarr& f()
{
	return str;
}

strT& f1()
{
	return str;
}

auto g() -> string(&)[10]
{
	return str;
}

decltype(str) &h()
{
	return str;
}

int main()
{
	cout << f()[0] << f()[1] << endl;
	cout << f1()[0] << f1()[1] << endl;
	cout << g()[1] << g()[0] << endl;
	cout << h()[1] << h()[1] << endl;
	return 0;
}