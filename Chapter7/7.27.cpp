#include <iostream>
using namespace std;

class Screen {
public:
	typedef string::size_type pos;

	Screen() = default;
	Screen(pos w, pos h, char c):
			width(w), height(h), content(w*h, c) {}
	Screen(pos w, pos h) :
			width(w), height(h), content(w*h, ' ') {}
	char get() const 
	{
		return content[cursor];
	}
	char get(pos r, pos c) const
	{
		return content[r * width + c];
	}
	string get_content() const
	{
		return content;
	}
	Screen& move(pos, pos);
	Screen& set(pos, pos, char);
	Screen& set(char);
	const Screen& display(ostream& os) const 
				{ do_display(os); return *this;}
	Screen& display(ostream& os)
				{ do_display(os); return *this;}

private:
	pos cursor = 0;
	pos width = 0, height = 0;

	string content;

	void do_display(ostream& os) const {
		os << content;
	}
};

Screen& Screen::set(char ch)
{
	content[cursor] = ch;
	return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
	content[r * width + c] = ch;
	return *this;
}

Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}