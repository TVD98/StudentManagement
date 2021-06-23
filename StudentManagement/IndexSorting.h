#pragma once
#include "ISorting.h"
class IndexSorting :
    public ISorting
{
public:
    int compare(Student student1, Student student2);
};

