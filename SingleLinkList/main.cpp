#include<iostream>
#include"SingleLink.h"
using namespace std;

int main() {
	SgLink<int> l;
	l.addAt(1, 1);
	l.addAt(2, 1);
	l.addAt(3, 1);
	l.addAt(4, 1);
	l.addAt(5, 1);
	l.addAt(6, 1);
	l.addAt(7, 1);
	l.showAll();
	cout << "*****************************" << endl << "the add list:" << endl;
	l.addAt(10, 7);
	l.showAll();
	cout << "*****************************" << endl << "the del list:" << endl;
	l.delAt(1);
	l.delAt(7);
	l.showAll();

	int getval = l.getValAt(6);
	cout << "the getval:" << getval << endl;
	cout << "*****************************" << endl << "the update list:" << endl;
	l.updateValAt(55,5);
	l.showAll();
	
	int len = l.getLen();
	cout << "len:" << len << endl;

	cout << "*****************************" << endl << "the clear list:" << endl;
	l.clear();
	l.addAt(1, 1);
	l.showAll();
	return 0;
}