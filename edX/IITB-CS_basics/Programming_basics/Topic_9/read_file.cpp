#include<iostream>
#include<stdio.h>
using namespace std;
//program to read a text file and make a copy of it
int main(){
	char line[200];
	FILE *infile, *outfile;
infile = fopen("readme","r");
outfile = fopen("readme.copy","w");
while(fgets(line, 199, infile)){
//fgets(line, 199, infile);
cout<<line;
fprintf(outfile,"%s" ,line);
//if(feof(infile)){break;}
}
fclose(infile);
fclose(outfile);
return 0;
}
