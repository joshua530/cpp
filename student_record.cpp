#include <iostream>

using std::string;

class StudentRecord {
public:
    StudentRecord();
    StudentRecord(int newGrade, int newId, string newName);

    int grade();
    int studentId();
    string name();

    void setGrade(int newGrade);
    void setStudentId(int newId);
    void setName(string newName);

    string letterGrade();

private:
    int _grade;
    int _studentId;
    string _name;

    bool isValidGrade(int grade);
};

StudentRecord::StudentRecord(int newGrade, int newId, string newName)
{
    setGrade(newGrade);
    setStudentId(newId);
    setName(newName);
}

StudentRecord::StudentRecord()
{
    setGrade(-1);
    setStudentId(-1);
    setName("");
}

int StudentRecord::grade()
{
    return _grade;
}

int StudentRecord::studentId()
{
    return _studentId;
}

string StudentRecord::name()
{
    return _name;
}

void StudentRecord::setGrade(int newGrade)
{
    if (isValidGrade(newGrade))
        _grade = newGrade;
    else
        _grade = -1;
}

void StudentRecord::setStudentId(int newId)
{
    _studentId = newId;
}

void StudentRecord::setName(string newName)
{
    _name = newName;
}

string StudentRecord::letterGrade()
{
    if (!isValidGrade(_grade))
        return "ERROR";

    const int NUM_CATEGORIES = 11;
    const string LETTER_GRADES[] = {"F",  "D", "D+", "C-", "C", "C+",
                                    "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0,  60, 67, 70, 73, 77,
                                      80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUM_CATEGORIES && _grade >= LOWEST_GRADE_SCORE[category])
        ++category;
    return LETTER_GRADES[category - 1];
}

bool StudentRecord::isValidGrade(int grade)
{
    return ((grade >= 0) && (grade <= 100));
}
