#include<iostream>
using namespace std;
//function decs
int comparator(int audience[][2], int idx1, int idx2);
void sorting(int audience[][2], int N, int &i_index, int &j_index);
void merge(int sortedarray[][2], int mergedarray[][2], int i_idx, int j_idx, int numElements);
long unsigned int power(int base, int exp);
void selectionSort(int audience[][2], int start, int end);
int findMinidx(int audience[][2], int start, int end);
int ecode(int base, int exp);
//function defs
int comparator(int audience[][2], int idx1, int idx2){
/* using power function: does not work for big inputs, ecode is better and cheaper
 * long unsigned int p1, p2;
p1= power(audience[idx1][0], audience[idx1][1]);
p2= power(audience[idx2][0], audience[idx2][1]);
p1 = p1%100;
p2 = p2%100;
*/
//using ecode
int p1,p2;
p1= ecode(audience[idx1][0], audience[idx1][1]);
p2= ecode(audience[idx2][0], audience[idx2][1]);
if(p1>p2){return -1;}
else{
if(p1<p2){return 1;}
else{return 0;}
}
}

int ecode(int base, int exp){
	int i, code=1;
	for(i=0;i<exp;i++){
	code*=base;
	code%=100;
	}
	return code;
}

void sorting(int audience[][2], int N, int &i_index, int &j_index){
	int i;
	bool flag_i=true, flag_j = true;
	// find i_index: stating from 0 till which ecode are in increasing order
	//fing j_index: starting from N-1 till which ecode are in decreasing order
	for(i=0;i<N-1;i++){
	if(flag_i){
	if(comparator(audience,i,i+1)>=0){//i+1 is bigger
	i_index=i+1;}
	else{flag_i=false;}
	}

	if(flag_j){
	if(comparator(audience,N-1-i,N-2-i)<=0){//N-1-i is bigger
	j_index=N-2-i;}
	else{flag_j=false;}
	}

	if(!(flag_i||flag_j)){break;}
	}
	//sort rows from i_index+1 to j_index-1 in increaasing order using selection sort
	selectionSort(audience, i_index+1, j_index-1);
	return;
}

int findMinidx(int audience[][2], int start, int end){
int i,min_idx=start;
for(i=start+1; i<=end; i++){
if(comparator(audience,min_idx,i)>0){continue;}
else{min_idx=i;}
}
return min_idx;
}

void selectionSort(int audience[][2], int start, int end){
	int min_idx, temp[2];
	if(end==start){return;}//nothing to do
	min_idx = findMinidx(audience,start,end);
	//swap min_idx and start data
	if(start!=min_idx){
	temp[0]=audience[start][0];
	temp[1]=audience[start][1];
       	audience[start][0] = audience[min_idx][0];	
       	audience[start][1] = audience[min_idx][1];	
       	audience[min_idx][0] = temp[0]; 
       	audience[min_idx][1] = temp[1];}
	return selectionSort(audience, start+1, end);
}

void merge(int audience[][2], int mergedarray[][2], int i_idx, int j_idx, int numElements){
int i,j,idx=0;
//merge 0-i_idx and j_idx-N-1 in increasing order
for(i=0,j=j_idx; ((i<=i_idx)||(j<numElements));){
if((i<=i_idx)&&(j<numElements)){
	if(comparator(audience,i,j)>=0){//i is smaller
	mergedarray[idx][0] = audience[i][0];
	mergedarray[idx][1] = audience[i][1];
	i++;
	}
	else{//j is smaller
	mergedarray[idx][0] = audience[j][0];
	mergedarray[idx][1] = audience[j][1];
	j++;
	}
}
else{
	if(i<=i_idx){//j-list is fin
	mergedarray[idx][0] = audience[i][0];
	mergedarray[idx][1] = audience[i][1];
	i++;
	}
	else{//i-list is fin
	mergedarray[idx][0] = audience[j][0];
	mergedarray[idx][1] = audience[j][1];
	j++;
	}
}
idx++;
}
//append i_idx+1 - j_idx-1
for(i=i_idx+1;i<j_idx;i++){
mergedarray[idx][0] = audience[i][0];
mergedarray[idx][1] = audience[i][1];
idx++;
}
return;
}

long unsigned int power(int base, int exp){
	if(exp==1){return base;}
	else{return base*power(base, exp-1);}
}

//main
int main(){
int i, N, i_idx=0,j_idx=0,min_idx;
int audience[100][2], mergedarray[100][2];
//take input
cout<<"Enter Num rows: ";cin>>N;
if((N<=0)||(N>100)){cout<<"Invalid inputs!"<<endl;return -1;}
for(i=0;i<N;i++){
cout<<"base #"<<i+1<<": "; cin>> audience[i][0];
cout<<"exp  #"<<i+1<<": "; cin>> audience[i][1];
}
j_idx=N;
//sort & merge
min_idx = findMinidx(audience,4,6);
cout<<"min_idx: "<<min_idx<<endl;

sorting(audience, N, i_idx, j_idx);
cout<<"i_idx: "<<i_idx<<" j_idx: "<<j_idx<<endl;
merge(audience, mergedarray, i_idx, j_idx, N);
//print merged array
cout<<"merged array:"<<endl;
cout<<"#\tbase\texp"<<endl;
for(i=0;i<N;i++){
cout<<i+1<<"\t";
cout<< mergedarray[i][0]<<"\t";
cout<<mergedarray[i][1]<<endl;
}

return 0;
}

