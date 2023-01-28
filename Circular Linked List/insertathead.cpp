#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next = NULL;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
node *insertathead(node *head, int x)
{
    node *temp = new node(x);
    if(head==NULL)
    {   head = temp;
        temp->next = head;
    }
    else
    {
        node *curr = head;
        while(curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    }
    return head;
}
void printList(node *head)
{
    if(head==NULL) return;
    node *curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    while(curr != head);
}
int main()
{
    int n,x;
    node *head = NULL;
    cout<<"How many elements you want to insert:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        head = insertathead(head,x);
    }
    cout<<endl;
    printList(head);
    return 0;
}