#include<cstring>
#include<iostream>
#include<stdio.h>
#include<cstdio>

#include "graph.h"
#include "Node.h"
#include "Polynomial.h"
#include "ConstPoly.h"

using namespace std;

/*
 * Program to compute derivate of a univariate (in x) function composed of operators: +,-,*,/ only
 * The main function parses the user given string input
 * and creates a binary tree as computational graph
 * Each node in the graph has its derivative computed. 
 * We print out the derivative of the root node in the graph
 * Allowable characters are: 'x','*','-','+','0-9';no spaces, brackets etc
 */
//fun decs:
void countNodes(char * s,int len,int &numNodes);
Node * ParseTempStr(char* tempstr, int temp_len, Graph &G, int &iNode);
Node *AddorSubNode(char* inp_string, int prev_symb, Graph &G, int &iNode, Node *L, Node *R);

//fun defs:
void countNodes(char * s,int len,int &numNodes){
int i;
bool primVarCounted=false;

for(i=0;i<len;i++){
	if(!(((int(s[i])>=48)&&(int(s[i]<=57)))||\
			(s[i]=='x')||(s[i]=='+')||(s[i]=='-')||(s[i]=='*'))){
		cout<<"string contains illegal character\n";numNodes=-1;return;}
if((s[i]=='x')&&(!primVarCounted)){
primVarCounted=true; numNodes+=1;}
if(s[i]!='x'){numNodes+=1;}
}
return;}

Node * ParseTempStr(char* tempstr, int temp_len, Graph &G, int &iNode){
int itmp, k;
Node *L,*R;
for(itmp=0;itmp<temp_len;){
//type of char: x or int?
if(itmp==0){
if(tempstr[itmp]=='x'){L = &G.nodeList.List[0];}
if((int(tempstr[itmp])>=48)&&(int(tempstr[itmp])<=57)){//const node
k = int(tempstr[itmp]) -48;
iNode++;
G.nodeList.append(iNode,ConstNode(k));
L = &G.nodeList.List[iNode];}
itmp++;
if(tempstr[itmp]=='\0'){break;}// x + sth or k+ sth
}

//get right
if(tempstr[itmp+1]=='x'){R = &G.nodeList.List[0];}
if((int(tempstr[itmp+1])>=48)&&(int(tempstr[itmp+1])<=57)){//const node
k = int(tempstr[itmp+1]) -48;
iNode++;
G.nodeList.append(iNode,ConstNode(k));
R = &G.nodeList.List[iNode];}
//addmul Node
iNode++;
G.nodeList.append(iNode,mulNode(L,R));
L = &G.nodeList.List[iNode];
itmp+=2;
}
return L;
}

bool StringHasChar(char *s, char q, int len){
	int i=0;
	bool flag=false;
	for(i=0;i<len;i++){
		if(s[i]==q){flag=true;break;}
	}
	return flag;
}

int main(int argc, char **argv){

int istr=0,itmp=0, numNodes=0, inp_len, temp_len=0;//numEdges=0
int iNode=0, prev_symb=0, new_symb;
char *inp_string = argv[1] ,tempstr[100];
//bool lastExpr=false;
bool inp_has_x=false;

Node *L, *R, *root;
Node temp;

//get input string
//cout<<"Enter expression whose derivative needs to be computed: \n";
//fgets(inp_string,100,stdin);
inp_len = strlen(inp_string);
if(inp_string[inp_len-1]=='\n'){inp_string[inp_len-1]='\0';inp_len--;}
inp_has_x = StringHasChar(inp_string, 'x', inp_len);
if(!inp_has_x){
	cout<<"The derivative is:\n";
	cout<<"(0.0)\n";
	return 0;}
//parse string:
//1) Count numNodes
countNodes(inp_string, inp_len, numNodes);
if(numNodes==-1){cout<<"Terminating!\n";return -1;}
Graph G = Graph(numNodes);
PrimaryVarNode primVarNode=PrimaryVarNode();
G.nodeList.append(0,primVarNode);iNode++;

//2) Break along +,- and make tree
R = &temp;
new_symb=0;
do{
L = R;
prev_symb=new_symb;

//get tempstr for expression
temp_len=0;itmp=0;
for(;;istr++,itmp++){
//check if end of string
if(inp_string[istr]=='\0'){
//lastExpr=true;
cout<<"String parsed"<<endl;break;}
//break if +,- ; new expr is coming
if((inp_string[istr]=='+')||(inp_string[istr]=='-')){
	new_symb=istr;	
	istr++;break;}
//put scanned char in tempstr
tempstr[itmp]=inp_string[istr];
temp_len++;
}//forloop
tempstr[itmp]='\0';

//parse tempstr to get Node
R = ParseTempStr(tempstr,temp_len,G,iNode);
//check for +,-,'\0'
if(inp_string[istr]=='\0'){
	if((L->left==NULL)&&(iNode==1)){root = R;break;}//expr: (R)'\0'
	else{//expr: (L)+(R)'\0'
 	root = AddorSubNode(inp_string, prev_symb, G, iNode, L, R);
	if(root==NULL){return -1;}
	}

}
else{//'+' or '-'symbol encountered
if(prev_symb!=0){//expr: (L)+(R)'+'
L = AddorSubNode(inp_string, prev_symb, G, iNode, L, R);}}
if(L==NULL){return -1;}

}while(istr<inp_len);

//update root in graph
G.rootNode= root;
//print derivative:
cout<<"The derivative is:\n";
printPoly(G.rootNode->NodeGrad);
return 0;
}

Node *AddorSubNode(char* inp_string, int prev_symb, Graph &G, int &iNode, Node *L, Node *R){
Node *Out;
switch(inp_string[prev_symb]){
	case '+':{	 iNode++;
			 G.nodeList.append(iNode, addNode(L,R));
			 Out = &G.nodeList.List[iNode];
			 break;}
	case '-':{	 iNode++;
			 G.nodeList.append(iNode, substractNode(L,R));
			 Out = &G.nodeList.List[iNode];
			 break;}
	default:{cout<<"sth went wrong, check expression!\n";Out=NULL;}
}
return Out;
}
