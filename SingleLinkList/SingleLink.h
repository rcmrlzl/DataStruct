#pragma once
#include<iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node<T> *next;
	Node(const T d) :data(d), next(NULL) {}
};

template<class T>
class SgLink {
public:
	SgLink() { head = nullptr; len = 0; };
	~SgLink() { clear(); };

	Node<T> *getPreNode(int pos) {
		Node<T> *pNode = head;
		for (int k = 1; k < pos-1; k++) {
			pNode = pNode->next;
		}
		return pNode;
	};

	int getLen();

	bool isEmpty() { return len == 0; };

	bool addAt(T val,int pos);

	bool delAt(int pos);

	T getValAt(int pos);

	bool updateValAt(T val,int pos);

	bool clear() {
		if (isEmpty()) {
			return false;
		}
		
		int k = getLen();
		for (int i = 1; i <= k; i++) {
			delAt(1);
		}
		return true;
		
	};

	void showAll() {
		Node<T> *findNode = head;
		while (findNode!=NULL) {
			cout << findNode->data << " ";
			findNode = findNode->next;
		}
		cout << endl;
	};

private:
	Node<T> *head;
	int len;
};

template<class T>
int SgLink<T>::getLen() {
	if (isEmpty()) {
		return 0;
	}
	return len;
}

template<class T>
bool SgLink<T>::addAt(T val,int pos) {
	Node<T> *pNode = new Node<T>(val);
	if (isEmpty()) {
		head = pNode;
		len++;
		return true;
	}
	if (pos == 1) {
		pNode->next = head;
		head = pNode;
		len++;
		return true;
	}
	if (pos > 1 && pos <=len) {
		Node<T> *preNode = getPreNode(pos);
		pNode->next = preNode->next;
		preNode->next = pNode;
		len++;
		return true;
	}
	else {
		cout << "error:the insert position is out of range!!" << endl;
		return false;
	}
}

template<class T>
bool SgLink<T>::delAt(int pos) {
	if (isEmpty()) {
		cout << "error:the del list is empty!!" << endl;
		return false;
	}
	if (pos == 1) {
		Node<T> *tempNode = head->next;
		delete head;
		head = tempNode;
		len--;
		return true;
	}
	if (pos > 1 && pos <= len) {
		Node<T> *preNode = getPreNode(pos);
		Node<T> *delNode = preNode->next;
		preNode->next = delNode->next;
		delete delNode;
		len--;
		return true;
	}
	else {
		cout << "error:the del position is out of range!!" << endl;
		return false;
	}
}

template<class T>
T SgLink<T>::getValAt(int pos) {
	if (isEmpty()) {
		cout << "error:the get list is empty!!" << endl;
		return false;
	}
	if (pos == 1) {
		return head->data;
	}
	if (pos > 1 && pos <= len) {
		Node<T> *pNode = getPreNode(pos)->next;
		return pNode->data;
	}
	else {
		cout << "error:the get position is out of range!!" << endl;
		return false;
	}
}

template<class T>
bool SgLink<T>::updateValAt(T val,int pos) {
	if (isEmpty()) {
		cout << "error:the update list is empty!!" << endl;
		return false;
	}
	if (pos == 1) {
		head->data = val;
		return true;
	}
	if (pos > 1 && pos <= len) {
		Node<T> *pNode = getPreNode(pos)->next;
		pNode->data = val;
		return true;
	}
	else {
		cout << "error:the get position is out of range!!" << endl;
		return false;
	}
}