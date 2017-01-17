#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

bool isOdd(int a)
{
	return a % 2;
}

bool isEven(int a)
{
	return !isOdd(a);
}

int main()
{
	ifstream ifs("infile");
	ofstream ofs1("outfile1"), ofs2("outfile2");
	istream_iterator<int> it(ifs), eof;
	vector<int> vint(it, eof);
	
	ostream_iterator<int> it1(ofs1, " "), it2(ofs2, "\n");

	vector<int> odd, even;
	auto iter = vint.begin();
	while (iter != vint.end())
	{
		if (*iter % 2)
			odd.push_back(*iter);
		else
			even.push_back(*iter);
		++iter;
	}

	copy(odd.begin(), odd.end(), it1);
	copy(even.begin(), even.end(), it2);
}