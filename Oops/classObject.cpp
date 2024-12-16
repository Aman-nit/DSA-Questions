#include <iostream>
using namespace std;

class Animal
{
private:
    int weight;

    // used to change access modifier private to public by defult acess modifier is private(object data and behaviour not acessesable outside the class);
public:
    // TO access and set the value of private data in object we have to use get and set function
    int getWeight()
    {
        return weight;
    }

    int setweight(int weight /*w*/)
    {
        // weight = w;
        // another way
        this->weight = weight;
    }

    // constructor is a initilization of a object memmber
    //  default constructor
    Animal()
    {
        this->weight = 0;
        this->age = 0;
        this->name = " ";
        cout << "Constructor called" << endl;
    }

    // parametrised constructor
    Animal(int age)
    {
        this->age = age;
        cout << "Parameterised constroctor called" << endl;
    }

    // Destructure (deleting the object )//in statically creating object destructor called automatically
    ~Animal()
    {
        cout << "i am in a statically destructor..." << endl;
    }
    // in case of dynamically creating /initilizing object we have to set a destructor to delete the object
    // delete b;

    // copy constructor
    Animal(Animal &obj)
    {
        this->age = obj.age;
        this->weight = obj.weight;
        this->name = obj.name;
        cout << "I am inside the copy Constructor" << endl;
    }
    // class have 2 things 1 state or properties
    int age;
    string name;

    // 2. Behaviour
    void sleep()
    {
        cout << "Dog is sleep ....." << endl;
    }
    void eat()
    {
        cout << "Dog is eating ....." << endl;
    }
};

int main()
{
    // Object creation

    // static creation
    Animal Dog;
    Dog.age = 12;
    Dog.name = "Locifer";
    cout << "Age of the dog is :- " << Dog.age << endl;
    cout << "Name of the dog is :- " << Dog.name << endl;
    Dog.eat();
    Dog.sleep();

    // Dynamic memory
    Animal *cat = new Animal;
    // because cat is a pointer
    (*cat).age = 15;
    (*cat).name = "Pillo";

    // alternate - dynamic
    cat->age = 32;
    cat->name = "Hello";
    cout << cat->age << endl;

    // Acessing private member of object
    Dog.setweight(10);
    cout << "Weight of the dog is :- " << Dog.getWeight() << endl;

    // initilization of object/calling constructor
    Animal a(32);
    Animal *b = new Animal(67);

    // Copying 1 object to another object
    // Animal c = a;
    Animal d(a);

    // deleting b
    delete b;
    return 0;
}