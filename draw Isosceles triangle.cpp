#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;
void treangle(int heigt);


int main() {
	cout << "Enter the height of an isosceles triangle:"<<endl;
	int heigt;
	cin >> heigt;
	treangle(heigt);
}

void treangle(int heigt) {
	char simb = '^';
	char prabel = ' ';
	string a;
	int i = 0;
	int c;
	int j;
	while (i <= heigt) {
		j = 0;
		while (j<heigt - i)
		{
			a = a + prabel;
			j++;
		}
		c = heigt - 2 * i;
		while (c <= heigt)
		{
			a = a + simb;
			c++;
		}
		a += "\n";
		i++;
	}
	cout << a << endl;

}

