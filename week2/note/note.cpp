#include <iostream>

class A
{
public:
    int a;
};

A &f(int b)
{
    A a;
    a.a = b;
    return a;
}

int main()
{
    A &a = f(10);
    std::cout << a.a << std::endl;
    std::cout << "Hello World" << std::endl;
    std::cout << a.a << std::endl;
}