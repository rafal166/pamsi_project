
/* 
 * File:   GraphGenerator.h
 * Author: rafal
 *
 * Created on 16 kwietnia 2020, 17:40
 */


#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H


#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#define FLAG_IF_EDGE_EXISTS 1
#define FLAG_IF_EDGE_NOT_EXISTS -1
#define EDGE_WEIGHT_RANGE_LOW 1
#define EDGE_WEIGHT_RANGE_HIGH 100

using namespace std;

class GraphGenerator {
protected:
	vector<int> vertices;
	vector<vector<int>> edges;
	int startVertice, numAllEdges;

	int getRandomWeight() {
		return rand() % EDGE_WEIGHT_RANGE_HIGH + EDGE_WEIGHT_RANGE_LOW;
	}

	bool checkIfEdgeExists(int start, int end = FLAG_IF_EDGE_NOT_EXISTS) {
		if (edges[start][end] == FLAG_IF_EDGE_EXISTS)
			return true;
		return false;
	}
public:

	GraphGenerator() {
		srand((unsigned) time(NULL));
	}

	void generateGraph(int numVertices, double graphDensity = 0, int startVert = 0, bool consistent = true, string fileName = "") {

		int numEdges = (graphDensity > 0) ? numVertices * (numVertices - 1) * graphDensity : 0;
		int finalNumEdges = consistent ? numEdges - numVertices : numEdges;
		int tmpStart, tmpEnd = 1;
		bool succes;
		vector<int> tmpVec;
		cout << "numEdges: " << numEdges << endl;
		startVertice = startVert;
		numAllEdges = numEdges;
		vertices.reserve(numVertices);
		edges.reserve(numVertices);

		for (int i = 0; i < numVertices; i++) {
			vertices.push_back(i);
			tmpVec.push_back(FLAG_IF_EDGE_NOT_EXISTS);
		}
		for (int i = 0; i < numVertices; i++)
			edges.push_back(tmpVec);

		if (consistent)
			for (int i = 0; i < numVertices; i++) {
				tmpEnd = (i + 1 >= numVertices) ? 0 : i + 1;
				edges[i][tmpEnd] = FLAG_IF_EDGE_EXISTS;
			}

		for (int i = 0; i < finalNumEdges; i++) {
			if (!i)
				tmpStart = startVertice;
			else
				tmpStart = succes ? (rand() % numVertices) : (++tmpStart > numVertices - 1) ? 0 : tmpStart;
			tmpEnd = rand() % numVertices;

			if (tmpStart == tmpEnd) {
				--i;
				continue;
			}
			succes = false;
			for (int j = 0; j < 100; j++) {
				if (!checkIfEdgeExists(tmpStart, tmpEnd)) {
					edges[tmpStart][tmpEnd] = FLAG_IF_EDGE_EXISTS;
					break;
				} else if (++tmpEnd > numVertices - 1)
					tmpEnd = 0;
			}
		}

		if (fileName.length())
			saveGraphToFile(fileName);
	}

	void saveGraphToFile(string filename) {
		ofstream file;
		file.open(filename);


		file << vertices.size() << "\t" << numAllEdges << "\t" << startVertice << "\n"; // zapisywanie początkowych wartości dla grafu
		for (int i = 0; i < edges.size(); i++) {
			for (int j = 0; j < (edges[i]).size(); j++) {
				if (edges[i][j] < 0)
					continue;
				file << i << "\t" << j << "\t" << getRandomWeight() << "\n"; // wypisywanie krawędzi
			}
		}

		file.close();
	}

};

#endif /* GRAPHGENERATOR_H */

