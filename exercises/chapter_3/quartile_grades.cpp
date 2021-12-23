#include <cmath>
#include <iostream>

using namespace std;

struct student {
    string name;
    int studentId;
    int grade;
};

void sortByGrade(struct student students[], int studentCount);
int compareStudents(const void *a, const void *b);
int getQuartile(int quartileCount, int totalCount);

int main(int argc, char const *argv[])
{
    int TOTAL_STUDENTS = 10;
    student students[TOTAL_STUDENTS] = {
        {"Martha", 1001, 81}, {"Martin", 1002, 88}, {"Stella", 1003, 90},
        {"John", 1004, 79},   {"Mike", 1005, 77},   {"Jane", 1006, 81},
        {"Festus", 1007, 88}, {"Anne", 1008, 92},   {"Stacy", 1009, 89},
        {"Robert", 1010, 90},
    };

    sortByGrade(students, TOTAL_STUDENTS);

    int firstQuartile = getQuartile(1, TOTAL_STUDENTS);
    int secondQuartile = getQuartile(2, TOTAL_STUDENTS);
    int thirdQuartile = getQuartile(2, TOTAL_STUDENTS);

    // TODO sort

    cout << "To score as well as 25% of the students, you need to score at "
            "least "
         << students[firstQuartile - 1].grade << "\n";
    cout << "To score as well as 50% of the students, you need to score at "
            "least "
         << students[secondQuartile - 1].grade << "\n";
    cout << "To score as well as 75% of the students, you need to score at "
            "least "
         << students[thirdQuartile - 1].grade << "\n";

    return 0;
}

void sortByGrade(struct student students[], int studentCount)
{
    int studentSize = sizeof(students[0]);
    qsort(students, studentCount, studentSize, compareStudents);
}

int compareStudents(const void *a, const void *b)
{
    student *studentA = (student *)a;
    student *studentB = (student *)b;
    return studentA->grade - studentB->grade;
}

int getQuartile(int quartileCount, int totalCount)
{
    if (quartileCount < 1 || quartileCount > 3) {
        cout << "Invalid quartile\n";
        exit(1);
    }

    int quarter = floor(totalCount / 4);

    return quarter * quartileCount;
}

void sortStudents(struct student sorted[], struct student students[],
                  int numStudents)
{
    int midpoint = floor(numStudents / 2);
}

void mergeSort(struct student left[], struct student right[])
{
}
