#include <iostream>

using namespace std;

inline bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

constexpr inline bool isSmaller(int a1, int a2)
{
	return a1 < a2;
}

int main()
{
	cout << isShorter("aaa", "bbbb") << endl;
	cout << isSmaller(1,3) << endl;
	return 0;
}