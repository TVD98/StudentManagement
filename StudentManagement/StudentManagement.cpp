
#include "Student.h"
#include <iostream>
#include "SubjectsSingleton.h"
#include "School.h"

int main()
{
    Subject* subject1 = new Subject("1111", "CSDL", 3);
    Subject* subject2 = new Subject("1112", "XSTK", 2);
    Subject* subject3 = new Subject("1113", "DLCM", 3);

    SubjectsSingleton::getInstance()->addSubject(subject1);
    SubjectsSingleton::getInstance()->addSubject(subject2);
    SubjectsSingleton::getInstance()->addSubject(subject3);

    Student student1 = Student("1", "TVD", "6-7-1998");
    student1.updateScores("1112", 8.3);
    student1.updateScores("1113", 7.7);
    student1.setPoinTraining(80);

    Student student2 = Student("3", "Duong", "28-8-1998");
    student2.updateScores("1113", 10.0);
    student2.setPoinTraining(90);
    student2.setSubsidyType(SubsidyType::POOR_HOUSEHOLD);

    Student student3 = Student("2", "Hien", "12-11-2001");
    student3.updateScores("1112", 8.3);
    student3.setPoinTraining(95);

    School school = School();
    school.addStudent(student1);
    school.addStudent(student2);
    school.addStudent(student3);

    cout << school.toString() << "\n";
}

