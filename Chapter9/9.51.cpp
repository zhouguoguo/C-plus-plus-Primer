#include <string>
#include <iostream>
#include <sstream>
using namespace std;

unsigned month_mapping(const string& str)
{
	if (str == "Jan" || str == "January") return 1;
	if (str == "Feb" || str == "February") return 2;
	if (str == "Mar" || str == "March") return 3;
	if (str == "Apr" || str == "April") return 4;
	if (str == "May" || str == "May") return 5;
	if (str == "Jun" || str == "June") return 6;
	if (str == "Jul" || str == "July") return 7;
	if (str == "Aug" || str == "August") return 8;
	if (str == "Sep" || str == "September") return 9;
	if (str == "Oct" || str == "October") return 10;
	if (str == "Nov" || str == "November") return 11;
	if (str == "Dec" || str == "December") return 12;
	else return 0;
}

class Date {
public:
	Date() {}
	Date(const string& str);

	void print()
	{
		cout << m_year << " " 
			 << m_month << " " 
			 << m_day << endl;
	};
private:
	unsigned m_year=1900;
	unsigned m_month=1;
	unsigned m_day=1;

};

Date::Date(const string& str)
{
	//type 1: "1/1/1990"
	string::size_type pos = 0;
	if((pos = str.find('/')) != string::npos) {
		string::size_type pos_d = 0;
		string::size_type pos_m = 0;

		pos_d = str.find('/');
		string day = str.substr(0, pos_d);
		m_day = stoi(day);

		pos_m = str.find('/', pos_d+1);
		string month = str.substr(pos_d+1, pos_m);
		m_month = stoi(month);

		string year = str.substr(pos_m+1);
		m_year = stoi(year);
	}
	else {
	//type2: "Jan 1 1900"
	//type3: "January 1, 1900"
		istringstream istr(str);
		string word;
		istr >> word;
		m_month = month_mapping(word);

		istr >> word;
		m_day = stoi(word);

		istr >> word;
		m_year = stoi(word);
	}
	
}

int main()
{
	Date date1;
	date1.print();
	Date birth("May 26, 2016");
	birth.print();
	Date preg("12/8/2015");
	preg.print();
	Date today("Jan 4 2017");
	today.print();
}