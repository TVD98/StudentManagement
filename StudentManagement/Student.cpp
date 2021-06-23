#include "Student.h"
#include <iostream>

Student::Student(string id, string name, string date)
{
	this->id = id;
	this->name = name;
	this->dateOfBirth = date;
	pointTraining = 0;
	subsidyType = SubsidyType::NONE;
}

Student::Student()
{
	pointTraining = 0;
	subsidyType = SubsidyType::NONE;
}

void Student::setPoinTraining(int point)
{
	this->pointTraining = point;
}

void Student::setSubsidyType(SubsidyType type)
{
	this->subsidyType = type;
}

void Student::addSubject(string subjectId)
{
	Subject* subject = SubjectsSingleton::getInstance()->getSubject(subjectId);
	if (subject != nullptr)
		scoresMap[subjectId] = 0.0;
}

void Student::updateScores(string subjectId, double scores)
{
	Subject* subject = SubjectsSingleton::getInstance()->getSubject(subjectId);
	if (subject != nullptr)
		scoresMap[subjectId] = scores;
}

double Student::getAverage()
{
	// chưa đk môn học nào
	if (scoresMap.size() == 0) {
		return 0.0;
	}
		
	// có đk
	double scoresTotal = 0.0;
	int coefficientTotal = 0;
	
	map<string, double>::iterator it;
	for (it = scoresMap.begin(); it != scoresMap.end(); it++)
	{
		Subject* subject = SubjectsSingleton::getInstance()->getSubject(it->first);
		scoresTotal += it->second * subject->coefficient;
		coefficientTotal += subject->coefficient;
	}
	return scoresTotal / coefficientTotal;
}

bool Student::contains(string key)
{
	return false;
}

int Student::getSholarship()
{
	double average = getAverage();
	if (average > 9.0) {
		if (pointTraining >= 90)
			return 300000;
		return 270000;
	}
	return 0.0;
}

int Student::getSubsidy()
{
	return subsidyTypeDict.find(subsidyType)->second;
}

string Student::toString()
{
	return "Student: [id: " + id + ", name: " + name + ", average: " + to_string(Helper::roundNumberUp(getAverage())) 
		+ ", grade: " + gradeTypeDict.find(getGrade())->second + ", point training : " + to_string(pointTraining) + ", scholarship : "
		+ to_string(getSholarship()) + ", subsidy: " + to_string(getSubsidy()) + "]";
}

GradeType Student::getGrade()
{
	double average = getAverage();
	if (average >= 8.0)
		return GradeType::VERY_GOOD;
	if (average >= 6.5)
		return GradeType::GOOD;
	if (average >= 4.0)
		return GradeType::PASS;
	return GradeType::WEAK;
}

Student::~Student()
{
}
