#include "student_record.cc"
#include <stdlib.h>
#include <string.h>

class StudentCollection {
private:
    struct StudentNode {
        StudentRecord student;
        StudentNode *next;
    };
    typedef StudentNode *StudentList;
    typedef bool (StudentCollection::*rankingFunc)(StudentRecord r1,
                                                   StudentRecord r2);

public:
    enum PolicyType { GRADE, NAME, STUDENT_ID };

    StudentCollection();
    StudentCollection(const StudentCollection &original);
    ~StudentCollection();

    void addRecord(StudentRecord newStudent);
    StudentRecord recordWithNumber(int studentId);
    void removeRecord(int studentId);
    StudentRecord firstStudent();
    void setStudentPolicy(PolicyType criteria);

    StudentCollection &operator=(const StudentCollection &rhs);

private:
    StudentList _listHead;
    rankingFunc _comparisonFunc;
    void deleteList(StudentList &theList);
    StudentList copiedList(const StudentList &original);

    bool higherGrade(StudentRecord r1, StudentRecord r2);
    bool lowerId(StudentRecord r1, StudentRecord r2);
    bool nameComesFirst(StudentRecord r1, StudentRecord r2);
};

bool StudentCollection::higherGrade(StudentRecord r1, StudentRecord r2)
{
    return r1.grade() > r2.grade();
}

bool StudentCollection::lowerId(StudentRecord r1, StudentRecord r2)
{
    if (r1.studentId() == -1)
        return false;
    if (r2.studentId() == -1 && r1.studentId() != -1)
        return true;
    return r1.studentId() < r2.studentId();
}

bool StudentCollection::nameComesFirst(StudentRecord r1, StudentRecord r2)
{
    if (r1.name() == "")
        return false;
    if (r2.name() == "" && r1.name() != "")
        return true;
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 1;
}

void StudentCollection::setStudentPolicy(PolicyType p)
{
    rankingFunc policy;
    switch (p) {
        case GRADE:
            policy = &StudentCollection::higherGrade;
            break;
        case NAME:
            policy = &StudentCollection::nameComesFirst;
            break;
        case STUDENT_ID:
            policy = &StudentCollection::lowerId;
            break;
        default:
            _comparisonFunc = NULL;
    }
    _comparisonFunc = policy;
}

StudentRecord StudentCollection::firstStudent()
{
    if (_listHead == NULL || _comparisonFunc == NULL) {
        StudentRecord dummy(-1, -1, "");
        return dummy;
    }

    StudentNode *first = _listHead;
    StudentNode *current = first->next;

    while (current != NULL) {
        bool currentShouldComeFirst =
            (this->*_comparisonFunc)(current->student, first->student);
        if (currentShouldComeFirst)
            first = current;
        current = current->next;
    }
    return first->student;
}

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

int main()
{
    StudentRecord r(10, 1, "one");
    StudentRecord r2(-1, -1, "");
    StudentRecord r3(20, 2, "two");
    StudentRecord r4(-1, -1, "");
    StudentRecord r5(30, 3, "three");
    StudentRecord r6(40, 4, "four");
    StudentRecord r7(-1, -1, "");

    StudentCollection c;
    c.addRecord(r);
    c.addRecord(r2);
    c.addRecord(r3);
    c.addRecord(r4);
    c.addRecord(r5);
    c.addRecord(r6);
    c.addRecord(r7);

    c.setStudentPolicy(StudentCollection::STUDENT_ID);
    StudentRecord s = c.firstStudent();
    std::cout << "";
}
