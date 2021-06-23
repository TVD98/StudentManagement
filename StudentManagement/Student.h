#pragma once
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include "SubjectsSingleton.h"
#include "Helper.h"
using namespace std;

enum SubsidyType
{
	NONE, MARTYRS, POOR_HOUSEHOLD
};

enum GradeType
{
	VERY_GOOD, GOOD, PASS, WEAK
};

static const map<SubsidyType, int> subsidyTypeDict = { {SubsidyType::NONE, 0}, {SubsidyType::MARTYRS, 200000},
	{SubsidyType::POOR_HOUSEHOLD, 180000} };

static const map<GradeType, string> gradeTypeDict = { {GradeType::VERY_GOOD, "Gioi"}, {GradeType::GOOD, "Kha"},
	{GradeType::PASS, "Trung binh"}, {GradeType::VERY_GOOD, "Yeu"} };

class Student
{
public:
	string id;
	string name;
	string dateOfBirth;
	map<string, double> scoresMap;
	int pointTraining;
	SubsidyType subsidyType;

	Student(string id, string name, string date);
	Student();
	void setPoinTraining(int point);
	void setSubsidyType(SubsidyType type);
	void addSubject(string subjectId);
	void updateScores(string subjectId, double scores);
	double getAverage();
	bool contains(string key);
	int getSholarship();
	int getSubsidy();
	GradeType getGrade();
	string toString();
	~Student();
};