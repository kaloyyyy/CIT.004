#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class node
{
public:
    string name;
    int number;
    node* next_ptr;
};

char menu();
bool isEmpty(node* head);
void addNode(node*& head, node*& last, int number, string name);
void firstNode(node*& head, node*& last, int number, string name);
void sortList(node*& head); 
void viewNode(node*current);
void deleteNode(node*& head, int delNum);
int cnt = 0;
int main()
{
    node* head = NULL;
    node* last = NULL;
    int delNum = NULL;
    int number;
    string name;
    char choice = 'e';

    do {
        choice = menu();
        switch (choice) 
        {

        case 'a':
            system("CLS");
            cout << "Enter the name\n";
            getline(cin, name);//allows more that one word of input for the string
            cout << "Enter the number\n";
            cin >> number;
            cin.ignore();
            addNode(head, last, number, name);
            cnt++;
            break;


        case 'b':
            system("CLS");
            viewNode(head);
            break;


        case 'c':
            system("CLS");
            viewNode(head);
            if (isEmpty(head))
            {//do nothing
            }
            else
            {
                cout << "enter the node position you want to delete\n";
                do
                {
                    cin >> delNum;
                    cin.ignore();
                    if (delNum > cnt)
                    {
                        cout << "enter a valid number within the nodes\n";
                    }
                } while (delNum > cnt);

                deleteNode(head, delNum);
                system("CLS");
                viewNode(head);
            }
            break;
        }
    } while (choice != 'd');

    return 0;
}


char menu()//this is just a menu, asking for the choice for the switch case in main
{
    char choice;
    cout << "a. add name and number\n";
    cout << "b. view all data\n";
    cout << "c. delete a data\n";
    cout << "d. close the program\n";
    cin >> choice;
    cin.ignore();
    return choice;
}
bool isEmpty(node* head)//checks if the head is empty then return boolean value of true or false
{
    if (head == NULL)
        return true;
    else
        return false;
}
void firstNode(node*& head, node*& last, int number, string name)//this is only used when the node head is empty.
{
    node* temp = new node;
    temp->number = number;
    temp->name = name;
    temp->next_ptr = NULL;
    head = temp;
    last = temp;
}
void addNode(node*& head, node*& last, int number,string name)
{
    if (isEmpty(head))
    {
        firstNode(head, last, number,name);//refer to void firstNode();
    }
    else
    {

        node* temp = new node;//declares a new node
        temp->number = number;// the int number and string name is cin'd in the main.
        temp->name = name;
        temp->next_ptr = NULL;
        last->next_ptr = temp;
        last = temp;
    }
    sortList(head);//after adding a data to the node, it is sorted in this function.
    system("CLS");
    cout << "---DATA SAVED---\n\n";
}
void sortList(node*&head)//sorting thing part. Yes.
{
    int tempNum;
    string tempName;
    node* i;
    node* j;
    for(i=head; i->next_ptr!=NULL;i=i->next_ptr)
    {
        for (j = i->next_ptr; j != NULL; j=j->next_ptr)
        {
            if (i->number > j->number)
            {
                tempNum = i->number;
                tempName = i->name;
                i->number = j->number;
                i->name = j->name;
                j->number = tempNum;
                j->name = tempName;
            }
        }
    }          
}
void viewNode(node* current)//just couts every node then stop when current point to NULL.
{
    if (isEmpty(current))
        cout << "---NO DATA---\n";
    else
    {
        cout << "---LIST OF DATA---\n\n";
        while (current != NULL)
        {
            cout << "name: "<<current->name << "  -----  ";
            cout << "number: "<<current->number << endl << endl;
            current = current->next_ptr;
        }
    }
}

void deleteNode(node*& head, int delNum)//not yet okay xD
{
    if (isEmpty(head))
    {
        cout << "there is nothing to delete\n";
    }
    else if (delNum == 1)
    {
        head = head->next_ptr;
        return;
        cnt--;
    }
    else
    {
        node* current = new node;
        node* previous = new node;
        current = head;
        for (int i = 1; i < delNum; i++)
        {
            previous = current;
            current = current->next_ptr;
        }
        previous->next_ptr = current->next_ptr;
        cnt--;
    }
}