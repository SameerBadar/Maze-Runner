#pragma once
#include"MyNode.h"
class Stack
{
public:
	void push(MyNode * );
	MyNode* pop();
	bool isEmpty();
	bool isFull();
private:
	MyNode* arr[10];
	int min = 10;
	int tos = 0;
};

