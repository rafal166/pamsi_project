/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Map.h
 * Author: rafal
 *
 * Created on 20 marca 2020, 11:17
 */

#ifndef MAP_H
#define MAP_H

//#include  <memory>

using namespace std;

template<typename KeyType, typename ValueType>
class Map {
protected:
	static const unsigned int capacity = 100;
	ValueType container[capacity];

public:

	Map() {
		for (int i = 0; i < capacity; i++)
			container[i] = "";
	}

	~Map() {
		for (int i = 0; i < capacity; i++)
			if (container[i] != "")
				delete &container[i];
	}

	Map(const Map<KeyType, ValueType>* other) {
		for (int i = 0; i < capacity; i++)
			container[i] = other->container[i];
	}

	Map<KeyType, ValueType>& operator=(Map<KeyType, ValueType> other) {
		for (int i = 0; i < capacity; i++)
			container[i] = other->container;
	}

	int hash(const KeyType& key) {
		unsigned int sum = 0;
		string tmpKey = key;
		for (char& c : tmpKey)
			sum += int(c);
		return sum % capacity;
	}

	void insert(const KeyType& key, const ValueType& value) {
		container[hash(key)] = value;
	}

	void remove(const KeyType& key) {
		container[hash(key)] = "";
	}

	ValueType& operator()(const KeyType& key) {
		return container[hash(key)];
	}

	void printAll() {
		for (int i = 0; i < capacity; i++)
			if (container[i] != "")
				cout << "Hasz: " << i << "; Wartość: " << container[i] << endl;
	};
};


#endif /* MAP_H */

