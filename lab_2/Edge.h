
/* 
 * File:   Edge.h
 * Author: rafal
 *
 * Created on 15 kwietnia 2020, 20:07
 */

#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"
#include <vector>
#include <memory>

using namespace std;

class Edge {
protected:
	shared_ptr<Vertex> start, end;
	int weight;
	//	shared_ptr<vector<shared_ptr<Edge>>> refToAdjListStart, refToAdjListEnd;
public:

	Edge(shared_ptr<Vertex> newStart, shared_ptr<Vertex> newEnd, int newWeight) {
		start = newStart;
		end = newEnd;
		weight = newWeight;
	}

	shared_ptr<Vertex> getStart() {
		return start;
	}

	shared_ptr<Vertex> getEnd() {
		return end;
	}

	int getWeight() {
		return weight;
	}

	//	void setAdjRefs(shared_ptr<vector<shared_ptr<Edge>>> startAdjRef, shared_ptr<vector<shared_ptr<Edge>>> endAdjRef) {
	//		refToAdjListStart = startAdjRef;
	//		refToAdjListEnd = endAdjRef;
	//		//		cout << endl << ((*refToAdjListEnd) [0])->getData();
	//	}

};


#endif /* EDGE_H */

