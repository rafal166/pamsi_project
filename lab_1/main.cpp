/* 
 * File:   main.cpp
 * Author: rafal
 *
 * Created on 24 marca 2020, 17:37
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <time.h> 
#include "MergeSort.h" 
#include "HeapSort.h" 

using namespace std;

template <typename T>
void printArrays(shared_ptr<vector<vector <T>>> tables) {

	int counter = 0;
	for (vector <T> vectors : *tables) {
		cout << counter++ << ") ";
		for (T data : vectors) {
			cout << data << " ";
			if (data < 10)
				cout << " ";
		}
		cout << endl;
	}
}

template <typename T>
shared_ptr<vector<vector <T>>> allocateArrays(int numberArrays, int numberElemsInOneArray, float sortPercent = 0, bool sortedReverse = false) {
	shared_ptr<vector<vector < T>>> tables = make_shared<vector<vector < T>>>();

	int numSorted = floor(numberElemsInOneArray * (sortPercent / 100));
	int numNotSorted = numberElemsInOneArray - numSorted;

	for (int a = 0; a < numberArrays; a++) {
		vector<T> tmpVector;

		for (int b = 0; b < numSorted; b++) {
			if (sortedReverse)
				tmpVector.push_back(numSorted - b);
			else
				tmpVector.push_back(b);
		}
		for (int b = 0; b < numNotSorted; b++)
			tmpVector.push_back(rand() % 50);

		tables->push_back(tmpVector);
	}

	return tables;
}

int main(int argc, char** argv) {
	srand((unsigned) time(NULL));
	vector<vector <int>> sorted_merge;
	vector<vector <int>> sorted_heap;
	shared_ptr<vector<vector <int>>> tables = allocateArrays<int>(2, 20, 0, false);


	for (vector<int> vectors : *tables) {
		sorted_merge.push_back(MergeSort<int>::sort(vectors));
		sorted_heap.push_back(HeapSort<int>::sort(vectors));
	}
	cout << endl << "__________ Print End Merge __________" << endl << endl;
	printArrays(make_shared<vector<vector <int>>>(sorted_merge));
	cout << endl << "__________ Print End Heap __________" << endl << endl;
	printArrays(make_shared<vector<vector <int>>>(sorted_heap));

	return 0;
}
