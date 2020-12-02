#include<iostream>
#include<cstring>
using namespace std;
void Dec2base(int num, int base);
void rev_str(char *inp_str, int len);

void Dec2base(int num, int base){
char outstr[100];
int i, len=0;
const char *alphabet="0123456789ABCDEF";
while(true){
i=num%base;
outstr[len]=alphabet[i];
len++;
num = (num)/base;
if(num==0){break;}
}
outstr[len]='\0';
rev_str(outstr, len);
printf("%s",outstr);
return;
}

void rev_str(char *inp_str, int len){
int i,mid; char temp;
mid=(len)/2;
for(i=0;i<mid;i++){
temp = *(inp_str +i);
*(inp_str+i)=*(inp_str+len-i-1);
*(inp_str+len-i-1)=temp;
}
return;
}

int main(){
int i;
cout<<"Enter decimal integer: ";cin>>i;
cout<<"Binary: ";
Dec2base(i,2);
cout<<endl;
cout<<"Octal: ";Dec2base(i,8);cout<<endl;
cout<<"Hex: ";Dec2base(i,16);cout<<endl;

return 0;
}
