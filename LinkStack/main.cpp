#include<iostream>
#include"Stack.h"
using namespace std;

int main() {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.pop();
	s.pop();
	cout << s.getTop() << endl;
	return 0;
}