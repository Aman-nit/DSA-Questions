// only root node can be delete in the heap
// PROCESS
// replace last node with rooot node
// place root node node at right place
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
    int deleteNode()
    {
        // replace root node value with last node value
        arr[1] = arr[size];
        size--;

        // place root node node at right place
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index;

            int largest = index;
            if (left < size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right < size && arr[largest] < arr[right])
            {
                largest = right;
            }
            if (largest == index)
            {
                // Value is at correct position
                return;
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
    }
};

int main()
{
    // CREATION OF HEAP
    heap h;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout << "Printing the heap " << endl;
    for (int i = 1; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;
    return 0;
}