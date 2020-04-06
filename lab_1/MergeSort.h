
/* 
 * File:   marge_sort.h
 * Author: rafal
 *
 * Created on 30 marca 2020, 11:49
 */

#ifndef MARGE_SORT_H
#define MARGE_SORT_H

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>

using namespace std;

template <typename T>
class MergeSort {
private:

	MergeSort() {

	}

	static void merge(shared_ptr<vector <T>> tables, int leftStart, int rightEnd) {
		static vector<T> tmpl(1000000);

		for (int i = leftStart; i < rightEnd; i++)
			tmpl[i - leftStart] = (*tables)[i];

		int leftEnd = (rightEnd + leftStart) / 2;
		int right = leftEnd + 1;

		int left = leftStart;
		int index = leftStart;

		while (left <= leftEnd && right <= rightEnd)
			if (tmpl[left - leftStart] <= tmpl[right - leftStart]) {
				(*tables)[index] = tmpl[left - leftStart];
				index++;
				left++;
			} else {
				(*tables)[index] = tmpl[right - leftStart];
				index++;
				right++;
			}

		while (left <= leftEnd) {
			(*tables)[index++] = tmpl[left - leftStart];
			left++;
		}
	}

public:

	static void sort(shared_ptr<vector <T>> tables, int left, int right) {

		if (right <= left) return;

		int center = (left + right) / 2;

		MergeSort<T>::sort(tables, left, center);
		MergeSort<T>::sort(tables, center + 1, right);

		MergeSort<T>::merge(tables, left, right);

	}

	static double sortAll(shared_ptr<vector<shared_ptr<vector <T>>>> tables) {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		for (shared_ptr<vector <int>> vectors : *tables)
			MergeSort<int>::sort(vectors, 0, vectors->size() - 1);

		auto End = Clock.now();
		cout << "Time from Merge: " << chrono::duration<double>(End - Start).count() << endl;
		return chrono::duration<double>(End - Start).count();
	}
};

#endif /* MARGE_SORT_H */

