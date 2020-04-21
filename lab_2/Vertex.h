
/* 
 * File:   Vertex.h
 * Author: rafal
 *
 * Created on 15 kwietnia 2020, 20:05
 */

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
protected:
	unsigned int index;
public:

	Vertex(int newIndex) {
		index = newIndex;
	}

	int getIndex() {
		return index;
	}
};


#endif /* VERTEX_H */

