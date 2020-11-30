#include<iostream>
using namespace std;
void mergeSort(int A[], int start, int end);
void mergeSortedSubarray(int A[], int start, int mid, int end);

void mergeSort(int A[], int start, int end){
	int mid;
	if(end==start+1){//terimination case
	return;}
	mid = (start+end)/2;
	mergeSort(A,start,mid);//sort first half
	mergeSort(A,mid,end);//sort second half
	//merge sorted arrays
	mergeSortedSubarray(A,start, mid, end);
	return;
}

void mergeSortedSubarray(int A[], int start, int mid, int end){
	int i,j, tempA[100], idx=start;
	//merge into tempA
	for(i=start,j=mid;((i<mid)||(j<end));){
	if((i<mid)&&(j<end)){//both subarrays are not exhausted
		if(A[i]>A[j]){tempA[idx]=A[i];i++;}
		else{tempA[idx]=A[j];j++;}
	}
	else{//either of the sorted subarray has exhausted
		if(i<mid){//sub array-2 has exhausted
			tempA[idx]=A[i];i++;}
		else{//sub array-1 has exhausted
			tempA[idx]=A[j];j++;}
	}
	idx++;
	}
	//copy tempA back to A
	for(i=start;i<end;i++){A[i]=tempA[i];}
	return;
}

int main(){
	int i,N, A[100];
	cout<<"Size of array to be sorted: ";cin>>N;
	if((N<=0)||(N>100)){cout<<"Invalid inputs!"<<endl; return -1;}
	//read values:
	for(i=0;i<N;i++){
	cout<<"Enter element #"<<i+1<<": ";cin>>A[i];
	}
	//start sorting
	mergeSort(A,0,N);
	//print sorted array
	cout<<"Sorted array:"<<endl;
	for(i=0;i<N;i++){
	cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
