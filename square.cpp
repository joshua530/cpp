#include <iostream>

int main(int argc, char const *argv[])
{
    int size;
    std::cout << "Enter square size: ";
    std::cin >> size;
    std::cout << std::endl;

    for (int i = size; i >= 1; --i) // for each column
    {
        for (int j = 1; j <= size; ++j) // print row
            std::cout << "#";
        std::cout << std::endl;
    }

    return 0;
}
