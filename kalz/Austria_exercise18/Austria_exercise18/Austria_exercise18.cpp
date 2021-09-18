#include <iostream>
using namespace std;

int main() {

	int x, y;
	int ans = 0;
	char letter;
	int count = 0;

	cout << "a. multlipication\nb. division\n";
	cin >> letter;


	switch (letter) {
	case 'a': cout << "enter the values\n";
		cin >> x >> y;

		do
		{

			ans = ans + x;
			y--;

		} while (y != 0);

		cout << "the product: " << ans << endl;
		break;





	case 'b': cout << "enter the dividend divisor respetively\n";

		cout << "enter the dividend\n";
		cin >> x;
		do		//this part ensures that the divisor is 0
		{
			cout << "enter the divisor\n";
			cin >> y;

		} while (y == 0);



		while (x >= y) { //this part is the repetetive subtration.
			x = x - y;
			count++;

		}

		cout << "the quotient: " << count << " r" << x; // x is the remainder
		break;

	}
}






