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
    cout << "!No duplicate elemets are allowed!" << endl;
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
    cout << endl;
    vector<int> ans;
    // PUTTING ARR ELEMENTS IN ANS
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
    }
    // PUTTING BRR ELEMENTS IN ANS
    for (int i = 0; i < brr.size(); i++)
    {
        ans.push_back(brr[i]);
    }
    cout << "Union array is:-" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}