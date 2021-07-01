#pragma once
#include "ISorting.h"
#include <vector>

enum OrderType {
	ASC = 1, DESC = -1
};

static const map<int, OrderType> orderTypeDict = { {1, OrderType::ASC}, {2, OrderType::DESC} };

class SortSystem
{
public:
	static void selectionSort(vector<Student>& studentList, ISorting* sorting, OrderType orderType) {
		int count = studentList.size();

		for (int i = 0; i < count - 1; i++)
		{
			int iMin = i;
			for (int j = i + 1; j < count; j++)
			{
				if (sorting->compare(studentList[iMin], studentList[j]) == orderType)
					iMin = j;
			}
			if (i != iMin)
				swap(studentList[i], studentList[iMin]);
		}
	}

	static void mergeSort(vector<Student>& studentList, int left, int right, ISorting* sorting, OrderType orderType) {
		// continue
		if (right > left)
		{
			int mid = (left + right) / 2;
			mergeSort(studentList, left, mid, sorting, orderType); // Goi de quy mang con ben trai
			mergeSort(studentList, mid + 1, right, sorting, orderType); // Goi de quy mang con ben phai
			merge(studentList, left, mid, right, sorting, orderType); // Goi ham so sanh hai mang con
		}
	}

private:
	static void merge(vector<Student>& studentList, int left, int mid, int right, ISorting* sorting, OrderType orderType) {
		// continue
		vector<Student>* tempList = new vector<Student>(right - left + 1); // Khoi tao mang tam de sap xep
		int i = left; // Vi tri phan tu dau tien cua mang con ben trai
		int j = mid + 1; // Vi tri phan tu dau tien cua mang con ben phai
		for (int k = 0; k <= right - left; k++)
		{
			if (sorting->compare(studentList.at(i), studentList.at(j)) == orderType)// Kiem phan tu cua mang con ben trai va ben phai
			{
				tempList->at(k) = studentList.at(j);
				j++; // Vi tri phan tu tiep theo cua mang
			}
			else // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
			{
				tempList->at(k) = studentList.at(i);
				i++; // Vi tri phan tu tiep theo cua mang

			}
			if (i == mid + 1)// Kiem tra mang con ben trai con phan tu nao khong
			{
				while (j <= right)// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
				{
					k++;
					tempList->at(k) = studentList.at(j);
					j++;
				}
				break;
			}
			if (j == right + 1)
			{
				while (i <= mid)
				{
					k++;
					tempList->at(k) = studentList.at(i);
					i++;
				}
				break;
			}
		}
		for (int k = 0; k <= right - left; k++) // Chep mang tam vao mang chinh
			studentList.at(left + k) = tempList->at(k);
		delete tempList;
	}
};
