

/* 
 * File:   HeapSort.h
 * Author: rafal
 *
 * Created on 30 marca 2020, 19:34
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

template <typename T>
class HeapSort {
private:

	static void maxHeapValidate(shared_ptr<vector <T>> table, int size, int parentIndex) {

		int first = parentIndex * 2 + 1;
		int second = parentIndex * 2 + 2;
		int currMax = parentIndex;

		if (first < size && (*table)[first] > (*table)[currMax])
			currMax = first;
		if (second < size && (*table)[second] > (*table)[currMax])
			currMax = second;

		if (currMax != parentIndex) {
			HeapSort::swap(table, currMax, parentIndex);
			HeapSort::maxHeapValidate(table, size, currMax);
		}

	}

	static void heapSort(shared_ptr<vector <T>> table) {

		int size = table->size();

		for (int i = size / 2 - 1; i >= 0; i--) // budowa kopca maksymalnego
			HeapSort::maxHeapValidate(table, size, i);

		for (int i = size - 1; i > 0; i--) { // rozbieranie kopca
			HeapSort::swap(table, 0, i);
			HeapSort::maxHeapValidate(table, --size, 0);
		}

	}

public:

	static void sort(shared_ptr<vector < T>> tables) {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		HeapSort<T>::heapSort(tables);

		auto End = Clock.now();
		chrono::duration<double> Time_delay = End - Start;
		showStatistic("Heap sort", Time_delay);

	}

	static void sortPart(shared_ptr<vector < T>> table, unsigned int startIndex, unsigned int endIndex) {
		int i = startIndex;
		int k = 0;
		shared_ptr<vector < T>> help_table = make_shared<vector < T >> ();

		for (; i < endIndex; i++) // przepisywanie fragmentu do tablicy pomocniczej
			help_table->push_back((*table)[i]);

		HeapSort<T>::heapSort(help_table); // sortowanie tablicy pomocniczej

		for (i = startIndex; i < endIndex; i++) // ponowne przepisywanie do głównej tablicy
			(*table)[i] = (*help_table)[k++];
	}

	//helper

	static void swap(shared_ptr<vector <T>> table, int one, int two) {
		T temp = (*table)[two];
		(*table)[two] = (*table)[one];
		(*table)[one] = temp;
	}
};

#endif /* HEAPSORT_H */

