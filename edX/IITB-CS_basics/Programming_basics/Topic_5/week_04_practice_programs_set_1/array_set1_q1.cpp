//Program array_set1_q1.cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;
	int A[n];
	for (int i = 0 ; i < n ; i++)
	{
		 cout << "Enter element no " << i+1 <<" : ";
		 cin >> A[i];
	}	

	// reversing the array :

	for (int i =0; i<n/2; i++)
	{
		 int temp;
		 temp = A[i];
		 A[i] = A[n-i-1];
		 A[n-i-1] = temp;
	}

	// printing the array after reversed 

	cout << "Printing the reversed array : " << endl; 
	for (int i = 0;i < n ; i++)
	{
	 	cout << A[i] << " " ;
	}
	cout << endl;

	return 0;
}
