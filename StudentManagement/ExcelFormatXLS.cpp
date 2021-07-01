#include "ExcelFormatXLS.h"

vector<string> ExcelFormatXLS::readFile(string link)
{
	vector<string> data = vector<string>();
	string temp = "";
	fstream inData;
	try {
		inData.open(link, ios::in);
		getline(inData, temp);
		while (temp != "") {
			data.push_back(temp);
			getline(inData, temp);
		}
		inData.close();
		return data;
	}
	catch (exception e) {
		cout << "Error";
	}
	return data;
}

bool ExcelFormatXLS::writeFile(string link, vector<string> output, vector<string> columnsName)
{
	fstream outData;
	try {
		outData.open(link, ios::out);
		for (int i = 0; i < columnsName.size(); i++) {
			outData << columnsName[i] << "\t";
		}
		outData << endl;
		for (int i = 0; i < output.size(); i++) {
			outData << output[i] << endl;
		}
		outData.close();
	}
	catch (exception e) {
		return false;
	}
	return true;
}
