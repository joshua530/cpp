#include <iostream>

using std::cout;
using std::string;

struct student {
    int grade;
    int studentID;
    string name;
};

int sortByGrade(const void *, const void *);
void printArray(student[], int);

int main(int argc, char *argv[])
{
    const int NUM_STUDENTS = 4;
    student students[NUM_STUDENTS] = {{81, 1001, "Martha"},
                                      {88, 1002, "Martin"},
                                      {90, 1003, "Stella"},
                                      {79, 1004, "John"}};

    qsort(students, NUM_STUDENTS, sizeof(students[0]), sortByGrade);
    printArray(students, NUM_STUDENTS);
}

int sortByGrade(const void *a, const void *b)
{
    student *studentA = (student *)a;
    student *studentB = (student *)b;
    int diff = studentA->grade - studentB->grade;

    if (diff < 0)
        return -1;
    else if (diff > 0)
        return 1;
    return diff;
}

void printArray(student toPrint[], int size)
{
    for (int i = 0; i < size; ++i) {
        student s = toPrint[i];
        cout << s.name << " - " << s.studentID << " - " << s.grade << "\n";
    }
}
