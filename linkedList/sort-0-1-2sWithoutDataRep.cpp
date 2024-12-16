// WHEN DATA REPLACEMENT ARE NOT ALLOWED

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

node *sortZeroOneTwo(node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is empty..." << endl;
        return NULL;
    }

    if (head->next == NULL)
    {
        cout << "Linked List have only one node ..." << endl;
        return head;
    }

    // Creat dummy nodes
    node *zeroHead = new node(-1);
    node *zeroTail = zeroHead;
    node *oneHead = new node(-1);
    node *oneTail = oneHead;
    node *twoHead = new node(-1);
    node *twoTail = twoHead;

    // traverse the orignal Linked List
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // take out the zero wali LL
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // apend the zeronode in zeroHead LL
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if (curr->data == 1)
        {
            // take out the one wali LL
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // apend the onenode in zeroHead LL
            oneTail->next = temp;
            oneTail = oneTail->next;
        }

        else if (curr->data == 2)
        {
            // take out the two wali LL
            node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // apend the twonode in zeroHead LL
            twoTail->next = temp;
            twoTail = twoTail->next;
        }
    }
    // ab yha pr ,zero, one ,two teeno LL ready hai

    // modifying one wali LL
    node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modifying two wali LL
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join LInked List
    if (oneHead != NULL)
    {
        // one wali node is non empty
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        // one wal ilst is empty
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // remove zerohead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return the head of the modified linked list

    return zeroHead;
}

int main()
{

    node *head = new node(0);
    node *first = new node(0);
    node *second = new node(0);
    node *third = new node(0);
    node *fourth = new node(0);
    node *fifth = new node(0);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout << "Printing Nodes...";
    printNodes(head);
    node *sorted = sortZeroOneTwo(head);
    printNodes(sorted);

    return 0;
}
