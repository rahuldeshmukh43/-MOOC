#include<iostream>
#include<string>

#include "Stack.h"
#include "shunting_help.h"

using namespace std;

/* Implementing the shunting algorithm for parsing mathematical expression
 * using stacks. Not tokenizing the input string, assuming every character is a token.
 * without functions(sin(.),cos(.),log(.)) or composite functions or functions with variable num of args
 * and unary operators.
 * reference: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 * Note: The o/p of shunting algorithm is RPN form of the expression which can be used
 * by autograd to make tree efficiently (refer to ../../../OOP/Topic_6/autograd)
 */

int main(int argc, char **argv){
	string op_str;
	bool flagParser=false;
	cout<<"Input expression using numbers, operator(+,-,/,*) and parentheses '(',')'"<<endl;
	//getline(cin,inp_str);
	string inp_str=argv[1];
	cout<< "Expressition give: "<<inp_str<<endl;

	flagParser= Parser(inp_str, op_str);
	if(!flagParser){return -1;}

	//print string
	cout<<"Post-Fix notation expression:\n";
	printf("%s\n",op_str.c_str());
	return 0;
}


