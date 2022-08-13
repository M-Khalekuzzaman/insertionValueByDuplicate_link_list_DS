#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;

    //Constructor declare
    Node(int data)
    {
        this -> data = data;
        this -> Next = NULL;
    }
};
void insertionAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}
int countLength(Node* &head)
{
    int count = 1;
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
        count++;
    }

    return count;
}
void insertionAtPosition(Node* &head,int value,int pos)
{
    Node *newNode = new Node(value);
    if(pos == 1)
    {
        Node *save_node = head;
        newNode->Next = save_node;
        head = newNode;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1; i<pos; i++)
    {
        temp = temp->Next;
    }
    Node *save = temp->Next;
    temp->Next = newNode;
    newNode->Next = save;
}
void insertValueByDuplicateList(Node* &head,int searchValue,int insert_value)
{
    Node *temp = head;
    int size = countLength(head);
    int savePosition[size+1];
    int count = 1,k = 1;;
    while(temp->Next != NULL)
    {
        int val = temp->data;
        if(val == searchValue)
        {
            savePosition[k] = count;
            k++;
        }

        temp = temp->Next;
        count++;
    }
    savePosition[0] = k;
    for(int i = 1; i<savePosition[0]; i++)
    {
        int pos = savePosition[i];
        insertionAtPosition(head,insert_value,pos+i);
    }

}
void printLinkList(Node* &head)
{
    Node *currentNode = head;
    while(currentNode != NULL)
    {
        cout<<currentNode->data;
        if(currentNode->Next != NULL) cout<<" -> ";
        currentNode = currentNode->Next;
    }
    cout<<endl;
}
int main()
{
    Node *head = NULL;
    int value,pos,choice = 1;
    cout<<"Choice 1 : Insert at Tail"<<endl;
    cout<<"Choice 2 : Insert value by duplicate link-list(enable link-list)"<<endl;
    cout<<"Choice 3 : Insert value unique list"<<endl;
    cout<<"Choice 0 : Exit"<<endl<<endl;
    while(choice != 0)
    {
        switch(choice)
        {
        case 1 :
            cout<<"Enter your value :";
            cin>>value;
            insertionAtTail(head,value);
            break;
        case 2 :
            cout<<"Search value after insert:";
            cin>>value;
            cout<<"Insert value after search value : ";
            int insert_value;
            cin>>insert_value;
            insertValueByDuplicateList(head,value,insert_value);
            break;
        case 3 :
            cout<<"Enter your value & pos : ";
            cin>>value>>pos;
            insertionAtPosition(head,value,pos);
            break;
        default:
            break;

        }
        cout<<"Next Choice : ";
        cin>>choice;
    }
    cout<<endl<<"Link-list : ";
    printLinkList(head);


    return 0;
}
