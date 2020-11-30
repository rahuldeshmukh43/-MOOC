//Program array_set1_q2.cpp
#include <iostream>
using namespace std;

int linear_search (int array[10], int element)
{
	int i=0,m=0;
	for (i=0;i<10;i++)
		if (array[i]==element){
			m=i;
			//break;//for first match
			continue;//last match
		}
	if (m<10)
		return m;
	else
		return -1;
}

int main ()
{
	int array[10], element=0, i=0;
	cout<<"Program to find an element in the array using linear search technique"<<endl;
	cout<<"Enter 10 elements present in the array:"<<endl;
	for (i=0;i<10;i++)
		cin>>array[i];
	cout<<"Enter the element to be searched : ";
	cin>>element;
	cout<<endl;
	int answer=linear_search(array, element);
	if (answer<0)
		cout<<"The element is not present in the array."<<endl;
	else
		cout<<"The element exists at array index "<<answer<<endl;
	return 0;
}
