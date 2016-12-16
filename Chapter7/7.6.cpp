#include <iostream>

using namespace std;

struct Sales_data {
	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
	double ave_price() {
		if (units_solds == 0) return 0;
		return revenue / units_solds;
	}
	std::string bookNo;
	unsigned units_solds = 0;
	double revenue = 0.0;
};

istream& Read(istream& is, Sales_data &in_data)
{
	double price = 0.0;
	is >> in_data.bookNo >> in_data.units_solds >> price;
	in_data.revenue = price * in_data.units_solds;
}

Sales_data add(const Sales_data& data1, const Sales_data& data2)
{
	Sales_data res;
	res.combine(data1);
	res.combine(data2);
	return res;
}

ostream& print(ostream& os, Sales_data& data)
{
	os << data.bookNo << " sold " << 
	      data.units_solds << 
	      " copies, average price is " <<
	      data.ave_price() <<
	      " total revenue is " <<
	      data.revenue;
	return os;
}

Sales_data& Sales_data::combine(const Sales_data& data)
{
	units_solds += data.units_solds;
	revenue += data.revenue;
	return *this;
}

int main()
{
	Sales_data total;
	if (Read(cin, total)) {
		Sales_data cur_data;
		while (Read(cin, cur_data)) {
			if (total.isbn() != cur_data.isbn())
			{
				print(cout, total);
				total = cur_data;
			}
			else {
				total.combine(cur_data);
			}
		}
	}
	return 0;
}