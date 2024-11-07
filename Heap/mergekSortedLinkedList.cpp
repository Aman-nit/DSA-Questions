#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with weight and value
struct Item
{
    double weight;
    double value;
};

// Comparator function to sort items based on value/weight ratio in descending order
bool compare(Item a, Item b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

// Function to perform the Fractional Knapsack algorithm
double fractionalKnapsack(int capacity, vector<Item> &items)
{
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0; // Maximum value we can get

    for (const auto &item : items)
    {
        if (capacity == 0)
            break;

        // Check if we can take the whole item
        if (item.weight <= capacity)
        {
            totalValue += item.value;
            capacity -= item.weight;
        }
        else
        {
            // Take the fraction of the remaining weight
            totalValue += item.value * (capacity / item.weight);
            capacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

int main()
{
    int n;
    double capacity;

    // Take input from the user
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> capacity;

    // Calculate maximum value we can carry in the knapsack
    double maxValue = fractionalKnapsack(capacity, items);

    // Display the result
    cout << "The maximum value in the knapsack can be: " << maxValue << endl;

    return 0;
}
