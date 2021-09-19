#include<iostream>
#include<stdlib.h>
#include<string>
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


char menu();
bool isEmpty(node* head);
void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating);
void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating);
void filterFriend();
void viewFriend(node* current);
void deleteFriend();


int main()
{
	node* head = NULL;
	node* last = NULL;
	string name;
	int age;
	char gender;
	int pRating;

	getline(cin, name);
	cin >> age;
	cin.ignore();
	cin >> gender;
	cin.ignore();
	cin >> pRating;
	cin.ignore();
	addFriend(head, last, name, age, gender, pRating);
	viewFriend(head);
	return 0;

}

char menu()
{
	char choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

bool isEmpty(node* head)
{
	if (head == NULL)
	{
		cout << "yes\n";
		return true;
	}
	else
		return false;
}

void firstFriend(node*& head, node*& last, string name, int age, char gender, int pRating)
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

void addFriend(node*& head, node*& last, string name, int age, char gender, int pRating)
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

}

void viewFriend(node* head)
{
	if (isEmpty(head))
		cout << "---Your friends list is empty---\n";
	else
	{
		cout << "Your\n";
		while (head != NULL)
		{
			cout << head->name << endl;
			cout << head->age << endl;
			cout << head->gender << endl;
			cout << head->pRating << endl << endl;
			head = head->next_ptr;
		}
	}
}