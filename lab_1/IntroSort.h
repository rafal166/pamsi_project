

/* 
 * File:   IntroSort.h
 * Author: rafal
 *
 * Created on 31 marca 2020, 10:29
 */

#ifndef INTROSORT_H
#define INTROSORT_H
#include <cmath>
#include "HeapSort.h" 

template <typename T>
class IntroSort {

	static int partition(shared_ptr<vector <T>> table, int left, int right) {

		int pivot = (*table)[right];
		// Index of smaller element 
		int i = (left - 1);
		for (int j = left; j <= right - 1; j++) {

			// If the current element is smaller 
			// than or equal to the pivot 
			if ((*table)[j] <= pivot) {

				// increment index of smaller element 
				i++;
				HeapSort<T>::swap(table, i, j);
			}
		}
		HeapSort<T>::swap(table, i + 1, right);
		return (i + 1);
	}

	static void introSort(shared_ptr<vector <T>> table, int left, int right, int currDepth) {
		if (right - left > 16) {
			if (!currDepth) {
				HeapSort<T>::sortPart(table, left, right);
			} else {
				currDepth--;

				int positionPivot = (left + right) / 2;
				HeapSort<T>::swap(table, positionPivot, right);

				int p = IntroSort<T>::partition(table, left, right);

				IntroSort<T>::introSort(table, left, p - 1, currDepth);
				IntroSort<T>::introSort(table, p + 1, right, currDepth);
			}
		} else
			HeapSort<T>::sortPart(table, left, right);

	}
private:
public:

	static void sort(shared_ptr<vector < T>> table) {
		int maxDepth = (int) floor(2 * log(table->size()) / M_LN2);
		IntroSort<T>::introSort(table, 0, table->size(), maxDepth);
	}

};


#endif /* INTROSORT_H */

