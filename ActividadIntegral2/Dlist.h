// =================================================================
//
// File: dlist.h
// Author: Andrea Piñeiro Cavazos
// Description: This file contains the implementation of a TDA Double
// Linked List
//
// =================================================================

#ifndef DLIST_H
#define DLIST_H

#include <string>
#include <sstream>
#include "exception.h"
#include "Data.h"

//template <class T> class DLink;
template <class T> class DList;

// =================================================================
// Definition of the Double Link class
// =================================================================

template <class T>
class DLink {
	private:
		DLink(T);
		DLink(T, DLink<T>*, DLink<T>*);

		T value;
		DLink<T> * next;
		DLink<T> * previous;

		friend class DList<T>;
};

// =================================================================
// Constructor. Initializes the value of double link. The variable 
// next and previous (pointers) is initialized to null.
// Complexity O(1)
// =================================================================
template <class T>
DLink<T>::DLink(T val) : value(val), next(0), previous(0) {}

// =================================================================
// Constructor. Initializes the value of double link, the value of 
// next and previous.
// Complexity O(1)
// =================================================================
template <class T>
DLink<T>::DLink(T val, DLink* nxt, DLink<T>* prev) : value(val), next(nxt), previous(prev) {}


// =================================================================
// Definition of the Double List class
// =================================================================
template <class T>
class DList {
	private:
		DLink<T> *head;
		DLink<T> *tail;
		void swap(int, int);

	public:
		DList();
		~DList();

		int size;
		void add(T) throw (OutOfMemory);
		int findFirst(int);
		int findLast(int);
		T get_obj(int) throw (IndexOutOfBounds);
		void update(int, T) throw (IndexOutOfBounds);
		void ordenaSeleccion();

		T remove(int) throw (IndexOutOfBounds);

		void clear();
		std::string toStringForward() const;
		std::string toStringBackward() const; 
};

// =================================================================
// Constructor. Initializes all variables to zero.
// Complexity O(1)
// =================================================================
template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

// =================================================================
// Destructor. Remove all items from the list.
// Complexity O(1) It only calls the clear function.
// =================================================================
template <class T>
DList<T>::~DList(){
	clear();
}

// =================================================================
// Adds an Double Link object to the list on the last position. 
// It receives an object.
// The function doesn't return anything.
// Complexity O(1)
// =================================================================
template <class T>
void DList<T>::add(T val) throw (OutOfMemory) {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	// If the list is empty, the head and tail of the list point to 
	// the new object. And "next" and "previous" ob newLink are set
	// to null.
	if (size == 0){
		newLink -> next = head;  
		newLink -> previous = tail;
		head = newLink;
		tail = newLink;
		size ++;
		return;
	}

	// If the list is not empty, "next" of newLink has to point towards
	// null and "previous" towards the tail of the list; so it points to 
	// the last object
	newLink -> next = 0;  
	newLink -> previous = tail;
	tail -> next = newLink;
	tail = newLink;
	size++;
}

// =================================================================
// Search an element of the list, by comparing each element with 
// the one received. It starts from the head.
// It uses 1 pointer, p moves forward starting form the head.
// The function returns the postion of the element
// Complexity O(n)
// =================================================================
template <class T>
int DList<T>::findFirst(int val) {
	DLink<T> *p;

	int cont = 0;
	p = head;
	while (p != 0){
		if (p -> value == val) {
			return cont ;
		}
		cont++;
		p = p -> next;
	}
	return -1;
}

// =================================================================
// Search an element of the list, by comparing each element with 
// the one received. It starts from the tail.
// It uses 1 pointer, p moves backwards starting from the tail.
// The function returns the postion of the element
// Complexity O(n)
// =================================================================

template <class T>
int DList<T>::findLast(int val) {
	DLink<T> *p;

	int cont = size - 1;
	p = tail;
	while (p != 0){
		if (p -> value == val) {
			return cont ;
		}
		cont--;
		p = p -> previous;
	}
	return -1;
}



// =================================================================
// Searchs an index in the list, and returns the object in it.
// It starts from the head if the index is closer to the beggining of 
// the list, or starts from the tail if it's closer to the end.
// Complexity O(n/2) -> O(n)
// =================================================================
template <class T>
T DList<T>::get_obj(int index) throw (IndexOutOfBounds){
	DLink<T> *p;
	int pos;
	T aux;

	if (index > size) {
		throw IndexOutOfBounds();
	}

	// If the index is closer to the beggining, the pointer p starts
	// from the head.
	if (index <= size - 1 / 2){
		p = head;
		pos = 0;
		// While the pointer doesn't points to null, if we've reached the
		// index we set the aux to be the object.
		while (p != 0){
			if (pos == index){
				aux = p -> value;
			}
			pos++;
			p = p -> next;
		}
	} else {
	// If the index is closer to the end the pointer starts from the end 
	// and moves backwards using previous. The position starts at size - 1.	
		p = tail;
		pos = size - 1;
		while (p != 0){
			if (pos == index){
				aux = p -> value;
			}
			pos--;
			p = p -> previous;
		}
	}
	return aux;
}


// =================================================================
// Updates the value of an element in the list, with the object and
// index received. 
// The function doesn't return anything
// It starts from the head if the index is closer to the beggining of 
// the list, or starts from the tail if it's closer to the end.
// Complexity O(n/2) -> O(n)
// =================================================================
template <class T>
void DList<T>::update(int index, T val) throw (IndexOutOfBounds) {
	DLink<T> *p;
	int pos;

	if (index > size) {
		throw OutOfMemory();
	}

	// If the index is closer to the beggining, the pointer p starts
	// from the head.
	if (index <= size - 1 / 2){
		p = head;
		pos = 0;
		// While the pointer doesn't points to null, if we've reached the
		// index we set the object's value to the value received.
		while (p != 0){
			if (pos == index){
				p -> value = val;
			}
			pos++;
			p = p -> next;
		}
	} else {
	// If the index is closer to the end the pointer starts from the end 
	// and moves backwards using previous. The position starts at size - 1.	
		p = tail;
		pos = size - 1;
		while (p != 0){
			if (pos == index){
				p -> value = val;
			}
			pos--;
			p = p -> previous;
		}
	}
}

// =================================================================
// It receives an index and removes the element in that position.
// The function returns the object removed.
// Complexity O(n)
// =================================================================
template <class T>
T DList<T>::remove(int index) throw (IndexOutOfBounds){
	T aux;
	DLink<T> *p, *q, *r;
	int pos;

	if (index > size) {
		throw IndexOutOfBounds();
	}

	if(index == 0) {
		if(head == 0 && tail == 0)
		{
			throw NoSuchElement();
		}
		p = head;
		aux = p -> value;
		if(head==tail)
		{
			head = 0;
			tail = 0;
		}
		else
		{
			head = p->next;
			head ->previous = 0;
		}
		delete p;
		size --;
		return aux;

	}

	// If the index is the last element in the list, the tail changes
	// to the previous element, and next points to 0.
	 else if (index == size - 1) {
		p = tail;
		aux = p -> value;
		tail = p -> previous;
		tail -> next = 0;
		delete p;

	} 

	else if (index < size-1 ){
    	p = head;
		for (int i = 1; i <= index; i++){
			if (index == i){
				q = p -> next;
				aux = q -> value;
				p -> next = q -> next;
				q -> next -> previous = q -> previous;
				delete q;
			} else {
				p = p -> next;
			}
		}	   
	}  
		

	size--;
	return aux;
}

// =================================================================
// Removes every element on the list.
// The function doesn't receive or return anything. It is used in the 
// destructor.
// Complexity O(n)
// =================================================================
template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p -> next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}


// =================================================================
// String representation of the elements in the list. The function 
// returns a string with the values of the elements
// Complexity O(n)
// =================================================================
template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";			}
			p = p->next;
		}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {	
	std::stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}


// =================================================================
// Implements the Selection sort algorithm. 
// It looks for the smallest element on the list and swaps it with 
// the first position.
// Complexity O(n^2)
// =================================================================
template <class T>
void DList<T>::ordenaSeleccion() {
	int pos;
	for (int i = 0; i < size - 1; i++){
		pos = i;
		for (int j = i + 1; j < size; j++){
			if (get_obj(j) < get_obj(pos)){
				pos = j;
			}
		}
		if (pos != i){
		swap(i, pos);
		}
	}
}


// =================================================================
// Swaps the information in 2 index
// It does not changes the pointers, only the objects. 
// Complexity O(1)
// =================================================================
template <class T>
void DList<T>::swap(int i, int j){
	if (i >= size) {
		throw IndexOutOfBounds();
	}
	if (j >= size) {
		throw IndexOutOfBounds();
	}	

	T temp;
	temp = get_obj(i);
	update(i, get_obj(j));
	update(j, temp);
}

#endif /* LIST_H */