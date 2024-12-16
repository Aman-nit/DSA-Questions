#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int gasStation(vector<int> &gas, vector<int> &cost)

{
    // ketna petrol km pad gaya hai
    int deficit = 0;
    // ketna petrol bacha hai
    int balance = 0;
    // circuit kaha se start krre ho
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int numbOfGasStation;

    cout << "Enter number of gas station present in a circular track:-";
    cin >> numbOfGasStation;
    vector<int> gas(numbOfGasStation);
    vector<int> cost(numbOfGasStation);
    cout << "Enter the amount of gas avilable in gas station.";
    for (int i = 0; i < gas.size(); i++)
    {
        cin >> gas[i];
    }
    cout << "Enter amount of gas required to visit next  station.";
    for (int i = 0; i < cost.size(); i++)
    {
        cin >> cost[i];
    }

    int ans = gasStation(gas, cost);
    if (ans > 0)
    {
        cout << "If we start from " << ans + 1 << "th gas station we cancomplete the circle.";
    }
    else
    {
        cout << "Oops we cant complete the cicle.";
    }

    return 0;
}