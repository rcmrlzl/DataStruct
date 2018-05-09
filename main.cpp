#include<iostream>
#include"SqList.h"
using namespace std;

int main() {
	SqList<int> l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	//l.DelValAt(5);
	l.changeValAt(2, 10);

	int position = l.getPos(6);
	int a = l.getValAt(2);
	cout << "a=" << a << endl;
	cout << "position=" << position << endl;
	cout << "the first val:" << l.getFirstVal() << endl;
	l.PrintList();
	cout << "############################" << endl;
	l.PrintReverse();
	return 0;
}