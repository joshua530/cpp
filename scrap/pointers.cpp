#include <iostream>

using std::cout;

void doSomething(int, int *);

int main(int argc, char const *argv[])
{
    /*
     * Pointers in C++ are indicated with an asterisk ( * ). Depending on the
     * context, the asterisk indicates either that a pointer is being declared
     * or that we mean the pointed-to memory, not the pointer itself.
     */

    // use of * to instantiate a new pointer
    // b will remain an integer since the * is bound
    // to the variable name. Not the variable type
    int *a, b, *c;
    cout << typeid(a).name() << "\n";
    cout << typeid(b).name() << "\n";

    int d = 3;
    a = &d;
    c = a;

    // dynamic memory allocation
    int *e = new int;

    // use of * to dereference ie to access the memory being referred to by the
    // pointer
    *e = 3;  // store three at the memory address pointed to by e
    int f = *e;
    cout << f << "\n";

    // deallocate memory allocated with new once it is no longer needed...
    delete e;

    // more on pointers
    int one = 1, two = 2;
    doSomething(one, &two);
    cout << one << "\n";
    cout << two << "\n";
}

/**
 * shared memory thanks to reference parameters(pointers in disguise)
 *
 * @param foo the reference parameter. If the reference parameter is preceded by
 * const, it cannot be changed
 * @param bar This reference parameter will not be changed. Instead of copying
 * the whole parameter that is passed in, a pointer to the parameter is copied
 * so that the memory address of the passed in variable is the same as the one
 * used by the function being called
 */
void referenceParameters(int &foo, const int &bar)
{
    foo = 5;
}

void doSomething(int a, int *b)
{
    a = 2;
    *b = 3;
}
