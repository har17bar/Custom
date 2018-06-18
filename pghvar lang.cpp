#include "stdafx.h"
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include <map>
#define PGHVAR  "pghvar"

using namespace std;
void open_file(const char *filename, ifstream &data);
void tokenizer(string line);


int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << " There is no file name to read!" << std::endl;
		return -1;
	}
	ifstream data;
	open_file(argv[1], data);
}


void tokenizer(string line) {
	std::map<string, int> umap;
	string token;
	int begin = 0;
	for ( int i = 0; i < line.length(); i++) {
		token = line.substr(begin, line.find(" "));
		begin = line.find(" ");
		cout << token << endl;
	}
	
	cout<<endl << token <<endl;
	//myMultiValueMap[strKey] = make_pair(firstDouble, secondDouble);
	
}
void open_file(const char *filename, ifstream &data) {
	std::string  fname(filename);
	std::string ext(".pgh");
	std::size_t found = fname.rfind(ext);
	if (found != fname.length() - 4) {
		std::cout << "Not correct file format!" << std::endl;
		return;
	}
	data.open(filename);
	if (data.fail())
	{
		cout << "FileError " << filename << " could not be found" << endl;
	}
	string line;
	int i = 1;
	while (std::getline(data, line))
	{
		tokenizer(line);
		std::cout << "line " << i << ": " << line << std::endl;
		++i;
	}
}