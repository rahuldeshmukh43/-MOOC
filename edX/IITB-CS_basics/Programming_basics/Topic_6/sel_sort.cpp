#include<iostream>
using namespace std;
int findMaxIdx(int A[], int i, int N);
void swap(int A[], int i_max, int i);

int findMaxIdx(int A[], int i, int N){
	int max=A[i],j, j_max=i;
	for(j=i;j<N;j++){
	if(A[j]>max){j_max=j;max=A[i];}
	}
	return j_max;
}

void swap(int A[], int i_max, int i){
	int temp;
	temp = A[i_max];
	A[i_max]=A[i];
	A[i] = temp;
        return;
}

//program for sorting in decreasing order
//using selection sort
int main(){
	int N, A[100],i,i_max;
	cout<<"Input size of array: ";cin>>N;
	if(N>100){cout<<"Too many elements!"<<endl;return -1;}
	if(N<=0){cout<<"Invalid input!"<<endl;return -1;}
	//read values
	for(i=0;i<N;i++){
	cout<<"Value #"<<i+1<<": ";cin>>A[i];
	}
	//sorting
	for(i=0;i<N;i++){
	//find max btw i and N
	i_max = findMaxIdx(A,i,N);
	//swap i_max with i
	swap(A,i_max,i);	
	}
	//print sorted list
	cout<<"Sorted elements are:"<<endl;
	for(i=0;i<N;i++){cout<<A[i]<<" ";}
	cout<<endl;
	return 0;
}
