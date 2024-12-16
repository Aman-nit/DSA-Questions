#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        cout << "Deleted " << this->data << endl;
    }
};
// Function to print the list
void printList(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to get the length of the list
int getLength(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// Insert at head
void insertAtHead(int data, node *&head, node *&tail)
{
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        node *newNode = new node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Insert at tail
void insertAtTail(int data, node *&head, node *&tail)
{
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        node *newNode = new node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; // Fix: update tail to point to the new node
    }
}
// Insert at a specific position
void insertAtPosition(int position, int data, node *&head, node *&tail)
{
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        if (position == 1)
        {
            insertAtHead(data, head, tail);
            return;
        }

        int len = getLength(head);
        if (position >= len)
        {
            insertAtTail(data, head, tail);
            return;
        }

        // Insert at middle
        node *prevNode = head;
        int i = 1;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }

        node *curr = prevNode->next; // Fix: curr should be the next node after prevNode
        node *newNode = new node(data);

        // Link the new node
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = curr;
        if (curr != NULL)
        {
            curr->prev = newNode;
        }
    }
}
void deleteFromPosi(int position, node *&head, node *&tail)
{
    int len = getLength(head);
    if (head == NULL)
    {
        cout << "Linked List is empty";
        return;
    }
    if (position > len)
    {
        cout << "Please enter a valid position";
        return;
    }

    if (head->next == NULL)
    {
        // Single node case
        node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if (position == 1)
    {
        // Deleting the first node
        node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == len)
    {
        // Deleting the last node
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    // Deleting any position in the middle
    node *left = head; // Correct initialization
    int i = 1;
    while (i < position - 1)
    {
        left = left->next; // Move the left pointer to the node before the target position
        i++;
    }

    // Now left is at position - 1, and curr is the node to be deleted
    node *curr = left->next;
    node *right = curr->next;

    left->next = right;
    right->prev = left;

    // Clean up the node to be deleted
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}

int main()
{
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *head = first;
    node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;
    cout << "Printing orignal Linked List" << endl;
    // Print original list
    printList(head);
    cout << endl;

    cout << "Printing Inserted at head Linked List" << endl;
    // Insert at head
    insertAtHead(20, head, tail);
    printList(head);
    cout << endl;

    cout << "Printing inserted at tail Linked List" << endl;
    // Insert at tail
    insertAtTail(60, head, tail);
    printList(head);
    cout << endl;

    cout << "Printing inserted at position X(x=4) Linked List" << endl;
    // Insert at position 4
    insertAtPosition(4, 80, head, tail);
    printList(head);
    cout << endl;

    cout << "Printing deleted at position X(x=3) Linked List" << endl;
    // Delte at position
    deleteFromPosi(3, head, tail);
    printList(head);
    cout << endl;

    return 0;
}
