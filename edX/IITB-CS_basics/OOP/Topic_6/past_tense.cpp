#include<iostream>
#include<cstring>
using namespace std;
/*
 * Program which prints out the past tense of 
 * a verb. Based on if it is a regular or an irregular verb
 */

class verb {
	protected:
	string root;
	public:
	string getRoot(){return root;}
	virtual string get_past() = 0;//pure virtual
};

class regular: public verb{
//past tense is just root + 'ed'
	public:
	regular(string r){root=r;}
	string get_past(){
	return root + "ed";}
};

class irregular:public verb {
//past tense is a special word
string past;
	public:
	irregular(string r, string p){
	root=r;past=p;}
	string get_past(){
	return past;}
};

int main(){
verb* v;
regular r[2]={regular("watch"),regular("play")};
irregular ir[3]={irregular("speak","spoke"), irregular("is","was"), irregular("go","went")};

int i;
string query;
bool found=false;

do{
cout<<"Enter the query verb: ";
cin>>query;

//find in regular dict
for(i=0;i<2;i++){
v=&r[i];
if(v->getRoot()==query){
found = true;
cout<<"Past Tense: ";
cout<<v->get_past()<<endl;
break;
}
}
if(found==true){continue;}
//find in irregular dict
for(i=0;i<3;i++){
v=&ir[i];
if(v->getRoot()==query){
found = true;
cout<<"Past Tense: ";
cout<<v->get_past()<<endl;
break;
}
}

if(found ==false ){
cout<<"Word not in dictionary\n";
}
found = false;

}while(true);
return 0;
}
