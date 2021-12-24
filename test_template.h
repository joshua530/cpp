#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_

template <typename T>
class TestTemp {
public:
    TestTemp();
    void setValue(T obj);
    T getValue();

private:
    T _obj;
};

#endif

#include "test_template.cpp"
