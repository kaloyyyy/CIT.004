#include<iostream>
#include<stdlib.h>//for system("CLS");
#include<string>//for getline for string;
using namespace std;

class node
{
public:
	string name;
	int age;
	char gender;
	int pRating;
	node* next_ptr;
};

string profile[4] = { "name: ","age: ","gender: ","popularity rating: " };

int friendCnt = 0;
char menu();
bool isEmpty(node* head);
void printFriend(node* current);

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating);
void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating);

void filterFriend(node* current);
void filterGender(node* current);
void filterRating(node* current);

void viewFriend(node* current);
void viewOneFriend(node* current);

void deleteFriend(node*&head, node*& last, node*current);
void delOneFriend(node*& head);
void delRating(node*& head);


int main()
{
	node* head = NULL;
	node* last = NULL;
	string name;
	int age = 0;
	char gender = 'x';
	int pRating = 0;
	bool gCheck = true;
	char sortChoice = 'x';
	char choice = 'x';
	do {
		choice = menu();
		switch (choice)
		{
		case 'a':
			system("CLS");
			cout << "enter your friend's name: \n";
			cin.ignore();
			getline(cin, name);

			cout << "enter " << name << "'s " << "age: \n";
			cin >> age;
			do{
				if (age < 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "please enter a valid age\n";
					cin >> age;
				}
				do {
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "please enter a valid age\n";
						cin >> age;
					}
				} while (cin.fail());
			} while (age < 0);

			cout << "enter " << name << "'s " << "gender: (M or F)\n";
			cin >> gender;
			cin.ignore();
			do {
				if (gender != 'M')
				{
					if (gender != 'F')
					{
						gCheck = false;
						cout << "please enter a valid gender(M or F)\n";
						cin >> gender;
					}
					else
					{
						gCheck = true;
					}
				}
				else
				{
					gCheck = true;
				}
			} while (gCheck == false);

			cout << "enter " << name << "'s " << "Popularity Rating: (0-100)\n";
			cin >> pRating;
			do {
				do {
					do {
						if (pRating < 0)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "please enter a valid popularity rating (0-100)\n";
							cin >> pRating;
						}
						if (pRating > 100)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "please enter a valid popularity rating (0-100)\n";
							cin >> pRating;
						}
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "please enter a valid popularity rating (0-100)\n";
							cin >> pRating;
						}
					} while (pRating > 100);
				} while (cin.fail());
			} while (pRating < 0);

			system("CLS");
			cout<<name<<" is now your friend!\n\n";
			addFriend(head, last, name, age, gender, pRating);
			break;

		case 'b':
			system("CLS");
			filterFriend(head);
			break;
		case 'c':
			system("CLS");
			viewFriend(head);
			break;
		case 'd':
			system("CLS");
			deleteFriend(head,last,head);
		}
	} while (choice != 'e');

	return 0;
}

char menu()//main menu
{
	cout << "friends: " << friendCnt << endl<<endl;
	char choice;
	cout << "a. add a friend\n";
	cout << "b. filter friends list\n";
	cout << "c. view friend\n";
	cout << "d. unfriend someone\n";
	cout << "e. close the program\n";
	cin >> choice;
	return choice;
}

void printFriend(node* current)//added this to call this in four diffenrent functions instead of typing these four lines of code in each of them
{
	cout << profile[0] << current->name << endl;
	cout << profile[1] << current->age << endl;
	cout << profile[2] << current->gender << endl;
	cout << profile[3] << current->pRating << endl << endl;
}

bool isEmpty(node* head)//checks if the linkedlist is empty
{
	if (head == NULL)
	{
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating)//this function is called in addFriend. it is called when the linkedlist is empty
{
	node* temp = new node;

	temp->name = name;
	temp->age = age;
	temp->gender = gender;
	temp->pRating = pRating;

	temp->next_ptr = NULL;

	head = temp;
	last = temp;
}

void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating)//adds a new friend
{
	if (isEmpty(head))
	{
		firstFriend(head, last, name, age, gender, pRating);
	}
	else
	{
		node* temp = new node;

		temp->name = name;
		temp->age = age;
		temp->gender = gender;
		temp->pRating = pRating;

		temp->next_ptr = NULL;
		last->next_ptr = temp;
		last = temp;
	}
	friendCnt++;
}



void filterFriend(node* current)// the menu for filtering.
{
	system("CLS");
	if (isEmpty(current))
	{
		cout << "your friend list is empty\n";
	}
	else
	{
		char sortChoice;
		cout << "a. sort friends by gender\n";
		cout << "b. sort friends by popularity rating\n";
		cin >> sortChoice;
		switch (sortChoice)
		{
		case 'a':
			filterGender(current);
			break;
		case 'b':
			filterRating(current);
			break;
		}
	}
}

void filterGender(node* current)//gender filter function. it will print all the matching inputted gender.
{
	char gFilter;
	bool gCheck = false;
	string gPrint="female";
	bool genderMatch = false;
	cout << "enter the gender you want to sort\n";
	cin >> gFilter;
	do {
		if (gFilter != 'M')
		{
			if (gFilter != 'F')
			{
				gCheck = false;
				cout << "please enter a valid gender(M or F)\n";
				cin >> gFilter;
			}
			else
			{
				gCheck = true;
			}
		}
		else
		{
			gCheck = true;
		}
	} while (gCheck == false);


	if (gFilter == 'M')
	{
		gPrint = "male";
	}
	system("CLS");
	cout << "list of your friends that are "<<gPrint << endl;

	while (current != NULL)
	{
		if (gFilter == current->gender)
		{
			printFriend(current);
			current = current->next_ptr;
			genderMatch = true;//once there's a matching gender, this will be true and will not print the prompt below
		}
		else
		{
			if (current == NULL)//if you're at the last node and there are zero matches with the filter, it will run the code below
			{
				if (genderMatch == false)
				{
					cout << "You have no friends with the selected gender\n";
				}
			}
			current = current->next_ptr;
		}
	}
}
void filterRating(node* current)//popularity rating filter function. 
{
	int rFilter;
	bool ratingMatch = false;

	cout << "enter the rating you want to filter\n";
	cin >> rFilter;
	while (rFilter > 100)
	{
		cout << "please re-enter a valid popularity rating (0-100)\n";
		cin >> rFilter;
	}
	system("CLS");

	cout << "Friends with popularity rating less that or equal to "<<rFilter<<endl;
	while (current != NULL)
	{
		if (current->pRating <= rFilter)
		{
			printFriend(current);
			current = current->next_ptr;
			ratingMatch = true;//once there's a matching gender, this will be true and will not print the prompt below
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)//if you're at the last node and there are zero matches with the filter, it will run the code below
			{
				if (ratingMatch == false)
				{
					cout << "You have no friends with the rating equal or below: " << rFilter << endl;
				}
			}
		}
	}
}

void viewFriend(node* current)//view friend menu
{
	system("CLS");
	char viewChoice;
	if (isEmpty(current))
	{
		cout << "your friend list is empty\n";
	}
	else
	{
		cout << "a. view a specific person\n";
		cout << "b. view your friends list\n";
		cin >> viewChoice;
		switch (viewChoice)
		{
		case 'a'://view specific person
			system("CLS");
			viewOneFriend(current);
			break;
		case 'b':
			system("CLS");
			cout << "---your Friend list---\n\n";
			while (current != NULL)
			{
				printFriend(current);
				current = current->next_ptr;
			}
			break;
		}
	}
}

void viewOneFriend(node* current)
{
	bool nameMatch = false;
	string viewName;
	cout << "enter your friend's complete name you want to view\n";
	cin.ignore();
	getline(cin, viewName);
	cout << "searching for " << viewName << "..." << endl << endl;
	while (current != NULL)
	{
		if (viewName == current->name)
		{
			printFriend(current);
			current = current->next_ptr;
			nameMatch = true;
		}
		else
		{
			current = current->next_ptr;
			if (current == NULL)
			{
				if (nameMatch == false)
				{
					system("CLS");
					cout << "You have no friends with name: " << viewName << endl;
				}
			}
		}
	}
}

void deleteFriend(node*& head, node*& last, node* current)
{
	if (isEmpty(current))
	{
		system("CLS");
		cout << "your friend list is empty\n";
	}
	else
	{
		char delChoice;
		cout << "a. delete a friend by name\n";
		cout << "b. delete friends based on popularity rating\n";
		cin >> delChoice;
		switch (delChoice)
		{
		case'a':
			delOneFriend(head);
			break;
		case'b':
			delRating(head);
			break;
		}
	}
}

void delOneFriend(node*& head)
{
	string nameDelete;
	bool nameMatch = false;
	system("CLS");

	cout << "enter your friend's full name you want to delete\n";
	cin.ignore();
	getline(cin, nameDelete);
	node* now = new node;
	node* prev = new node;
	now = head;
	cout << "searching for " << nameDelete << "'s account...\n\n";
	while (now != NULL)
	{
		if (nameDelete == now->name)
		{
			friendCnt--;
			nameMatch = true;
			if (nameDelete == head->name)
			{
				head = now->next_ptr;
			}
			else
			{
				prev->next_ptr = now->next_ptr;
			}
			cout << nameDelete << " unfriended\n\n";
		}
		prev = now;
		now = now->next_ptr;
	}
	if (nameMatch == false)
	{
		cout << "You have no friends with name: " << nameDelete << endl;
	}

}

void delRating(node*& head)
{
	int ratingDelete;
	bool ratingMatch = false;
	system("CLS");

	cout << "enter your friends' rating you want to unfriend\n";
	cin >> ratingDelete;
	node* now = new node;
	node* prev = new node;
	now = head;
	cout << "unfriending with rating " << ratingDelete << "...\n\n";
	while (now != NULL)
	{
		if (ratingDelete == now->pRating)
		{
			cout << now->name << " unfriended\n\n";
			if (ratingDelete == head->pRating)
			{
				head = now->next_ptr;
			}
			else
			{
				prev->next_ptr = now->next_ptr;
			}
			ratingMatch = true;
			friendCnt--;
		}
		prev = now;
		now = now->next_ptr;
	}
	if (ratingMatch == false)
	{
		cout << "you do not have a friend with the popularity rating of: " << ratingDelete << endl;
	}
}