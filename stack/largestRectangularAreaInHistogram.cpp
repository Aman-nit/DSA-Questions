// #include <iostream>
// #include <vector>
// #include <stack>
// #include <algorithm>
// using namespace std;

// void prevSmaller(vector<int> &bar, vector<int> &prev)
// {

//     stack<int> s;
//     s.push(-1);
//     for (int i = 0; i < bar.size(); i++)
//     {
//         int curr = bar[i];
//         while (s.top() != -1 && bar[s.top()] >= curr)
//         {
//             s.pop();
//         }
//         prev[i] = s.top();

//         s.push(i);
//     }
// }

// void nextSmaller(vector<int> &bar, vector<int> &next)
// {

//     stack<int> s;
//     s.push(-1);
//     for (int i = bar.size() - 1; i >= 0; i--)
//     {
//         int curr = bar[i];
//         while (s.top() != -1 && bar[s.top()] >= curr)
//         {
//             s.pop();
//         }
//         next[i] = s.top();

//         s.push(i);
//     }
// }

// void printVector(vector<int> &p)
// {

//     for (int i = 0; i < p.size(); i++)
//     {
//         cout << p[i] << " ";
//     }
//     cout << endl;
// }

// int getRectangularAreaHistogram(vector<int> &height, vector<int> &next, vector<int> &prev)
// {

//     int maxArea = 0;
//     int size = height.size();
//     for (int i = 0; i < height.size(); i++)
//     {
//         int length = height[i];
//         if (next[i] == -1)
//         {
//             next[i] = size;
//         }

//         int width = next[i] - prev[i] - 1;
//         int area = length * width;
//         maxArea = max(maxArea, area);
//     }
//     return maxArea;
// }
// int main()
// {
//     vector<int> bar;
//     bar = {2, 1, 5, 6, 2, 3};
//     vector<int> prev(bar.size());
//     vector<int> next(bar.size());
//     vector<int> areaVector(bar.size());

//     printVector(bar);
//     prevSmaller(bar, prev);
//     printVector(prev);
//     nextSmaller(bar, next);
//     printVector(next);
//     int maxArea = getRectangularAreaHistogram(bar, prev, next);
//     cout << maxArea << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void prevSmaller(const vector<int> &bar, vector<int> &prev)
{
    stack<int> s;
    s.push(-1); // Push -1 to handle the case for the first element
    for (int i = 0; i < bar.size(); i++)
    {
        int curr = bar[i];
        while (s.top() != -1 && bar[s.top()] >= curr)
        {
            s.pop();
        }
        prev[i] = s.top(); // Index of previous smaller element
        s.push(i);         // Push current index
    }
}

void nextSmaller(const vector<int> &bar, vector<int> &next)
{
    stack<int> s;
    s.push(-1); // Push -1 to handle the case for the last element
    for (int i = bar.size() - 1; i >= 0; i--)
    {
        int curr = bar[i];
        while (s.top() != -1 && bar[s.top()] >= curr)
        {
            s.pop();
        }
        next[i] = s.top(); // Index of next smaller element
        s.push(i);         // Push current index
    }
}

void printVector(const vector<int> &p)
{
    for (int value : p)
    {
        cout << value << " ";
    }
    cout << endl;
}

int getRectangularAreaHistogram(const vector<int> &height, const vector<int> &next, const vector<int> &prev)
{
    int maxArea = 0; // Start with 0 as maximum area
    int size = height.size();
    for (int i = 0; i < height.size(); i++)
    {
        int length = height[i];
        int width = (next[i] == -1 ? size : next[i]) - prev[i] - 1; // Handle edge case
        int area = length * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main()
{
    vector<int> bar = {2, 4};
    vector<int> prev(bar.size());
    vector<int> next(bar.size());

    cout << "Bar heights: ";
    printVector(bar);

    prevSmaller(bar, prev);
    cout << "Previous smaller indices: ";
    printVector(prev);

    nextSmaller(bar, next);
    cout << "Next smaller indices: ";
    printVector(next);

    int maxArea = getRectangularAreaHistogram(bar, next, prev);
    cout << "Maximum area: " << maxArea << endl;

    return 0;
}
