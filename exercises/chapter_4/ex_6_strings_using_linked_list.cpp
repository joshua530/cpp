#include <iostream>
// characterAt
struct stringNode {
    char character;
    stringNode *next;
};

typedef stringNode *listString;

using std::cout;

void append(listString &str, char toAppend)
{
    stringNode *character = new stringNode;
    character->character = toAppend;
    character->next = NULL;

    if (str == NULL) {
        str = character;
        return;
    }

    stringNode *iterator = str;
    while (iterator->next != NULL)
        iterator = iterator->next;

    iterator->next = character;
}

/**
 * Finds character at given position. The position is one based
 */
char characterAt(const listString &s, int position)
{
    if (position < 1)
        return 0;

    stringNode *iterator = s;
    int counter = 1;

    while (iterator != NULL) {
        if (counter == position)
            return iterator->character;
        iterator = iterator->next;
        ++counter;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    listString str;
    stringNode *n = new stringNode;
    n->character = 'a';
    stringNode *n2 = new stringNode;
    n2->character = 'b';
    stringNode *n3 = new stringNode;
    n3->character = 'c';
    n->next = n2;
    n2->next = n3;
    n3->next = NULL;
    str = n;
    n = n2 = n3 = NULL;
    // append(str, 'd');

    listString str2; // default value?
    listString str3 = NULL;
    // append(str2, 'a');
    // append(str3, 'a');

    std::cout << characterAt(str, 2) << "\n";
    std::cout << characterAt(str, 4) << "\n";
    std::cout << characterAt(str, 1) << "\n";
    std::cout << characterAt(str, 0) << "\n";

    cout << characterAt(str2, 1) << "\n";
    cout << characterAt(str3, 1) << "\n";
}
