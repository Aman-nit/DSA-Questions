//WHEN DATA REPLACEMENT ARE ALLOWED 

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

void sortZeroOneTwo(node *&head)
{
    // step-01, find number of zeros ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        if (temp->data == 1)
        {
            one++;
        }
        if (temp->data == 2)
        {
            two++;
        }
        temp = temp->next;
    }

    // step-02, fill 0 ,1,2
    temp = head;
    while (temp != NULL)
    {

        // filling 0
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }
        // filling 1
        while (one--)
        {
            temp->data = 1;
            temp = temp->next;
        }
        // filling 0
        while (two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
}

int main()
{

    node *head = new node(1);
    node *first = new node(2);
    node *second = new node(2);
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
    sortZeroOneTwo(head);
    // printNodes(head);
    printNodes(head);

    return 0;
}
