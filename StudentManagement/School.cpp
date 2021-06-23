#include "School.h"

School::School()
{
	sortingType = SortingType::AVERAGE;
}

void School::add(Student newStudent, int index)
{
	studentList.insert(studentList.begin() + index, newStudent);
}

void School::addStudent(Student student)
{
	// tim vi tri de them phan tu moi
	ISorting* sorting = SortingFactory::sortingFromType(sortingType);
	int indexToAdd = SearchSystem::search(studentList, 0, studentList.size() - 1, student, sorting);
	this->add(student, indexToAdd);
}

void School::sort(SortingType type)
{
	ISorting* sorting = SortingFactory::sortingFromType(type);
	SortSystem::selectionSort(studentList, sorting, OrderType::ASC);
	this->sortingType = type;
}

string School::toString()
{
	string result = "";
	for (int i = 0; i < studentList.size(); i++) {
		result += "[stt: " + to_string(i) + "] " + studentList[i].toString() + "\n";
	}
	return result;
}

School::~School()
{
}
