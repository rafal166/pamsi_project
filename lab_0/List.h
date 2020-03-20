
/* 
 * File:   List.h
 * Author: rafal
 *
 * Created on 18 marca 2020, 14:53
 */

#ifndef LIST_H
#define LIST_H
#include  <memory>
#include  "Node.h"
#include  "ListIterator.h"
#include  "ListIteratorConst.h"

using namespace std;

template<typename T>
class List {
protected:
	shared_ptr<Node<T>> head;
	unsigned int counter;

	shared_ptr<Node<T>> getLastNode() {
		if (head == nullptr)
			return nullptr;
		shared_ptr<Node < T>> start = head;

		while (start->getNextNode() != nullptr)
			start = start->getNextNode();
		return start;
	}
public:

	List() {
		head = nullptr;
		counter = 0;
	}

	~List() {
		head = nullptr;
	}

	List(const List<T>* source) {
		head = source.head;
		counter = source.counter;
	}

	List<T>& operator=(List<T> other) {
		head = other.head;
		counter = other.counter;
		return *this;
	}

	void pushBack(const T & newData) {
		shared_ptr<Node < T >> last = this->getLastNode();
		shared_ptr<Node < T >> elem(new Node<T>(newData));

		if (head != nullptr)
			last->setNextNode(elem);
		else
			head = elem;

		counter++;
	}

	void pushFront(const T & newData) {
		shared_ptr<Node < T >> elem(new Node<T>(newData));
		elem->setNextNode(head);
		head = elem;
		counter++;
	}

	void insert(const T& newData, int index) {
		if (index <= 0)
			pushFront(newData);
		else
			if (index > counter)
			pushBack(newData);
		else {
			int count = 0;
			shared_ptr<Node < T>> start = head;

			while (count != (index - 1)) {
				start = start->getNextNode();
				++count;
			}

			shared_ptr<Node < T >> elem(new Node<T>(newData));
			elem->setNextNode(start->getNextNode());
			start->setNextNode(elem);
			counter++;
		}
	}

	void remove(const T & element) {
		if (head != nullptr) {
			shared_ptr<Node < T >> start = head;
			shared_ptr<Node < T >> prev = nullptr;

			while (start != nullptr) {
				if (start->getData() == element) {
					if (prev == nullptr)
						head = start->getNextNode();
					else
						prev->setNextNode(start->getNextNode());
				} else {
					prev = start;
				}
				start = start->getNextNode();
			}
			counter--;
		}
	}

	T& operator[](int index) {
		if (index < 0 || index > counter)
			index = 0; // throw exception ale trzeba by to dopisać.
		int count = 0;
		shared_ptr<Node < T>> start = head;

		while (count < index) {
			start = start->getNextNode();
			++count;
		}
		return start->getData();
	}

	void printAllNodes() {
		if (head == nullptr)
			cout << "List is empty" << endl;
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
	// Iterator Methods

	ListIterator<T> begin() {
		ListIterator<T> iter_new(head);
		return iter_new;
	}

	ListIterator<T> end() {
		ListIterator<T> iter_new(nullptr);
		return iter_new;
	}

	ListIteratorConst<T> cbegin() const {
		ListIteratorConst<T> iter_new(head);
		return iter_new;
	}

	ListIteratorConst<T> cend() const {
		ListIteratorConst<T> iter_new(nullptr);
		return iter_new;
	}


};




#endif /* LIST_H */

