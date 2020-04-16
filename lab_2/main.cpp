
/* 
 * File:   main.cpp
 * Author: rafal
 *
 * Created on 14 kwietnia 2020, 19:35
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "ListGraph.h"
#include "GraphGenerator.h"

using namespace std;

vector<int> numVertices = {5, 10, 20, 30, 40}; // liczba wierzchołków w grafie
vector<double> graphDensity = {.25, .50, .75, 1}; // gęstość grafów

int main(int argc, char** argv) {

	ListGraph<int, int> graph;

	GraphGenerator generator;
	generator.generateGraph(10, .25, 0, true, "my_graph.csv");

	graph.readGraphFromFile("my_graph.csv");
	graph.printAdjList();
	graph.FBFindWay();

	return 0;
}

