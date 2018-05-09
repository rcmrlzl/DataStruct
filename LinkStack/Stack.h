#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node *next;
	Node(const T &d) :data(d), next(NULL) {}
};

template<class T>
class Stack {
public:
	Stack() { top = NULL; };
	~Stack() { clear(); };
	bool push(T val);
	bool pop();
	bool clear();
	bool isEmpty() { return top==NULL; };
	T getTop();
	
private:
	Node<T> *top;
	
};

template<class T>
bool Stack<T>::push(T val) {
	Node<T> *pnode = new Node<T>(val);
	pnode->next = top;
	top = pnode;
	return true;
}

template<class T>
bool Stack<T>::pop() {
	if (isEmpty()) {
		cout << "error:the stack popped is empty!!" << endl;
		return false;
	}
	Node<T> *pnode = top->next;
	delete top;
	top = pnode;
}

template<class T>
T Stack<T>::getTop() {
	if (isEmpty()) {
		cout << "error:the stack get is empty!!" << endl;
		return false;
	}
	return top->data;
}

template<class T>
bool Stack<T>::clear() {
	if (isEmpty()) {
		cout << "error:the stack cleared is empty!!" << endl;
		return false;
	}
	else {
		while (top != NULL) {
			Node<T> *pnode = top->next;
			delete top;
			top = pnode;
		}
		return true;
	}
}