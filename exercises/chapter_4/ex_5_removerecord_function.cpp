#include <iostream>

struct student {
    int grade;
    int studentId;
    student *next;
};

typedef student *studentList;

/**
 * removes student with given id if the student exists
 *
 * @param students the list to delete a student from
 * @param studentId id that the student we should delete has
 */
void removeRecord(studentList &students, int studentId)
{
    student *iterator = students;
    student *beforeToRemove = NULL;
    student *toRemove = NULL;

    while (iterator != NULL) {
        if (iterator->studentId == studentId) {
            if (beforeToRemove == NULL) // student to remove is first in list
                students = iterator->next;
            else
                beforeToRemove->next = iterator->next;
            toRemove = iterator;
            toRemove->next = NULL;
            break;
        } else {
            beforeToRemove = iterator;
        }
        iterator = iterator->next;
    }

    if (toRemove != NULL)
        delete toRemove;
}

int main(int argc, char *argv[])
{
    student *a = new student;
    a->studentId = 1;
    a->grade = 80;
    student *b = new student;
    a->next = b;
    b->studentId = 2;
    b->grade = 81;
    student *c = new student;
    b->next = c;
    c->studentId = 3;
    c->grade = 82;
    student *d = new student;
    c->next = d;
    d->studentId = 4;
    d->grade = 83;
    d->next = NULL;

    studentList students = a;
    a = b = c = d = NULL;
    removeRecord(students, 3);
    std::cout << "";
    removeRecord(students, 1);
    std::cout << "";
    studentList std = NULL;
    studentList s;
    removeRecord(std, 1);
    removeRecord(s, 1);
    std::cout << "Program ran!\n";
}
