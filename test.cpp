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
	vector<Token> TokenList;
	void tokenizer(string line);
	void print() {
		for(int i=0;i<TokenList.size();++i){
			cout<<"type:"<<TokenList[i].T_type<<"  "<<"expresion: "<<TokenList[i].T_expresion<<endl;
		}
	}
};
class Variable{
public:
	string V_name;
	string V_type;
	string V_value;
	vector<Variable> VariableList;
};


string checktType(string tok);
void openFile(const char *filename, ifstream &data);
void execution(Token &obj);

void Token::tokenizer(string line) {
	string tok;
	string type;
	stringstream s(line);
	while (s >> tok) {
		type = checktType(tok);
		T_type = type;
		T_expresion = tok;
		TokenList.push_back(*this);
	}
}

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
		if (line[line.size() - 1] != ';') {
			cout << "Syntax Error in line "<< i << endl;
			return -1;
		}
		Token tmp;
		tmp.tokenizer(line);
		execution(tmp);
		break;
		std::cout << "line " << i << ": " << line << std::endl;
		++i;

	}
	
}
void executdef(Token &obj){
	variable tmp;
	tmp.V_name=obj.TokenList[1].T_expresion;
	for (int i = 0; i < obj.TokenList[3].T_expresion.size(); ++i) {
		if (obj.TokenList[i] =='.' &&  obj.TokenList[3].T_expresion[0]!='"' && obj.TokenList[3].T_expresion[obj.TokenList[3].T_expresion.size()-1]!='"')
			tmp.V_value="double";
		}
	}
}
void execution(Token &obj){
	if(obj.TokenList[0].T_type=="keyword"){
		if(obj.TokenList[0].T_expresion=="pghvar"){
			executdef(obj);
		}		
		else if(obj.TokenList[0].T_expresion=="print"){
			
		}
		else{
			cout<<"eror"<<endl;
		}
	}
	for(int i=0;i<obj.TokenList.size();++i){
		cout<<"type:"<<obj.TokenList[i].T_type<<"  "<<"expresion: "<<obj.TokenList[i].T_expresion<<endl;
	}
}
void openFile(const char *filename, ifstream &data) {
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
}



string checktType(string tok) {
	if (tok == "pghvar"|| tok == "print") {
		return "keyword";
	}
	else if (tok == "=" || tok == "+" || tok == "*" || tok == "/") {
		return "operator";
	}
	else if (tok == ";") {
		return "semicolon";
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
