
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
private:

	static void quickSort(shared_ptr<vector <T>> table, int left, int right) {
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
			QuickSort::quickSort(table, left, j);

		if (i < right)
			QuickSort::quickSort(table, i, right);
	}
public:

	static void sort(shared_ptr<vector <T>> tables) {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		QuickSort<T>::quickSort(tables, 0, tables->size());

		auto End = Clock.now();
		chrono::duration<double> Time_delay = End - Start;
		showStatistic("Heap sort", Time_delay);
	}

};

#endif /* QUICKSORT_H */

