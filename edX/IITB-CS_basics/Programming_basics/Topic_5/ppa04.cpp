#include<iostream>
using namespace std;

//Program for finding max profit on 5 day window
int main(){
	int price[5],i, i_buy=0, i_sell=0, i_profit=0,max_prof=0;
	//ask for input
	cout<<"Enter weekly prices:"<<endl;
	for(i=0;i<5;i++){
	cout<<"Price for day #"<<i+1<<": ";
	cin>>price[i];
	}
	max_prof = price[1]-price[0];
	for(i=1;i<5;i++){
	//if increasing
	if(price[i_buy]<=price[i]){
		//update i_sell and profit
		i_sell=i;
		i_profit=price[i_sell]-price[i_buy];
		if(i_profit>max_prof){max_prof=i_profit;}
	}
	else{//cheaper price available		
		i_profit = price[i]-price[i_buy];
		if(i_profit>max_prof){i_sell=i;max_prof=i_profit;}
		i_buy=i;		
	}
	}
	//print info
	cout<<"Max profit: "<<max_prof<<endl;
	return 0;
}
