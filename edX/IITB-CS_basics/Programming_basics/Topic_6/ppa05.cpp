#include<iostream>
using namespace std;
//PPA05: sorting
//function decs
int comparator( float marksarray[][2], int idx1, int idx2);
int selectionSort2(float array[][2], int numElements);
int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numelements);
void mergeSort(float array[][2],int start, int end);
void mergeSortedSubarray(float array[][2], int start, int mid, int end);

//helping functions
float sqrt(float num);
float rms(float num1, float num2);
float myabs(float num);

//function defs
int comparator( float marksarray[][2], int idx1, int idx2){
float rms1, rms2;
//compute rms for rows idx1, idx2
rms1 = rms(marksarray[idx1][0], marksarray[idx1][1]);
rms2 = rms(marksarray[idx2][0], marksarray[idx2][1]);
//compare rms
if(rms1>rms2){return -1;}//idx1 is greater
else{
	if(rms1<rms2){return 1;}//idx2 is greater
	else{//rms1 == rms2
		if(marksarray[idx1][1]>marksarray[idx2][1]){return -1;}
		else{
			if(marksarray[idx1][1]==marksarray[idx2][1]){return 0;}
			else{return 1;}
			}
	}
}
}

int selectionSort2(float array[][2], int numElements){
int brkpt=0, i, cmp, tempA[2];
//find break point
for(i=0;i<numElements-1;i++){
cmp = comparator(array, numElements-1-i, numElements-i-2);
if(cmp==-1){brkpt=numElements-i-1;break;}
}
//sort remaining data 0-(brkpt-1) in increasing order using merge sort
mergeSort(array,0,brkpt);
//return break point
return brkpt;
}

int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numelements){
int num_non_dup,i,j,idx=0,count=0;
bool flag_duplicate;
for(i=0,j=0;((i<break_point)||(j<numelements-break_point));){
	flag_duplicate=false;
if((i<break_point)&&(j<numelements-break_point)){
	switch (comparator(sortedarray,i,numelements-1-j)){
		case 1:{//i is smaller
			mergedarray[idx][0]=sortedarray[i][0];
			mergedarray[idx][1]=sortedarray[i][1];
			i++;
			count++;
			break;
			}

		case 0:{//found duplicate
		      	i++;
		       	j++;	
			flag_duplicate=true;
			break;	       
		       }

		case -1:{//numelements-1-j is smaller
			mergedarray[idx][0]=sortedarray[numelements-1-j][0];
			mergedarray[idx][1]=sortedarray[numelements-1-j][1];
			j++;
			count++;
			break;  
		       }
	
	}
}
else{
	if(i<break_point){
	mergedarray[idx][0]=sortedarray[i][0];
	mergedarray[idx][1]=sortedarray[i][1];
	i++;
	count++;
	}
	else{
	mergedarray[idx][0]=sortedarray[numelements-1-j][0];
	mergedarray[idx][1]=sortedarray[numelements-1-j][1];
	j++;
	count++;
	}

}
if(!flag_duplicate){idx++;}
}
return count;
}

void mergeSort(float array[][2],int start, int end){
	int mid;
	//sort start-end not-inclusive of end
	if(end==0){return;}
	if(end==start+1){return;}//only one element: nothing to do;
	mid= (start+end)/2;
	mergeSort(array,start,mid);
	mergeSort(array,mid,end);
	mergeSortedSubarray(array,start,mid,end);
	return;
}

void mergeSortedSubarray(float array[][2], int start, int mid, int end){
int i,j,tempA[100][2],idx=start;
for(i=start,j=mid;((i<mid)||(j<end));){
	if((i<mid)&&(j<end)){//both sub arrays are not finished
		if(comparator(array,i,j)<0){
		tempA[idx][0] = array[j][0];
		tempA[idx][1] = array[j][1];
		j++;
		}
		else{	
		tempA[idx][0] = array[i][0];
		tempA[idx][1] = array[i][1];
		i++;
		}
	}
	else{//either of the  sub arrays is finished
		if(i<mid){//subarray-1 is not finished
		tempA[idx][0] = array[i][0];
		tempA[idx][1] = array[i][1];
		i++;
		}
		else{
		tempA[idx][0] = array[j][0];
		tempA[idx][1] = array[j][1];
		j++;
		}
	}
	idx++;
}
//copy tempA back to array
for(i=start;i<end;i++){
array[i][0] = tempA[i][0];
array[i][1] = tempA[i][1];
}
return;
}


//helping functions
float myabs(float num){
if(num>=0.0){return num;}
else{return -1.0*num;}
}

float sqrt(float num){
//sqrt using newtons method
// f(x) = x^2 -num = 0
// f'(x)= 2x
float tolx=0.001, tolf=0.001, x_str, x_prev;
int i,max=10;
if(num==0){return 0.0;}
x_str = 0.5*num;//x0
for(i=0;i<max;i++){
	//newton step
	x_prev= x_str;
	x_str = x_prev - (x_prev*x_prev - num)/(2*x_prev);
	if((myabs(x_str-x_prev)<tolx)||(myabs(x_str*x_str-x_prev*x_prev)<tolf)){//reached tolerance
	return x_str;
	}
}
cout<<"***sqrt("<<num<<"):"<<x_str<<"***"<<endl;
return x_str;
}

float rms(float num1, float num2){
return 0.5*sqrt((num1*num1)+(num2*num2));
}

//main function
int main(){
int numElements, i, brkpt, num_non_dup;
float marksarray[100][2], mergedarray[100][2];
//read input
cout<<"number of students: ";cin>>numElements;
if((numElements<=0)||(numElements>100)){cout<<"Invalid inputs!";return -1;}
for(i=0;i<numElements;i++){
cout<<"midsem #"<<i+1<<": ";cin>>marksarray[i][0];
cout<<"endsem #"<<i+1<<": ";cin>>marksarray[i][1];
}
//find breakpoint
brkpt=selectionSort2(marksarray,numElements);
//cout<<"brkpt:"<<brkpt<<endl;
/*
//print sorted array
cout<<"sorted array: "<<endl;
cout<<"#\tmidsem\tendsem"<<endl;
for(i=0;i<numElements;i++){
cout<<i+1<<"\t";
cout<<marksarray[i][0]<<"\t";
cout<<marksarray[i][1]<<endl;
}
cout<<"-------------"<<endl;
//
*/
num_non_dup = merge(marksarray, mergedarray, brkpt, numElements);
//cout<<"num_non_dup:"<<num_non_dup<<endl;
//print merged array data:
cout<<"merged array: increasing order"<<endl;
cout<<"#\tmidsem\tendsem"<<endl;
for(i=0;i<num_non_dup;i++){
cout<<i+1<<"\t";
cout<<mergedarray[i][0]<<"\t";
cout<<mergedarray[i][1]<<endl;
}
return 0;
}
