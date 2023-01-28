#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
node *insertathead(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    }
    return head;
}

node *insertatend(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        head = insertathead(head, x);
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return head;
}
void printList(node *head)
{
    if (head == NULL)
        return;
    node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}
int main()
{
    int x, n;
    node *head = NULL;
    cout << "how many elements you want:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        head = insertatend(head, x);
    }
    printList(head);
    return 0;
}