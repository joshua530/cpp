#include <iostream>

using std::string;

class StudentRecord {
public:
    StudentRecord();
    StudentRecord(int newGrade, int newId, string newName);

    int grade();
    int studentId();
    int name();

    void setGrade(int newGrade);
    void setStudentId(int newId);
    void setName(string newName);

    string letterGrade();

private:
    int _grade;
    int _studentId;
    string _name;
};
