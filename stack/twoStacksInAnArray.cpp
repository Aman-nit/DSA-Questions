#include <iostream>
using namespace std;

class stack
{
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }
    // functions

    void push1(int data)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stck overflow.....Stack 1" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stck overflow..... Stack 2" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack is empty.../underflow in stack 1" << endl;
        }
        else
        {
            top1--;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack is empty.../underflow in stack 2" << endl;
        }
        else
        {
            top2++;
        }
    }
    // This is just for understanding and visualising how this array is filling and how all are going in side the array
    // IT IS NOT THE  PART OF IMPLEMENTATION OF STACK USING ARRAY
    void print()
    {
        cout << endl;
        cout << "top1: " << top1 << endl;
        cout << "top2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();
    s.push1(60);
    s.print();

    s.push2(100);
    s.print();
    s.push2(200);
    s.print();
    s.push2(300);
    s.print();
    s.push2(400);
    s.print();

    return 0;
}
