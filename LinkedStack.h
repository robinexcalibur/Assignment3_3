/*
 * LinkedStack.h
 *
 *  Created on: Oct 30, 2017
 *      Author: Robin
 *
 *      Sources:
 *      https://stackoverflow.com/questions/9438209/for-every-character-in-string
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;


//LinkedStack.h
template <class T>
struct node{
   T data;
   node<T>* next;
};

template <class T>
class LinkedStack{
     node<T> *top;
     int count;
  public:
    LinkedStack();
    LinkedStack(T&);
 	bool isEmpty();
 	void push(T&);
 	T pop();
 	T peek();
 	void destroy();
 	~LinkedStack();
};
//provide function implementations here

template <class T>
LinkedStack<T>::LinkedStack() {
	top = NULL;
	count = 0;
}

template <class T>
LinkedStack<T>::LinkedStack(T& item) {
	top = NULL;
	count = 1;
	top->data = item;
}

template <class T>
bool LinkedStack<T>::isEmpty() {
	return count == 0;
}

template <class T>
void LinkedStack<T>::push(T& item) {
	node<T> *temp = new node<T>;
	temp->data = item;
	temp->next = top;
	top = temp;
	++count;
}

template <class T>
T LinkedStack<T>::pop() {
	if(!isEmpty()) {
		node<T> *temp = new node<T>;
		temp->data = top->data;
		top = top->next;
		--count;
		return temp->data;
	} else {
		cout << "Stack is empty." << endl;
		return top->data;
	}
}

template <class T>
T LinkedStack<T>::peek() {
	return top->data;
}

template <class T>
void LinkedStack<T>::destroy() {
	top = NULL;
	top->data = NULL;
}

template <class T>
LinkedStack<T>::~LinkedStack() {
	node<T> *temp = new node<T>;
	while (top == NULL) {
		temp = top;
		top = top->next;
		delete temp;
	}
	delete top;
}

#endif /* LINKEDSTACK_H_ */
