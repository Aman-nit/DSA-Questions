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
        data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to print nodes from head to tail
void printNodes(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to reverse the linked list
void reverseList(node *&head, node *prev, node *curr)
{
    // Base case: when we reach the end of the list
    if (curr == NULL)
    {
        // Set the new head as the previous node
        head = prev;
        return;
    }
    // Save the next node to move forward in the list
    node *forward = curr->next;

    // Reverse the direction
    curr->next = prev;
    if (prev != NULL)
        prev->prev = curr;

    // Recursion to reverse the next part of the list
    reverseList(head, curr, forward);
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    // Create nodes
    node *first = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    node *fourth = new node(40);

    // Link the nodes
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->prev = third;
    third->prev = second;
    second->prev = first;

    head = first;
    tail = fourth;

    // Print the original list
    cout << "Original List: ";
    printNodes(head);
    cout << endl;

    // Reverse the list
    node *prev = NULL;
    node *curr = head;
    reverseList(head, prev, curr);

    // Print the reversed list
    cout << "Reversed List: ";
    printNodes(head);
    cout << endl;

    return 0;
}
