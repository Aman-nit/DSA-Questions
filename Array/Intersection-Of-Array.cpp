#include <iostream>
#include <vector>
using namespace std;
// SOLVE FOR DUPLICATE ELEMENT ALSO

int main()
{
    int n, m;

    cout << "Enter number of elemt of arr:-";
    cin >> n;
    cout << "Enter number of elemt of brr:-";
    cin >> m;
    cout << endl;
    vector<int> arr(n);
    vector<int> brr(m);
    cout << "Element of arr:-" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    cout << "Element of brr:-" << endl;
    for (int i = 0; i < brr.size(); i++)
    {
        cin >> brr[i];
    }

    vector<int> ans;
    // INTERSECTION OF ARR AND BRR
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr.size(); j++)
        {
            if (arr[i] == brr[j])
            {
                ans.push_back(arr[i]);
            }
        }
    }

    cout << "Union array is:-" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}