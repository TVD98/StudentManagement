#pragma once
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class Helper {
public:
	static float roundNumberUp(double number) {
		return roundf(number * 100) / 100.f;
	}

	static vector<string> split(string input, string delimiter) {
		size_t pos = 0;
		string token;
		vector<string> result;
		while ((pos = input.find(delimiter)) != string::npos) {
			token = input.substr(0, pos);
			result.push_back(token);
			input.erase(0, pos + delimiter.length());
		}
		result.push_back(input);
		return result;
	}

	static string trim(string input) {
		int firstIndex = 0; int size = input.length();
		for (int i = 0; i < size; i++) {
			if (input.at(i) == ' ' || static_cast<int16_t>(input.at(i)) == -257)  firstIndex++;
			else break;
		}
		int endIndex = size;
		for (int j = size - 1; j >= 0; j--) {
			if (input.at(j) == ' ' || static_cast<int16_t>(input.at(j)) == -257)  endIndex--;
			else break;
		}
		return input.substr(firstIndex, endIndex);
	}
};