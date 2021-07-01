#pragma once
#include "Student.h"
#include <vector>
#include "SortSystem.h"
#include "SortingFactory.h"
#include "SearchSystem.h"
#include "ExcelFormatXLS.h"

class School
{
private:
	void add(Student newStudent, int index);
	void remove(int index);
	Student createStudentFromInfo(string info);
public:
	vector<Student> studentList;
	SortingType sortingType;

	School();
	void addStudent(Student student);
	void sort(SortingType type);
	void addStudentsFromExcelFile(string fileName);
	int removeStudentsByKey(string key);
	vector<Student> searchStudentsByKey(string key);
	string toString();
	~School();
};

