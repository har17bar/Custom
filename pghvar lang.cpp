#include <iostream>
#include<string>
#include <fstream>
#include <sstream>  
#include <vector>

using namespace std;

class Token {
public:
	string T_type;
	string T_expresion;
	Token(string type, string expresion) {
		T_type = type;
		T_expresion = expresion;
	}
	void print() {
		cout << "Token type: " << T_type <<"___"<< " expresion: " << T_expresion << endl;
	}
};

void openFile(const char *filename, ifstream &data);
void tokenizer(string line);
string checktType(string tok);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cout << " There is no file name to read!" << std::endl;
		return -1;
	}
	ifstream data;
	openFile(argv[1], data);
	string line;
	int i = 1;
	while (std::getline(data, line))
	{
		tokenizer(line);
		std::cout << "line " << i << ": " << line << std::endl;
		++i;
	}
}

void openFile(const char *filename, ifstream &data) {
	std::string  fname(filename);
	std::string ext(".jss");
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
}

void tokenizer(string line) {
	vector<Token> TokenList;
	string tok;
	string type;
	stringstream s(line);
	int i = 0;
	while (s >> tok) {
		type=checktType(tok);
		Token tmp(type, tok);
		TokenList.push_back(tmp);
		TokenList[i].print();
		i++;
	}
	//stex
}

string checktType(string tok) {
	if (tok == "var"|| tok == "print") {
		return "keyword";
	}
	else if (tok == "=" || tok == "+" || tok == "*" || tok == "/") {
		return "operator";
	}
	else if (tok == ";") {
		return "endl";
	}
	else {
		for (int i = 0; i < tok.size(); ++i) {
			if (tok[i] =='.'|| ( tok[0]=='"' && tok[tok.size()-1] == '"' ) || ( (int)tok[i]<=57 && tok[i]>=49) ){
				return "literal";
			}
		}
	}
	return "variable";
}


