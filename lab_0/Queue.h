/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 12:56
 */

#ifndef QUEUE_H
#define QUEUE_H


#include  <memory>
#include  "Node.h"

using namespace std;

template<typename T>
class Queue {
protected:
	shared_ptr<Node<T>> head;
	unsigned int counter;

	shared_ptr<Node<T>> getBeforeLastNode() {
		if (head == nullptr)
			return nullptr;
		shared_ptr<Node < T>> start = head;

		while (start->getNextNode() != nullptr && start->getNextNode()->getNextNode() != nullptr)
			start = start->getNextNode();
		return start;
	}
public:

	Queue() {
		head = nullptr;
		counter = 0;
	}

	~Queue() {
		head = nullptr;
	}

	Queue(const Queue<T>* source) {
		head = source.head;
		counter = source.counter;
	}

	Queue<T>& operator=(Queue<T> other) {
		head = other.head;
		counter = other.counter;
		return *this;
	}

	void enqueue(const T & newData) {
		shared_ptr<Node < T >> elem(new Node<T>(newData));
		elem->setNextNode(head);
		head = elem;
		counter++;
	}

	T dequeue() {
		if (head != nullptr) {
			T data;
			shared_ptr<Node < T >> beforeLast = this->getBeforeLastNode();
			if (beforeLast->getNextNode() == nullptr) {
				data = head->getData();
				head = nullptr;
			} else {
				data = beforeLast->getNextNode()->getData();
				beforeLast->setNextNode(nullptr);
			}
			counter--;
			return data;
		} else {
			cout << "Queue is empty" << endl;
			return 0; // throw exception
		}
	}

	void printAllNodes() {
		if (head == nullptr)
			cout << "Queue is empty" << endl;
		else {
			shared_ptr<Node < T>> start = head;
			int count = counter;
			while (start->getNextNode() != nullptr) {
				cout << count << ". " << start->getData() << endl;
				start = start->getNextNode();
				count--;
			}
			cout << count << ". " << start->getData() << endl;
		}
	}

	bool isEmpty() {
		return counter < 1;
	}
};


#endif /* QUEUE_H */

