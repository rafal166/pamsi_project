
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
};


#endif /* EDGE_H */

