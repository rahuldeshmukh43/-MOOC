#include<iostream>
using namespace std;

// this program prints true/false when the first number 
// is the largest of the three numbers
int main(){
	int A, B, C;
	bool isALargest;
	cout<<"Print three numbers:";
	cin >> A >> B >> C;
	isALargest = (A > B) && (A>C);
	cout <<"A is the largest: ";
	cout <<isALargest<<"\n";
	cout<< "A is greater than B:";
	cout<< boolalpha << (A > B)<<"\n";
	cout << "A is greater than C:";
	cout<< boolalpha << (A>C)<<"\n";
	return 0;
}
