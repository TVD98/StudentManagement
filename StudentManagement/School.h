#pragma once
#include "Student.h"
#include <vector>
#include "SortSystem.h"
#include "SortingFactory.h"
#include "SearchSystem.h"

class School
{
private:
	void add(Student newStudent, int index);
public:
	vector<Student> studentList;
	SortingType sortingType;

	School();
	void addStudent(Student student);
	void sort(SortingType type);
	string toString();
	~School();
};

