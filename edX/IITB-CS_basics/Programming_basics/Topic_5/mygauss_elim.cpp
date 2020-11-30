#include<iostream>
using namespace std;
//function declarations


//functinos


//main program: simple gaussian elimination
int main(){
	int n,i,j,k;
	float A[100][100],b[100],x[100];
	float div,mulx,sum=0.0;
	//size
	cout<<"Enter size of matrix n: ";cin>>n;
	if(n>100){cout<<"Size "<<n<<">100 not allowed"<<endl; return -1;}
	//read matrix A
	for(i=0; i<n ; i++){
	for(j=0;j<n;j++){
	cout<<"Enter a["<<i<<","<<j<<"]: ";cin>>A[i][j];}}
	//read vector b
	for(i=0;i<n;i++){cout<<"Enter b["<<i<<"]: ";cin>>b[i];}
	//Gaussian elimination on [A|b]
	for(i=0;i<n;i++){//for each row
	//normalize the row
	div= A[i][i];A[i][i] = 1.0;b[i]/=div;
	for(k=i+1;k<n;k++){A[i][k]/=div;}
	if(i<n-1){//make a[i,i] as pivot
	for(j=i+1;j<n;j++){//for each row element below pivot
	//substract the entire pivot row with multiplier
	mulx = A[j][i];A[j][i]=0.0;
	b[j] = b[j] - mulx*b[i];
	for(k=i+1;k<n;k++){A[j][k] = A[j][k] - mulx*A[i][k];}
	}}}
	//solve for x using back substitution
	for(i=n-1;i>=0;i--){
	sum=0.0;
	for(j=i+1;j<n;j++){sum += A[i][j]*x[j];}
	x[i] = (b[i]-sum)/A[i][i];
	}
	//print Upper trig mat
	cout<<"A Upper trig:"<<endl;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	cout<<A[i][j]<<" ";
	}
	cout<<endl;
	}
	//print new B:
	cout<<"Reduced b: [";
	for(i=0;i<n-1;i++){cout<<b[i]<<", ";}
	cout<<b[n-1]<<"]"<<endl;
	//print answer
	cout<<"The solution is x: [";
	for(i=0;i<n-1;i++){cout<<x[i]<<", ";}
	cout<<x[n-1]<<"]"<<endl;
	return 0;
}
