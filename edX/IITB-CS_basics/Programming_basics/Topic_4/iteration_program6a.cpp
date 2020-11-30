#include<iostream>
using namespace std;
float C2F(int C);

float C2F(int C){
	return C*(9.0/5) + 32; 
}

int main(){
	int i;
	cout<<"\tC\t\tF\t"<<endl;
	for(i=10;i<=30;i++){
	cout<<"\t"<<i<<"\t\t"<<C2F(i)<<"\t"<<endl;	
	}
	return 0;
}
