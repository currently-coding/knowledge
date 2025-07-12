#include <iostream>

class MyClass
{
private:
    static int accessCount; // Static member variable to count accesses
    int data;               // Sample member variable

public:
    MyClass(int value) : data(value) {}

    // Const member function that accesses data
    int getValue() const
    {
        ++accessCount; // IncrThis approach allows you to track accesses to const member functions without violating const-correctness. The mutable static variable ensures that the access count is maintained across all instances of the class and can be accessed even from const member functions.ement access count
        return data;   // Access and return data
    }

    // Static member function to display access count
    static void displayAccessCount()
    {
        std::cout << "Access count: " << accessCount << std::endl;
    }
};

// Initialization of static member variable
int MyClass::accessCount = 0;

int main()
{
    MyClass obj(10);

    // Access getValue multiple times
    for (int i = 0; i < 5; ++i)
    {
        int value = obj.getValue();
        std::cout << "Value: " << value << std::endl;
    }

    // Display access count
    MyClass::displayAccessCount();

    return 0;
}
