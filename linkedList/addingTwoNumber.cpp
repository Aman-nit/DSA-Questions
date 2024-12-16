// WHEN DATA REPLACEMENT ARE ALLOWED

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

void printNodes(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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
node *sumNodes(node *&head1, node *&head2)
{
    // step-01,Reverse both Linked List
    head1 = reverseLinkedList(head1);
    head2 = reverseLinkedList(head2);

    // step-02,Add reversed Linked List
    node *ansHead = NULL;
    node *ansTail = NULL;
    int carry = 0;

    while (head1 != NULL && head2 != NULL)
    {
        // calculate sum
        int sum = carry + head1->data + head2->data;
        /// find digit to creat node for
        int digit = sum % 10;
        // calculate carry
        carry = sum / 10;
        // creat a new node for the digit
        node *newNode = new node(digit);
        // attach the new node into the answer wali linked list
        if (ansHead == NULL)
        {
            // entering first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1 != NULL)
    {
        /* code */
    }

    // step-03,Revers added Linked list
}

int main()
{

    node *head1 = new node(2);
    node *second1 = new node(4);
    head1->next = second1;

    node *head2 = new node(2);
    node *second2 = new node(3);
    node *third2 = new node(4);
    head2->next = second2;
    second2->next = third2;

    cout << "Printing Nodes of first LL...";
    printNodes(head1);
    cout << "Printing Nodes of second LL...";
    printNodes(head2);

    sumNodes(head1, head2);

    return 0;
}
