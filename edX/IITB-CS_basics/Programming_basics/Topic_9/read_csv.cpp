#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//Program to read CSV file and write the content in different format to output file
int main(){
int i,j,k,N=0;
FILE *fpin, *fpout;
char linestr[80],outstr[80],head[80],sroll[6],sname[30], sbatch[4], smarks[10];
int sr, sb;
float sm;
char sn[30];

fpin=fopen("CSV_data.txt","r");
fpout = fopen("marks_data.txt","w");
if((fpin==NULL)||(fpout==NULL)){
cout<<"could not open file!"<<endl;
return -1;}

fgets(linestr,79,fpin);
while(!feof(fpin)){
i=0;k=0;
//separate out sroll, sname, sbatch, smarks
while((sroll[i++]=linestr[k++])!=',');
sroll[i-1]='\0';i=0;
while((sname[i++]=linestr[k++])!=',');
for(j=i-1;j<29;j++){sname[j]=' ';}
sname[29]='\0';i=0;
while((sbatch[i++]=linestr[k++])!=',');
sbatch[i-1]='\0';i=0;
while((smarks[i++]=linestr[k++])!='\0');
smarks[i-1]='\0';i=0;
//format field values for outfile
sscanf(sroll,"%d",&sr);//formatted string to sr
sscanf(sname,"%s",sn);
sscanf(sbatch,"%d",&sb);
sscanf(smarks,"%f",&sm);
//print to outfile
sprintf(outstr,"%5d %30s %3d %5.2f\n",sr,sn,sb,sm);
printf("%s",outstr);
fprintf(fpout,"%s",outstr);
//read next line
fgets(linestr,79,fpin);
N+=1;
}
cout<<"\nInput file has been read and printed\n";
cout<<"Output file marks_data.txt created\n";
cout<<N<<" records written to output file\n";
fclose(fpin);
fclose(fpout);
return 0;
}
