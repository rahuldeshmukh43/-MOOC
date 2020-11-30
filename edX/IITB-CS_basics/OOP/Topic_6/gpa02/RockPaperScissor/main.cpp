/*
 * main.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: rahul
 */

#include<iostream>

#include"weapon.h"

using namespace std;

int main(){
	int r_s,p_s,s_s;
	bool rp, ps, sr;
	Rock R;
	Paper P;
	Scissor S;
	cout<<"Enter strength of Rock, Paper, Scissor: ";
	cin>>r_s>>p_s>>s_s;
	R.setPower(r_s); P.setPower(p_s);S.setPower(s_s);
	rp = R.battle(P);
	ps = P.battle(S);
	sr = S.battle(R);
	/*
	 * cout<<boolalpha<<rp;
	 * cout<<boolalpha<<ps;
	 * cout<<boolalpha<<sr<<endl;
	 */
	cout<<rp;
	cout<<ps;
	cout<<sr<<endl;
	return 0;
}




