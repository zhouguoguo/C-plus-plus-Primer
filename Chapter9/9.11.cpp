#include <vector>
#include <iostream>
using namespace std;

void print(const vector<int>& vec)
{
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec;
	print(vec);
	vector<int> vec1{0,1,2,3,4,5,6,7};
	print(vec1);
	vector<int> vec2 = {9,8,7,6,5,4};
	print(vec2);
	vector<int> vec3(vec2);
	print(vec3);
	vector<int> vec4(vec1.cbegin(), vec1.cend());
	print(vec4);
	vector<int> vec5(vec4.cbegin(), vec4.cbegin()+2);
	print(vec5);
	vector<int> vec6(10, -1);
	print(vec6);
	vector<int> vec7(15);
	print(vec7);
	return 0;
}