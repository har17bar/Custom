
#include <iostream>
#include <string>
using namespace std;

const int size = 10;

struct Stack {
	int top;
	int stackarr[size];
	int MinstackArr[size];
	int MinTop;
}s_obj;

bool stack_is_not_full(Stack const &);
bool stack_is_not_empty(Stack const &);
void push(Stack &, int);
void pop(Stack &);
void print(Stack);
void printMin(Stack const &s_obj);
int main()
{
	s_obj.top = -1;
	s_obj.MinTop = -1;
	int choise, number, total;
	cout << "Pres 1 :push element into stack" << endl;
	cout << "Pres 2 :pop element from the stack" << endl;
	cout << "Pres 3 :print elements" << endl;
	cout << "Pres 4 :print stack min element" << endl;
	cout << "Pres 0 :exit program" << endl;
	cin >> choise;
	while (choise)
	{
		if (choise == 1)
		{
			cout << "how many elemnets to push?" << "\t";
			cin >> total;
			for (int i = 0; i<total; ++i)
			{
				cout << endl << "Push " << i + 1 << " element" << "\t";
				cin >> number;
				push(s_obj, number);
			}
		}
		if (choise == 2)
		{
			cout << endl << "how many element to pop?" << "\t";
			cin >> total;
			if (stack_is_not_empty(s_obj))
			{
				for (int i = 0; i<total; ++i)
				{
					pop(s_obj);
				}
			}
			else
			{
				cout << endl << "Stack is empty" << endl;
			}

		}
		if (choise == 3)
		{
			if (stack_is_not_empty(s_obj))
				print(s_obj);
			else
				cout << endl << "Stack is empty" << endl;
		}
		if (choise == 4)
		{
			if (stack_is_not_empty(s_obj))
				printMin(s_obj);
			else
				cout << endl << "Stack is empty" << endl;
		}
		cout << endl << "Enter another choise" << endl;
	
		cin >> choise;
	}

}
void printMin(Stack const &s_obj){
   cout<<"Stack min is "<< s_obj.MinstackArr[s_obj.MinTop]<<endl;
}
void push(Stack  &s_obj, int number)
{
	if (stack_is_not_full(s_obj))
	{
	    if(	s_obj.MinTop != -1)
	    {
	        if(number<=s_obj.MinstackArr[s_obj.MinTop]){
	             s_obj.MinTop++;
	             s_obj.MinstackArr[s_obj.MinTop]=number;
	        }
	    }
	    else
	    {
	        s_obj.MinTop++;
	        s_obj.MinstackArr[s_obj.MinTop]=number;
	    }
		s_obj.top++;
		s_obj.stackarr[s_obj.top] = number;
	}
	else
		cout << endl << "Stack is overfloww" << endl;
}

bool stack_is_not_full(Stack const &s_obj)
{
	if (s_obj.top == size - 1)
		return false;
	else
		return true;
}

void pop(Stack &s_obj)
{
	if (stack_is_not_empty(s_obj))
	{
	    if(s_obj.stackarr[s_obj.top]== s_obj.MinstackArr[s_obj.MinTop]){
	        s_obj.MinTop--;
	    }
	    s_obj.top--;
	}
	else
		cout << endl << "stack is empty" << endl;
}


bool stack_is_not_empty(Stack const &s_obj)
{
	if (s_obj.top == -1)
		return false;
	else
		return true;
}

void print(Stack s_obj)
{
	cout << endl << "in stack is:" << endl;
	while (s_obj.top != -1)
	{
		cout << endl << s_obj.stackarr[s_obj.top] << endl;
		s_obj.top--;
	}
}
