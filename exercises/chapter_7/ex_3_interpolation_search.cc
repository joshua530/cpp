#include "student_record.cc"
#include <math.h>
#include <ostream>

/** merge sort for sorting student records by id */
StudentRecord *sortByStudentId(StudentRecord *items, int size)
{
    if (size < 2)
        return items;

    int midpoint = floor(size / 2);
    int sizeLeft = midpoint;
    int sizeRight = size - sizeLeft;

    StudentRecord *left = new StudentRecord[sizeLeft];
    StudentRecord *right = new StudentRecord[sizeRight];
    for (int i = 0; i < sizeLeft; ++i)
        left[i] = items[i];
    for (int i = midpoint, j = 0; i < size; ++i, ++j)
        right[j] = items[i];

    left = sortByStudentId(left, sizeLeft);
    right = sortByStudentId(right, sizeRight);

    int leftPos = 0, rightPos = 0, sortedPos = 0;

    StudentRecord *sorted = new StudentRecord[size];

    while (leftPos < sizeLeft && rightPos < sizeRight) {
        if (left[leftPos].grade() <= right[rightPos].grade()) {
            sorted[sortedPos] = left[leftPos];
            ++leftPos;
        } else {
            sorted[sortedPos] = right[rightPos];
            ++rightPos;
        }
        ++sortedPos;
    }

    while (leftPos < sizeLeft) {
        sorted[sortedPos] = left[leftPos];
        ++sortedPos;
        ++leftPos;
    }
    while (rightPos < sizeRight) {
        sorted[sortedPos] = right[rightPos];
        ++sortedPos;
        ++rightPos;
    }
    delete[] left;
    delete[] right;

    return sorted;
}

/** uses the interpolation search algorithm */
int studentIndexWithGrade(int grade, StudentRecord students[], int size)
{
    int low = 0, high = size - 1, mid;

    while (students[low].studentId() != students[high].studentId() &&
           grade >= students[low].grade() && grade <= students[high].grade()) {
        /*
         * formula is:
         * mid = low +
         * ((target-A[low])*(high-low)/(A[high]-A[low]));
         * low = lowest index
         * high = highest index
         * A = the list of items to search from
         */
        mid = low + ((grade - students[low].grade()) * (high - low) /
                     (students[high].grade() - students[low].grade()));
        int midStudentGrade = students[mid].grade();
        if (midStudentGrade == grade) {
            return mid;
        } else if (grade < midStudentGrade) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (students[mid].grade() == grade)
        return mid;
    return -1;
}

int main(int argc, char *argv[])
{
    StudentRecord r(10, 1, "one");
    StudentRecord r2(20, 2, "two");
    StudentRecord r3(30, 3, "three");
    StudentRecord r4(40, 4, "four");
    StudentRecord r5(50, 5, "five");
    StudentRecord r6(60, 6, "six");
    StudentRecord r7(70, 7, "seven");

    StudentRecord items[] = {r3, r, r5, r7, r2, r6, r4};

    StudentRecord *sorted = sortByStudentId(items, 7);

    std::cout << studentIndexWithGrade(3, sorted, 7) << "\n";
    // implement the interpolation search algorithm
    delete[] sorted;
}
