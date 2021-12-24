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

/*
 * classes that have template definitions and header files(defined in header,
 * implemented in source file)
 * --------------------------------------------------------------------------------------------------------
 * -> define dummy function in implementation.cpp
 * -> include implementation.cpp in file that uses the class(contains function
 * or class that uses the class)
 * -> include implementation.cpp in header file and remove implementation.cpp
 * from project but not from folder
 */
