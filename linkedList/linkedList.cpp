#include <iostream>
using namespace std;

// LINKLIST:-It is a linear data structure which does not allocate continuous memory

class node
{
public:
    int data;
    node *next;
    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        cout << "Node with the value: " << this->data << " is deleted";
    }
};

// Function to print the linked list
void printingNodes(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert node at the head of the linked list
void insertAtHead(node *&head, node *&tail, int data)
{
    // Check for empty linked list
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Create a new node and insert it at the head
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

// Insert node at the tail of the linked list
void insertAtTail(node *&tail, node *&head, int data)
{
    // Check for empty linked list
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Create a new node and insert it at the tail
    node *newNode = new node(data);
    tail->next = newNode;
    tail = newNode;
}

// Insert node at any position
void insertAtPosition(int position, node *&head, node *&tail, int data)
{
    // Handle empty list
    if (head == NULL)
    {
        node *newNode = new node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // If position is 0, insert at the head
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // Traverse to the position before insertion
    int i = 1;
    node *prev = head;
    while (i < position && prev->next != NULL)
    {
        prev = prev->next;
        i++;
    }

    // If reached the end, insert at the tail
    if (prev->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }

    // Insert the node in between
    node *curr = prev->next;
    node *newNode = new node(data);
    newNode->next = curr;
    prev->next = newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deletingNodes(int position, node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delte ,LL is empty" << endl;
        return;
    }
    // deleting first node
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int lent = countNodes(head);

    // deleting last node
    if (position == lent)
    {
        // step 1 :find prer
        int i = 1;
        node *prev = head;
        while ((i < position - 1))
        {
            prev = prev - 1;
            i++;
        }
        //  step 2
        prev->next = NULL;
        // step 3
        node *temp = tail;
        // step 4
        tail = prev;
        // step 5
        delete temp;
        return;
    }

    // deleting middle nodes
    // step 1: find prev and current nodes
    int i = 1;
    node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    node *curr = prev->next;

    // step 2
    prev->next = curr->next;
    // step 3
    curr->next = NULL;
    // step 4
    delete curr;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    // Inserting nodes at the head
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);

    // Inserting a node at the tail
    insertAtTail(tail, head, 77);

    // Printing the linked list
    printingNodes(head);

    // Inserting at position 0 (which is the head)
    insertAtPosition(6, head, tail, 102);
    printingNodes(head);

    // Counting the number of nodes
    int totalNodes = countNodes(head);
    cout << "Total number of nodes: " << totalNodes << endl;
    printingNodes(head);
    // DELETING NODES
    deletingNodes(3, head, tail);
    cout << endl;
    printingNodes(head);
    return 0;
}
