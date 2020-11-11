#include <iostream>
#include "Student.h"
#pragma once
using namespace std;

template <class T>
class DLListNode
{
public:
	DLListNode();
	DLListNode(T*);
	~DLListNode();
	DLListNode *next;
	DLListNode *prev;
	T *data;
};

template <class T>
DLListNode<T>::DLListNode()
{
	next = NULL;
	prev = NULL;
}

template <class T>
DLListNode<T>::DLListNode(T* d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

template <class T>
DLListNode<T>::~DLListNode()
{
}

template <class T>
class Queue
{
private:
	DLListNode<T> *front;
	DLListNode<T> *back;
	unsigned int size;
public:
	Queue();
	~Queue();
	void insertFront(T*);
	void insertBack(T* student);
	T removeFront();
	T removeBack();
	T find(T*);
	T deletePos(int);

	void printList();
	bool isEmpty();
	unsigned int getSize();
};

template <class T>
Queue<T>::Queue()
{
	front = NULL;
	back = NULL;
	size = 0;
}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::insertFront(T *data)
{
	DLListNode<Student> *node = new DLListNode<Student>(data);
	if (size == 0) {
		back = node;
		front = node;
	}
	else {
		node->next = front;
		front->prev = node;
		front = node;
	}
	++size;
}

template <class T>
void Queue<T>::insertBack(T* student)
{
	DLListNode<Student*> *node = new DLListNode<Student*>(student);
	if (size == 0) {
		back = node;
		front = node;
	}
	else {
		node->prev = back;
		back->next = node;
		back = node;
	}
	++size;
}

template <class T>
T Queue<T>::removeFront()
{
	if (isEmpty()) {
		return NULL;
	}
	T data = front->data;
	front = front->next;
	front->prev = NULL;
	return data;
}

template <class T>
T Queue<T>::removeBack()
{
	if (isEmpty()) {
		return NULL;
	}
	T data = back->data;
	back = back->prev;
	back->next = NULL;
	return data;
}

template <class T>
T Queue<T>::find(T* d)
{
	DLListNode *current = front;
	while (current->next != NULL) {
		if (current->data == d) {
			T data = current->data;
			return data;
		}
		else {
			current = current->next;
		}
	}
	cout << d << " not found in list\n";
	return NULL;
}

template <class T>
T Queue<T>::deletePos(int pos)
{
	if (pos >= size || pos < 0) {
		cout << "That node doesn't exist\n";
		return NULL;
	}
	else if (pos == 0) {
		removeFront();
		size--;
	}
	else if (pos == (size - 1)) {
		removeBack();
		size--;
	}
	else {
		int p = 0;
		DLListNode<Student> *current = front;
		DLListNode<Student> *prevN = front;
		DLListNode<Student> *nextN = front->next;

		while (p != pos) {
			prevN = current;
			current = current->next;
			nextN = current->next;
			p++;
		}
		prevN->next = nextN;
		nextN->prev = prevN;
		current->next = NULL;
		current->prev = NULL;
		T temp = current->data;
		size--;
		return temp;
	}
}

template <class T>
void Queue<T>::printList()
{
	if (isEmpty()) {
		cout << "Empty List\n";
	}
	else {
		DLListNode<Student> *current = front;
		while (current != NULL) {
			cout << current << " ";
			current = current->next;
		}
		cout << endl;
	}
}

template <class T>
bool Queue<T>::isEmpty()
{
	return(front == NULL && back == NULL);
}

template <class T>
unsigned int Queue<T>::getSize()
{
	return size;
}

