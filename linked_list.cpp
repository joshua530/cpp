#include <iostream>

struct listNode {
    int studentNum;
    int grade;
    listNode *next;
};

typedef listNode *studentList;

using std::cout;

void addStudent(studentList &students, int studentNum, int grade)
{
    listNode *s = new listNode;
    s->studentNum = studentNum;
    s->grade = grade;
    s->next = students;

    students = s;
}

double averageRecord(const studentList &students)
{
    if (students == NULL)
        return 0;

    double totalMarks = 0.0;
    int studentCount = 0;

    listNode *loopPtr = students;
    while (loopPtr != NULL) {
        totalMarks += loopPtr->grade;
        loopPtr = loopPtr->next;
        ++studentCount;
    }

    double average = totalMarks / studentCount;
    return average;
}

int main(int argc, char *argv[])
{
    studentList students;
    listNode *s = new listNode;
    s->grade = 70;
    s->studentNum = 1000;
    listNode *s2 = new listNode;
    s2->grade = 80;
    s2->studentNum = 1001;
    listNode *s3 = new listNode;
    s3->grade = 91;
    s3->studentNum = 1002;
    s->next = s2;
    s2->next = s3;

    students = s;
    s = s2 = s3 = NULL;

    double average = averageRecord(students);
    studentList l;
    cout << averageRecord(l) << "\n";

    if (average == (91.0 + 80 + 70) / 3)
        cout << "Passed!\n";
    else
        cout << "Failed!\n";
}
