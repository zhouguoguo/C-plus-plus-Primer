#include <stack>
#include <iostream>

using namespace std;

int priority(char c)
{
	switch(c) {
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
			return 3;
	}
}

void printChStack(stack<char> optStack)
{
	cout << "optStack:\n";
	while (!optStack.empty())
	{
		cout << optStack.top() << endl;
		optStack.pop();
	}
}

void printIntStack(stack<int> opdStack)
{
	cout << "opdStack:\n";
	while (!opdStack.empty())
	{
		cout << opdStack.top() - '0' << endl;
		opdStack.pop();
	}
}

bool isOpt(char ch)
{
	if (ch == '+' || ch == '-' ||
		ch == '*' || ch == '/' ||
		ch == '(' || ch == ')' )
		return true;
	else return false;
}

int calculate_once(char ch, int a, int b)
{
	switch(ch) {
	case '+':
		cout << "calculate_once + :" << a + b << endl;
		return a + b;
	case '-':
		cout << "calculate_once - :" << a - b << endl;
		return a - b;
	case '*':
		cout << "calculate_once * :" << a * b << endl;
		return a * b;
	case '/':
		cout << "calculate_once / :" << a / b << endl;
		return a / b;
	}
}

void calculate(stack<char>& optStack, stack<int>& opdStack)
{
	while (!optStack.empty() && optStack.top() != '(') {
		char opt = optStack.top();
		optStack.pop();
		int opd1 = opdStack.top() - '0';
		opdStack.pop();
		int opd2 = opdStack.top() - '0';
		opdStack.pop();
		opdStack.push(calculate_once(opt, opd2, opd1) + '0');
	}
	if (!optStack.empty() && optStack.top() == '(')
	{
		optStack.pop();
	}
}

int process(const string& str)
{
	stack<char> optStack;
	stack<int> opdStack;

	for (auto ch : str)
	{
		cout << "\ncurrent char:" << ch << endl;
		if (isdigit(ch)) {
			opdStack.push(ch);
		}
		else if (isOpt(ch)){
			if (ch == ')')
			{
				calculate(optStack, opdStack);
			}
			else if (optStack.empty() || optStack.top() == '(')
			{
				optStack.push(ch);
			}
			else if (priority(optStack.top()) < priority(ch))
			{
				optStack.push(ch);
			}
			else if (priority(optStack.top()) >= priority(ch))
			{
				calculate(optStack, opdStack);
				optStack.push(ch);
			}
		}
		else {
			cout << "Error character!\n";
			return -1;
		}

		printChStack(optStack);
		printIntStack(opdStack);
	}
	if (!optStack.empty()) {
		calculate(optStack, opdStack);
	}
}

int main()
{
	string s = "(1+2)*(1+(3-1)/6)";
	process(s);

	return 0;
}