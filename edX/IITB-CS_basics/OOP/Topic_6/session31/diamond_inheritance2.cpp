#include<iostream>
using namespace std;

/*
 * Diamond inheritance example: need to use virtual inheritance to avoid ambiguous function call
 */

class student{
int rollNo;
	public:
		student(int a):rollNo(a){}
		int getRollNo(){
		return rollNo;
		}
};

class midsem:virtual public student{
float midSemMarks;
	public:
		midsem(int a, float b):student(a), midSemMarks(b){}
		float getMidSemMarks(){return midSemMarks;}
};

class endsem:virtual public student{
float endSemMarks;
	public:
		endsem(int a, float b):student(a), endSemMarks(b){}
		float getEndSemMarks(){return endSemMarks;}
};

class total: public midsem, public endsem{
float totalMarks;
	public:
	total(int a, float b, float c):student(a), midsem(a,b),endsem(a,c){}
	float getTotal(){
	return midsem::getMidSemMarks()+endsem::getEndSemMarks();
	}
};

int main(){
int roll=1001;
float midM = 32.2, endM=43.4;
total s1(roll, midM, endM);
cout<<s1.getRollNo()<<endl;//call to getRollNo() is ambiguous as there are two candidates 
cout<<s1.getMidSemMarks()<<endl;
cout<<s1.getEndSemMarks()<<endl;
cout<<s1.getTotal()<<endl;
return 0;
}

