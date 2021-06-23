#pragma once
#include "IndexSorting.h"
#include "AverageSorting.h"

class SortingFactory
{
public:
	static ISorting* sortingFromType(SortingType type) {
		switch (type)
		{
		case AVERAGE:
			return new AverageSorting();
		case ID:
			return new IndexSorting();
		default:
			return new IndexSorting();
		}
	}

	static ISorting* sortingFromInt(int selection) {
		switch (selection)
		{
		case 1:
			return new IndexSorting();
		case 2:
			return new AverageSorting();
		default:
			return new IndexSorting();
		}
	}
};