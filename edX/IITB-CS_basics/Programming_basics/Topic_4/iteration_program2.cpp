#include<iostream>
using namespace std;

int main(){
	int n,i,x,max,max2;
	cout<<"Enter n: ";cin>>n;
	for(i=0;i<n;i++){
		cout<<"Enter #"<<i+1<<" positive number: ";
		cin>>x;
		if(i==0){max=x;max2=x;}
		else{
			if(x>max){max2 = max; max = x;continue;}
			if(x>max2){max2=x;continue;}
		}
	}
	//print
	cout<<"From the "<<n<<" given numbers, the second highest number is "<<max2<<endl;
	return 0;	
}
