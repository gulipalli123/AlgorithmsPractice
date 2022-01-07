// AmazonPractice.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
class Stack {
	const static int max = 100;
	int arr[max];
	int top;

public:
	Stack() { top = -1; }
	bool isFull() {
		if (top == max - 1)
			return true;
		return false;
	}
	bool isEmpty() {
		if (top == -1)
			return true;
		return false;
	}
	void push(int x) {
		if (isFull() == false){
			top++;
			arr[top] = x;
		}
		else {
			std::cout << "stack overflow error" << "\n";
		}
	}
	int pop() {
		if (isEmpty() == false) {
			int y = arr[top];
			top--;
			return y;
		}
		else {
			std::cout << "stack underflow error" << "\n";
		}
	}
	int top_val() {
		if (isEmpty() == false) {
			int x =  arr[top];
			return x;
		}
		else {
			std::cout << "stack underflow error" << std::endl;
		}
	}
};
/*

class SpecialStack : public Stack {
	Stack min;
	//Stack orig;

public:
	int pop() {
			int x = Stack::pop(); //doubt : how it works
			min.pop();
			return x;
	}
	void push(int x) {
		if (isEmpty() == true) {
			Stack::push(x);
			min.push(x);
		}
		else {
			int y = min.pop();
			min.push(y);
			if (x < y)
				min.push(x);
			else
				min.push(y);
			Stack::push(x);
		}
	}
	int getMin() {
		int x = min.pop();
		min.push(x);
		return x;
	}

};*/

class SpecialStack {
	int min = -1;
	int dummy_val = 9999;
	Stack st;

public:
	void push(int val) {
		if (true == st.isEmpty() || val < min) {
			min = val;
		}
		st.push(val * dummy_val + min);
	}

	int pop() {
		if (true == st.isEmpty()) {
			return -1;
		}
		int y = st.pop()/dummy_val;
		if (false == st.isEmpty())
			min = st.top_val() % dummy_val;
		else
			min = -1;

		return y;
	}

	int getMin() {
		if(false == st.isEmpty())
			return min;
		return -1;
	}
};