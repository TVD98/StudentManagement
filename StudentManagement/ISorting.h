#pragma once
#include "Student.h"

enum SortingType
{
	AVERAGE, ID
};

class ISorting
{
public:
	virtual int compare(Student, Student) = 0;
};