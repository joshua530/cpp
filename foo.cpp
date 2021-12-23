#include <ctime>
#include <iostream>
#include <random>

int getRandomAge()
{
    return (random() % 99) + 1;
}

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 300; ++i)
        std::cout << getRandomAge() << "\n";
}
