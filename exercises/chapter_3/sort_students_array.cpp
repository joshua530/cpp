#include <cmath>
#include <iostream>

using namespace std;

struct student {
    string name;
    int studentId;
    int grade;
};

void sort(struct student[], int);

int main(int argc, char const *argv[])
{
    const int TOTAL_STUDENTS = 10;
    student students[TOTAL_STUDENTS] = {
        {"Martha", 1001, 81}, {"Martin", 1002, 88}, {"Stella", 1003, 90},
        {"John", 1004, 79},   {"Mike", 1005, 77},   {"Jane", 1006, 81},
        {"Festus", 1007, 88}, {"Anne", 1008, 92},   {"Stacy", 1009, 89},
        {"Robert", 1010, 90},
    };

    sort(students, TOTAL_STUDENTS);
    cout << "";
}

// TODO ensure sort works
// terminate called after throwing an instance of 'std::bad_alloc'
//   what():  std::bad_alloc
/**
 * sort student array using merge sort
 */
void sort(struct student toSort[], int length)
{
    if (length <= 1)
        return;

    int midpoint = floor(length / 2);
    student left[midpoint];
    student right[length - midpoint];

    // split
    for (int i = 0; i < midpoint; ++i) left[i] = toSort[i];
    for (int i = 0, j = midpoint; j < length; ++i, ++j) right[i] = toSort[j];

    int lenLeft = midpoint;
    int lenRight = length - lenLeft;
    sort(left, lenLeft);
    sort(right, lenRight);

    struct student sorted[length];

    int leftPosition = 0;
    int rightPosition = 0;

    // sort the items
    int sortedArrayPos = 0;
    for (; sortedArrayPos < lenLeft || sortedArrayPos < lenRight;
         ++sortedArrayPos) {
        if (left[sortedArrayPos].grade < right[sortedArrayPos].grade) {
            sorted[sortedArrayPos] = left[leftPosition];
            ++leftPosition;
        } else {
            sorted[sortedArrayPos] = right[rightPosition];
            ++rightPosition;
        }
    }

    // clear any remaining items in the arrays
    for (int j = leftPosition; j < lenLeft; ++j) {
        sorted[sortedArrayPos] = left[j];
        ++sortedArrayPos;
    }
    for (int j = rightPosition; j < lenRight; ++j) {
        sorted[sortedArrayPos] = right[j];
        ++sortedArrayPos;
    }

    // for (int i = 0; i < length; ++i) toSort[i] = sorted[i];
    toSort = sorted;
    // delete[] left;
    // delete[] right;
    // delete[] sorted;
}
