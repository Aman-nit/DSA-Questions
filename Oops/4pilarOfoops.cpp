#include <iostream>
using namespace std;

// ENCAPSULATION

// It is basially hiding the data member and member function , we can say we are Encapsulate the member in a class or object by using access modifier
class animal
{
private:
    int age;
    int weight;

public:
    void eating()
    {
        cout << "Eating ....." << endl;
    }

    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

// INHARITANCE called (is a relationship)

// types of INHARITANCE
// 1.Single == 1 parent properties inharits to 1 child
// 2.Multilevel == 1 parent class properties inharits to child then grand child then grand of grand child and soo on.....
// 3.Multiple == 2 parent class properties inharits to 1 single child
// 4. Hirarchical == 1 parents properties inharits to multiple child
// 5.Hybrid == mixture of all types of inharitance

// inharit is the transfer of properties (data member & member function) from a parent class to a child class
class fish
{
public:
    int age;
    int weight;
    void swiming()
    {
        cout << "Swiming....." << endl;
    }
};

// 1.Single == 1parent properties inharits to 1 child
// tuna is a child class inharited from fish
class tuna : public fish
{
};

// 2.Multilevel == 1 parent class properties inharits to child then grand child then grand of grand child and soo on.....
class fruits
{
public:
    string name;
};
class mango : public fruits
{
public:
    int weight;
};
class alphanso : public mango
{
public:
    int sugarLevel;
};

// 3.Multiple == 2 parent class properties inharits to 1 single child
class a
{
public:
    int physic;
    a()
    {
        physic = 210;
    }
};
class b
{
public:
    int physic;
    b()
    {
        physic = 120;
    }
};
class c : public a, public b
{
public:
    int math;
};

// 4. Hirarchical == 1 parents properties inharits to multiple child
class car
{
public:
    int age;
    int weight;
    string name;
    void speedUp()
    {
        cout << "Speeding up...." << endl;
    }
};
class scorpio : public car
{
};
class fortuner : public car
{
};

// POLYMORPHSIM (existing in many form )
// 1.Compile time polymorhism
// 2.run time polymorhsim

// 1.Compile time polymorhism
// i.functio overloading
// ii.operator overloading

// i.functio overloading(functional polymorphsim)
class math
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
    int sum(int a, float b)
    {
        return a + b + 100;
    }
};

// ii.operator overloading
class param
{
public:
    int val;

    void operator+(param &obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;
        cout << (value2 - value1) << endl;
    }
};

// 2.run time polymorhsim/Dynamic binding
// function overriding
class birds
{
public:
    virtual void speaking()
    {
        cout << "Swiming....." << endl;
    }
};
class crow : public birds

{
public:
    // override
    void speaking()
    {
        cout << "Barking.....";
    }
};

// 4. ABSTRACTION

int main()
{
    // singe inharitance
    tuna f;
    f.swiming();
    // multilevel inharitance
    alphanso a;
    cout << a.name << " " << a.weight << " " << a.sugarLevel << endl;
    // Multiple inharitance
    // dimond problem/
    // when same properties are present in both parent then compiler will be confused which parent side of the properties to be display
    // scope resolutiion operator
    c obj;
    cout << obj.a::physic << " " << obj.b::physic << " " << obj.math << endl;

    // 4. Hirarchical == 1 parents properties inharits to multiple child
    scorpio f11;
    f11.speedUp();
    fortuner s11;
    s11.speedUp();

    // POLYMORPHSIM (existing in many form )
    // i.functio overloading(functional polymorphsim)
    math obb;
    cout << obb.sum(43, 87) << endl;

    // ii.operator overloading

    param obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;
    // this should print difference  between them
    obj1 + obj2;

    // 2.run time polymorhsim/Dynamic binding
    // function overriding
    // birds namee;
    // namee.speaking();
    // crow s;
    // s.speaking();

    // Upcasting
    birds *hell = new crow();
    hell->speaking();

    return 0;
}