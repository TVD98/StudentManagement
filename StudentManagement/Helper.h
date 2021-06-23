#pragma once
#include <math.h>

class Helper {
public:
	static float roundNumberUp(double number) {
		return roundf(number * 100) / 100.f;
	}
};