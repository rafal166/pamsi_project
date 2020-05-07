
/* 
 * File:   main.cpp
 * Author: rafal
 *
 * Created on 14 kwietnia 2020, 19:35
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "GraphGenerator.h"

#define NUM_RUNS 100
using namespace std;

vector<int> numVertices = {10, 50, 100, 500, 1000}; // liczba wierzchołków w grafie
vector<double> graphDensity = {.25, .50, .75, 1}; // gęstość grafów

void testList() {
	vector<double> result;
	result.clear();
	for (int vertNum : numVertices) {
		for (double density : graphDensity) {
			ListGraph graphMain;
			graphMain.generate(vertNum, density, 0, true);

			double sum = 0;
			result.clear();
			result.reserve(NUM_RUNS);

			for (int i = 0; i < NUM_RUNS; i++) {
				ListGraph graph;
				graph.generate(vertNum, density, 0, true);
				result.push_back(graph.FBFindWay());
			}

			for (double res : result)
				sum += res;
			graphMain.addResultToFile(sum / result.size());
			result.clear();
		}
	}
}

void testMatrix() {
	vector<double> result;
	result.clear();
	for (int vertNum : numVertices) {
		for (double density : graphDensity) {
			MatrixGraph graphMain;
			graphMain.generate(vertNum, density, 0, true);
			double sum = 0;
			result.clear();
			result.reserve(NUM_RUNS);

			for (int i = 0; i < NUM_RUNS; i++) {
				MatrixGraph graph;
				graph.generate(vertNum, density, 0, true);
				result.push_back(graph.FBFindWay());
			}
			for (double res : result)
				sum += res;
//			graphMain.addResultToFile(sum / result.size());
			result.clear();
		}
	}
}

int main() {

	//	thread listTherad(testList);
	thread matrixTherad(testMatrix);

	//	listTherad.join();
	matrixTherad.join();

	return 0;
}
