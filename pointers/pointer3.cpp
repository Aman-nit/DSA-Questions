#include <iostream>
using namespace std;
void util(int *p)
{
  *p += 1;
}
void solve(int **p)
{
  **p += 1;
}

void refrenceFunc(int &a)
{
  a++;
}
int main()
{

  //  int a =5;

  //  int* p = &a;
  //  int ** q = &p;

  //  cout << "before "<< endl;
  //  cout << a<< endl;
  //  cout << p<< endl;
  //  cout << *p<< endl;

  //  util(p);

  //  cout << "After "<< endl;
  //  cout << a<< endl;
  //  cout << p<< endl;
  //  cout << *p<< endl;

  // int x = 12;
  // int *p = &x;
  // int **q = &p;

  // cout << x << endl;
  // solve(q);
  // cout << x << endl;

  // ----------------------REFRENCE VARIABLE---------------------------------

  int n = 5;
  int &m = n;
  // m is refrence variable which is pointing to the same memory location of a
  // here only m is creating in sambol table with the location of n

  //               SAMBOL TABLE
  //__________________________________________
  // n ====> let 104 (location of n)
  // m ====> 104 (location of n)
  cout << n << endl;
  cout << m << endl;

  refrenceFunc(n);

  cout << n << endl;
  return 0;
}