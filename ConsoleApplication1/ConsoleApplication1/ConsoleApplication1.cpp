void function4() {
	fstream text;
	fstream text2;
	string y = "";

	function1();
	readfile1();
	clearfile2();

	int x; //variable for paragraph

	cout << "Choose a Paragraph: ";
	cin >> x;
	x--;

	text.open("test.txt");
	text2.open("test2.txt");
	while (!text.eof()) {
		for (int i = 0; i < par; i++) { // similar to function 3 but in function 4 we are only to delete a paragraph
			getline(text, y);
			if (x != i) text2 << y << endl;
		}
	}
	text.close();
	text2.close();
	letter = 0, word = 0, sent = 0, par = 0;

}

int main() { //int

	int a; //choice
	int loop = 1;
	fstream text;
	int print;

	while (loop = 1) {
		system("CLS");

		cout << "\n========Menu=================\n"; //Menu
		cout << "\n 1. - Function 1 = show content of test.txt and write on test2.txt";
		cout << "\n 2. - Function 2 = Rewrite all first letter of words is in uppercase and remove all spaces and newline of test2.txt";
		cout << "\n 3. - Fucntion 3 = from test1.txt, enter new paragraph in text2.txt";
		cout << "\n 4. - Function 4 = Delete a paragraph in text2.txt";
		cout << "\n 5. - Exit\n";
		cout << "\n============================="; //Menu
		cout << "\n\n Type the number of choice: ";
		cin >> a;
		cout << "\n\n";

		switch (a) {
		case 1:
			function1(); //call func1
			break;
		case 2:
			function2(); //call func2
			break;
		case 3:
			function3(); //call func3
			break;
		case 4:
			function4(); //call func4
			break;
		case 5:
			cout << "\n\nGoodbye! 😃" << endl;
			return 0;

		case 6:
			cout << "clear file2";
			clearfile2();

		default:
			cout << "\n\nInvalid Input! Type again." << endl;
		}
		cout << "\n\nPress any keys to continue...";
		_getch();
	}
} .sln file