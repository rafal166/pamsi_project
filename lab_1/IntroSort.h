

/* 
 * File:   IntroSort.h
 * Author: rafal
 *
 * Created on 31 marca 2020, 10:29
 */

#ifndef INTROSORT_H
#define INTROSORT_H
#include <cmath>

template <typename T>
class IntroSort {

	static void introSort(shared_ptr<vector <T>> table, int left, int right, int currDepth) {
		if (right - left > 16) {
			if (!currDepth) {
				HeapSort<T>::sortPart(table, left, right);
			} else {
				currDepth--;

				int i = left;
				int j = right;
				int PositionPivot = (i + j) / 2;
				T Pivot = (*table)[PositionPivot];
				T tmpl;

				while (i <= j) {
					while ((*table)[i] < Pivot)
						i++;

					while ((*table)[j] > Pivot)
						j--;

					if (i <= j) {
						tmpl = (*table)[i];
						(*table)[i] = (*table)[j];
						(*table)[j] = tmpl;
						i++;
						j--;
					}
				}
				if (j > left)
					IntroSort<T>::introSort(table, left, j, currDepth);

				if (i < right)
					IntroSort<T>::introSort(table, i, right, currDepth);

			}
		} else
			HeapSort<T>::sortPart(table, left, right);

	}

public:

	static void sort(shared_ptr<vector < T>> table) {
		int maxDepth = (int) floor(2 * log(table->size()) / M_LN2);
		IntroSort<T>::introSort(table, 0, table->size(), maxDepth);
	}

	static double sortAll(shared_ptr<vector<shared_ptr<vector <T>>>> tables) {

		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		for (shared_ptr<vector < T >> vectors : *tables)
			IntroSort<T>::sort(vectors);

		auto End = Clock.now();
		cout << "Time from Intro: " << chrono::duration<double>(End - Start).count() << endl;
		return chrono::duration<double>(End - Start).count();
	}

};


#endif /* INTROSORT_H */

