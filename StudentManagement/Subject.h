#pragma once
#include <string>
using namespace std;

class Subject
{
public:
	string id;
	string name;
	int coefficient;

	Subject(string id, string name, int coefficient);
	~Subject();
};

