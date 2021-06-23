#include "IndexSorting.h"

int IndexSorting::compare(Student student1, Student student2)
{
    return student1.id.compare(student2.id);
}
