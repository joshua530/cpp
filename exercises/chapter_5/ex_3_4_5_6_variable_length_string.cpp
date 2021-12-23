#include <iostream>

class String {
private:
    struct StringNode {
        char character;
        StringNode *next;
    };
    typedef StringNode *ListString;

public:
    String();
    String(const String &s);
    String(std::string s);
    String(char c);
    ~String();

    void append(char toAppend);
    void concatenate(const String &str);
    void remove(int start, int count);

    char operator[](const int &i);

private:
    ListString _headNode;
    ListString copiedString(const String &s);
    void concatenate(const ListString &s);
    void deleteString();
    ListString fromString(std::string s);
    ListString fromChars(const char *chars);
    char characterAt(int position);
    StringNode *createNode(char c, StringNode *next);
};

String::String()
{
    _headNode = NULL;
}

String::String(const String &s)
{
    ListString newString = copiedString(s);
    _headNode = newString;
}

/**
 * Creates a new string node
 */
String::StringNode *String::createNode(char c, StringNode *next)
{
    StringNode *node = new StringNode;
    node->character = c;
    node->next = next;
    return node;
}

String::ListString String::fromString(std::string s)
{
    ListString newString = NULL;
    StringNode *newNode;
    StringNode *loopPtr;

    for (const char &c : s) {
        newNode = createNode(c, NULL);

        if (newString == NULL) {
            newString = loopPtr = newNode;
        } else {
            loopPtr->next = newNode;
            loopPtr = loopPtr->next;
        }
    }
    return newString;
}

String::String(std::string s)
{
    _headNode = fromString(s);
}

String::String(char c)
{
    StringNode *newNode = createNode(c, NULL);
    _headNode = newNode;
}

String::~String()
{
    deleteString();
}

void String::deleteString()
{
    StringNode *current = _headNode;
    StringNode *tmp;

    while (current != NULL) {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    std::cout << "";
}

void String::append(char toAppend)
{
    StringNode *newNode = createNode(toAppend, NULL);

    if (_headNode == NULL) {
        _headNode = newNode;
        return;
    }

    StringNode *loopPtr = _headNode;
    while (loopPtr->next != NULL)
        loopPtr = loopPtr->next;
    loopPtr->next = newNode;
}

void String::concatenate(const String &b)
{
    if (b._headNode == NULL)
        return;

    // checks whether ListStrings are stored in same location to
    // avoid endless loop when an object is concatenated with itself
    if (_headNode == b._headNode) {
        ListString l = copiedString(b);
        concatenate(l);
    } else
        concatenate(b._headNode);
}

void String::concatenate(const ListString &s)
{
    StringNode *toCopyPosition = s;
    StringNode *currentPosition = _headNode;
    StringNode *toCopy;

    while (currentPosition != NULL && currentPosition->next != NULL)
        currentPosition = currentPosition->next;

    // in case the object's string is currently empty
    toCopy = createNode(toCopyPosition->character, NULL);

    if (currentPosition == NULL) {
        currentPosition = toCopy;
        _headNode = currentPosition;
    } else {
        currentPosition->next = toCopy;
        currentPosition = currentPosition->next;
    }
    toCopyPosition = toCopyPosition->next;

    while (toCopyPosition != NULL) {
        toCopy = createNode(toCopyPosition->character, NULL);

        currentPosition->next = toCopy;

        currentPosition = currentPosition->next;
        toCopyPosition = toCopyPosition->next;
    }
}

char String::characterAt(int position)
{
    if (_headNode == NULL || position < 1)
        return 0;

    int currentPos = 1;
    StringNode *loopPtr = _headNode;

    while (loopPtr != NULL && currentPos < position) {
        loopPtr = loopPtr->next;
        ++currentPos;
    }

    if (loopPtr == NULL)
        return 0;

    if (currentPos == position)
        return loopPtr->character;
    return 0;
}

char String::operator[](const int &i)
{
    return characterAt(i);
}

String::ListString String::copiedString(const String &s)
{
    if (s._headNode == NULL)
        return NULL;

    ListString newString;
    StringNode *oldStringPos = s._headNode;
    StringNode *newStringPos;

    StringNode *newNode = createNode(oldStringPos->character, NULL);
    newString = newStringPos = newNode;

    oldStringPos = oldStringPos->next;

    while (oldStringPos != NULL) {
        newNode = createNode(oldStringPos->character, NULL);
        newStringPos->next = newNode;

        newStringPos = newStringPos->next;
        oldStringPos = oldStringPos->next;
    }
    return newString;
}

void String::remove(int start, int count)
{
    if (start < 0 || count < 1)
        return;
    if (_headNode == NULL)
        return;

    int position = 1;
    StringNode *loopPtr = _headNode;
    StringNode *beforeDeletion = NULL;

    while (loopPtr != NULL && position < start) {
        if (position == start - 1)
            beforeDeletion = loopPtr;
        loopPtr = loopPtr->next;
        ++position;
    }

    while (loopPtr != NULL && position < start + count) {
        StringNode *tmp = loopPtr;
        loopPtr = loopPtr->next;
        delete tmp;
        if (position == (start + count - 1) || loopPtr == NULL)
            if (beforeDeletion != NULL)
                beforeDeletion->next = loopPtr;
            else
                _headNode = loopPtr;
        ++position;
    }
}
