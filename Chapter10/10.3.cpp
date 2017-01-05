#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vint(10, 3);
	int sum = accumulate(vint.cbegin(), vint.cend(), 0);
	cout << sum << endl;

	vector<double> vd(10, 3.11);
	double sum_d = accumulate(vd.cbegin(), vd.cend(), 0.0);
	cout << sum_d << endl;

	vector<const char*> c1 = {"hash", "baby"};
	vector<const char*> c2 = {"hash", "babys", "is"};

	cout << equal(c1.cbegin(), c1.cend(), c2.cbegin()) << endl;
}