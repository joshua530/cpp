#include "student_record.cpp"
#include <iostream>

class StudentCollection {
private:
    struct StudentNode {
        StudentRecord student;
        StudentNode *next;
    };
    typedef StudentNode *StudentList;

public:
    StudentCollection();
    StudentCollection(const StudentCollection &original);
    ~StudentCollection();

    void addRecord(StudentRecord newStudent);
    StudentRecord recordWithNumber(int studentId);
    void removeRecord(int studentId);

    StudentCollection &operator=(const StudentCollection &rhs);

private:
    StudentList _listHead;
    void deleteList(StudentList &theList);
    StudentList copiedList(const StudentList &original);
};

StudentCollection::StudentCollection()
{
    _listHead = NULL;
}

StudentCollection::StudentCollection(const StudentCollection &original)
{
    _listHead = copiedList(original._listHead);
}

void StudentCollection::addRecord(StudentRecord newStudent)
{
    StudentNode *newNode = new StudentNode;
    newNode->student = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

StudentRecord StudentCollection::recordWithNumber(int studentId)
{
    StudentNode *loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->student.studentId() != studentId)
        loopPtr = loopPtr->next;

    if (loopPtr == NULL) {
        StudentRecord sr(-1, -1, "");
        return sr;
    }

    return loopPtr->student;
}

void StudentCollection::removeRecord(int studentId)
{
    StudentNode *beforeDeletion = NULL;
    StudentNode *loopPtr = _listHead;

    while (loopPtr != NULL && loopPtr->student.studentId() != studentId) {
        beforeDeletion = loopPtr;
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL)
        return;

    // student to be deleted is the first in the list
    if (beforeDeletion == NULL)
        _listHead = loopPtr->next;
    else
        beforeDeletion->next = loopPtr->next;

    delete loopPtr;
}

/**
 * Deletes all students in the student list
 */
void StudentCollection::deleteList(StudentList &theList)
{
    StudentNode *loopPtr = theList;
    StudentNode *tmpPlaceholder = NULL;
    while (loopPtr != NULL) {
        tmpPlaceholder = loopPtr;
        loopPtr = loopPtr->next;
        delete tmpPlaceholder;
    }
}

StudentCollection::~StudentCollection()
{
    deleteList(_listHead);
}

StudentCollection::StudentList
StudentCollection::copiedList(const StudentList &original)
{
    if (original == NULL)
        return NULL;

    StudentNode *originalListPos = original;

    StudentNode *newStudent = new StudentNode;
    newStudent->student = originalListPos->student;
    newStudent->next = NULL;

    StudentList newList = newStudent;
    StudentNode *newListPos = newStudent;
    originalListPos = originalListPos->next;

    while (originalListPos != NULL) {
        newStudent = new StudentNode;
        newStudent->student = originalListPos->student;
        newStudent->next = NULL;

        newListPos->next = newStudent;
        newListPos = newStudent;
        originalListPos = originalListPos->next;
    }

    return newList;
}

/**
 * operator method format
 */
StudentCollection &StudentCollection::operator=(const StudentCollection &rhs)
{
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = rhs._listHead;
    }
    return *this;
}
