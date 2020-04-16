
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

template <typename T_vertex, typename T_edge>
class Edge {
protected:
	shared_ptr<Vertex < T_vertex>> start, end;
	T_edge weight;
	shared_ptr<vector<shared_ptr<Edge<T_vertex, T_edge>>>> refToAdjListStart, refToAdjListEnd;
public:

	Edge(shared_ptr<Vertex < T_vertex>> newStart, shared_ptr<Vertex < T_vertex>> newEnd, T_edge newWeight) {
		start = newStart;
		end = newEnd;
		weight = newWeight;
	}

	shared_ptr<Vertex < T_vertex>> getStart() {
		return start;
	}

	shared_ptr<Vertex < T_vertex>> getEnd() {
		return end;
	}

	T_edge getWeight() {
		return weight;
	}

	void setAdjRefs(shared_ptr<vector<shared_ptr<Edge<T_vertex, T_edge>>>> startAdjRef, shared_ptr<vector<shared_ptr<Edge<T_vertex, T_edge>>>> endAdjRef) {
		refToAdjListStart = startAdjRef;
		refToAdjListEnd = endAdjRef;
		//		cout << endl << ((*refToAdjListEnd) [0])->getData();
	}
	
};


#endif /* EDGE_H */

