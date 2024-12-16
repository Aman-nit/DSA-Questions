#include <iostream>
// #include <stack>
using namespace std;

// WE CAN CREAT STACK USING STATIC AND DYNAMIC ARRY AND USING LINKED LIST

// Using Dynamic Array

class stack
{
private:
    int *arr;
    int top;
    int siz;

public:
    stack(int size)
    {
        arr = new int[size];
        this->siz = size;
        top = -1;
    }

    // Functions
    void push(int data)
    {
        if (siz - top > 1)
        {
            // space avilable
            // insering data
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is full..../Stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            // stack is empty

            cout << "Stack is empty.. /Stack under flow" << endl;
        }
        else
        {
            // stack is not empty
            top--;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            // stack is empty

            cout << "Stack is empty.. /Stack under flow" << endl;
        }
        else
        {
            int data = arr[top];
            return data;
        }
    }
    int size()
    {
        cout << top + 1 << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{

    // creation of stack using  STL(Standard templete library)
    /* stack<int> st;

     // Insertion
     st.push(10);
     st.push(20);
     st.push(30);
     st.push(40);
     st.push(50);
     st.push(60);

     // Remove
     st.pop();

     // Check aelement on top
     cout << "Element on top is : " << st.top() << endl;

     // Size
     cout << "Size of the stack is: " << st.size() << endl;

     cout << st.empty() << endl;
     if (st.empty())
     {
         cout << "Stack is empty... " << endl;
     }
     else
     {
         cout << "Stack is not empty..." << endl;
     }

     // printing stack elements
     while (st.empty() == 0)
     {
         cout << st.top() << " " << endl;
         st.pop();
     } */

    stack s(10);

    // insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.isEmpty())
    {
        cout << s.getTop() << endl;
        s.pop();
    }

    return 0;
}
