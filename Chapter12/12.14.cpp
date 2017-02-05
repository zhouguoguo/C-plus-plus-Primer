#include <iostream>
#include <memory>

using namespace std;

struct destination {
};
struct connection{
};
connection connect(destination *)
{

}
void disconnection(connection* p)
{

}

void end_connection(connection* p)
{
	disconnection(p);
}

void f(destination& d)
{
	connection c = connect(&d);
	// use connection c
	shared_ptr<connection> sp(&c, end_connection);

	shared_ptr<connection> sp1(&c, [c](){disconnection(&c);});
}

int main()
{
	destination d;
	f(d);	
}