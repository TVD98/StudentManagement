#pragma once
#include "ISorting.h"
class AverageSorting :
    public ISorting
{
public:
    int compare(Student student1, Student student2);
};

