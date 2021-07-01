#pragma once
#include "Student.h"

enum SortingType
{
	AVERAGE, ID
};

static map<SortingType, string> sortingTypeToStringDict = { {SortingType::AVERAGE, "Diem trung binh"}, {SortingType::ID, "MSSV"} };

static map<int, SortingType> intToSortingTypeDict = { {1, SortingType::ID}, {2, SortingType::AVERAGE} };

class ISorting
{
public:
	virtual int compare(Student, Student) = 0;
};