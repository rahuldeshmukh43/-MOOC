#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdio.h>
using namespace std;
//Program for counting words in a sentence
int main(){
	char sentence[200];
	int len,i,numwords=0, left=0, right=0;
	bool flag_first_space=false, flag_last_space=false;
	//take input:
	cout<<"Enter a sentence: ";
	fgets(sentence,200,stdin);
	len = strlen(sentence);
	//remove left spaces
	for(i=0;;i++){
	if(sentence[i]==' '){left+=1;}
	else{break;}
	}
	//remove right spaces
	for(i=len-2;;i--){
	if(sentence[i]==' '){right+=1;}
	else{break;}
	}
	sentence[len-right-1]='\0';
	cout<<"l: "<<left<<" r: "<<right<<endl;
	cout<<"len: "<<len<<endl;
	//count words
	for(i=left;i<=len-right-1;i++){
	if(!flag_first_space){//prev letter was not blank
	if((sentence[i]==' ')||(sentence[i]=='\0')){//first space
		flag_first_space=true;
		numwords+=1;
		if(sentence[i]!='\0'){cout<<'*'<<endl;}
	}	
	else{cout<<sentence[i];}
	}
	else{//first space is seen
		if((sentence[i]!=' ')&&(sentence[i]!='\0')){
		cout<<sentence[i];
		flag_first_space=false;
		}
		if(sentence[i]=='\0'){cout<<endl;break;}
	}
	}
	cout<<endl;
	cout<<"Num words: "<<numwords<<endl;
	return 0;
}
