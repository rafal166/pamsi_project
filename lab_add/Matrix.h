
/* 
 * File:   Matrix.h
 * Author: rafal
 *
 * Created on 28 kwietnia 2020, 21:13
 */

#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <tgmath.h>
#define MIN_RAND_INT 1
#define MAX_RAND_INT 10

using namespace std;

class Matrix {
	shared_ptr<vector<vector<int>>> data = make_shared<vector<vector<int>>>();
	int numColumn = 0; // ilość kolumn
	int sizeColumns = 0; // ilość wierszy

	int getRandomInt() {
		return rand() % MAX_RAND_INT + MIN_RAND_INT;
	}
public:
	// konstruktory

	Matrix() {
	}

	Matrix(unsigned int lines, unsigned int columns = 0, int type = -1) {
		generate(lines, columns, type);
	}
	// operatory

	Matrix(const Matrix& source) {
		data = make_shared<vector<vector<int>>>(*(source.data));
		numColumn = source.numColumn;
		sizeColumns = source.sizeColumns;
	}

	Matrix& operator=(const Matrix& source) {
		data = make_shared<vector<vector<int>>>(*(source.data));
		numColumn = source.numColumn;
		sizeColumns = source.sizeColumns;
		return *this;
	}

	Matrix& operator*(Matrix & source) {
		standardMultiply(source);
		return *this;
	}

	vector<int>& operator[](const int idx) {
		return (*data)[idx];
	}

	int operator()(const int idx, const int idx2) {
		return (*data)[idx][idx2];
	}

	void operator()(const int idx, const int idx2, const int newElem) {
		(*data)[idx][idx2] = newElem;
	}

	//

	void generate(unsigned int lines, unsigned int columns = 0, int type = -1) {
		// -1 - losowa
		// 0 - zerowa
		// 1 - jedynkowa

		srand((unsigned) time(NULL));
		data = make_shared<vector<vector<int>>>();
		sizeColumns = lines;
		numColumn = (columns) ? columns : sizeColumns;

		//		if( n < 1)
		//			throw Exception();
		data->reserve(numColumn);
		for (int i = 0; i < numColumn; i++) {
			vector<int> tmp;
			tmp.reserve(sizeColumns);
			for (int j = 0; j < sizeColumns; j++)
				if (type == 1)
					tmp.push_back(2);
				else if (type == 0)
					tmp.push_back(0);
				else
					tmp.push_back(2);

			data->push_back(tmp);
		}
	}

	void printMatrix() {
		cout << "---------------------------" << endl;
		cout << "Printuje" << endl;
		for (int i = 0; i < numColumn; i++) {
			for (int j = 0; j < sizeColumns; j++) {
				cout << (*data)[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void standardMultiply(Matrix & source) {
		int numColumns = data->size();
		int numRows = ((*(source.data))[0]).size();
		cout << "Multiply" << endl;
		cout << "first" << endl;
		printMatrix();
		cout << "second" << endl;
		source.printMatrix();


		Matrix tmp(data->size(), ((*(source.data))[0]).size(), 0);
		cout << "Temporary" << endl;
		tmp.printMatrix();

		for (int i = 0; i < numColumns; i++)
			for (int j = 0; j < numRows; j++)
				for (int k = 0; k < numColumns; k++)
					tmp(i, j, tmp(i, j) + ((*data)[i][k] * (*(source.data))[k][i]));
		cout << "result" << endl;
		tmp.printMatrix();

		data = tmp.data;
	}

	void StrassenMultiply(Matrix & source) {
		int numColumns = data->size();
		int numRows = ((*(source.data))[0]).size();
		cout << "StrassenMultiply" << endl;

		extendsSizeToPowerOfTwo(*this);
		extendsSizeToPowerOfTwo(source);
		Strassen(source, data->size());
	}
private:

	void extendsSizeToPowerOfTwo(Matrix & source) {
		int n = pow(2, ceil(log(source.data->size()) / log(2)));
		vector<int> tmp;
		tmp.reserve(n);

		for (int i = 0; i < n; i++)
			tmp.push_back(0);

		source.data->reserve(n);

		for (int i = 0; i < source.data->size(); i++)
			for (int j = (*source.data)[i].size(); j < n; j++)
				(*source.data)[i].push_back(0);

		for (int i = source.data->size(); i < n; i++)
			source.data->push_back(tmp);

		source.numColumn = source.sizeColumns = n;
		source.printMatrix();
	}

	Matrix Strassen(Matrix & source, int currSize) {
		Matrix result(currSize);
		if (currSize <= 2) {
			result = *this * source;
		}else{
		
		}

		return result;
	}
};

#endif /* MATRIX_H */

