#include<iostream>
using namespace std;
int * getArray1D(int n);
int ** getArray2D(int m, int n, int **Aptr);

int * getArray1D(int n){
	int *row;
	row = new int[n];
	//read data
	for(int i=0;i<n;i++){
	cout<<"\tEnter col#"<<i+1<<": ";
	cin>>*(row+i);
	}
	return row;
}

int ** getArray2D(int m, int n, int **Aptr){
	int i;
	//m rows n columns
	for(i=0; i<m; i++){//for each row
	cout<<"Enter data for row #"<<i+1<<endl;
	*(Aptr + i) = getArray1D(n);//1D array of size n	
	}
	return Aptr;
}

int main(){
int **Array, m,n;
cout<<"Enter array size m,n: ";cin>>m>>n;
Array = new int * [m];//1D array
Array = getArray2D(m,n,Array);

//print Array
for(int i=0;i<m; i++){
for(int j=0;j<n; j++){
cout<<*(*(Array+i)+j)<<" ";
}
cout<<endl;
}
return 0;
}

