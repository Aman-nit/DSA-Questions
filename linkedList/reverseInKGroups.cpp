#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLinkedList(node *&head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

node *reverseKNodes(node *head, int k)
{

    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return NULL;
    }

    int len = getLength(head);
    if (k > len)
    {
        cout << "Please inter a valid value of k " << endl;
        return head;
    }

    // it means number of nodes in LL is >=k;
    node *prev = NULL;
    node *curr = head;
    node *forward = curr->next;
    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // recursive call
    if (forward != NULL)
    {
        // we still have nodes to reverse
        head->next = reverseKNodes(forward, k);
    }

    // return head of the modified Linked List
    return prev;
}
int main()
{
    node *head = new node(10);
    node *first = new node(20);
    node *second = new node(30);
    node *third = new node(40);
    node *fourth = new node(50);
    node *fifth = new node(60);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    printLinkedList(head);
    cout << endl;

    int k;
    cout << "Enter the value of k :-";
    cin >> k;
    head = reverseKNodes(head, k);

    printLinkedList(head);
    cout << endl;

    return 0;
}