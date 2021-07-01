
#include "Student.h"
#include <iostream>
#include "SubjectsSingleton.h"
#include "School.h"
#include "UIClient.h"

int main()
{
	Subject* subject1 = new Subject("1111", "CSDL", 3);
	Subject* subject2 = new Subject("1112", "XSTK", 2);
	Subject* subject3 = new Subject("1113", "DLCM", 3);

	SubjectsSingleton::getInstance()->addSubject(subject1);
	SubjectsSingleton::getInstance()->addSubject(subject2);
	SubjectsSingleton::getInstance()->addSubject(subject3);

	School school = School();
	school.addStudentsFromExcelFile("DS Sinh Vien.xls");

	cout << school.toString() << "\n";

	int selection = 0;
	do
	{
		selection = UIClient::mainMenu();
		switch (selection)
		{
		case 1:
		{
			SortingType sorting = UIClient::enteringSortingType();
			school.sort(sorting);
			cout << school.toString() << "\n";
			break;
		}
		case 2:
		{
			Student student = UIClient::enteringStudent();
			school.addStudent(student);
			cout << school.toString() << "\n";
			break;
		}
		case 3:
		{
			string key = UIClient::enteringString("Nhap tu khoa");
			int count = school.removeStudentsByKey(key);
			cout << "Da xoa " << count << " sinh vien theo tu khoa '" << key << "'\n";
			cout << school.toString() << "\n";
			break;
		}
		case 4:
		{
			string key = UIClient::enteringString("Nhap tu khoa");
			vector<Student> students = school.searchStudentsByKey(key);
			cout << "Tim thay " << students.size() << " sinh vien theo tu khoa '" << key << "'\n";
			for (Student student : students) {
				cout << student.toString() << endl;
			}
			break;
		}
		}
	} while (selection != 5);
}

