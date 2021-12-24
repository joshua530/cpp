#include "student_record_and_decorators.cc"
#include "student_record_and_decorators.h"
#include <iostream>

using std::cout;

int main(int argc, const char *argv[])
{
    // uses the decorator pattern to add more properties to a student record

    StudentRecord withPaper(60, 2, "Jane");
    StudentRecord withAudit(70, 3, "Joan");
    StudentRecord withYear(80, 4, "Julie");
    StudentRecord withPaperYearNAudit(90, 5, "James");

    StudentInterface *withPaperP = (StudentInterface *)&withPaper;
    StudentInterface *withAuditP = (StudentInterface *)&withAudit;
    StudentInterface *withYearP = (StudentInterface *)&withYear;
    StudentInterface *withPaperYearNAuditP =
        (StudentInterface *)&withPaperYearNAudit;

    TermPaperDecorator p(withPaperP);
    p.setTermPaper("Math");
    ClassAuditDecorator a(withAuditP);
    a.setClassAuditStatus(true);
    YearOfEnrollmentDecorator y(withYearP);
    y.setYearOfEnrollment(2019);

    cout << p.termPaper() << "\n";
    cout << p.grade() << "\n";
    cout << p.letterGrade() << "\n\n";

    cout << a.isAuditing() << "\n";
    cout << a.name() << "\n";
    cout << a.studentId() << "\n";
    a.setStudentId(123);
    cout << a.studentId() << "\n\n";

    cout << y.yearOfEnrollment() << "\n";
    cout << y.name() << "\n";
    y.setName("Jules");
    cout << y.name() << "\n";

    BaseStudentDecorator *pya = new TermPaperDecorator(withPaperYearNAuditP);
    pya->setTermPaper("English");
    pya = new YearOfEnrollmentDecorator(pya);
    pya->setYearOfEnrollment(2019);
    pya = new ClassAuditDecorator(pya);
    pya->setClassAuditStatus(false);

    // cout << ((TermPaperDecorator *)pya)->termPaper() << "\n";
    // cout << ((YearOfEnrollmentDecorator *)pya)->yearOfEnrollment() << "\n";
    // cout << ((ClassAuditDecorator *)pya)->isAuditing() << "\n";
    // TODO from here downwards decorator pattern
    cout << pya->termPaper() << "\n";
    cout << pya->yearOfEnrollment() << "\n";
    cout << pya->isAuditing() << "\n";
}
