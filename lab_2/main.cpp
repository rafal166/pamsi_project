
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

using namespace std;

vector<int> numVertices = {5, 10, 20, 30, 40}; // liczba wierzchołków w grafie
vector<int> graphDensity = {.25, .50, .75, 1}; // gęstość grafów

void generateGraph(int numVertices, int numEdges){

}

int main(int argc, char** argv) {

	ListGraph<int, int> graph;
	//	graph.insertVertex(2);
	//	graph.insertVertex(3);
	//	graph.insertEdge(0, 1, 4);

	//	cout << "Data: " << graph.getVertex(1)->getIndex() << endl;
	graph.readGraphFromFile("hej.csv");
	graph.printAdjList();
//	graph.saveGraphToFile("hej2.csv");
	graph.FBFindWay();

	return 0;
}

