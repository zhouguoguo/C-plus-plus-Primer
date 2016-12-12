#include <vector>
#include <iterator>

using namespace std;
//bool compare(matrix& m1, matrix&m2);

vector<int>::iterator change_val(int, vector<int>::iterator);
double calc(double);
int count(const string&, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

int main()
{
	calc(66);
	count("asdf", 'a');
	sum(vec.begin(), vec.end(), 3.8);
	return 0;
}