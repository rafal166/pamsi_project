
/* 
 * File:   ListIteratorConst.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 11:07
 */

#ifndef LISTITERATORCONST_H
#define LISTITERATORCONST_H

#include <iostream>
#include  <memory>
#include  "Node.h"


using namespace std;

template <class T> class ListIteratorConst : public iterator <forward_iterator_tag, Node<T>>
{
	shared_ptr<Node < T >> ptr = nullptr;
	public:
	using difference_type = std::size_t;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	using iterator_category = std::forward_iterator_tag;

	// Constructors and Copy Operators

	ListIteratorConst<T>(shared_ptr<Node < T >> p) {
		ptr = p;
	}

	ListIteratorConst<T>(const ListIteratorConst<T>* source) {
		ptr = source->ptr;
	}

	ListIteratorConst<T>& operator=(const ListIteratorConst<T> other);

	// Increment Operators
	ListIteratorConst<T>& operator++();
	ListIteratorConst<T> operator++(int);


	// Comparison Operators
	bool operator==(ListIteratorConst<T> other);
	bool operator!=(ListIteratorConst<T> other);

	// Dereference Operators
	const T& operator*();
	const T& operator->();
};

template <typename T >
ListIteratorConst<T>& ListIteratorConst<T>::operator=(ListIteratorConst<T> other) {
	ptr = other.ptr;
	return *this;
}

// Increment Operators

template <typename T >
ListIteratorConst<T>& ListIteratorConst<T>::operator++() {
	ptr = ptr->getNextNode();
	return *this;
}

template <class T >
ListIteratorConst<T> ListIteratorConst<T>::operator++(int) {
	ListIteratorConst<T> copy(this);
	ptr = ptr->getNextNode();
	return copy;
}


// Comparison Operators

template <typename T >
bool ListIteratorConst<T>::operator==(ListIteratorConst<T> other) {
	return ptr == other.ptr;
}

template <typename T >
bool ListIteratorConst<T>::operator!=(ListIteratorConst<T> other) {
	cout << "!=" << endl;
	return true;
	//		return ptr != other.ptr;
}

// Dereference Operators

template <class T >
const T& ListIteratorConst<T>::operator*() {
	return ptr->getData();
}

template <typename T >
const T& ListIteratorConst<T>::operator->() {
	return ptr->getData();
}

#endif /* LISTITERATOR_H */

