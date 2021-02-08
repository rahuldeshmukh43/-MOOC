#include<iostream>
#include "Stack_array.h"
using namespace std;

//Stack using array
Stack::Stack():size(0){}

bool Stack::IsEmpty(){
if(size==0){return true;}
else{return false;}}

bool Stack::IsFull(){
if(size==MAX_SIZE){return true;}
else{return false;}}

bool Stack::Top(char &top_el){
if(size==0){return false;}
else{top_el=s[size-1];return true;}}

bool Stack::Push(char el){
if(size==MAX_SIZE){return false;}
s[size++]=el;
return true;}

bool Stack::Pop(char &el){
if(size==0){return false;}
size--;
el = s[size];
return true;}

//Queue using array
Queue::Queue():size(0){}

bool Queue::IsEmpty(){
if(size==0){return true;}
else{return false;}}

bool Queue::IsFull(){
if(size==MAX_SIZE){return true;}
else{return false;}}

bool Queue::Front(char &f_el){
if(size==0){return false;}
else{f_el=q[0];return true;}}

bool Queue::End(char &end_el){
if(size==0){return false;}
else{end_el=q[size-1];return true;}}

bool Queue::Push(char el){
if(size==MAX_SIZE){return false;}
q[size++]=el;
return true;}

bool Queue::Pop(char &el){
if(size==0){return false;}
el=q[0];
size--;
int i;
for(i=0;i<size;i++){
	q[i]=q[i+1];
}
return true;}


