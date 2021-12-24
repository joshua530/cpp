#include "student_record_and_decorators.h"

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

//########### base student decorator #############

BaseStudentDecorator::BaseStudentDecorator(StudentInterface *student)
{
    _student = student;
}

int BaseStudentDecorator::grade()
{
    return _student->grade();
}

int BaseStudentDecorator::studentId()
{
    return _student->studentId();
}

string BaseStudentDecorator::name()
{
    return _student->name();
}

string BaseStudentDecorator::letterGrade()
{
    return _student->letterGrade();
}

void BaseStudentDecorator::setGrade(int grade)
{
    _student->setGrade(grade);
}

void BaseStudentDecorator::setStudentId(int id)
{
    _student->setStudentId(id);
}

void BaseStudentDecorator::setName(string name)
{
    _student->setName(name);
}

string BaseStudentDecorator::termPaper()
{
    return _termPaper;
}

int BaseStudentDecorator::yearOfEnrollment()
{
    return _yearOfEnrollment;
}

bool BaseStudentDecorator::isAuditing()
{
    return _isAuditing;
}

//################ end base student decorator #############

//############# TermPaperDecorator ##############
void TermPaperDecorator::setTermPaper(string paper)
{
    _termPaper = paper;
}

void TermPaperDecorator::setClassAuditStatus(bool isAuditing)
{
}
void TermPaperDecorator::setYearOfEnrollment(int year)
{
}

TermPaperDecorator::TermPaperDecorator(StudentInterface *s)
    : BaseStudentDecorator(s)
{
}
//########## end TermPaperDecorator ############

//########## YearOfEnrollment ##############
void YearOfEnrollmentDecorator::setYearOfEnrollment(int year)
{
    _yearOfEnrollment = year;
}

void YearOfEnrollmentDecorator::setTermPaper(string paper)
{
}

void YearOfEnrollmentDecorator::setClassAuditStatus(bool isAuditing)
{
}

YearOfEnrollmentDecorator::YearOfEnrollmentDecorator(StudentInterface *s)
    : BaseStudentDecorator(s)
{
}

//########## end YearOfEnrollment #############

//########## ClassAuditDecorator ##############
void ClassAuditDecorator::setClassAuditStatus(bool isAuditing)
{
    _isAuditing = isAuditing;
}

void ClassAuditDecorator::setTermPaper(string paper)
{
}
void ClassAuditDecorator::setYearOfEnrollment(int year)
{
}

ClassAuditDecorator::ClassAuditDecorator(StudentInterface *s)
    : BaseStudentDecorator(s)
{
}
//############ end ClassAuditDecorator #################
