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

node *reverseLinkedList(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *Forw = curr->next;
    while (curr != NULL)
    {
        Forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Forw;
    }
    return prev;
}

bool checkPalindrom(node *head)
{
    // for no node in LL
    if (head == NULL)
    {
        cout << "Linked List is empty..." << endl;
        return true;
    }
    // for only one node in LL
    if (head->next == NULL)
    {
        cout << "Linked List has only one node ...." << endl;
        return true;
    }
    // For more than 1(>1) node in LL

    // Step-01, find middle of the node
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // At the end of the loop slow will middle of the LL

    // step-02,Reverse LL sfter middle node
    node *reverseLLkaHead = reverseLinkedList(slow->next);
    // joining the reversd LL into th eunreversed LL
    // slow->next = reverseLinkedList;

    // Step-03, start comparision of rversed and un reversed LL

    node *temp = head;
    node *temp2 = reverseLLkaHead;
    while (temp2 != NULL)
    {
        if (temp->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main()
{

    node *head = new node(10);
    node *first = new node(20);
    node *second = new node(30);
    node *third = new node(200);
    node *fourth = new node(10);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    bool isPalindrom = checkPalindrom(head);
    if (isPalindrom)
    {
        cout << "Linked List is a valid palindrom..." << endl;
    }
    else
    {
        cout << "Linked List is not a valid palindrom...";
    }
    return 0;
}