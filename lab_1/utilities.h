
/* 
 * File:   utilities.h
 * Author: rafal
 *
 * Created on 3 kwietnia 2020, 17:29
 */

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
void printArrays(shared_ptr<vector<shared_ptr<vector <T>>>> tables) {

	int counter = 0;
	for (shared_ptr<vector < T >> vectors : *tables) {
		cout << counter++ << ") ";
		for (T data : *vectors) {
			cout << data << " ";
			if (data < 10)
				cout << " ";
		}
		cout << endl;
	}
}

template <typename T>
shared_ptr<vector<shared_ptr<vector <T>>>> allocateArrays(int numberArrays, int numberElemsInOneArray, float sortPercent = 0, bool sortedReverse = false) {
	vector < shared_ptr<vector < T>>> first_vec;
	shared_ptr<vector < shared_ptr<vector < T>>>> tables = make_shared <vector < shared_ptr<vector < T>>> >(first_vec);

	int numSorted = floor(numberElemsInOneArray * (sortPercent / 100));

	for (int a = 0; a < numberArrays; a++) {
		shared_ptr<vector < T>> tmpVector = make_shared<vector < T >> ();

		for (int c = 0; c < numberElemsInOneArray; c++)
			tmpVector->push_back(rand() % 1000);
		if (sortPercent > 0)
			if (sortedReverse)
				sort(tmpVector->begin(), tmpVector->begin() + numSorted, less<int>());
			else
				sort(tmpVector->begin(), tmpVector->begin() + numSorted, greater<int>());

		tables->push_back(tmpVector);
	}

	return tables;
}

template <typename T>
bool isSorted(shared_ptr<vector<shared_ptr<vector <T>>>> tables, int asc = 1) {
	T last;
	for (shared_ptr<vector < T >> vectors : *tables) {
		last = (*vectors)[0];
		for (T elem : *vectors) {
			if (asc > 0 && last > elem)
				return false;
			else
				if (last < elem)
				return false;
			last = elem;
		}
	}
	return true;
}

#endif /* UTILITIES_H */

