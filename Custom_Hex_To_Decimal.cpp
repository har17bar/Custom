#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
int c_convert(char s) {
	switch (s) {
	case 'A':
		return 10;
		break;
	case 'B':
		return 11;
		break;
	case 'C':
		return 12;
		break;
	case 'D':
		return 13;
		break;
	case 'E':
		return 14;
		break;
	case 'F':
		return 14;
		break;


	default:
		return s - '0';
	}
}
void hexto10(string hex) {
	int length = hex.length() - 1;
	int index = length;
	long long summ = 0;
		for (int i = 0; i <= length; ++i) {
			summ += c_convert(hex[i]) * pow(16, index);
			index--;
		}
		cout << summ << endl;
		
}
int main()
{
	hexto10("035AC5B1");
	return 0;
}

