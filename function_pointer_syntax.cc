#include <iostream>

typedef void (*func)(std::string); // type

void printName(std::string name)
{
    std::cout << name << "\n";
}

int main(int argc, char const *argv[])
{
    func f = &printName;
    void (*foo)(std::string) = &printName; // variable

    f("John");
    foo("Doe");
    (*foo)("John");
    (*f)("Doe");

    // to call a member function referred to by a pointer, do
    // (this->*func_ptr)(params)
}
