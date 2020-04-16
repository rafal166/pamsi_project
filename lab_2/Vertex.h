
/* 
 * File:   Vertex.h
 * Author: rafal
 *
 * Created on 15 kwietnia 2020, 20:05
 */

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

template <typename T_vertex>
class Vertex {
protected:
	T_vertex data;
	unsigned int index;
public:

	Vertex(int newIndex) {
		index = newIndex;
	}

	T_vertex getData() {
		return data;
	}

	int getIndex() {
		return index;
	}
};


#endif /* VERTEX_H */

