#include <iostream>
using namespace std;

void SolveArr(int arr[])
{
    cout << sizeof(arr);
}

int main()
{

    int arr[4] = {1, 12, 13, 4};
    // cout << arr << endl;
    // cout << arr[0] << endl;
    // cout << &arr << endl;
    // cout << &arr[0] << endl;

    // int *p = arr;
    // cout << p << endl;
    // cout << &p << endl;
    // cout << *arr << endl;
    // cout << *arr + 1 << endl;   // it will add 1 in arr[0]==1;
    // cout << *(arr + 1) << endl; // it will be like arr[0+1]==12

    int i = 2;
    cout << arr[i] << endl;
    cout << i[arr] << endl;

    char ch[10] = "Aman";
    char *ptr = ch;
    cout << ch << endl;
    cout << &ch << endl;
    cout << ch[0] << endl;
    cout << &ptr << endl;
    cout << *ptr << endl;
    SolveArr(arr);

    return 0;
}