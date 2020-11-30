#include<iostream>
using namespace std;
//function declartations
bool dateVal(int date);

//dateVal function; checks validity of date
bool dateVal(int date){
	//date in the for of ddmmyyyy
	int dd, mm, yr, ddmm;
	bool dateflag=false;
	// find dd, mm, yr
	yr = date%10000;
	ddmm = date/10000;
	dd = ddmm/100;
	mm = ddmm%100;
	// check validity of dd,mm, yr
	if ((dd<1) || (dd>31) || (mm<1) || (mm>12) || (yr<1) ){
	dateflag = true;
	}
	return dateflag;
}

//main function: Prgoram which prints a greeting to the user and 
//then prints out a fortune messsage
int main(){
	int date, time, hash;
	int hh, min;
	bool dateflag, timeflag=false;

	cout<< "Enter a valid date (ddmmyyyy) and time (hhmm)"<<endl;
	cin>>date>>time;
	// check vaidity of inputs
	dateflag = dateVal(date);
	// check for validity of time
	hh = time/100;
	min = time%100;
	if ((hh<1) || (hh>24) || (min<1) || (min>59)){
		timeflag = true;
	}
	// print if bad inputs
	if (dateflag || timeflag){
		cout<< "Bad inputs"<<endl;
		return -1;
	}
	// print greeting based on time
	if (hh>=6 && hh<12){
		cout<<"Good Morning!"<<endl;
	}
	else {
		if (hh>=12 && hh< 18){
			cout<<"Good Afternoon!"<<endl;
		}
		else{cout<<"Good Evening!"<<endl;}
	}	
	// print fortune message
	hash = (date + time)%3; //hash \in \{0,1,2\}
//	cout<<"hash: "<<hash<<endl;
	switch (hash){
	case 0:{cout<<"time and tide wait for none."<<endl;break;}
	case 1:{cout<<"wit beyond measure is the greatest treasure."<<endl;break;}
	default:{cout<<"a stitch in time saves nine."<<endl; break;}
	}
	return 0;
}	


