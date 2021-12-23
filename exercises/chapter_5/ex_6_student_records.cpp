#include <iostream>

class StudentRecords {
public:
    struct Student {
        int grade;
        int studentId;
        Student *next;
    };
    typedef Student *StudentList;

    StudentRecords();
    StudentRecords(StudentList list);
    StudentRecords(const StudentRecords &records);
    ~StudentRecords();
    void addRecord(int grade, int studentId);
    double averageRecord();
    StudentRecords recordsWithinRange(int start, int end);

    StudentRecords &operator=(const StudentRecords &rhs);

private:
    StudentList _headNode;
    StudentList copyOfList(StudentList list);
    void deleteRecords();
    bool numWithinRange(int num, int start, int end);
};

StudentRecords::StudentRecords()
{
    _headNode = NULL;
}

StudentRecords::StudentList StudentRecords::copyOfList(StudentList list)
{
    // create a new list
    StudentList newList = NULL;
    Student *newListPtr, *toBeCopiedPtr = list;

    // copy all students in the passed in student list into the new list
    while (toBeCopiedPtr != NULL) {
        Student *s = new Student;
        s->grade = toBeCopiedPtr->grade;
        s->studentId = toBeCopiedPtr->studentId;
        s->next = NULL;

        if (newList == NULL) {
            newList = newListPtr = s;
        } else {
            newListPtr->next = s;
            newListPtr = newListPtr->next;
        }
        toBeCopiedPtr = toBeCopiedPtr->next;
    }
    return newList;
}

StudentRecords::StudentRecords(StudentList list)
{
    StudentList newList = copyOfList(list);
    _headNode = newList;
}

StudentRecords::StudentRecords(const StudentRecords &records)
{
    StudentList newList = copyOfList(records._headNode);
    _headNode = newList;
}

void StudentRecords::deleteRecords()
{
    Student *currentNode = _headNode;
    while (currentNode != NULL) {
        Student *tmp = currentNode;
        currentNode = currentNode->next;
        delete tmp;
    }
}

StudentRecords::~StudentRecords()
{
    deleteRecords();
}

void StudentRecords::addRecord(int grade, int studentId)
{
    Student *newStudent = new Student;
    newStudent->grade = grade;
    newStudent->studentId = studentId;
    newStudent->next = NULL;
    newStudent->next = _headNode;
    _headNode = newStudent;
}

double StudentRecords::averageRecord()
{
    double total = 0;
    int count = 1;

    Student *loopPtr = _headNode;
    while (loopPtr != NULL) {
        total += loopPtr->grade;
        ++count;
        loopPtr = loopPtr->next;
    }

    return total / count;
}

StudentRecords &StudentRecords::operator=(const StudentRecords &rhs)
{
    if (this != &rhs) {
        StudentList newList = copyOfList(rhs._headNode);
        deleteRecords();
        _headNode = newList;
    }
    return *this;
}

StudentRecords StudentRecords::recordsWithinRange(int start, int end)
{
    StudentList newList = NULL;
    Student *loopPtr = _headNode;
    Student *newListPtr;

    while (loopPtr != NULL) {
        if (numWithinRange(loopPtr->grade, start, end)) {
            Student *newStudent = new Student;
            newStudent->grade = loopPtr->grade;
            newStudent->studentId = loopPtr->studentId;
            newStudent->next = NULL;

            if (newList == NULL) {
                newList = newListPtr = newStudent;
            } else {
                newListPtr->next = newStudent;
                newListPtr = newListPtr->next;
            }
        }
        loopPtr = loopPtr->next;
    }

    StudentRecords newRecords(newList);
    return newRecords;
}

bool StudentRecords::numWithinRange(int num, int start, int end)
{
    return (num >= start) && (num <= end);
}
