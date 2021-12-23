#include <cmath>
#include <iostream>

using std::cout;
using std::floor;

int sortSales(const void *, const void *);
double findMedian(const int[], int);

int main(int argc, char const *argv[])
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766,
         2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}};

    qsort(sales[0], NUM_MONTHS, sizeof(int), sortSales);
    qsort(sales[1], NUM_MONTHS, sizeof(int), sortSales);
    qsort(sales[2], NUM_MONTHS, sizeof(int), sortSales);

    double medians[NUM_AGENTS];
    for (int i = 0; i < NUM_AGENTS; ++i)
        medians[i] = findMedian(sales[i], NUM_MONTHS);

    // TODO munmap_chunk(): invalid pointer(build) on build
    cout << "";
    return 0;
}

int sortSales(const void *a, const void *b)
{
    int *left = (int *)a;
    int *right = (int *)b;

    return *left - *right;
}

double findMedian(const int data[], int size)
{
    double median;
    int midpoint = floor(size / 2);

    if (size % 2 == 0)
        median = (data[midpoint] + data[midpoint - 1]) / 2;
    else
        median = data[midpoint];
    return median;
}
