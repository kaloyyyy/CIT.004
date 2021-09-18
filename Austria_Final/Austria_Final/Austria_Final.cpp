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
};


char menu();
bool isEmpty(node*head);
void firstFriend(node* head, node*& last, string name, int age, char gender, int pRating);
void addFriend(node* head, node*& last, string name, int age, char gender, int pRating);
void filterFriend();
void viewFriend();
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
	cin >> gender;
	cin >> pRating;
	addFriend(head, last, name, age, gender, pRating);

	return 0;



}

void addFriend(node* head, node*& last, string name, int age, char gender, int pRating)
{
	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}