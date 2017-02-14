#include <iostream>
using namespace std;

class Point {
public:
	Point() = default;
	Point(Point& p) : m_x(p.m_x), m_y(p.m_y) {
		++i;
		cout << "copy constructor, i = " << i << endl;
	}
private:
	double m_x;
	double m_y;
	static int i;
};

int Point::i = 0;

Point global;
Point foo_bar(Point arg)
{
	Point local = arg, *heap = new Point(global);
	*heap = local;
	Point pa[4] = {local, *heap};
	return *heap;
}

int main()
{
	Point p1 = global;
	Point p2(global);
	foo_bar(global);

	return 0;
}