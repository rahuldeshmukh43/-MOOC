#include<iostream>
using namespace std;
void insertion_sort(int list[], int N);
void swap(int list[], int i, int j);
void shell_sort(int list[], int N);
void heap_sort(int list[], int N);
void quicksort(int list[],int start, int end);
void quicksort2(int list[],int start, int end);

void swap(int list[],int i, int j){
int temp;
if(i==j){return;}
if((i<0)||(j<0)){return;}
temp =list[i];
list[i] = list[j];
list[j]= temp;
return;
}

void insertion_sort(int list[], int N){
int i,j,v;
for(i=1;i<N;i++){
	v=list[i];
if(list[i-1]<list[i]){continue;}
else{//smaller num
	//swap i and i-1
	swap(list,i,i-1);
	for(j=i-2;j>=0;j--){
	if(list[j]<v){//v is bigger: do nothing
		break;}
	else{//v is smaller: swap 
		swap(list,j,j+1);
	}
	}
}
}
return;
}

void shell_sort(int list[], int N){
int gaps[8]={701, 301, 132, 57, 23, 10 ,4,1};
int i,j,k, gap, temp;
for(i=0;i<8;i++){//for each gap value
gap = gaps[i];
//do gapped- insertion sort
for(j=gap;j<N;j++){//each position of gap sequence
temp = list[j];//last element of cur list: 0-j
//gap sort cur list
for(k=j; ((k>=gap) && (list[k-gap]>temp)); k-=gap){
	//k>=gap : k is decreasing by multiple of gap, k=gap: do nothing as only one element. k>=gap: check if sorted?
	//list[k-gap]>temp: if k-gap element is bigger then not sorted. put list[k-gap] at list[k]
	list[k] = list[k-gap];// shift right
}
//put temp at k
list[k]=temp;
}
}
return;
}

void heap_sort(int list[], int N){
	//hard to code now
return;
}

void quicksort(int list[],int start, int end){
	//assume pivot is last element
int i,j, temp;
if(end<=0){return;}
if(start>=end){return;}//only one element
//find correct position of pivot element
temp = list[end];//pivot element
for(i=start,j=end;((j>=0)&&(i<=end));){
if(list[i]>temp){
swap(list,i,j-1);
swap(list,j-1,j);//pivot now at j-1
j--;
}
else{i++;}
if(j<=i){break;}
}
//quicksort subarrays
quicksort(list,start,j-1);
quicksort(list,j+1,end);
return;
}

void quicksort2(int list[],int start, int end){
	//assume pivot is last mid element
int i,j, temp, mid;
if(end<=0){return;}
if(start>=end){return;}//only one element
//find correct position of pivot element
mid= (start+end)/2;
temp = list[mid];//pivot element
//make pivot at correct place in first half
for(i=start,j=mid;((j>=0)&&(i<=mid));){
if(list[i]>temp){
swap(list,i,j-1);
swap(list,j-1,j);//pivot now at j-1
j--;
}
else{i++;}
if(j<=i){break;}
}
//make pivot correct in second half
for(i=end,j=j;((j<end)&&(i>=mid));){
if(list[i]<temp){
swap(list,i,j+1);
swap(list,j+1,j);//pivot now at j-1
j++;
}
else{i--;}
if(j>=i){break;}
}
//quicksort subarrays
quicksort2(list,start,j-1);
quicksort2(list,j+1,end);
return;
}

int main(){
	int N,list[100],i;
	cout<<"Enter N: ";cin>>N;
	if((N<=0)||(N>100)){cout<<"Invalid input!";return -1;}
	for(i=0;i<N;i++){
	cout<<"element #"<<i+1<<": ";
	cin>>list[i];	
	}
	//sort
	//insertion_sort(list, N);	
	//shell_sort(list,N);
	//quicksort(list,0,N-1);
	quicksort2(list,0,N-1);
	//print sorted list
	cout<<"sorted list:"<<endl;
	for(i=0;i<N;i++){
	cout<<list[i]<<" ";
	}
	cout<<endl;
	return 0;
}
