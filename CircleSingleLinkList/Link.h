#pragma once
#include<iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node(const T &d) :data(d), next(NULL) {}
};

template<class T>
class Link {
public:
	Link() { head = NULL; rear = NULL; len = 0; };
	~Link() {};

	Node<T> *getPreNode(int pos) {
		Node<T> *prenode = head;
		for (int k = 1; k < pos - 1; k++) {
			prenode = prenode->next;
		}
		return prenode;
	}

	int getLen() { return len; };

	Node<T> *getHead() { return head; };
	Node<T> *getRear() { return rear; };

	bool insertAt(T val, int pos);
	bool insert(T val);

	bool delAt(int pos);
	bool del();

	bool updateVal(T val,int pos);

	Link<T> Merge(Link<T> l1, Link<T> l2);

	bool isEmpty() { return len == 0; };

	void showAll() {
		Node<T> *findNode = head;
		for (int k = 1; k <= len; k++) {
			cout << findNode->data << " ";
			findNode = findNode->next;
		}
		cout << endl;
	};

private:
	Node<T>* head;
	Node<T>* rear;
	int len;
};

template<class T>
bool Link<T>::insertAt(T val,int pos) {
	Node<T> *pnode = new Node<T>(val);
	if (isEmpty()) {
		head = pnode;
		rear = pnode;
		head->next = rear;
		rear->next = head;
		len++;
		return true;
	}
	if (pos > 0 && pos <= len) {
		Node<T> *prenode = getPreNode(pos);
		if (pos == 1) {
			pnode->next = head;
			rear->next = pnode;
			head = pnode;
			len++;
			return true;
		}
		else {
			pnode->next = prenode->next;
			prenode->next = pnode;
			len++;
			return true;
		}
	}
	else {
		cout << "插入下标超出范围！" << endl;
		return false;
	}
}

template<class T>
bool Link<T>::insert(T val) {
	Node<T> *pnode = new Node<T>(val);
	if (isEmpty()) {
		head = pnode;
		rear = pnode;
		head->next = rear;
		rear->next = head;
		len++;
		return true;
	}
	else {
		rear->next = pnode;
		pnode->next = head;
		rear = pnode;
		len++;
		return true;
	}
}

template<class T>
bool Link<T>::delAt(int pos) {
	if (isEmpty()) {
		cout << "删除列表为空！！" << endl;
		return false;
	}
	else {
		if (pos > 0 && pos <= len) {
			Node<T> * prenode = getPreNode(pos);
			Node<T> * pnode = prenode->next;
			if (pos == 1) {
				Node<T> * pnode = head->next;
				delete head;
				head = pnode;
				len--;
				return true;
			}
			else {
				prenode->next = pnode->next;
				delete pnode;
				len--;
				return true;
			}
		}
		else {
			cout << "删除下标超出范围！！" << endl;
			return false;
		}
	}
}

template<class T>
bool Link<T>::del() {
	if (isEmpty()) {
		cout << "删除列表为空！！" << endl;
		return false;
	}
	else {
		Node<T> *pnode = head->next;
		delete head;
		head = pnode;
		len--;
		return true;
	}
}

template<class T>
bool Link<T>::updateVal(T val,int pos) {
	if (isEmpty()) {
		cout << "需要修改的列表为空！！" << endl;
		return false;
	}
	else {
		if (pos > 0 && pos <= len) {
			if (pos == 1) {
				head->data = val;
			}
			else {
				getPreNode(pos)->next->data = val;
				return true;
			}
		}
		else {
			cout << "需要修改的下标超出范围！！" << endl;
			return false;
		}
	}
}

template<class T>
Link<T> Link<T>::Merge(Link<T> l1, Link<T> l2) {
	Link<T> l3;
	if (l1.isEmpty())  return l2;
	if (l2.isEmpty())  return l1;
	l1.getRear()->next = l2.getRear()->next;
	l2.getRear()->next = l1.getHead();
	l1.len += l2.len;
	return l1;
}