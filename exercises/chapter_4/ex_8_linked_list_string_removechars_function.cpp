#include <iostream>

struct stringNode {
    char character;
    stringNode *next;
};

typedef stringNode *listString;

using std::cout;

/**
 * Removes a certain number of characters from a string
 * @param start the one based position where removal will start
 * @param len the number of characters to be removed
 */
void removeChars(listString &s, int start, int len)
{
    stringNode *beforeRemoval;
    stringNode *iterator = s;
    int position = 1;

    if (start == 1) {
        beforeRemoval = NULL;
    } else {
        // find node before the first one to be removed
        while (position < start - 1) {
            iterator = iterator->next;
            ++position;
        }

        beforeRemoval = iterator;
        // move pointer forward to first node to be removed
        iterator = beforeRemoval->next;
        ++position;
    }

    // end of list not reached and we haven't reached the last node
    // to delete
    stringNode *tmp;
    while (iterator != NULL && position < start + len) {
        tmp = iterator;
        iterator = iterator->next;
        ++position;
        delete tmp;
    }

    if (beforeRemoval != NULL) {
        beforeRemoval->next = iterator;
    } else {
        s = iterator;
    }
}

int main(int argc, char *argv[])
{
    stringNode *c = new stringNode;
    c->character = 'a';
    stringNode *c2 = new stringNode;
    c2->character = 'b';
    stringNode *c3 = new stringNode;
    c3->character = 'c';
    stringNode *c4 = new stringNode;
    c4->character = 'd';
    stringNode *c5 = new stringNode;
    c5->character = 'e';
    stringNode *c6 = new stringNode;
    c6->character = 'f';
    c->next = c2;
    c2->next = c3;
    c3->next = c4;
    c4->next = c5;
    c5->next = c6;
    c6->next = NULL;

    listString s = c;
    c = c2 = c3 = c4 = c5 = c6 = NULL;

    // removeChars(s, 2, 3);
    // removeChars(s, 1, 6);
    listString u = NULL;
    listString t;
    removeChars(u, 1, 1);
    // removeChars(t, 1, 1); // default value?
}
