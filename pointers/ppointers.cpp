#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 5;
    int *ptr = &a;
    cout << a << endl;
    // cout << &a << endl;
    // cout << &b << endl;
    cout << ptr << endl;
    a += 1;
    cout << a << endl;
    ptr += 1;
    cout << ptr << endl;
    cout << *ptr << endl;

    int *intPtr;
    char *charPtr;
    double *doublePtr;
    float *floatPtr;
    void *voidPtr;

    cout << "Size of int pointer: " << sizeof(intPtr) << " bytes" << endl;
    cout << "Size of char pointer: " << sizeof(charPtr) << " bytes" << endl;
    cout << "Size of double pointer: " << sizeof(doublePtr) << " bytes" << endl;
    cout << "Size of float pointer: " << sizeof(floatPtr) << " bytes" << endl;
    cout << "Size of void pointer: " << sizeof(voidPtr) << " bytes" << endl;
    // NULL POINTER
    int *point = 0;
    cout << *point << endl;

    return 0;
}