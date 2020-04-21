
/* 
 * File:   MatrixGraph.h
 * Author: rafal
 *
 * Created on 16 kwietnia 2020, 17:14
 */

#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include "ListGraph.h"

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#define INFINITY 2147483640

class MatrixGraph : public ListGraph {
private:
	vector<vector<shared_ptr<Edge>>> adjList;
public:
	//help methods

	void reserveMemory(int numVertex, int numEdges) {
		vertexList.clear();
		adjList.clear();
		edgeList.clear();

		adjList.reserve(numVertex);
		vertexList.reserve(numVertex);
		edgeList.reserve(numEdges); // rezerwacja miejsca w liście krawędzi

		vector<shared_ptr < Edge>> adjVector; // pusty wektro dla listy sąsiedztwa
		for (int i = 0; i < numVertex; i++)
			adjVector.push_back(nullptr);



		for (; numVertex > 0; numVertex--) {
			vertexList.push_back(nullptr); // rezerwacja w liście wierzchołków
			adjList.push_back(adjVector); // dodawanie wektora w liście sąsiedztwa
		}
	}
	// Metody uaktualniające

	void insertEdge(int start, int end, int data) {
		shared_ptr<Edge> edge =
				make_shared<Edge> (vertexList[start], vertexList[end], data);
		edgeList.push_back(edge);
		(adjList[start]).push_back(edge);
		//		(adjList[end]).push_back(edge); // odkomentuj to a dostaniesz graf nieskierowany

		//		edge->setAdjRefs(make_shared<vector < shared_ptr < Edge>>>(adjList[start]), make_shared<vector < shared_ptr < Edge>>>(adjList[end]));
	}

	// gettery

	void printAdjList() {
		cout << "------------------------------------" << endl;
		cout << "Rozmiar tablicy sąsiedztwa " << adjList.size() << endl;
		for (int i = 0; i < adjList.size(); i++) {
			cout << "Wierzchołek " << i << " sąsiaduje z ";
			for (shared_ptr<Edge> edge : adjList[i])
				if (edge)
					cout << edge->getEnd()->getIndex() << " ";
			cout << endl;
		}
	}

	// Algorytm Bellmana-Forda

	double FBFindWay() {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		int n = vertexList.size(), somsiad;
		// rezerwacja pamięci dla lepszej wydajności
		wayPrices.clear();
		rodaStops.clear();
		wayPrices.reserve(n);
		rodaStops.reserve(n);

		for (int i = 0; i < n; i++) { // wypełnianie początkowe tabel
			rodaStops.push_back(-1);
			if (i == startVertex)
				wayPrices.push_back(0);
			else
				wayPrices.push_back(INFINITY);
		}

		for (int i = 0; i < n; i++) { // pętla po wszystkich wierzchołkach
			for (shared_ptr<Edge> edge : adjList[i]) { // pętla po wszystkich sąsiadach z listy sąsiedztwa
				if (!edge) continue;

				somsiad = edge->getEnd()->getIndex();
				if (wayPrices[somsiad] > wayPrices[i] + edge->getWeight()) { // sprawdzanie czy tędy nie będzie taniej dojść
					// tutaj jest taniej więc aktualizuje cenę drogi do tego wierzchołka
					wayPrices[somsiad] = wayPrices[i] + edge->getWeight();
					rodaStops[somsiad] = i;
				}
			}
		}

		auto End = Clock.now();
		cout << "Time from Matrix: " << chrono::duration<double>(End - Start).count() << endl;
		return chrono::duration<double>(End - Start).count();
	}

	void addResultToFile(double duration) {
		fstream file;

		file.open("results.csv", ios::app);
		file << setprecision(6);
		file << "Matrix\t" << numAllVertices << "\t" << density * 100 << "%\t" << duration << endl;

		file.close();
	}


};

#endif /* MATRIXGRAPH_H */

