
/* 
 * File:   PriorityPriorityQueue.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 18:52
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include  <memory>
#include  "PriorityNode.h"

using namespace std;

template<typename T>
class PriorityQueue {
protected:
	shared_ptr<PriorityNode<T>> head;
	unsigned int counter;

	shared_ptr<PriorityNode<T>> getBeforeLastNode() {
		if (head == nullptr)
			return nullptr;
		shared_ptr<PriorityNode < T>> start = head;

		while (start->getNextNode() != nullptr && start->getNextNode()->getNextNode() != nullptr)
			start = start->getNextNode();
		return start;
	}
public:

	PriorityQueue() {
		head = nullptr;
		counter = 0;
	}

	~PriorityQueue() {
		head = nullptr;
	}

	PriorityQueue(const PriorityQueue<T>* source) {
		head = source.head;
		counter = source.counter;
	}

	PriorityQueue<T>& operator=(PriorityQueue<T> other) {
		head = other.head;
		counter = other.counter;
		return *this;
	}

	void enqueue(const T & newData, int priority) {
		shared_ptr<PriorityNode < T >> elem(new PriorityNode<T>(newData, priority));
		if (head != nullptr) {
			if (head->getNextNode() != nullptr
					&& head->getNextNode()->getPriority() < priority) {
				elem->setNextNode(head);
				head = elem;
			} else {
				shared_ptr<PriorityNode < T >> start = head;
				while (
						start->getNextNode() != nullptr
						&& start->getNextNode()->getPriority() >= priority
						) {
					cout << "#######Następny większy" << endl;
					start = start->getNextNode();
				}

				elem->setNextNode(start->getNextNode());
				start->setNextNode(elem);
			}
		} else {
			elem->setNextNode(head);
			head = elem;
		}
		counter++;
	}

	T dequeue() {
		if (head != nullptr) {
			T data;
			shared_ptr<PriorityNode < T >> beforeLast = this->getBeforeLastNode();
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
			cout << "PriorityQueue is empty" << endl;
			return 0; // throw exception
		}
	}

	void printAllNodes() {
		if (head == nullptr)
			cout << "PriorityQueue is empty" << endl;
		else {
			shared_ptr<PriorityNode < T>> start = head;
			int count = counter;
			while (start->getNextNode() != nullptr) {
				cout << count << ". " << start->getData() << " --- " << start->getPriority() << endl;
				start = start->getNextNode();
				count--;
			}
			cout << count << ". " << start->getData() << " --- " << start->getPriority() << endl;
		}
	}

	bool isEmpty() {
		return counter < 1;
	}
};


#endif /* PRIORITYQUEUE_H */

