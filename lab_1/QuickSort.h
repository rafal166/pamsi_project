
/* 
 * File:   QuickSort.h
 * Author: rafal
 *
 * Created on 31 marca 2020, 09:10
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
class QuickSort {
public:

	static void sort(shared_ptr<vector <T>> table, int left, int right) {
		int i = left;
		int j = right;
		int PositionPivot = (i + j) / 2;
		T Pivot = (*table)[PositionPivot];
		T tmpl; //zmienna pomocnicza

		while (i <= j) {
			while ((*table)[i] < Pivot) //Przesun w prawo granice lewa
				i++;

			while ((*table)[j] > Pivot) //Przesun w lewo granice prawa
				j--;

			if (i <= j) //Jesli granice sa poprawne
			{
				tmpl = (*table)[i];
				(*table)[i] = (*table)[j];
				(*table)[j] = tmpl;
				i++;
				j--;
			}
		}
		if (j > left)
			QuickSort::sort(table, left, j);

		if (i < right)
			QuickSort::sort(table, i, right);
	}

	static double sortAll(shared_ptr<vector<shared_ptr<vector <T>>>> tables) {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		for (shared_ptr<vector <int>> vectors : *tables) {
			QuickSort<int>::sort(vectors, 0, vectors->size());
		}

		auto End = Clock.now();
		cout << "Time from Quick: " << chrono::duration<double>(End - Start).count() << endl;
		return chrono::duration<double>(End - Start).count();
	}

};

#endif /* QUICKSORT_H */

