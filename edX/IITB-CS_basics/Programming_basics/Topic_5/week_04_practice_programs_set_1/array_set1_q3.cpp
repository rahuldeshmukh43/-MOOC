//Program array_set1_q3.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i,no_students;
	cout<<"Enter the number of students : ";
	cin>>no_students;
	float marks[no_students];
	float sum = 0;
	cout<<"Enter the marks of students one by one : "<<endl;
	for(i=0;i<no_students;++i)  //reading the no.s and finding sum..
	{
		cin>>marks[i];
		sum=sum+marks[i];
	}
	cout << "The average of entire class is : "<<sum/no_students<<endl;
	return 0 ;
}
