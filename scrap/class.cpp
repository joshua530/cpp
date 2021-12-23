#include <iostream>

class Sample {
public:
    Sample();
    Sample(int num);
    int doesSomething(double param);

private:
    int intData;
};

int main()
{
    Sample one;
    Sample two(3);
}
