#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> list = {55, 60, 70, 80, 90, 100};

	for (auto grade : list) {
		cout << (grade >= 90 ? "High Pass" 
			                 : (grade >= 75 ? "Pass" 
			                 	            : (grade >= 60 ? "Low Pass"
			                 	            			   : "Fail")));
		cout << endl;
	}
	return 0;
}