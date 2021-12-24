#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

// TODO how to store and retrieve arbitrary values

template <typename T>
class ValueHolder {
public:
    void setValue(T value);
    T getValue();

private:
    T _value;
};

class StudentRecord {
public:
    void addExtraField(string key, string value);
    void addExtraField(string key, int value);
    void addExtraField(string key, double value);
    void addExtraField(string key, char value);
    auto retrieveField(string key);

private:
    map<string, int> intMap;
    map<string, double> doubleMap;
    map<string, string> strMap;
    map<string, char> charMap;
};
