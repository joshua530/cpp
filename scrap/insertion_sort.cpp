#include <iostream>

using std::cout;
using std::endl;

std::string strArray(int *toPrint, int);

// int main(int argc, char const *argv[])
// {
//     const int ARR_SIZE = 10;
//     int items[ARR_SIZE] = {2, 1, 33, 5, 89, 28, 0, -3, 9, -22};

//     cout << strArray(items, ARR_SIZE) << endl;
//     int start = 0;
//     for (int i = start; i < ARR_SIZE; ++i)
//         for (int j = i; j > start && items[j] < items[j - 1]; --j) {
//             int tmp = items[j];
//             items[j] = items[j - 1];
//             items[j - 1] = tmp;
//         }
//     cout << strArray(items, ARR_SIZE) << endl;
//     return 0;
// }

std::string strArray(int *toPrint, int size)
{
    std::string items = "";
    char tmp[50];

    for (int i = 0; i < size; ++i) {
        sprintf(tmp, "%d ", toPrint[i]);
        items += tmp;
    }
    items.erase(items.find_last_not_of(" ") + 1);
    return items;
}
