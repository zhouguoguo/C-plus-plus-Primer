#include <iostream>

using namespace std;

struct Sales_data {
	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
	std::string bookNo;
	unsigned units_solds = 0;
	double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& data)
{
	units_solds += data.units_solds;
	revenue += data.revenue;
	return *this;
}

bool get_one_sales_item(Sales_data& data)
{
	if (cin >> data.bookNo && 
		cin >> data.units_solds &&
		cin >> data.revenue)
	{
		return true;
	}
	return false;
}

int main()
{
	Sales_data total;
	if (get_one_sales_item(total)) {
		Sales_data cur_data;
		while (get_one_sales_item(cur_data)) {
			if (total.isbn() != cur_data.isbn())
			{
				cout << total.bookNo << " sold " 
					 << total.units_solds << " copies, "
					 << "total revenue: " << total.revenue << endl;
				total = cur_data;
			}
			else {
				total.combine(cur_data);
			}
		}
	}
	return 0;
}