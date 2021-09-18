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
void firstFriend();
void addFriend();
void filterFriend();
void viewFriend();


int main()
{
	node* head = NULL;
	node* last = NULL;

}