#include<iostream>
#include "Stack.h"
using namespace std;
void Stack::push(MyNode* ptr) {
	if (tos < min) {
		arr[tos] = ptr;
		tos++;
		return;
	}
	cout << "Stack OverFlow " << endl;
}
MyNode* Stack::pop() {
	if (tos > 0) {
		tos--;
		return arr[tos];
	}
	//cout << "Stack Is Out Of Bounds " << endl;
	return nullptr;
}
bool Stack::isFull() {
	if (tos == min) {
		return true;
	}
	return false;
}
bool Stack::isEmpty() {
	if (tos >= 0 && tos < min) {
		return true;
	}
	return false;

}