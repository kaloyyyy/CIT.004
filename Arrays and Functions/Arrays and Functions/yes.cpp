#include <iostream>

using namespace std;

class Node
{
    public:
    string words;
    int number;
    Node* next_ptr;
};

void addNode(Node**);
void deleteNode(Node**);

int main()
{
    Node*head=NULL;
    int choice=0;
    int option=0;
    
    while(choice==0)
    {
        addNode(&head);
        Node*traverse=head;
        
        while(traverse!=NULL)
        {
            cout<<endl<<traverse->words<<endl;
            cout<<traverse->number<<endl<<endl;;
            traverse=traverse->next_ptr;
        }
        
        cout<<"option?: ";
        cin>>option;
        
        if(option==0)
        {
            deleteNode(&head);
        }
        
        traverse=head;
        
        while(traverse!=NULL)
        {
            cout<<endl<<traverse->words<<endl;
            cout<<traverse->number<<endl<<endl;;
            traverse=traverse->next_ptr;
        }
        
        
        
        cout<<"choice: ";
        cin>>choice;
    }
    return 0;
}

void addNode(Node** head)
{
    string words_in;
    int number_in;
    
    if(*head==NULL)
    {
        *head=new Node();
        
        Node*storage=new Node();
        cout<<"word?: ";
        cin>>words_in;
        cout<<"number: ";
        cin>>number_in;
        
        storage->words=words_in;
        storage->number=number_in;
        storage->next_ptr=NULL;
        
        *head=storage;
    }
    else
    {
        Node*storage=new Node();
        cout<<"word?: ";
        cin>>words_in;
        cout<<"number: ";
        cin>>number_in;
        
        storage->words=words_in;
        storage->number=number_in;
        storage->next_ptr=NULL;
        
        Node*traverse=*head;
        
        while(traverse->next_ptr!=NULL)
        {
            traverse=traverse->next_ptr;
        }
        traverse->next_ptr=storage;
    }
}


void deleteNode(Node** head)
{
    Node*traverse=*head;
    Node*previous=NULL;
    
    while(traverse->next_ptr!=NULL)
    {
        previous=traverse;
        traverse=traverse->next_ptr;
    }
    previous->next_ptr=NULL;
    delete traverse;
}