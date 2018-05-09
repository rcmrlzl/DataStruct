#pragma once
#include<iostream>
using namespace std;

typedef int ElemType;
struct Stack{
	ElemType *st;
	ElemType top;
	int stackSize;
};

bool initStack(Stack &stack,int size) {
	stack.st = new ElemType[size];
	if (!stack.st) {
		return false;
	}
	stack.stackSize = size;
	stack.top = 0;
	return true;
}

bool isEmpty(Stack &stack) {
	return stack.top == 0;
}

bool Push(Stack &stack,ElemType val) {
	if (stack.top >= stack.stackSize) {
		cout << "Ҫ�����ջ��������" << endl;
		return false;
	}
	stack.st[++stack.top] = val;
	return true;
}

bool Pop(Stack &stack) {
	if (isEmpty(stack)) {
		cout << "Ҫɾ����ջ�Կգ���" << endl;
		return false;
	}
	stack.top--;
	return false;
}

ElemType getTop(Stack &stack) {
	if (isEmpty(stack)) {
		cout << "Ҫ��ȡ��ջΪ�գ���" << endl;
		return false;
	}
	return stack.st[stack.top];
}

void destroyStack(Stack &stack) {
	cout << "cleared successed!!" << endl;
	delete[] stack.st;
	stack.top = 0;
}

void displayStack(Stack &stack) {
	if (!isEmpty(stack)) {
		for (int k = 1; k <=stack.top; k++) {
			cout << stack.st[k] << " ";
		}
		cout << endl;
	}
}