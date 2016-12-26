#include <iostream>
#include <forward_list>

using namespace std;

void print(const forward_list<int>& il)
{
	for (auto iter = il.cbegin(); iter != il.cend(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void rmOdd(forward_list<int>& flst)
{
	auto pre = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2 == 1) {
			curr = flst.erase_after(pre);
		}
		else {
			pre = curr;
			++curr;
		}
	}
}

int main()
{
	forward_list<int> fint = {0,1,2,3,4,5,6,7,8};
	print(fint);

	rmOdd(fint);
	print(fint);
	return 0;
}