#include <iostream>

using namespace std;

struct Sales_data {
	std::string bookNo;
	unsigned units_solds = 0;
	double revenue = 0.0;
};

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
			if (total.bookNo != cur_data.bookNo)
			{
				cout << total.bookNo << " sold " 
					 << total.units_solds << " copies, "
					 << "total revenue: " << total.revenue << endl;
				total = cur_data;
			}
			else {
				total.units_solds += cur_data.units_solds;
				total.revenue += cur_data.units_solds * 
								 cur_data.revenue;
			}
		}
	}
	return 0;
}