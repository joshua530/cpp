#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    int num_rows = 7;
    int boundary = std::ceil((double)num_rows / 2);
    int num_hashes = 0;

    for (int row = 1; row <= num_rows; ++row)
    {
        if (row <= boundary)
            ++num_hashes;
        else
            --num_hashes;

        for (int counter = 1; counter <= num_hashes; ++counter)
            std::cout << "#";
        std::cout << "\n";
    }
}
