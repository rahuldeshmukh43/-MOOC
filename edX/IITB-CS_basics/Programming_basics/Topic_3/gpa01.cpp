#include<iostream>
using namespace std;
//function declarations
int SqdNumSum(int num);
int shift(int num);

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
//function for computing cyclic right shift of a number by 1 bit
int shift(int num){
	int i,Lsb,ans=0,mulx=1;
	int d;
	Lsb = num%10;//least significant bit
	num /= 10;
	for(i=0;;i++){
		if(num==0){break;}
		d = num%10;
		num /= 10;
		ans += d*mulx;
		mulx *= 10;	
	}
	ans += Lsb*mulx;
	return ans;
}

//program that checks life of hard disk using its rpm
int main(){
	int rpm0,maxRPM, i, irpm;
	int ssd, A, B, C, life;
	bool goodDiskFlag=true;
	cout<<"Enter the RPM: ";cin>>rpm0;
	irpm = rpm0;
	maxRPM=8*rpm0;
	if (!((rpm0>=3524) && (rpm0<=8524))){cout<<"Bad inputs"<<endl; return -1;}
	for(i=0;i<10;i++){
		if (irpm>maxRPM){goodDiskFlag=false;break;}
		ssd = SqdNumSum(irpm);//sum of squares
		A = ssd*323;
		B = shift(irpm);
		C = A + (B%100);
		{//print info
		cout<<" irpm:"<<irpm;
		cout<<" i:"<<i+1;
		cout<<" ssd:"<<ssd;
		cout<<" A:"<<A<<" B:"<<B;
		cout<<" newRPM:"<<C<<endl;
		}
		irpm = C;
	}
	life = i;
	//print stuff
	cout<<"Is Good Disk: "<<boolalpha<<goodDiskFlag<<endl;
	cout<<"Final RPM: "<<irpm<<endl;
	cout<<"Life: "<<life<<endl;
	return 0;
}

