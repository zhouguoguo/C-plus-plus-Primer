#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Sales_item {
	friend istream& read(istream&, Sales_item&);
	friend ostream& print(ostream&, const Sales_item&);
	friend void process_records(vector<Sales_item>&);
public:
	Sales_item() : 
			bookNo(""), 
			units_sold(0), 
			revenue(0.0){}
	Sales_item(string n) : 
			bookNo(n), 
			units_sold(0), 
			revenue(0.0){}
	Sales_item(string n, unsigned u, unsigned price) : 
			bookNo(n), 
			units_sold(u), 
			revenue(u * price){}
	string isbn() const {return bookNo;}
	Sales_item& combine(const Sales_item& cur);
private:
	string bookNo;
	unsigned units_sold;
	double revenue;
};

Sales_item& Sales_item::combine(const Sales_item& cur)
{
	this->units_sold += cur.units_sold;
	this->revenue += cur.revenue;
	return *this;
}

istream& read(istream& is, Sales_item& d)
{
	double price;
	is >> d.bookNo >> d.units_sold >> price;
	d.revenue = d.units_sold * price;
	return is;
}

ostream& print(ostream& os, const Sales_item& d)
{
	os << d.bookNo << " " << d.units_sold << 
		" " << d.revenue << endl;
	return os;
}

ostream& print_vec(ostream& os, const vector<Sales_item>& vec)
{
	for (auto d : vec)
		print(os, d);
	return os;
}

bool compareIsbn(const Sales_item& s1, const Sales_item& s2)
{
	return s1.isbn().size() < s2.isbn().size();
}

bool notEqual(const Sales_item& s1, const string& str)
{
	return s1.isbn() != str;
}

void process_records(vector<Sales_item>& vec)
{
	vector<Sales_item>::iterator it = vec.begin();
	string bookstr;
	unsigned res1 = accumulate(vec.begin(), vec.end(), 0, 
			bind(plus<unsigned>(), _1, 
				 bind(&Sales_item::units_sold, _2)));

	while (it != vec.end())
	{
		bookstr = it->isbn();
		auto last = find_if(it, vec.end(), 
							[bookstr](const Sales_item& s1) 
							{return bookstr != s1.isbn();});
		unsigned copies_sum = accumulate(it, last, 0, 
			bind(plus<unsigned>(), _1, 
				 bind(&Sales_item::units_sold, _2)));
		double revenue_sum = accumulate(it, last, 0, 
			bind(plus<unsigned>(), _1, 
				 bind(&Sales_item::revenue, _2)));
		cout << "book" << " " << bookstr
			 << " sold " << copies_sum << " copies, "
			 << " total revenue " << revenue_sum << endl;
		it = last;
	}
}

int main()
{
	vector<Sales_item> vec;
	ifstream ifs("sales_datas");
	Sales_item cur;

	while (read(ifs, cur))
	{
		vec.push_back(cur);
	}
	
	sort(vec.begin(), vec.end(), compareIsbn);
	print_vec(cout, vec);
	process_records(vec);

}