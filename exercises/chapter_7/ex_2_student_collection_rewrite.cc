#include "student_record.cc"
#include <list>
#include <ostream>
#include <string.h>

using std::list;

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

    void addRecord(StudentRecord newStudent);
    double averageRecord();

private:
    list<StudentRecord> _studentList;
};

StudentCollection::StudentCollection()
{
}

StudentCollection::StudentCollection(const StudentCollection &original)
{
    list<StudentRecord>::const_iterator current = original._studentList.begin();
    list<StudentRecord>::const_iterator end = original._studentList.end();

    while (current != end) {
        _studentList.push_back(*current);
        ++current;
    }
}

void StudentCollection::addRecord(StudentRecord newStudent)
{
    _studentList.push_back(newStudent);
}

double StudentCollection::averageRecord()
{
    int numStudents = 0;
    double total = 0;

    for (list<StudentRecord>::iterator iter = _studentList.begin();
         iter != _studentList.end(); ++iter) {
        ++numStudents;
        total += (*iter).grade();
    }

    return total / numStudents;
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

    std::cout << c.averageRecord() << "\n";
}
