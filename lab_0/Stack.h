
/* 
 * File:   Stack.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 12:39
 */

#ifndef STACK_H
#define STACK_H


#include  <memory>
#include  "Node.h"

using namespace std;

template<typename T>
class Stack {
protected:
	shared_ptr<Node<T>> head;
	unsigned int counter;

public:

	Stack() {
		head = nullptr;
		counter = 0;
	}

	~Stack() {
		head = nullptr;
	}

	Stack(const Stack<T>* source) {
		head = source.head;
		counter = source.counter;
	}

	Stack<T>& operator=(Stack<T> other) {
		head = other.head;
		counter = other.counter;
		return *this;
	}

	void push(const T & newData) {
		shared_ptr<Node < T >> elem(new Node<T>(newData));
		elem->setNextNode(head);
		head = elem;
		counter++;
	}

	T pop() {
		if (head == nullptr) {
			cout << "Stack is empty" << endl;
			return 0;
		} else {
			shared_ptr<Node < T >> start = head;
			head = start->getNextNode();
			counter--;
			return start->getData();
		}
	}

	void printAllNodes() {
		if (head == nullptr)
			cout << "Stack is empty" << endl;
		else {
			shared_ptr<Node < T>> start = head;
			int count = 1;
			while (start->getNextNode() != nullptr) {
				cout << count << ". " << start->getData() << endl;
				start = start->getNextNode();
				count++;
			}
			cout << count << ". " << start->getData() << endl;
		}
	}

	bool isEmpty() {
		return counter < 1;
	}



};



#endif /* STACK_H */

