#include <iostream>

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

bool inArray(auto needle, auto *hayStack, int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        if (needle == hayStack[i])
            return true;
    return false;
}
