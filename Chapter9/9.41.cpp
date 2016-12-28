#include <vector>
#include <iostream>
using namespace std;

void print(const vector<char>& vec)
{
	for (auto a : vec) {
		cout << a << " ";
	}
	cout << "\nvec.size = " << vec.size()
		 << " vec.capacity = " << vec.capacity() << endl;
}

int main()
{
	vector<char> chvec(5, 'h');
	print(chvec);
	string s(chvec.cbegin(), chvec.cend());
	cout << s << endl;
	return 0;
}