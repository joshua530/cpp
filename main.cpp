#include <iostream>

typedef void (*func)(std::string);

void printName(std::string name)
{
    std::cout << name << "\n";
}

int main(int argc, char const *argv[])
{
    func f = &printName;
    void (*foo)(std::string) = &printName;
}
