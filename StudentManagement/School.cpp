#include "School.h"

School::School()
{
	sortingType = SortingType::AVERAGE;
}

void School::add(Student newStudent, int index)
{
	studentList.insert(studentList.begin() + index, newStudent);
}

void School::remove(int index) {
	studentList.erase(studentList.begin() + index);
}

Student School::createStudentFromInfo(string info)
{
	vector<string> elements = Helper::split(info, "\t");
	Student student = Student(elements[0], elements[1], elements[2]);
	student.setPoinTraining(atoi(elements[4].c_str()));
	student.setSubsidyType(stringToSubsidyTypeDict.find(elements[5])->second);

	vector<string> scoresList = Helper::split(elements[3], ";");
	for (string temp : scoresList) {
		vector<string> scoreSubjectMap = Helper::split(temp, ":");
		student.updateScores(scoreSubjectMap[0], atoi(scoreSubjectMap[1].c_str()));
	}
	return student;
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
	SortSystem::mergeSort(studentList, 0, studentList.size() - 1, sorting, OrderType::ASC);
	this->sortingType = type;
}

void School::addStudentsFromExcelFile(string fileName)
{
	ExcelFormatXLS excel = ExcelFormatXLS();
	vector<string> infoList = excel.readFile(fileName);
	for (int i = 1; i < infoList.size(); i++) {
		Student student = createStudentFromInfo(infoList[i]);
		addStudent(student);
	}
}

int School::removeStudentsByKey(string key)
{
	vector<int> studentIndexs = SearchSystem::search(studentList, key);
	for (int i = 0; i < studentIndexs.size(); i++) {
		remove(studentIndexs[i] - i);
	}
	return studentIndexs.size();
}

vector<Student> School::searchStudentsByKey(string key)
{
	vector<int> studentIndexs = SearchSystem::search(studentList, key);
	vector<Student> students;
	for (int index : studentIndexs) {
		students.push_back(studentList[index]);
	}
	return students;
}

string School::toString()
{
	string result = "DS Sinh vien duoc sap xep tang dan theo " + sortingTypeToStringDict.find(sortingType)->second + ":\n";
	for (int i = 0; i < studentList.size(); i++) {
		result += "[stt: " + to_string(i) + "] " + studentList[i].toString() + "\n";
	}
	return result;
}

School::~School()
{
}
