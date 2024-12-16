#include <iostream>
using namespace std;
void util(int* p)
{
*p +=1;
}

int main() {
 
 int a =5;

 int* p = &a;
 int ** q = &p;

 cout << "before "<< endl;
 cout << a<< endl;
 cout << p<< endl;
 cout << *p<< endl;

 util(p); 

 cout << "After "<< endl;
 cout << a<< endl;
 cout << p<< endl;
 cout << *p<< endl;
 
  return 0;
}