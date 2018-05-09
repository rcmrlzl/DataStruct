#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node<T> *next;
	Node<T> *pre;
	Node(const T &d) :data(d), next(NULL), pre(NULL) {}
};

template<class T>
class Link {
public:
	Link() { head = NULL; tail = NULL; len = 0; };
	~Link() {};

	bool insertFont(T val);
	bool insertTail(T val);
	bool insertAt(T val,int pos);

	bool delFont();
	bool delTail();
	bool delAt(int pos);

	bool updatValAt(T val,int pos);

	T getFont();
	T getTail();
	T getAt(int pos);

	bool isEmpty() { return len == 0; };

	Node<T> *getPreNode(int pos) {
		Node<T> *pnode = head;
		for (int k = 1; k < pos - 1; k++) {
			pnode = pnode->next;
		}
		return pnode;
	};

	void showAll() {
		Node<T> *findNode = head;
		for (int k = 1; k <=len; k++) {
			cout << findNode->data << " ";
			findNode = findNode->next;
		}
		cout << endl;
	}

private:
	Node<T> *head;
	Node<T> *tail;
	int len;
};

template<class T>
bool Link<T>::insertFont(T val) {
	Node<T> *pnode = new Node<T>(val);
	if (isEmpty()) {
		head = pnode;
		tail = pnode;
		len++;
		return true;
	}
	else {
		pnode->next = head;
		head->pre = pnode;
		head = pnode;
		len++;
		return true;
	}
}

template<class T>
bool Link<T>::insertTail(T val) {
	Node<T> *pnode = new Node<T>(val);
	if (isEmpty()) {
		head = pnode;
		tail = pnode;
		len++;
		return true;
	}
	else {
		tail->next = pnode;
		pnode->pre = tail;
		tail = pnode;
		len++;
		return true;
	}
}

template<class T>
bool Link<T>::insertAt(T val, int pos) {
	if (pos<1 || pos>len) {
		cout << "插图元素下标超出范围！！" << endl;
		return false;
	}
	else {
		if (pos == 1) {
			insertFont(val);
		}
		else {
			Node<T> *pnode = new Node<T>(val);
			Node<T> *prenode = getPreNode(pos);
			pnode->next = prenode->next;
			pnode->pre = prenode;
			prenode->next->pre = pnode;
			prenode->next = pnode;
			len++;
			return true;
		}
	}
}

template<class T>
bool Link<T>::delFont() {
	if (isEmpty()) {
		cout << "要删除的列表为空！！" << endl;
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
bool Link<T>::delTail() {
	if (isEmpty()) {
		cout << "要删除的列表为空！！" << endl;
		return false;
	}
	else {
		Node<T> *pnode = tail->pre;
		delete tail;
		tail = pnode;
		len--;
		return true;
	}
}
template<class T>
bool Link<T>::delAt(int pos) {
	if (pos<1 || pos>len) {
		cout << "要删除的元素下标超出范围!!" << endl;
		return false;
	}
	else {
		if (pos == 1) {
			delFont();
		}
		else if (pos == len) {
			delTail();
		}
		else {
			Node<T> *pnode = getPreNode(pos)->next;
			Node<T> *prenode = getPreNode(pos);
			prenode->next = pnode->next;
			pnode->next->pre = prenode;
			len--;
			return true;
		}
	}
}

template<class T>
bool Link<T>::updatValAt(T val,int pos){
	if (isEmpty()) {
		cout << "要修改的列表不存在！！" << endl;
		return false;
	}
	else {
		if (pos<1 || pos>len) {
			cout << "要修改的元素下标超出范围!!" << endl;
			return false;
		}
		else {
			Node<T> *pnode = getPreNode(pos)->next;
			pnode->data = val;
			return true;
		}
	}
}

template<class T>
T Link<T>::getFont() {
	if (isEmpty()) {
		cout << "要获取元素列表为空！！" << endl;
		return false;
	}
	else {
		return head->data;
	}
}

template<class T>
T Link<T>::getTail() {
	if (isEmpty()) {
		cout << "要获取元素列表为空！！" << endl;
		return false;
	}
	else {
		return tail->data;
	}
}

template<class T>
T Link<T>::getAt(int pos) {
	if (isEmpty()) {
		cout << "要获取元素列表为空！！" << endl;
		return false;
	}
	else {
		if (pos<1 || pos>len) {
			cout << "要修改的元素下标超出范围!!" << endl;
			return false;
		}
		else {
			Node<T> *pnode = getPreNode(pos)->next;
			return pnode->data;
		}
	}
}