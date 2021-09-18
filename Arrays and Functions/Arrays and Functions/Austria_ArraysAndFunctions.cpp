#include <iostream>
using namespace std;

class node
{
public:
    string words;
    int number;
    node* next_ptr;
};

bool isEmpty(node* head);
char menu();
void addNode(node*& head, node*& last, int number);
void addAnywhere(node*& head, node*& last, int number);
void deleteNode(node*& head, node*& last);
void viewNode(node* current);
int main()
{
    node* head = NULL;
    node* last = NULL;

    char choice;
    int number;
    string word;

    do {
        choice = menu();
        switch (choice) {
        case '1':
            cout << "Please enter number: ";
            cin >> number;
            addAnywhere(head, last, number);
            break;
        case '2': 
            deleteNode(head, last);
            break;
        case '3': 
            viewNode(head);
            break;
        default: cout << "Exit Program...\n";
                
        }
    } while (choice != '4');
}

bool isEmpty(node* head)
{
    if (head == NULL)
        return true;
    else
        return false;
}
char menu()
{
    char choice;

    cout << "Option\n";
    cout << "1. Input Data.\n";
    cout << "2. Delete Item.\n";
    cout << "3. Display List.\n";
    cout << "4. Quit Program\n";

    cin >> choice;

    return choice;
}
void addNode(node*& head, node*& last, int number)
{
    node* temp = new node;
    temp->number = number;
    temp->next_ptr = NULL;
    head = temp;
    last = temp;
}
void addAnywhere(node*& head, node*& last, int number)
{
    if (isEmpty(head))
        addNode(head, last, number);
    else
    {
        node* temp = new node;
        temp->number = number;
        temp->next_ptr = NULL;
        last->next_ptr = temp;
        last = temp;
    }
}
void deleteNode(node*& head, node*& last)
{
    if (isEmpty(head))
        cout << "LIST EMPTY\n";
    else if (head == last)
    {
        delete head;
        head = NULL;
        last = NULL;
    }
    else
    {
        node* temp = head;
        head = head->next_ptr;
        delete temp;
    }
}
void viewNode(node* current)
{
    if (isEmpty(current))
        cout << "No data inputted\n";
    else
    {
        cout << "List: \n";
        while (current != NULL)
        {
            cout << current->number << endl;
            current = current->next_ptr;
        }
    }
}
