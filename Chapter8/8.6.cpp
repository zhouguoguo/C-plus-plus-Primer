#include <iostream>
#include <fstream>

using namespace std;

class Sales_data {
	friend istream& read(istream&, Sales_data &i);
	friend ostream& print(ostream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string& s, unsigned u, double p) : 
				bookNo(s), units_solds(u), revenue(u*p){}
	Sales_data(const string& s) : bookNo(s){}
	Sales_data(istream&);

	string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data&);
private:
	inline double ave_price() const;
	std::string bookNo;
	unsigned units_solds = 0;
	double revenue = 0.0;
};

istream& read(istream& is, Sales_data &in_data)
{
	double price = 0.0;
	is >> in_data.bookNo >> in_data.units_solds >> price;
	in_data.revenue = price * in_data.units_solds;
	return is;
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
	      ", total revenue is " <<
	      data.revenue;
	return os;
}

double Sales_data::ave_price() const {
	if (units_solds == 0) return 0;
	return revenue / units_solds;
}

Sales_data::Sales_data(istream& is)
{
	read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& data)
{
	units_solds += data.units_solds;
	revenue += data.revenue;
	return *this;
}

int main(int argc, char* argv[])
{
	Sales_data total;
	ifstream ifs;
	ofstream ofs;
	if (argc <= 2) { 
		cout << "File name missing!\n";
		return 1;
	}
//	ofs.open(*(argv+2));
	ofs.open(*(argv+2), ofstream::app);
	ifs.open(*(argv+1));
	if (read(ifs, total)) {
		Sales_data cur_data;
		while(read(ifs, cur_data)) {
			if (total.isbn() == cur_data.isbn())
			{
				total.combine(cur_data);
			}
			else {
				print(ofs, total) << endl;
				total = cur_data;
			}
		}
		print(ofs, total) << endl;
	} else {
		cerr << "No data?!" << endl;
	}

	return 0;
}