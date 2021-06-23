#include "Subject.h"

Subject::Subject(string id, string name, int coefficient)
{
	this->id = id;
	this->name = name;
	this->coefficient = coefficient;
}

Subject::~Subject()
{
}
