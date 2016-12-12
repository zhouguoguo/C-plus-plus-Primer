#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char s1[] = "Hello";
	const char s2[] = "World";

	char s3[20];
	strcpy(s3, s1);
	strcat(s3, " ");
	strcat(s3, s2);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}