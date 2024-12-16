#include <iostream>  // Including necessary libraries to use input/output
#include <vector>    // To use the vector data structure
#include <algorithm> // For using the 'min' function to compare two numbers

using namespace std; // To avoid typing 'std::' before standard C++ features (like cout, cin)

// Class definition for a custom stack named "MyStack"
class MyStack
{
public:
    // A vector (dynamic array) to hold pairs of integers.
    // Each pair stores two values:
    // 1. The value we push onto the stack.
    // 2. The minimum value in the stack at the time of that push.
    vector<pair<int, int>> st;

    // Default constructor for MyStack (though not used here)
    void minStack()
    {
    }

    // Function to push a new element onto the stack
    // The element being pushed is 'val'
    void push(int val)
    {
        // If the stack is empty, we push the first value as the minimum value
        if (st.empty())
        {
            // 'make_pair' creates a pair where both the value and the minimum value are the same (since it's the only element)
            pair<int, int> p = make_pair(val, val);
            st.push_back(p); // Push the pair into the stack
        }
        else
        {
            // Otherwise, we push the new value 'val' and the minimum between 'val' and the current minimum element in the stack
            pair<int, int> p;
            p.first = val;                         // The actual value to be pushed onto the stack
            p.second = min(val, st.back().second); // The minimum value so far, comparing with the last minimum
            st.push_back(p);                       // Push this pair onto the stack
        }
    }

    // Function to remove the top element from the stack
    void pop()
    {
        st.pop_back(); // Removes the top element from the vector (stack)
    }

    // Function to check if the stack is empty
    bool empty()
    {
        return st.empty(); // Returns 'true' if the stack is empty, otherwise 'false'
    }

    // Function to get the top element of the stack
    int top()
    {
        return st.back().first; // Returns the first value (the actual stack value) of the top element
    }

    // Function to get the minimum element in the stack at the current time
    int getMin()
    {
        return st.back().second; // Returns the second value (the minimum value) of the top element
    }
};

// Main function to demonstrate the working of the stack
int main()
{
    MyStack ms; // Create an object 'ms' of MyStack class

    // Push five elements onto the stack
    ms.push(10); // Push 10 onto the stack
    ms.push(5);  // Push 5 onto the stack
    ms.push(20); // Push 20 onto the stack
    ms.push(2);  // Push 2 onto the stack
    ms.push(8);  // Push 8 onto the stack

    // Display the current top and minimum elements of the stack
    cout << "Top element: " << ms.top() << endl;        // Should output the last pushed element (8)
    cout << "Minimum element: " << ms.getMin() << endl; // Should output the minimum element (2) so far

    return 0; // End of the program
}
