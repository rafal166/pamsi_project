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
#include <thread>
#include "utilities.h" 
#include "MergeSort.h" 
#include "HeapSort.h" 
#include "QuickSort.h" 
#include "IntroSort.h" 
#include "CSVSaver.h" 

using namespace std;

#define NUM_ARRAYS 100
#define NUM_ELEM_IN_ARRAY_LV0 10000  // A
#define NUM_ELEM_IN_ARRAY_LV1 50000  // B
#define NUM_ELEM_IN_ARRAY_LV2 100000 // C
#define NUM_ELEM_IN_ARRAY_LV3 500000 // D
#define NUM_ELEM_IN_ARRAY_LV4 1000000 // E
#define SAVING_VERSION 1

vector<string> CSVcolumnList = {"sortType", "A", "B", "C", "D", "E"};
vector<float> sortTypes = {0, 25, 50, 75, 95, 99, 99.7};

void test_merge_sort() {
	CSVSaver saver = CSVSaver("MergeSort_" + to_string(SAVING_VERSION) + ".csv", CSVcolumnList);
	shared_ptr<vector < shared_ptr<vector < int>>>> array_lv0, array_lv1, array_lv2, array_lv3, array_lv4;

	// Wszystkie elementy tablicy losowe
	array_lv0 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV0);

	saver.addData(MergeSort<int>::sortAll(array_lv0));

	saver.save();
}

void test_quick_sort() {
	CSVSaver saver = CSVSaver("QuickSort_" + to_string(SAVING_VERSION) + ".csv", CSVcolumnList);
	shared_ptr<vector < shared_ptr<vector < int>>>> array_lv0, array_lv1, array_lv2, array_lv3, array_lv4;

	for (float type : sortTypes) {
		saver.addData("First " + to_string(type) + " sorted");
		array_lv0 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV0, type);
		array_lv1 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV1, type);
		array_lv2 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV2, type);
		array_lv3 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV3, type);
		array_lv4 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV4, type);

		saver.addData(QuickSort<int>::sortAll(array_lv0));
		saver.addData(QuickSort<int>::sortAll(array_lv1));
		saver.addData(QuickSort<int>::sortAll(array_lv2));
		saver.addData(QuickSort<int>::sortAll(array_lv3));
		saver.addData(QuickSort<int>::sortAll(array_lv4));
		saver.newLine();
	}

	// Wszystkie elementy posortowane odwrotnie
	saver.addData("All sorted reverse");
	array_lv0 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV0, 100, true);
	array_lv1 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV1, 100, true);
	array_lv2 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV2, 100, true);
	array_lv3 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV3, 100, true);
	array_lv4 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV4, 100, true);

	saver.addData(QuickSort<int>::sortAll(array_lv0));
	saver.addData(QuickSort<int>::sortAll(array_lv1));
	saver.addData(QuickSort<int>::sortAll(array_lv2));
	saver.addData(QuickSort<int>::sortAll(array_lv3));
	saver.addData(QuickSort<int>::sortAll(array_lv4));

	saver.save();
}

void test_intro_sort() {
	CSVSaver saver = CSVSaver("IntroSort_" + to_string(SAVING_VERSION) + ".csv", CSVcolumnList);
	shared_ptr<vector < shared_ptr<vector < int>>>> array_lv0, array_lv1, array_lv2, array_lv3, array_lv4;

	for (float type : sortTypes) {
		saver.addData("First " + to_string(type) + " sorted");
		array_lv0 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV0, type);
		array_lv1 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV1, type);
		array_lv2 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV2, type);
		array_lv3 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV3, type);
		array_lv4 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV4, type);

		saver.addData(IntroSort<int>::sortAll(array_lv0));
		saver.addData(IntroSort<int>::sortAll(array_lv1));
		saver.addData(IntroSort<int>::sortAll(array_lv2));
		saver.addData(IntroSort<int>::sortAll(array_lv3));
		saver.addData(IntroSort<int>::sortAll(array_lv4));

		saver.newLine();
	}


	// Wszystkie elementy posortowane odwrotnie
	saver.addData("All sorted reverse");
	array_lv0 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV0, 100, true);
	array_lv1 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV1, 100, true);
	array_lv2 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV2, 100, true);
	array_lv3 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV3, 100, true);
	array_lv4 = allocateArrays<int>(NUM_ARRAYS, NUM_ELEM_IN_ARRAY_LV4, 100, true);

	saver.addData(IntroSort<int>::sortAll(array_lv0));
	saver.addData(IntroSort<int>::sortAll(array_lv1));
	saver.addData(IntroSort<int>::sortAll(array_lv2));
	saver.addData(IntroSort<int>::sortAll(array_lv3));
	saver.addData(IntroSort<int>::sortAll(array_lv4));

	saver.save();
}

int main(int argc, char** argv) {
	srand((unsigned) time(NULL)); // inicjowanie generatora liczb losowych

	thread merge_thread(test_merge_sort);
	//		thread quick_thread(test_quick_sort);
	//		thread intro_thread(test_intro_sort);

	merge_thread.join();
	//	quick_thread.join();
	//	intro_thread.join();

	return 0;
}
