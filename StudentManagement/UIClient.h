#pragma once
#include "Helper.h"
#include "SubjectsSingleton.h"
#include <iostream>
using namespace std;
class UIClient {
public:
	static Student enteringStudent() {
		vector<string> info;
		vector<string> columnsName = { "MSSV", "Ten", "Ngay sinh (d/M/yyyy)", "Diem ren luyen" };
		cout << "Nhap thong tin sinh vien:" << endl;
		for (string item : columnsName) {
			info.push_back(enteringString(item));
		}
		Student student = Student(info[0], info[1], info[2]);
		student.setPoinTraining(atoi(info[3].c_str()));
		SubsidyType subsidyType = enteringSubsidyType();
		student.setSubsidyType(subsidyType);
		map<string, double> scoresMap = enteringScoresMap();
		student.scoresMap = scoresMap;
		return student;
	}

	static map<string, double> enteringScoresMap() {
		map<string, double> scoresMap;
		int selection = 0;
		string title = "Nhap diem cho sinh vien";
		vector<string> columnsName = { "Tiep tuc", "Ket thuc" };
		do {
			selection = enteringSelectionMenu(title, columnsName);
			if (selection == 1) {
				Subject* subject = enteringSubject();
				if (subject != nullptr) {
					double scores = enteringScores();
					scoresMap[subject->id] = scores;
				}
				else {
					cout << "Khong tim thay mon hoc" << endl;
				}
			}
		} while (selection != 2);
		return scoresMap;
	}

	static Subject* enteringSubject() {
		string selection = enteringString("Nhap ma mon hoc");
		return SubjectsSingleton::getInstance()->getSubject(selection);
	}

	static string enteringString(string columnName) {
		string temp = "";
		cout << columnName << ": ";
		getline(cin, temp);
		return Helper::trim(temp);
	}

	static double enteringScores() {
		string temp = "";
		double selection = 0;
		do {
			selection = enteringDouble("Nhap diem");
		} while (selection < 0.0 || selection > 10.0);
		return selection;
	}

	static double enteringDouble(string columnName) {
		string temp = "";
		bool completion = false;
		double selection = 0.0;
		do {
			try {
				temp = enteringString(columnName);
				selection = stod(temp.c_str());
				completion = true;
			}
			catch (exception e) {

			}
		} while (completion == false);
		return selection;
	}

	static int enteringInt(string columnName) {
		string temp = "";
		bool completion = false;
		int selection = 0;
		do {
			try {
				temp = enteringString(columnName);
				selection = atoi(temp.c_str());
				completion = true;
			}
			catch (int e) {

			}
		} while (completion == false);
		return selection;
	}

	static SubsidyType enteringSubsidyType() {
		string title = "Chon dien tro cap";
		vector<string> columnsName = { "Khong", "Ho ngheo", "Con thuong binh" };
		int selection = enteringSelectionMenu(title, columnsName);
		return intToSubsidyTypeDict.find(selection)->second;
	}

	static SortingType enteringSortingType() {
		string title = "Chon tieu chi sap xep";
		vector<string> columnsName = { "Theo mssv", "Theo diem trung binh" };
		int selection = enteringSelectionMenu(title, columnsName);
		return intToSortingTypeDict.find(selection)->second;
	}

	static void selectionMenuForm(string title, vector<string> arr) {
		cout << title << endl;
		for (int i = 0; i < arr.size(); i++) {
			cout << "\t" << (i + 1) << " " << arr[i] << "." << endl;
		}
	}

	static int enteringSelectionMenu(string title, vector<string> columnsName) {
		string temp = "";
		selectionMenuForm(title, columnsName);
		int selection = 0;
		do {
			selection = enteringInt("Nhap lua chon");
		} while (selection < 1 || selection > columnsName.size());
		return selection;
	}

	static int mainMenu() {
		string title = "Tac vu chinh cua chuong trinh";
		vector<string> columnsName = { "Sap xep", "Them sinh vien", "Xoa sinh vien theo tu khoa",
			"Lay thong tin sinh vien theo tu khoa",
			"Thoat" };
		return enteringSelectionMenu(title, columnsName);
	}
};