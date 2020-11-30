#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct studentinfo{
int roll;
char name[30];
int batch;
float marks;
};

int main(){
struct studentinfo s;
int count=0, rec_size;
int r,b;
float m;
char n[30];
FILE *fpin, *fpout;

rec_size = sizeof(s);

fpin = fopen("marks_data.txt","r");
if(fpin==NULL){cout<<"could not open file"<<endl;return -1;}
fpout = fopen("student.db","wb");
if(fpout==NULL){cout<<"could not open file"<<endl;return -1;}

fscanf(fpin,"%d %s %d %f",&r,n,&b,&m);
while(!feof(fpin)){
//put data into structure
s.roll=r; s.batch=b; s.marks = m;
strcpy(s.name,n);
//write to out file
fwrite(&s,rec_size,1,fpout);
printf("%2d %5d %30s %3d %2.5f\n",count+1,s.roll,s.name,s.batch,s.marks);
//read next line
fscanf(fpin,"%d %s %d %f",&r,n,&b,&m);
count++;
}
//close files
fclose(fpin);
fclose(fpout);
//print info
cout<<"marks_data.txt file read and printed\n";
cout<<"Database file student.db created with student info\n";
cout<<"Total records written: "<<count<<endl;
return 0;
}

