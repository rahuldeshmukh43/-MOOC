#ifndef SHUNTINGHELP_H
#define SHUNTINGHELP_H

#include<map>
#include<string>

#include "Stack.h"

using namespace std;

//maps for getting operator precedence and associativity
class Operator_oracle{
map<char,int> pred_dict={
		{'^',4},
		{'*',3},
		{'/',3},
		{'+',2},
		{'-',2}};
map<char,char> assoc_dict={
		{'^','R'},
		{'*','L'},
		{'/','L'},
		{'+','L'},
		{'-','L'}};;
public :
void OpPrednAssoc(char op, int &pred, char &assoc);
};


//function for identifying if a char is an operator or not
bool IsOperator(char x);
bool IsNumber(char x);
bool IsParen(char x, char &assoc);

//function for converting queue to string
void queue2str(Queue* Q, string &op);
bool Parser(string &inp_str,string &op_str);

#endif
