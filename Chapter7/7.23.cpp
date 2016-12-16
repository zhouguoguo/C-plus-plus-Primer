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

private:
	pos cursor = 0;
	pos width = 0, height = 0;

	string content;
};

Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}

int main()
{
	Screen screen1(3, 5, 'a');
	cout << screen1.get_content() << endl;
	cout << screen1.get() << endl;
	cout << screen1.get(2, 2) << endl;
	cout << screen1.move(1, 1).get() << endl;
	return 0;
}