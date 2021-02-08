#include<iostream>
#include<string>
using namespace std;

/* Program to a binary string to gray string and vice versa */

char Xor(char a, char b){
string s;
s+=a;
s+=b;
if(s=="00"){return '0';} 
if(s=="01"){return '1';}
if(s=="10"){return '1';}
if(s=="11"){return '0';}
}

char invert(char c){
if(c=='1'){return '0';}
else{return '1';}
}

string Binary2Gray(string binary){
	int i;
	char temp;
	string gray; 
gray+=binary[0];//MSB
for(i = 1;i<binary.length();i++){
temp = Xor(binary[i],binary[i-1]);
gray+=temp;
}
return gray;
}

string Gray2Binary(string gray){
string binary;
binary+=gray[0];//MSB
for(int i=1;i<gray.length();i++){
if(gray[i]=='0'){binary+=binary[i-1];}
else{
binary+=invert(binary[i-1]);
}
}
return binary;}

int main(){
string inp,gray, gray2bin;
int inp_len;
cout<<"Binary: ";
getline(cin,inp);
inp_len = inp.length();
gray = Binary2Gray(inp);
gray2bin = Gray2Binary(gray);
cout<<"Gray: "<<gray<<endl;
//cout<<endl;
cout<<"Gray2Bin: "<<gray2bin<<endl;
return 0;
}
