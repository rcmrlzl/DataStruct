#pragma once
#include<iostream>
using namespace std;

template<class T>
class SqList {
public:
	SqList() {
		initList();
	};

	~SqList() { clear(); };

	//插入元素  
	bool insert(T val);			 //向表尾插入新元素  
										  				
	T getValAt(int pos);		 //返回指定位置的元素  
								 
	bool DelVal(T val);			 //删除元素  

	bool DelValAt(int location); //删除指定元素  
									 
	bool changeValAt(int pos, T val);   //更改指定元素  
	
	bool PrintList();			 //打印顺序表  
	
	int getPos(T val);           //查找指定元素，并返回其在表中的位置    
	
	T getFirstVal();      //返回匹配的第一个元素的位置（位置是一个整数值哈！！）    
										 
	bool isEmpty();	 //判断顺序表是否为空  
	
	bool initList();	 //初始化书序表  
	
	void clear() {
		for (int k = 0; k < lenght; k++) {
			array[k] = NULL;
		}
		size = 0;
		lenght = 0;
	};		 //清空顺序表  
	
	void destroyList() {};			 //销毁顺序表  
	
	bool PrintReverse();		     //反转顺序表
	
	int getLength()				 //获取顺序表长度  
	{
		return length;
	}

private:
	T *array;
	int lenght;
	int size;
	const int defalutSize = 10;
};

template<class T>
bool SqList<T>::insert(T val) {
	if (lenght < size) {
		array[lenght] = val;
		lenght++;
		return true;
	}
	else {
		cout << "error:the list is full!!" << endl;
		return false;
	}
}


template<class T>
T SqList<T>::getValAt(int pos) {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	if (pos < 0 || pos >= lenght) {
		cout << "error:the pos out of the valid lenght!!" << endl;
	}
	else {
		return array[pos];
	}
}

template<class T>
bool SqList<T>::DelVal(T val) {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	for (int k = 0; k < lenght; k++) {
		if (array[k] == val) {
			for (int i = k; i < lenght; i++) {
				array[i] = array[i + 1];
			}
			lenght--;
			return true;
		}
	}
	return false;
 }

template<class T>
bool SqList<T>::DelValAt(int pos) {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	if (pos < 0 || pos >= lenght) {
		cout << "error:the pos out of the valid lenght!!" << endl;
		return false;
	}
	else {
		for (int k = pos; k < lenght; k++) {
			array[k] = array[k + 1];
		}
		lenght--;
		return true;
	}
}

template<class T>
bool SqList<T>::changeValAt(int pos,T val) {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	if (pos < 0 || pos >= lenght) {
		cout << "error:the pos out of the valid lenght!!" << endl;
		return false;
	}
	else {
		array[pos] = val;
		return true;
	}
}



template<class T>
int SqList<T>::getPos(T val) {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	for (int k = 0; k < lenght; k++) {
		if (array[k] == val) {
			return k;
		}
	}
	cout << "error:the val isnot in the list!!" << endl;
	return -1;
}

template<class T>
T SqList<T>::getFirstVal() {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	else {
		return array[0];
	}
}

template<class T>
bool SqList<T>::isEmpty() {
	if (lenght == 0)
		return true;
	return false;
}

template<class T>
bool SqList<T>::initList() {
	size = defalutSize;
	if (size > 0) {
		array = new T[size];
		lenght = 0;
		for (int k = 0; k < size; k++) {
			array[k] = NULL;
		}
		return true;
	}
	else {
		cout << "the size is illegal!!" << endl;
		return false;
	}
}

template<class T>
bool SqList<T>::PrintList() {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	for (int k = 0; k < lenght; k++) {
		cout << array[k] << " ";
	}
	cout << endl;
	return true;
}

template<class T>
bool SqList<T>::PrintReverse() {
	if (isEmpty()) {
		cout << "error:the list is empty!!" << endl;
		return false;
	}
	for (int k = lenght-1; k >=0; k--) {
		cout << array[k] << " ";
	}
	cout << endl;
	return true;
}
