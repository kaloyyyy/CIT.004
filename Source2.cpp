
#include <iostream>
using namespace std;

void number(int x0, int count)
{
	int x1;
	cout << "input a number: ";
	cin >> x1;
	if (x0 < x1) {
		cout << "the current number is greater than the previous number\n";
	}if (x0 > x1) {
		cout << "the current number is less than the previous number\n";
	}
	else if (x0 == x1) {
		cout << "the current number is equal to the previous number\n";
	}
	count++;
	if (count == 5) {
		cout << "end";
	}
	else
	{
		number(x1, count);
	}
}

int main()
{
	int x0;
	cout << "input a number: ";
	cin >> x0;
	number(x0, 1);
}


