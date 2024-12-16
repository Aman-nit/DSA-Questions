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

node *getMiddle(node *&head)
{

    if (head->next == NULL)
    {
        // there is only one node present in linked list
        return head;
    }
    if (head == NULL)
    {
        // no node is present in LINKED LIST
        cout << "Linked List is empty " << endl;
        return head;
    }

    // LL have more than one node
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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

    int middle = getMiddle(head)->data;
    cout << "Middle of Linked List is: " << middle << endl;
    return 0;
}