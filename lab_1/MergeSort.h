
/* 
 * File:   marge_sort.h
 * Author: rafal
 *
 * Created on 30 marca 2020, 11:49
 */

#ifndef MARGE_SORT_H
#define MARGE_SORT_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <fstream>
#include <chrono>
#include "showStatistic.h"

using namespace std;

template <typename T>
class MergeSort {
private:

	static void merge(shared_ptr<vector <T>> tables, int leftStart, int rightEnd) {
		vector<T> tmpl;
		for (T value : *tables)
			tmpl.push_back(value);

		int leftEnd = (rightEnd + leftStart) / 2;
		int right = leftEnd + 1;

		int left = leftStart;
		int index = leftStart;

		while (left <= leftEnd && right <= rightEnd)
			if (tmpl[left] <= tmpl[right])
				(*tables)[index++] = tmpl[left++];
			else
				(*tables)[index++] = tmpl[right++];

		while (left <= leftEnd)
			(*tables)[index++] = tmpl[left++];
	}

	static void merge_sort(shared_ptr<vector <T>> tables, int left, int right) {
		if (right <= left) return;

		int center = (left + right) / 2;

		MergeSort<T>::merge_sort(tables, left, center);
		MergeSort<T>::merge_sort(tables, center + 1, right);

		MergeSort<T>::merge(tables, left, right);

	}

public:

	static void sort(shared_ptr<vector <T>> tables) {

		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		MergeSort<T>::merge_sort(tables, 0, tables->size() - 1);

		auto End = Clock.now();
		chrono::duration<double> Time_delay = End - Start;
		showStatistic("Merge sort", Time_delay);
	}
};


#endif /* MARGE_SORT_H */

