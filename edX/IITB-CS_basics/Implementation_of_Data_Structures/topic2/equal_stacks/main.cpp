#include<iostream>
#include<stack>
using namespace std;

//class definitions
class my_stack {
	public: 
		stack<int> s;
		int sum=0;
		int ht=0;
		int top(){return s.top();}
		int pop(){
		//pops element on top
		int top=s.top();
		ht-=1;
		sum-=top;
		s.pop();
		return top;
		}
		void push(int x){
			s.push(x);
			sum+=x;
			ht+=1;
		}
		bool empty(){return s.empty();}
};

//function declarations
my_stack input_stack(int n);


my_stack input_stack(int n){
my_stack in, out;
int temp,i;
for(i=0;i<n;i++){
cin>>temp;
in.push(temp);
}

for(i=0;i<n;i++){
temp= in.top();
in.pop();
out.push(temp);
}
return out;
}


int main(){
	my_stack s1, s2, s3, *s_list[3];
	s_list[0] = &s1;
	s_list[1] = &s2;
	s_list[2] = &s3;
	int i,temp,max_sum, max_idx, sizes[3];
	int n1, n2, n3;
	cout<<"Enter number of cylinders in stacks: ";
	cin>>n1>>n2>>n3;
	cout<<"Stack1 hts: ";
	s1 = input_stack(n1); sizes[0] = s1.sum;
	cout<<"Stack2 hts: ";
	s2 = input_stack(n2); sizes[1] = s2.sum;
	cout<<"Stack3 hts: ";
	s3 = input_stack(n3); sizes[2] = s3.sum;
	while(!(s1.empty() && s2.empty() && s3.empty())){
	max_sum = 0;
	if((s1.sum == s2.sum) && (s2.sum == s3.sum)){
		cout<<"All stacks of same ht: "<<s1.sum<<endl;
		return 0;
	}
	//find max and pop
	for(i=0;i<3;i++){
	temp = s_list[i]->sum;
	if(temp > max_sum){max_sum = temp; max_idx = i;}
	}
	temp = s_list[max_idx]->pop();
	}
	return 0;
}
