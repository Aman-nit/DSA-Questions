// VALID ONLY FOR SORTED LINKED LIST

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

void removeDuplicte(node *&head)
{
    // FOR EMPTY LINKED LIST
    if (head == NULL)
    {
        cout << "Linked List is empty.........." << endl;
        return;
    }
    // For SINGLE NODE IN LINKED LIST
    if (head->next == NULL)
    {
        cout << "Single node in Linked List......." << endl;
        return;
    }
    // FOR >1 NODES IN LINKED LIST
    node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            // delete node
            temp = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{

    node *head = new node(1);
    node *first = new node(2);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(4);
    node *fifth = new node(4);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "Printing Nodes...";
    printNodes(head);
    removeDuplicte(head);
    cout << "Removed duplicate nodes...";
    printNodes(head);

    return 0;
}
