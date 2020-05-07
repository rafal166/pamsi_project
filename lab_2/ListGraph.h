
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
#include "GraphGenerator.h"

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#define INFINITY 2147483640

class ListNode {
public:
	int numVertex;
	int weight;
	shared_ptr<ListNode> next;
};

class ListGraph : public GraphGenerator {
private:
	vector<shared_ptr<ListNode>> adjList;
protected:
	int startVertex;
	double density;
	vector<shared_ptr<Vertex>> vertexList;
	vector<shared_ptr<Edge>> edgeList;
	vector<int> wayPrices, rodaStops;
	//help methods

	virtual void reserveMemory(int numVertex, int numEdges) {

		//		vertexList.clear();
//		adjList.clear();
		//		edgeList.clear();

		adjList.reserve(numVertex);
		vertexList.reserve(numVertex);
		edgeList.reserve(numEdges); // rezerwacja miejsca w liście krawędzi

		for (; numVertex > 0; numVertex--) {
			vertexList.push_back(nullptr); // rezerwacja w liście wierzchołków
			adjList.push_back(nullptr); // rezerwacja w liście wierzchołków
		}

	}
public:

	// generowanie

	void generate(int numVertices, double graphDensity = 0, int startVert = 0, bool consistent = true) {

		generateGraph(numVertices, graphDensity, startVert, consistent);
		startVertex = startVertice;
		density = graphDensity;
		reserveMemory(numAllVertices, numAllEdges);
		//
		int ilosc_krawedzi = numAllEdges;
		for (int i = 0; i < edges.size(); i++) {
			for (int j = 0; j < (edges[i]).size(); j++) {
				if (j < 0) continue;
				// czytanie pierwszego wierzchołka
				if (!checkIfVertexExists(i))
					insertVertexOnIndex(i); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób
				// czytanie drugiego wierzchołka
				if (!checkIfVertexExists(j))
					insertVertexOnIndex(j); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób
				// Tworzenie krawędzi
				insertEdge(i, j, getRandomWeight()); // dodawanie nowej krawędzi
			}
		}
	}

	// Metody uaktualniające

	void insertVertex() {
		vertexList.push_back(make_shared<Vertex> (vertexList.size()));
	}

	void insertVertexOnIndex(int number) {
		shared_ptr<Vertex> vert = make_shared<Vertex> (number);
		vertexList[number] = vert;
		//		cout << "Dodaje na pozycji " << number << ". Ilość wierzchołków " << vertexList.size() << endl;
	}

	virtual void insertEdge(int start, int end, int data) {
		shared_ptr<Edge> edge =
				make_shared<Edge> (vertexList[start], vertexList[end], data);
		edgeList.push_back(edge);

		shared_ptr<ListNode> elem = make_shared<ListNode>();
		elem->weight = data;
		elem->numVertex = end;
		elem->next = adjList[start];
		adjList[start] = elem;
		//		(adjList[start]).push_back(edge);
		//		(adjList[end]).push_back(edge); // odkomentuj to a dostaniesz graf nieskierowany

		//		edge->setAdjRefs(make_shared<vector < shared_ptr<Edge>>>(adjList[start]), make_shared<vector < shared_ptr<Edge>>>(adjList[end]));
	}

	void setStartVertex(int num) {
		startVertex = num;
	}


	// file IO

	void saveGraphToFile(string filename) {
		ofstream file;
		file.open(filename);

		file << vertexList.size() << "\t" << edgeList.size() << "\t" << 0 << "\n"; // zapisywanie początkowych wartości dla grafu
		for (shared_ptr<Edge> edge : edgeList)
			file << edge->getStart()->getIndex() << "\t" << edge->getEnd()->getIndex() << "\t" << edge->getWeight() << "\n"; // wypisywanie krawędzi

		file.close();
	}

	bool readGraphFromFile(string filename) {
		cout << "Rozpoczynam czytanie z pliku" << endl;
		ifstream file;
		file.open(filename);

		ofstream log;
		log.open("log.txt");

		string data;
		int num1, num2, num3, ilosc_krawedzi; // jakieś zmienne pomocnicze
		if (!getline(file, data, '\t')) // prezerwatywa jakby pliku nie było
			return false;

		num1 = stoi(data);
		getline(file, data, '\t');
		num2 = stoi(data);
		reserveMemory(num1, num2); // rezerwacja pamięci dla zadanych ilości wierzchołków i krawędzi
		log << num1 << " wierzchołków, " << num2 << " krawędzi, " << endl;

		getline(file, data);
		num1 = stoi(data);
		setStartVertex(num1); // ustawianie wierzchołka startowego
		log << "startowy - " << num1 << endl;

		ilosc_krawedzi = num2;
		for (; ilosc_krawedzi > 0; ilosc_krawedzi--) { // czytanie kolejnych krawędzi z pliku
			log << "Czytanie krawędzi nr. " << ilosc_krawedzi << endl;

			// czytanie pierwszego wierzchołka
			getline(file, data, '\t');
			num1 = stoi(data);
			if (!checkIfVertexExists(num1)) {
				insertVertexOnIndex(num1); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób
			}
			// czytanie drugiego wierzchołka
			getline(file, data, '\t');
			num2 = stoi(data);
			if (!checkIfVertexExists(num2)) {
				insertVertexOnIndex(num2); // jeśli ten wierzchołek jeszcze nie istnieje to go zrób
			}

			// czytanie wagi krawędzi
			getline(file, data, '\n');
			num3 = stoi(data);

			insertEdge(num1, num2, num3); // dodawanie nowej krawędzi
		}

		log.close();
		file.close();
		cout << "Czytanie z pliku zakończone" << endl;
		return true;
	}
	// gettery

	shared_ptr<Vertex> getVertex(int index) {
		return vertexList[index];
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

		for (int i = 0; i < vertexList.size(); i++) {
			auto elem = adjList[i];
			cout << i << ".";
			while (elem) {
				cout << elem->numVertex << "$" << elem->weight << "\t";
				elem = elem->next;
			}
			cout << endl;
		}
	}

	// Algorytm Bellmana-Forda

	double FBFindWay() {
		chrono::high_resolution_clock Clock;
		auto Start = Clock.now();

		int n = vertexList.size();
		shared_ptr<ListNode> somsiad;

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

			auto somsiad = adjList[i];
			while (somsiad) {
				if (wayPrices[somsiad->numVertex] > wayPrices[i] + somsiad->weight) { // sprawdzanie czy tędy nie będzie taniej dojść
					// tutaj jest taniej więc aktualizuje cenę drogi do tego wierzchołka
					wayPrices[somsiad->numVertex] = wayPrices[i] + somsiad->weight;
					rodaStops[somsiad->numVertex] = i;
				}
				somsiad = somsiad->next;
			}
		}

		auto End = Clock.now();
		cout << "Time from List: " << chrono::duration<double>(End - Start).count() << endl;
		return chrono::duration<double>(End - Start).count();
	}

	void saveWayPrices(string filename) {
		// wypisywanie do konsoli wyniku
		//		cout << endl << "Najkrótsze drogi to: " << endl;
				//for (int i = 0; i < wayPrices.size(); i++)
		//			coute << i << ") " << wayPrices[i] << endl;

		ofstream file;
		file.open(filename);
		int p = 0;
		for (int i = 0; i < wayPrices.size(); i++) {
			file << startVertex << "-" << i << "\t" << wayPrices[i] << "\t";

			int p = rodaStops[i];
			while (p) {
				file << p << ", ";
				p = rodaStops[p];
			}
			file << endl;
		}

		file.close();
	}

	void addResultToFile(double duration) {
		fstream file;

		file.open("results.csv", ios::app);
		file << setprecision(6);
		file << "List\t" << numAllVertices << "\t" << density * 100 << "%\t" << duration << endl;

		file.close();
	}
};


#endif /* LISTGRAPH_H */

