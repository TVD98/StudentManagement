#include "SubjectsSingleton.h"

SubjectsSingleton* SubjectsSingleton::shared = nullptr;

SubjectsSingleton::SubjectsSingleton()
{
}

SubjectsSingleton* SubjectsSingleton::getInstance()
{
    if (shared == nullptr) {
        shared = new  SubjectsSingleton();
    }
    return shared;
}

void SubjectsSingleton::addSubject(Subject* subject)
{
    subjectsMap[subject->id] = subject;
}

Subject* SubjectsSingleton::getSubject(string subjectId)
{
    map<string, Subject*>::iterator it = subjectsMap.find(subjectId);
    if (it != subjectsMap.end()) {
        return it->second;
    }
    return nullptr;
}

SubjectsSingleton::~SubjectsSingleton()
{
}


