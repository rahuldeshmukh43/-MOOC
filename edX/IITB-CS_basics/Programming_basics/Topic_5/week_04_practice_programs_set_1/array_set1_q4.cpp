//Program array_set1_q4.cpp
#include <iostream>
#include<string>

using namespace std;

int main()
{	
	//char array[100];
	string array;
	int i;
	cout<<"Enter a text string : ";
	//cin>>array;
	getline(cin,array);
	//array = cin.get();
	i=0;
	while(array[i]!='\0')
	{
		if(array[i]>=97 && array[i]<=122)
		{
			array[i]=array[i]-32;
		}
		i++;
	}
	cout<<"Upper case string is : "<<array<<endl;
	return 0;
}
