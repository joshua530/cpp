#include "student_record.cpp"
#include <string.h>

// a pointer to a function that takes a StudentCollection and integer
// as parameters and returns a pointer to a student record
// irrelevant to this context, just put here for reference purposes
// typedef StudentRecord *(*someFunction)(StudentCollection a, int b);

// pointer to a function that takes two StudentRecord objects and
// returns a boolean indicating whether r1 should come before r2
typedef bool (*firstStudentPolicy)(StudentRecord r1, StudentRecord r2);

// the policies
bool gradeIsHigher(StudentRecord r1, StudentRecord r2)
{
    return r1.grade() > r2.grade();
}

bool studentIdIsLower(StudentRecord r1, StudentRecord r2)
{
    return r1.studentId() < r2.studentId();
}

bool nameComesFirst(StudentRecord r1, StudentRecord r2)
{
    return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

class ScIterator;

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
    void setFirstStudentPolicy(firstStudentPolicy p);
    StudentRecord firstStudent();
    ScIterator firstItemIterator();

    StudentCollection &operator=(const StudentCollection &rhs);

    friend class ScIterator;

private:
    StudentList _listHead;
    firstStudentPolicy _currentPolicy;
    void deleteList(StudentList &theList);
    StudentList copiedList(const StudentList &original);
};

class ScIterator {
public:
    ScIterator();
    ScIterator(StudentCollection::StudentNode *initial);
    void advance();
    bool pastEnd();
    StudentRecord student();

private:
    StudentCollection::StudentNode *current;
};

ScIterator::ScIterator(StudentCollection::StudentNode *initial)
{
    current = initial;
}

ScIterator StudentCollection::firstItemIterator()
{
    return ScIterator(_listHead);
}

StudentCollection::StudentCollection()
{
    _listHead = NULL;
    _currentPolicy = NULL;
}

StudentCollection::StudentCollection(const StudentCollection &original)
{
    _listHead = copiedList(original._listHead);
    _currentPolicy = NULL;
}

void StudentCollection::addRecord(StudentRecord newStudent)
{
    StudentNode *newNode = new StudentNode;
    newNode->student = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

void StudentCollection::setFirstStudentPolicy(firstStudentPolicy p)
{
    _currentPolicy = p;
}

StudentRecord StudentCollection::firstStudent()
{
    if (_listHead == NULL || _currentPolicy == NULL) {
        StudentRecord dummyRecord(-1, -1, "INVALID");
        return dummyRecord;
    }

    StudentNode *first, *current;
    first = _listHead;
    current = first->next;
    while (current != NULL) {
        bool currentShouldComeFirst =
            _currentPolicy(current->student, first->student);
        if (currentShouldComeFirst)
            first = current;
        current = current->next;
    }
    return first->student;
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

void ScIterator::advance()
{
    if (current != NULL)
        current = current->next;
}

bool ScIterator::pastEnd()
{
    return current == NULL;
}

StudentRecord ScIterator::student()
{
    if (current == NULL)
        return StudentRecord(-1, -1, "");
    return current->student;
}

int main(int argc, char *argv[])
{
    StudentRecord r(10, 1, "one");
    StudentRecord r2(20, 2, "two");
    StudentRecord r3(30, 3, "three");
    StudentRecord r4(40, 4, "four");

    StudentCollection c;
    c.addRecord(r);
    c.addRecord(r2);
    c.addRecord(r3);
    c.addRecord(r4);

    ScIterator iterator = c.firstItemIterator();
    int numRecords = 0;
    int total = 0;

    while (!iterator.pastEnd()) {
        ++numRecords;
        total += iterator.student().grade();
        iterator.advance();
    }
    double average = (double)total / numRecords;
    std::cout << average << "\n";
}
