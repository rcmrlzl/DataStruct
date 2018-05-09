#include<iostream>
#include"link.h"
using namespace std;

int main() {
	Link<int> l;
	l.insertFont(1);
	l.insertTail(2);
	l.insertTail(3);
	l.insertTail(6);
	l.insertTail(7);
	l.insertAt(4, 1);
	l.insertAt(5, 4);
	l.showAll();

	/*l.delFont();
	l.showAll();

	l.delTail();
	l.showAll();

	l.delAt(0);

	l.delAt(1);
	l.showAll();

	l.delAt(4);
	l.showAll();

	l.delAt(2);
	l.showAll();*/

	l.updatValAt(55, 2);
	l.showAll();

	int getfont = l.getFont();
	cout << "getfont:" << getfont << endl;

	int gettail = l.getTail();
	cout << "gettail:" << gettail << endl;

	int getIndexFive = l.getAt(5);
	cout << "getIndex(5):" << getIndexFive << endl;
	return 0;
}