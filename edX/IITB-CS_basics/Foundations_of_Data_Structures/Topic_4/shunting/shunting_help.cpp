#include<iostream>
#include<map>
#include<string.h>

#include "Stack.h"
#include "shunting_help.h"

using namespace std;

void Operator_oracle::OpPrednAssoc(char op, int &pred, char &assoc){
	pred = pred_dict[op];
	assoc = assoc_dict[op];}

//function for identifying if a char is an operator or not
bool IsOperator(char x){
switch(x){
	case '^':
	case '*':
	case '/':
	case '+':
	case '-':return true; break;
	default:{return false; break;}
}}

bool IsNumber(char x){
	int v= (int)x;
	if((v>=48)&&(v<=57)){return true;}
	return false;
}

bool IsParen(char x, char &assoc){
	if(x=='('){assoc='L';return true;}
	if(x==')'){assoc='R';return true;}
	return false;
}

//function for converting queue to string
void queue2str(Queue* Q, string &op){
	char el;
	while(!(Q->IsEmpty())){
		Q->Pop(el);
		op+=el;}
}

bool Parser(string &inp_str, string &op_str){
	Stack S_opr;
	Queue Q_out;
	Operator_oracle Oracle;
	int i=0, pred_token, pred_top, ti;
	char token, assoc_token,top_char, assoc_top, pop_el, temp_el;
	bool flagOprToken=false, flagNumToken=false, flagParenToken=false, flagParenTop=false;

	while(i < inp_str.length()){
		token = inp_str[i];
		if(token==' '){i++;continue;}
		flagOprToken = IsOperator(token);
		flagNumToken = IsNumber(token);
		flagParenToken = IsParen(token, assoc_token);
		if(!(flagOprToken || flagNumToken|| flagParenToken)){cout<<"Error: Invalid character in expression\n";return false;}
		if(flagNumToken){Q_out.Push(token); i++; continue;}
		//elseif func
		if(flagOprToken){
			S_opr.Top(top_char);
			Oracle.OpPrednAssoc(token, pred_token, assoc_token);
			if(IsOperator(top_char)){Oracle.OpPrednAssoc(top_char, pred_top, assoc_top);}
			/*
			 * while ((there is an operator at the top of the operator stack)
              and ((the operator at the top of the operator stack has greater precedence)
                  or (the operator at the top of the operator stack has equal precedence and the token is left associative))
              and (the operator at the top of the operator stack is not a left parenthesis)):
			 */

			while( (!(S_opr.IsEmpty()))
					&& ( (pred_top>pred_token)||( (pred_top==pred_token) && (assoc_token=='L') ) )
					&& ( top_char!='(' )){
					S_opr.Pop(pop_el);
					Q_out.Push(pop_el);
					S_opr.Top(top_char);
					if(!S_opr.IsEmpty()){
						if(IsOperator(top_char)){
							Oracle.OpPrednAssoc(top_char, pred_top, assoc_top);}
					}
			}
			//push token to S_opr
			S_opr.Push(token);S_opr.Top(top_char);i++; continue;
		}
		if(flagParenToken && assoc_token=='L'){S_opr.Push(token);i++; continue;}
		if(flagParenToken && assoc_token=='R'){
			while(top_char!='('){
				S_opr.Pop(pop_el);
				Q_out.Push(pop_el);
				S_opr.Top(top_char);
			}
			if(top_char=='('){S_opr.Pop(temp_el);}
			//if(func token at top){}
			i++;continue;
		}
	}
	//all tokens have been read
	while(!S_opr.IsEmpty()){
		S_opr.Pop(pop_el);
		Q_out.Push(pop_el);
	}

	queue2str(&Q_out, op_str);
	return true;
}
