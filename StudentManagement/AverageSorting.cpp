#include "AverageSorting.h"

int AverageSorting::compare(Student student1, Student student2)
{
    double average1 = student1.getAverage();
    double average2 = student2.getAverage();
    if (average1 > average2)
        return 1;
    if (average1 < average2)
        return -1;
    return 0;
}
