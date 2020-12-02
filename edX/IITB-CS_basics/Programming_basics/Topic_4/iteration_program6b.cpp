#include<iostream>
using namespace std;
float C2F(int C);

float C2F(int C){
	return C*(9.0/5) + 32; 
}

int main(){
	int i=10;
	cout<<"\tC\t\tF\t"<<endl;
	while(i<=30){
	cout<<"\t"<<i<<"\t\t"<<C2F(i)<<"\t"<<endl;	
	i+=1;
	}
	return 0;
}
