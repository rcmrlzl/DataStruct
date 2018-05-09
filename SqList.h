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

	//����Ԫ��  
	bool insert(T val);			 //���β������Ԫ��  
										  				
	T getValAt(int pos);		 //����ָ��λ�õ�Ԫ��  
								 
	bool DelVal(T val);			 //ɾ��Ԫ��  

	bool DelValAt(int location); //ɾ��ָ��Ԫ��  
									 
	bool changeValAt(int pos, T val);   //����ָ��Ԫ��  
	
	bool PrintList();			 //��ӡ˳���  
	
	int getPos(T val);           //����ָ��Ԫ�أ����������ڱ��е�λ��    
	
	T getFirstVal();      //����ƥ��ĵ�һ��Ԫ�ص�λ�ã�λ����һ������ֵ��������    
										 
	bool isEmpty();	 //�ж�˳����Ƿ�Ϊ��  
	
	bool initList();	 //��ʼ�������  
	
	void clear() {
		for (int k = 0; k < lenght; k++) {
			array[k] = NULL;
		}
		size = 0;
		lenght = 0;
	};		 //���˳���  
	
	void destroyList() {};			 //����˳���  
	
	bool PrintReverse();		     //��ת˳���
	
	int getLength()				 //��ȡ˳�����  
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
