#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    int number;
    Node* next_ptr;
};

char menu();

bool isEmpty(Node* head);
void addNode(Node*& head, Node*& last, int number, string name);
void firstNode(Node*& head, Node*& last, int number, string name);
void sortList(Node*& head);
void viewNode(Node* current);
void deleteNode(Node*& head, int delNum);


int counter = 0;

char menu()
{
    char choice;
    cout << "\nChoose your choice: (Capitalize your letter of choice) \n";
    cout << "         ================================\n" << endl;

    cout << "A. Create a record \n" << endl;
    cout << "B. Display all record/s \n" << endl;
    cout << "C. Delete a record \n" << endl;
    cout << "D. EXIT \n" << endl;
    cin >> choice;
    cin.ignore();
    return choice;
}

bool isEmpty(Node* head)
{
    if (head == NULL)
        return true;
    else
        return false;
}

void addNode(Node*& head, Node*& last, int number, string name)
{
    if (isEmpty(head))
    {
        firstNode(head, last, number, name);
    }
    else
    {

        Node* temp = new Node;
        temp->number = number;
        temp->name = name;
        temp->next_ptr = NULL;
        last->next_ptr = temp;
        last = temp;
    }
    sortList(head);
    system("CLS");
    cout << "=Record Saved=\n";
}

void firstNode(Node*& head, Node*& last, int number, string name)
{
    system("CLS");
    Node* temp = new Node;
    temp->number = number;
    temp->name = name;
    temp->next_ptr = NULL;
    head = temp;
    last = temp;
}

void sortList(Node*& head)
{
    int tempNum;
    string tempName;
    Node* i;
    Node* j;
    for (i = head; i->next_ptr != NULL; i = i->next_ptr)
    {
        for (j = i->next_ptr; j != NULL; j = j->next_ptr)
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

void viewNode(Node* current)
{
    if (isEmpty(current))
        cout << "NO RECORDS \n";
    else
    {
        cout << "List of Records: \n" << endl;
        while (current != NULL)
        {
            cout << "Number: " << current->number << endl;
            cout << "Name: " << current->name << endl;
            cout << "------" << endl;

            current = current->next_ptr;
        }
    }
}

void deleteNode(Node*& head, int delNum)
{
    if (isEmpty(head))
    {
        cout << "Nothing to delete. \n";
    }
    else if (delNum == 1)
    {
        head = head->next_ptr;
        return;
        counter--;
    }
    else
    {
        Node* current = new Node;
        Node* previous = new Node;
        current = head;
        for (int i = 1; i < delNum; i++)
        {
            previous = current;
            current = current->next_ptr;
        }
        previous->next_ptr = current->next_ptr;
        counter--;
    }
}

int main()
{
    Node* head = NULL;
    Node* last = NULL;
    int delNum;
    int number;
    string name;
    char choice = 'E';

    do {
        choice = menu();
        switch (choice)
        {
        case 'A':
            system("CLS");
            cout << "Enter the number: \n";
            cin >> number;
            cin.ignore();
            cout << "Enter the name: \n";
            getline(cin, name);

            addNode(head, last, number, name);
            counter++;
            break;

        case 'B':
            system("CLS");
            viewNode(head);
            break;

        case 'C':
            system("CLS");
            viewNode(head);
            if (isEmpty(head))
            {
            }
            else
            {
                cout << "Enter the number you wish to delete \n";
                do
                {
                    cin >> delNum;
                    cin.ignore();
                    if (delNum > counter)
                    {
                        cout << "Enter a valid number within the records listed above \n";
                    }
                } while (delNum > counter);

                deleteNode(head, delNum);
                system("CLS");
                viewNode(head);
            }
            break;
        }
    } while (choice != 'D');
    system("CLS");
    cout << "==You Exited The Program==\n";
    cout << ">,...THANK YOU...,<";
    return 0;
}