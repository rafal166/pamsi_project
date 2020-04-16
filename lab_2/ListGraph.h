
/* 
 * File:   ListGraph.h
 * Author: rafal
 *
 * Created on 15 kwietnia 2020, 20:06
 */

#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "Vertex.h"
#include "Edge.h"

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#define INFINITY 2147483640

template <typename T_vertex, typename T_edge>
class ListGraph {
protected:
	int startVertex;
	vector<shared_ptr<Vertex<T_vertex>>> vertexList;
	vector<shared_ptr<Edge<T_vertex, T_edge>>> edgeList;
	vector<vector<shared_ptr<Edge<T_vertex, T_edge>>>> adjList;
public:

	// Metody uaktualniające

	void insertVertex() {
		vertexList.push_back(make_shared<Vertex < T_vertex >> (vertexList.size()));

		vector<shared_ptr<Edge<T_vertex, T_edge>>> adjVector;
		adjList.push_back(adjVector);
	}

	void insertVertexByNum(int number) {
		shared_ptr<Vertex < T_vertex>> vert = make_shared<Vertex < T_vertex >> (number);
		vertexList[number] = vert;
		//		cout << "Dodaje na pozycji " << number << ". Ilość wierzchołków " << vertexList.size() << endl;
	}

	void insertEdge(int start, int end, T_edge data) {
		shared_ptr<Edge <T_vertex, T_edge>> edge =
				make_shared<Edge <T_vertex, T_edge >> (vertexList[start], vertexList[end], data);
		edgeList.push_back(edge);
		(adjList[start]).push_back(edge);
		//		(adjList[end]).push_back(edge); // odkomentuj to a dostaniesz graf nieskierowany

		edge->setAdjRefs(make_shared<vector < shared_ptr<Edge<T_vertex, T_edge>>>>(adjList[start]), make_shared<vector < shared_ptr<Edge<T_vertex, T_edge>>>>(adjList[end]));
	}

	void setStartVertex(int num) {
		startVertex = num;
	}


	// file IO

	void saveGraphToFile(string filename) {
		ofstream file;
		file.open(filename);

		file << vertexList.size() << "\t" << edgeList.size() << "\t" << 0 << "\n"; // zapisywanie początkowych wartości dla grafu
		for (shared_ptr<Edge < T_vertex, T_edge >> edge : edgeList)
			file << edge->getStart()->getIndex() << "\t" << edge->getEnd()->getIndex() << "\t" << edge->getWeight() << "\n"; // wypisywanie krawędzi

		file.close();
	}

	bool readGraphFromFile(string filename) {
		ifstream file;
		file.open(filename);

		string data;
		int num1, num2, num3; // jakieś zmienne pomocnicze
		if (!getline(file, data, '\t')) // prezerwatywa jakby pliku nie było
			return false;

		num1 = stoi(data);
		getline(file, data, '\t');
		num2 = stoi(data);
		reserveMemory(num1, num2); // rezerwacja pamięci dla zadanych ilości wierzchołków i krawędzi

		getline(file, data);
		num1 = stoi(data);
		setStartVertex(num1); // ustawianie wierzchołka startowego

		for (int i = num2; i > 0; i--) { // czytanie kolejnych krawędzi z pliku
			// czytanie pierwszego wierzchołka
			getline(file, data, '\t');
			num1 = stoi(data);
			if (!checkIfVertexExists(num1))
				insertVertexByNum(num1); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób

			// czytanie drugiego wierzchołka
			getline(file, data, '\t');
			num2 = stoi(data);
			if (!checkIfVertexExists(num2))
				insertVertexByNum(num2); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób

			// czytanie wagi krawędzi
			getline(file, data, '\n');
			num3 = stoi(data);

			insertEdge(num1, num2, num3); // dodawanie nowej krawędzi
		}

		file.close();
		return true;
	}
	// gettery

	T_vertex getDataFomVertex(int index) {
		return (vertexList[index])->getData();
	}

	shared_ptr<Vertex < T_vertex>> getVertex(int index) {
		return vertexList[index];
	}

	//help methods

	void reserveMemory(int numVertex, int numEdges) {
		vector<shared_ptr<Edge<T_vertex, T_edge>>> adjVector; // pusty wektro dla listy sąsiedztwa

		for (; numVertex > 0; numVertex--) {
			vertexList.push_back(nullptr); // rezerwacja w liście wierzchołków
			adjList.push_back(adjVector); // dodawanie wektora w liście sąsiedztwa
		}
		edgeList.reserve(numEdges); // rezerwacja miejsca w liście krawędzi
	}

	bool checkIfVertexExists(int numVert) {
		// jeśli numer wierzchołka jest większy od liczby wszystkich wierzchołków lub ten index wskazuje na nullptr to nie ma wierzchołka pod tym indexem
		if (vertexList.size() >= numVert || vertexList[numVert] == nullptr)
			return false;
		return true;
	}

	void printAdjList() {
		cout << "------------------------------------" << endl;
		cout << "Rozmiar tablicy sąsiedztwa " << adjList.size() << endl;
		for (int i = 0; i < adjList.size(); i++) {
			cout << "Wierzchołek " << i << " sąsiaduje z ";
			for (shared_ptr<Edge < T_vertex, T_edge >> edge : adjList[i])
				cout << edge->getEnd()->getIndex() << " ";
			cout << endl;
		}
	}

	// Algorytm Bellmana-Forda

	void FBFindWay() {
		int n = vertexList.size(), somsiad; //
		vector<int> d, p;

		// rezerwacja pamięci dla lepszej wydajności
		d.reserve(n);
		p.reserve(n);

		for (int i = 0; i < n; i++) { // wypełnianie początkowe tabel
			p.push_back(-1);
			if (i == startVertex)
				d.push_back(0);
			else
				d.push_back(INFINITY);
		}

		for (int i = 0; i < n; i++) { // pętla po wszystkich wierzchołkach
			for (shared_ptr<Edge < T_vertex, T_edge >> edge : adjList[i]) { // pętla po wszystkich sąsiadach z listy sąsiedztwa
				somsiad = edge->getEnd()->getIndex();
				if (d[somsiad] > d[i] + edge->getWeight()) { // sprawdzanie czy tędy nie będzie taniej dojść
					// tutaj jest taniej więc aktualizuje cenę drogi do tego wierzchołka
					d[somsiad] = d[i] + edge->getWeight();
					p[somsiad] = i;
				}
			}
		}

		// wypisywanie do konsoli wyniku
		cout << endl << "Najkrótsze drogi to: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i << ") " << d[i] << endl;
		}
	}
};


#endif /* LISTGRAPH_H */

