#include<iostream>
#include<cmath>
using namespace std;

struct V3{
double x,y,z;
double length(){return sqrt(x*x+y*y+z*z);}
V3 add(V3 const &a){
V3 out;
out.x = x+a.x; out.y = y + a.y; out.z = z+ a.z;
return out;
}
V3 scale(double const factor){
V3 out;
out.x = x*factor; out.y = y*factor; out.z = z*factor;
return out;
}
void print(){printf("[x:%f y:%f z:%f]\n",x,y,z);return;}
};

struct motionSim{
V3 initPos, initVel, initAcc;
V3 currPos, currVel, currAcc;
void init(){
currPos = initPos; currVel = initVel; currAcc= initAcc;
return;
}

void performStep(double const deltaT){
//update pos, vel, acc using deltaT
//d = u*t + 0.5*a*t^2
//pos = pos + d
//v = u+a*t
V3 disp = currVel.scale(deltaT).add(currAcc.scale(0.5*deltaT*deltaT));
currPos = currPos.add(disp);
currVel = currVel.add(currAcc.scale(deltaT));
return;
}

void printPos(){
currPos.print();
return;
}
};


int main(){
motionSim mSim;
V3 initPos, initVel, initAcc;
double deltaT, totalTime, itime;
//read inputs
cout<<"Enter Initial Position (x,y,z):";
cin>>mSim.initPos.x>>mSim.initPos.y>>mSim.initPos.z;
cout<<"Enter Initial Velocity(x,y,z):";
cin>>mSim.initVel.x>>mSim.initVel.y>>mSim.initVel.z;
cout<<"Enter Initial Acc (x,y,z):";
cin>>mSim.initAcc.x>>mSim.initAcc.y>>mSim.initAcc.z;
cout<<"Enter deltaT: ";
cin>>deltaT;
cout<<"Enter Total time: ";
cin>>totalTime;
//validate inputs
if((deltaT<=0)||(totalTime<=0)){cout<<"Invalid Inputs!"<<endl;
return -1;}
//loop and print currPos 
mSim.init();
itime=0;
while(itime<=totalTime){
cout<<"Time: "<<itime<<" Pos: ";mSim.printPos();
itime+=deltaT;
mSim.performStep(deltaT);
}
return 0;
}
