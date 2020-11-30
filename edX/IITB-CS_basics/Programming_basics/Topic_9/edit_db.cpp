#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

struct StudentInfo {
int roll; char name[30];
int batch; float marks;
};
//Program to edit a binary file 
//1) read nth line and print name and marks
//2) Given roll no. print info
//3) Given Name/Roll no., change students marks
int main(){

struct StudentInfo s;
FILE *fp_db;
long POS;
int i=0, rec_num, rec_size, N, roll_no;
bool found=false;

rec_size = sizeof(s);

//open file
fp_db = fopen("student.db","rb+");
if(fp_db==NULL){cout<<"COuld not open file!"<<endl; return -1;}

//1) Read nth line and print name and marks
cout<<"Enter line number to be printed: ";cin>>rec_num;
if(rec_num<1){cout<<"Invalid Line number!"<<endl; return -1;}
POS = (rec_num-1)*rec_size;
fseek(fp_db,POS,SEEK_SET);
fread(&s,rec_size,1,fp_db);
//print name and marks
cout<<"Record starting at byte position "<<POS<<" is:\n";
printf("%5d %30s %3d %5.2f\n",s.roll,s.name,s.batch,s.marks);
cout<<"Record Number is: "<<rec_num<<endl;
cout<<"-----------------"<<endl;

//2)Given roll no. print info
rewind(fp_db);//set ptr to starting of file
cout<<"Give Roll no: ";cin>>roll_no;
POS=ftell(fp_db);
while(fread(&s,rec_size,1,fp_db)){
if(s.roll==roll_no){
//found student
found = true;
rec_num = POS/rec_size + 1;
cout<<"Found Roll no: "<<roll_no;
cout<<" at record no: "<<rec_num<<endl;
cout<<"The name and marks are: ";
printf("%30s %5.2f\n",s.name, s.marks);
break;
}
POS=ftell(fp_db);
}
if(!found){cout<<"Invalid Roll no. (out of bounds)!"<<endl; return -1;}
cout<<"-----------------"<<endl;

//3) edit the record in file
rewind(fp_db);
//if(roll_no<10101){cout<<"Invalid roll no!"<<endl; return -1;}
POS = (rec_num-1)*rec_size;//corresponding POS
fseek(fp_db, POS, SEEK_SET);
fread(&s,rec_size,1,fp_db);
//print info
cout<<"Original record starting at byte position "<<POS<<" is:\n";
printf("%5d %30s %3d %5.2f\n",s.roll,s.name,s.batch,s.marks);
cout<<"-----------------"<<endl;
//change marks;
cout<<"Enter new marks for "<<s.name<<": ";cin>>s.marks;
rewind(fp_db);
fseek(fp_db,POS,SEEK_SET);
fwrite(&s,rec_size,1,fp_db);//made the change
//print edited line
rewind(fp_db);
fseek(fp_db,POS,SEEK_SET);
fread(&s,rec_size, 1, fp_db);
cout<<"Modified record starting at byte position "<<POS<<" is:\n";
printf("%5d %30s %3d %5.2f\n",s.roll,s.name,s.batch,s.marks);
cout<<"-----------------"<<endl;
//close file
fclose(fp_db);
cout<<"File edited and closed"<<endl;
return 0;
}
