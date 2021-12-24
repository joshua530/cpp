#include <string>

using std::string;

#ifndef _STUDENT_RECORD_N_DECS_
#define _STUDENT_RECORD_N_DECS_

class StudentInterface {
public:
    virtual int grade() = 0;
    virtual int studentId() = 0;
    virtual string name() = 0;
    virtual string letterGrade() = 0;

    virtual void setGrade(int newGrade) = 0;
    virtual void setStudentId(int newId) = 0;
    virtual void setName(string newName) = 0;
};

class StudentRecord : public StudentInterface {
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

class BaseStudentDecorator : public StudentInterface {
public:
    BaseStudentDecorator(StudentInterface *student);
    int grade();
    int studentId();
    string name();
    string letterGrade();

    void setGrade(int newGrade);
    void setStudentId(int newId);
    void setName(string newName);

    string termPaper();
    int yearOfEnrollment();
    bool isAuditing();

    virtual void setTermPaper(string paper) = 0;
    virtual void setYearOfEnrollment(int year) = 0;
    virtual void setClassAuditStatus(bool isAuditing) = 0;

protected:
    string _termPaper;
    int _yearOfEnrollment;
    bool _isAuditing;

private:
    StudentInterface *_student;
};

class TermPaperDecorator : public BaseStudentDecorator {
public:
    TermPaperDecorator(StudentInterface *s);
    void setTermPaper(string paper);
    void setYearOfEnrollment(int year);
    void setClassAuditStatus(bool isAuditing);
};

class YearOfEnrollmentDecorator : public BaseStudentDecorator {
public:
    YearOfEnrollmentDecorator(StudentInterface *s);
    void setYearOfEnrollment(int year);
    void setTermPaper(string paper);
    void setClassAuditStatus(bool isAuditing);
};

class ClassAuditDecorator : public BaseStudentDecorator {
public:
    ClassAuditDecorator(StudentInterface *s);
    void setClassAuditStatus(bool isAuditing);
    void setTermPaper(string paper);
    void setYearOfEnrollment(int year);
};

#endif
