#include<iostream>
#include"stack.h"
using namespace std;

int main() {
	Stack st;
	initStack(st, 10);
	Push(st, 1);
	Push(st, 2);
	Push(st, 3);
	Push(st, 4);
	Push(st, 5);
	Pop(st);
	int a = getTop(st);
	cout << a << endl;
	destroyStack(st);
	displayStack(st);
	return 0;
}