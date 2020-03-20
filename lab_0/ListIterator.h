
/* 
 * File:   ListIterator.h
 * Author: rafal
 *
 * Created on 19 marca 2020, 10:27
 */

#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include <iostream>
#include  <memory>
#include  "Node.h"


using namespace std;

template <class T> class ListIterator : public iterator <forward_iterator_tag, Node<T>>
{
	shared_ptr<Node < T >> ptr = nullptr;
	public:
	using difference_type = std::size_t;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	using iterator_category = std::forward_iterator_tag;

	// Constructors and Copy Operators

	ListIterator<T>(shared_ptr<Node < T >> p);
	ListIterator<T>(const ListIterator<T>* source);
	ListIterator<T>& operator=(const ListIterator<T> other);

	// Increment Operators
	ListIterator<T>& operator++();
	ListIterator<T> operator++(int);


	// Comparison Operators
	bool operator==(ListIterator<T> other);
	bool operator!=(ListIterator<T> other);

	// Dereference Operators
	T& operator*();
	T& operator->();
};

template <typename T >
ListIterator<T>::ListIterator(shared_ptr<Node < T >> p) {
	ptr = p;
}

template <typename T >
ListIterator<T>::ListIterator(const ListIterator<T>* source) {
	ptr = source->ptr;
}

template <typename T >
ListIterator<T>& ListIterator<T>::operator=(ListIterator<T> other) {
	ptr = other.ptr;
	return *this;
}

// Increment Operators

template <typename T >
ListIterator<T>& ListIterator<T>::operator++() {
	ptr = ptr->getNextNode();
	return *this;
}

template <class T >
ListIterator<T> ListIterator<T>::operator++(int) {
	ListIterator<T> copy(this);
	ptr = ptr->getNextNode();
	return copy;
}


// Comparison Operators

template <typename T >
bool ListIterator<T>::operator==(ListIterator<T> other) {
	return ptr == other.ptr;
}

template <typename T >
bool ListIterator<T>::operator!=(ListIterator<T> other) {
	return ptr != other.ptr;
}


// Dereference Operators

template <class T >
T& ListIterator<T>::operator*() {
	return ptr->getData();
}

template <typename T >
T& ListIterator<T>::operator->() {
	return ptr->getData();
}

#endif /* LISTITERATOR_H */

