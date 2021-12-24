//#include "test_template.cpp"
#include "test_template.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    TestTemp<int> foo;
    foo.setValue(0);
    std::cout << foo.getValue() << "\n";
}
