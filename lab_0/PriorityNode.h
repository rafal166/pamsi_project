
/* 
 * File:   PriorityNode.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 18:59
 */

#ifndef PRIORITYNODE_H
#define PRIORITYNODE_H

#include  <memory>

template<typename T>
class PriorityNode {
protected:
	T data;
	std::shared_ptr<PriorityNode<T>> next = nullptr;
	unsigned int priority;

public:

	PriorityNode(const T& newData, int newPriority) : data(newData) {
		priority = newPriority;
	}

	~PriorityNode() {
	}

	std::shared_ptr<PriorityNode<T>> getNextNode() {
		return next;
	}

	T& getData() {
		return data;
	}

	void setNextNode(std::shared_ptr<PriorityNode<T>> newNext) {
		next = newNext;
	}

	void setPriority(int newPriority) {
		priority = newPriority;
	}

	int getPriority() {
		return priority;
	}

};

#endif /* PRIORITYNODE_H */

