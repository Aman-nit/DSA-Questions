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

bool checkForLoop(node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return false;
    }
    node *slow = head;
    node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == fast)
        {
            return true;
        }
    }
    // fast NULL hogaya
    return false;
}
int main()
{
    node *head = new node(10);
    node *first = new node(20);
    node *second = new node(30);
    node *third = new node(40);
    node *fourth = new node(50);
    node *fifth = new node(60);
    node *sixth = new node(70);
    node *seventh = new node(80);
    node *eighth = new node(90);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    // eighth->next = NULL;
    eighth->next = fifth;

    if (checkForLoop(head) == true)
    {
        cout << "Congratulation Loop is present ...";
    }
    else
    {
        cout << "Oops!  Loop is not present .";
    }

    return 0;
}