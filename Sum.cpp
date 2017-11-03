/*
 * Sum.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: Robin
 */

#include "LinkedStack.h"
#include <iostream>
using namespace std;


int main() {
	LinkedStack<char> *first = new LinkedStack<char>;
	LinkedStack<char> *second = new LinkedStack<char>;
	LinkedStack<int> *third = new LinkedStack<int>;
	string holder;
	int a, b, c;
	bool ten = false;

	//build first:
	cout << "Please enter a number: ";
	cin >> holder;
	for(char& c : holder) {
	    first->push(c);
	}

	//build second:
	cout << "Please enter a number: ";
	cin >> holder;
	for(char& c : holder) {
	    second->push(c);
	}

	//start sum:
	cout << "Sum: ";
	while (!first->isEmpty() || !second->isEmpty()) {
		//one number has more digits than the other:
		if (first->isEmpty() == true) {
			while (!second->isEmpty()) {
				c = second->pop() - '0';
				third->push(c);
			}
			break;
		} else if (second->isEmpty() == true) {
			while (!first->isEmpty()) {
				c = first->pop() - '0';
				third->push(c);
			}
			break;
		}
		a = first->pop() - '0';
		b = second->pop() - '0';
		//start adding
		if (ten == false) {
			if (a + b > 9) {
				ten = true;
				c = (a + b)%10;
				third->push(c);
			} else {
				ten = false;
				c = a + b;
				third->push(c);
			}
		} else { //carry the 1
			if (a + b + 1 > 9) {
				ten = true;
				c = (a + b)%10;
				third->push(c);
			} else {
				ten = false;
				c = a + b + 1;
				third->push(c);
			}
		}
	}
	if (ten == true) {
		c = 1;
		third->push(c);
	}
	while (!third->isEmpty()) {
		cout << third->pop();
	}
}


