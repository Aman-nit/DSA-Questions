// A integer is given to you that is the size of a rod and 3 sizes X,Y anad z  is given to you find out the maximum number of piece can be created by that rod .
#include <iostream>
#include <vector>
using namespace std;
int cutIntoSegments(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT16_MIN;
    }

    int a = cutIntoSegments(n - x, x, y, z) + 1;
    int b = cutIntoSegments(n - y, x, y, z) + 1;
    int c = cutIntoSegments(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));

    return ans;
}

int main()
{
    int n, x, y, z;
    cout << "Enter length of rod:-";
    cin >> n;
    cout << "Enter size of 1st segment:-";
    cin >> x;
    cout << "Enter size of 2nd segment:-";
    cin >> y;
    cout << "Enter size of 3rd segment:-";
    cin >> z;

    int ans = cutIntoSegments(n, x, y, z);
    if (ans < 0)
    {
        ans = 0;
    }
    cout << "Maximum number of segment is  " << ans;
    return 0;
}