
/* 
 * File:   showStatistic.h
 * Author: rafal
 *
 * Created on 30 marca 2020, 17:51
 */

#ifndef SHOWSTATISTIC_H
#define SHOWSTATISTIC_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

void showStatistic(string title, chrono::duration<double> duration) {

	cout << title << endl;
	cout << "Czas: " << duration.count() << "s" << endl;
}

#endif /* SHOWSTATISTIC_H */

