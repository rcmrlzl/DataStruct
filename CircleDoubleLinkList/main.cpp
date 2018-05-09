#include<iostream>
#include"link.h"
using namespace std;
int main() {
	Link<int> l;

	l.insertFont(1);
	l.insertTail(2);
	l.insertTail(3);
	l.insertAt(11,1);
	l.insertAt(22,4);
	l.showAll();

	l.delAt(3);
	l.showAll();

	l.updateValAt(33,3);
	l.showAll();

	int font = l.getAt(1);
	int tail = l.getAt(4);
	int at = l.getAt(2);

	cout << "font:" << font << endl;
	cout << "tail:" << tail << endl;
	cout << "index(2):" << at << endl;

	return 0;
}