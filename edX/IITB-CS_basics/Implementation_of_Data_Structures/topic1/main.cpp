#include<iostream>
#include "gpa01.h"

int main(){
	int s,d;
	int dist;

	SafeMap g(4);
	g.addSafeRoute(0,1);
	g.addSafeRoute(0,2);
	g.addSafeRoute(1,2);
	g.addSafeRoute(2,0);
	g.addSafeRoute(2,3);
	
	while(true){
	cout<<"Enter node ids for safepath (start, dest): ";
	cin>>s>>d;
	dist = g.isReachable(s,d);
	if(dist==-1){
	cout<<"There is no safe path from "<<s<<" to "<<d<<endl;
	}
	else{
	cout<<"There is a safe path from "<<s<<" to "<<d;
	cout<<" and path length is "<<dist<<endl;
	}
	}
	return 0;
}
