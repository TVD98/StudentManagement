#pragma once
#include <vector>
#include "ISorting.h"

class SearchSystem {
public:
    // tim kiem vi tri de them phan tu
    static int search(vector<Student> array, int left, int right, Student newStudent, ISorting* sorting)
    {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            // If the element is present at the middle
            // itself
            if (sorting->compare(array[mid], newStudent) == 0)
                return mid;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (sorting->compare(array[mid], newStudent) == 1)
                return search(array, left, mid - 1, newStudent, sorting);

            // Else the element can only be present
            // in right subarray
            return search(array, mid + 1, right, newStudent, sorting);
        }

        // We reach here when element is not
        // present in array
        return right + 1;
    }

    // tim kiem vi tri cac phan tu theo tu khoa
    static vector<int> search(vector<Student> array, string key) {
        vector<int> indexs;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i].contains(key)) {
                indexs.push_back(i);
            }
        }
        return indexs;
    }
};