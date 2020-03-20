/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: rafal
 *
 * Created on 17 marca 2020, 19:58
 */

#ifndef ELEMLIST_H
#define ELEMLIST_H

#include  <memory>
template<typename T>
class Node {
protected:
	T data;
	std::shared_ptr<Node<T>> next = nullptr;

public:

	Node(const T& newData) : data(newData) {
	}

	~Node() {
	}

	std::shared_ptr<Node<T>> getNextNode() {
		return next;
	}

	T& getData() {
		return data;
	}

	void setNextNode(std::shared_ptr<Node<T>> newNext) {
		next = newNext;
	}

};

#endif /* ELEMLIST_H */

