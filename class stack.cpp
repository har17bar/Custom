﻿#include <iostream>
using namespace std;

class Stack {
private:
	int *_arr;
	int _top;
	int _size;
public:
	Stack() {
		this->_top = -1;
	}
	void init( int size =10);
	void push(const int value);
	bool is_not_full();
	void increase(const int size);
	void pop();
	bool is_not_empty();
	void print();
	~Stack() {}
};


int main()
{
	Stack obj;
	int choice, value, size;
	cout << "Stack size is by defult 10" << endl;
	cout << "Pres any-number for leave stack by defult OR 2 to give size stack" << endl;
	while (!(cin >> size)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	if (size == 2) {
		cout << "enter new size stack" << "\t";
		cin >> value;
		obj.init(value);
	}
	else {
		obj.init();
	}
	cout << "1:"<<'\t'<<"Push element in stack" << endl;
	cout << "2:" << '\t' << "Pop element from the stack" << endl;
	cout << "3:" << '\t' << "Print elements in  the stack" << endl;
	cout << "0:" << '\t' << "Exit program" << endl;
	cin >> choice;
	while (choice!=0) {
		if(choice==1){
			cout << "how mach value to push" << "\t";
			cin >> size;
			for (int i = 0; i < size; ++i) {
				cout << "enter " << i + 1 << " value"<<"\t";
				cin >> value;
				obj.push(value);
			}
			
		}
		if(choice==2){
			obj.pop();
		}
		if (choice == 3) {
			obj.print();
		}
		cout << "enter unother choise" << "\t";
		cin >> choice;
	}
}

void Stack::init(int size)
{
	this->_size = size;
	this->_arr = new int[this->_size];
}

void Stack::push(const int value)
{
	if (is_not_full()) {
		this->_arr[++this->_top] = value;
	}
	else {
		int press,size;
		cout << "Stack is full" << endl;
		cout << "Pres 2 to give new size stack" << endl;
		cin >> press;
		if (press == 2) {
			cout << "Enter size" << endl;
			cin >> size;
			while (size < this->_size) {
				cout << "incorect size:" << endl;
				cout << "Enter size" << endl;
				cin >> size;
			}
			increase(size);

				
		}
		
	}
	
}

void Stack::pop()
{
	if(is_not_empty())
		--(this->_top);
	else
		cout << "Stack is empty" << endl;
}

bool Stack::is_not_empty()
{
	if (this->_top == -1)
		return false;
	return true;
}

void Stack::print() {
	if (is_not_empty()) {
		for (int i = this->_top; i >= 0; --i) {
			cout << this->_arr[i] << endl;
		}
	}
	else {
		cout << "Stack is empty" << endl;
	}
	
}

void Stack::increase(const int size)
{
	int *tmp = new int[size];
	for (int i = 0; i < this->_size; ++i) {
		tmp[i] = this->_arr[i];
	}
	delete [] this->_arr;
	this->_arr = tmp;
	this->_size = size;
}

bool Stack::is_not_full()
{
	if (this->_size - 1 == this->_top)
		return false;
	return true;
}
