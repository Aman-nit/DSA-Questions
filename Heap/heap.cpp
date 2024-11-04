// COMPLETE BINARY TREE:- a binary tree which have all the level is completely filled except last level and filling of nodes follow left to right filling .

// HEAP:- is a data structure which is complete binary tree and follow heap properties

// MAX HEAP:- Every node of complete binary shoud be greater than their child nodes

// INSERTION OF NODE IN HEAP
#include <iostream>
using namespace std;

class heap
{
public:
    int arr[101];
    int size;

    heap()
    {
        size = 0;
    }
    void insert(int value)
    {
        // value insert karo end me
        size = size + 1;
        int index = size;
        arr[index] = value;

        // Iss value ko sahi position pr le jan hai
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
};
int main()
{
    heap h;
    // INSERING IN A HEAP
    //  h.arr[0] = -1;
    //  h.arr[1] = 100;
    //  h.arr[2] = 50;
    //  h.arr[3] = 60;
    //  h.arr[4] = 40;
    //  h.arr[5] = 45;
    //  h.size = 5;

    // CREATION OF HEAP

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    // cout << "Printing the heap " << endl;
    // for (int i = 0; i <= h.size; i++)
    // {
    //     cout << h.arr[i] << " ";
    // }
    // cout << endl;

    cout << "Printing the heap " << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    return 0;
}