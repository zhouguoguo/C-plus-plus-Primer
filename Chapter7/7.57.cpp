#include <iostream>
#include <vector>
using namespace std;

class Account {
public:
	Account() = default;
	void calculate() {amount += amount*intereatRate;}
	static double get_rate() {return intereatRate;}
	static void set_rate(double);

private:
	double amount;
	string owner;
	static constexpr double rate = 6;
	static constexpr double intereatRate = 1;
	static double initRate() {return 0;}
	static constexpr int period = 30;
	double daily_tbl[period];
//	static vector<double> vec(2);
};

vector<double> vecT(2);

//double Account::intereatRate = initRate();
const int Account::period;

void Account::set_rate(double newRate)
{
//	intereatRate = newRate;
}

int main()
{
	Account a;
	return 0;
}