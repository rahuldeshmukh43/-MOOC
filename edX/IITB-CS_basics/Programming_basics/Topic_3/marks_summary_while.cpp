#include<iostream>
using namespace std;
// program for calculating the av, max, min of marks
// of students. The loop ends when someone enters -1000 as marks
int main(){
	int min, max, marks, sum=0;
	float av, count=0.0;
	// while loop
	while(true){
		cout<<"Enter marks for student #"<<count+1.0<<": "<<endl;
		cin >> marks;
		//check for loop termination condition
		if (marks==-1000){break;}
		// update aggregates & count
		sum += marks;
		if (count==0.0){//min max initialization
		min = marks;
		max = marks;
		}
		//update min and max using conditional expressions
		min = (marks < min) ? marks : min;
		max = (marks > max) ? marks : max;
		count += 1.0;
	}
	//compute av
	av = sum/(count);	
	//print stats
	cout << "Class Average: "<<av<<endl;
	cout<< "Min: "<< min << endl;
	cout << "Max: "<< max << endl;
	return 0;
}
