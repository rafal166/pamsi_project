/*

/* 
 * File:   main.cpp
 * Author: rafal
 *
 * Created on 28 kwietnia 2020, 20:42
 */

#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main(int argc, char** argv) {
	Matrix matrix(4);
	Matrix matrix2(matrix);

//	matrix = matrix * matrix2;
	matrix.StrassenMultiply(matrix2);

	return 0;
}

