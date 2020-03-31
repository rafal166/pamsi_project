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
#include "QuickSort.h" 
#include "IntroSort.h" 

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
	int numNotSorted = numberElemsInOneArray - numSorted;

	for (int a = 0; a < numberArrays; a++) {
		shared_ptr<vector < T>> tmpVector = make_shared<vector < T >> ();
		//
		for (int b = 0; b < numSorted; b++) {
			if (sortedReverse)
				tmpVector->push_back(numSorted - b);
			else
				tmpVector->push_back(b);
		}
		for (int c = 0; c < numNotSorted; c++)
			tmpVector->push_back(rand() % 20);

		tables->push_back(tmpVector);
	}

	return tables;
}

#define NUM_ARRAYS 2
#define NUM_ELEM_IN_ARRAY 200

int main(int argc, char** argv) {
	srand((unsigned) time(NULL)); // inicjowanie generatora liczb losowych

	// alokajca tablic do sortowania
	auto sorted_merge = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY);
	auto sorted_heap = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY);
	auto sorted_quick = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY);


	for (shared_ptr<vector <int>> vectors : *sorted_heap) {
		//		MergeSort<int>::sort(vectors);
		//		HeapSort<int>::sortPart(vectors, 4, 10);
		IntroSort<int>::sort(vectors);
		//		QuickSort<int>::sort(vectors);
	}
	//	cout << endl << "__________ Print End Quick __________" << endl << endl;
	//	printArrays(make_shared<vector<vector <int>>>(sorted_quick));
	cout << endl << "__________ Print End Heap __________" << endl << endl;
	printArrays(sorted_heap);

	return 0;
}
