#include<iostream>
#include<cmath>
using namespace std;

struct V3 {
double x,y,z;//data members: state variables
//member functions
double length(){return sqrt(x*x+y*y+z*z);}

double dot(V3 const &a){
return x*a.x + y*a.y + z*a.z;
}

V3 add(V3 const &a){
V3 out;
out.x = x + a.x;
out.y = y + a.y;
out.z = z + a.z;
return out;
}

V3 cross(V3 const &a){
V3 out;
/*
 * |i   j   k  |
 * |x   y   z  |
 * |a.x a.y a.z|
 *
 */
out.x = y*a.z -z*a.y;
out.y = -1*(x*a.z - z*a.x);
out.z = x*a.y -y*a.x;
return out;
}

V3 normalize(){
//normalize the vector
V3 out;
double len = sqrt(x*x+y*y+z*z);
out.x = x/len;
out.y = y/len;
out.z = z/len;
return out;
}


V3 scale(double const factor){
V3 out;
out.x = x*factor;
out.y = y*factor;
out.z = z*factor;
return out;
}

void print(){
printf("[%f, %f, %f]\n",x,y,z);
return;
}

};

V3 project(V3 a, V3 b);

V3 project(V3 a, V3 b){
//project x onto a
V3 out = b.normalize();
double d = a.dot(b);
return out.scale(d);
}

int main(){
V3 a,b, unit_a, unit_b,axb, a_on_b;
cout<<"Enter x,y,z for a: ";cin>>a.x>>a.y>>a.z;
cout<<"Enter x,y,z for b: ";cin>>b.x>>b.y>>b.z;
cout<<"Len a:"<<a.length()<<" b:"<<b.length()<<endl;
unit_a = a.normalize();
unit_b = b.normalize();
axb= a.cross(b);
a_on_b = project(a,b);
cout<<"Dot a.b: "<<a.dot(b)<<" b.a: "<<b.dot(a)<<endl;
cout<<"Cross axb: ";axb.print();
cout<<"Project function (a on b): ";
a_on_b.print();
cout<<"Unit a: ";unit_a.print();
cout<<"Unit b: ";unit_b.print();
cout<<"a on b = Unit b scaled by a.b: ";
unit_b.scale(a.dot(b)).print();
cout<<"a+b: ";a.add(b).print();
cout<<"a-b: ";
a.add(b.scale(-1.0)).print();
return 0;
}
