/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CSVSaver.h
 * Author: rafal
 *
 * Created on 3 kwietnia 2020, 17:50
 */

#ifndef CSVSAVER_H
#define CSVSAVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CSVSaver {
private:
	ofstream file;
	string data;
	string currLine;

	void start(string fileName = "", vector<string> columnList = {}) {
		if (fileName.length() > 0) {
			file.open("./data/" + fileName);
			for (string elem : columnList)
				data += elem + ";";
			data += "\n";
		}
	}
public:

	CSVSaver(string fileName = "", vector<string> columnList = {}) {
		start(fileName, columnList);
	}

	void reset(string fileName, vector<string> columnList) {
		if (file.is_open())
			save();
		currLine = data = "";
		start(fileName, columnList);
	}

	void addData(string newData) {
		if (currLine.length() > 0)
			currLine += "\"" + newData + "\"" + ";";
		else
			currLine = "\"" + newData + "\"" + ";";
	}

	void addData(double newData) {
		if (currLine.length() > 0)
			currLine += to_string(newData) + ";";
		else
			currLine = to_string(newData) + ";";
	}

	void addData(float newData) {
		if (currLine.length() > 0)
			currLine += to_string(newData) + ";";
		else
			currLine = to_string(newData) + ";";
	}

	void addData(int newData) {
		if (currLine.length() > 0)
			currLine += to_string(newData) + ";";
		else
			currLine = to_string(newData) + ";";
	}

	void newLine() {
		data += currLine + "\n";
		currLine = "";
	}

	bool save() {
		try {
			newLine();
			file << data;
			file.close();
			return true;
		} catch (const ofstream::failure& e) {
			return false;
		}
	}

};

#endif /* CSVSAVER_H */

