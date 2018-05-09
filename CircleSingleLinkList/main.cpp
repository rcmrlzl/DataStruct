#include<iostream>
#include"Link.h"
using namespace std;

int main() {
	Link<int> l;
	l.insertAt(1,1);
	l.insertAt(2,1);
	l.insertAt(3,1);
	l.insertAt(4,1);
	l.insertAt(5,1);
	l.showAll();
	l.insert(9);
	l.insert(8);
	l.insert(7);
	l.insert(6);
	l.showAll();

	l.delAt(9);
	l.del();
	int len = l.getLen();
	cout << "len:" << len << endl;
	l.showAll();

	l.updateVal(77, 7);
	l.updateVal(11, 1);
	l.updateVal(22, 2);
	l.showAll();

	Link<int> l2;
	l2.insert(44);
	l2.insert(55);
	l2.insert(66);
	l2.insert(65);
	l2.showAll();

	Link<int> l3 = l3.Merge(l, l2);
	l3.showAll();
	return 0;
}