#pragma once
#include "Subject.h"
#include <map>

class SubjectsSingleton
{
private:
	map<string, Subject*> subjectsMap;

	static SubjectsSingleton* shared;
	SubjectsSingleton();

public:
	static SubjectsSingleton* getInstance();
	void addSubject(Subject* subject);
	Subject* getSubject(string subjectId);
	~SubjectsSingleton();
};

