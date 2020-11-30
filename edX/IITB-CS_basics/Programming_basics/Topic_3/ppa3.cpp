#include<iostream>
using namespace std;
//function declarations
int SqdNumSum(int num);

//function that computes the sum of squares of individual digits of the the number
int SqdNumSum( int num ){
	int d,sum=0;
	//loop and add squares
	for(int i=0;;i++){
		if(num==0){break;}
		d = num%10;
		sum += d*d;
		num /= 10;
	}
	return sum;
}

//program that checks if input is a happy number
int main(){
	int num, i, imax=10;
	int next_num, old_num, final_num, cycle_count;
	bool happyFlag=false;
	//input the number
	cout<<"Enter the number: "; cin>>num;
	old_num=num;
	//loop 
	for(i=0;i<imax;i++){
		next_num=SqdNumSum(old_num);//sum of squares
		//cout<<"**debug**: i:"<<i<<" next_num:"<<next_num<<endl;
		if(next_num==1){happyFlag=true;break;}
		old_num = next_num;
	}
	final_num = next_num;
	cycle_count = (happyFlag)?i+1:i;//as starting from 0
	//print stuff
	cout<<"Is happy: "<<boolalpha<<happyFlag<<endl;
	cout<<"final num: "<<final_num<<endl;
	cout<<"cycle count: "<<cycle_count<<endl;	
	return 0;
}

