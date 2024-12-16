#include <iostream>
#include <vector>
using namespace std;
int main()
{

    vector<int> arr;
    int ans = (arr.size() / sizeof(int));
    cout << arr.size();
    cout << arr.capacity() << endl;
    cout << ans;

    return 0;
}