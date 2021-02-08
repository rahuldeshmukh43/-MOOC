#include<iostream>
using namespace std;
int sign(float x);
//float calc_area(Triangle T);
float my_abs(float x);
/* 
 * Program to read in two triangles and see if they intersect
 */

float my_abs(float x){
if(x>=0){return x;}
else{return -1*x;}
}

int sign(float x){
if(x>=0){return 1;}
else{return -1;}
}

class Point{
	public:
	float x,y;
	Point():x(0.0),y(0.0){}
	Point(float i, float j):x(i),y(j){}
	void read_point(){
	float i,j;
	cout<<"Enter point coordinates x,y:";
	cin>>i>>j;
	x = i; y = j;
	return;}

	void print_point(){
	printf("[%3.2f %3.2f]\n",x,y);
	}
};

class Line{
	float a,b,c; //eq:ax+by+c=0
	public:
		Point p[2];
		
		Line(Point &p1, Point &p2){
		p[0]=p1;p[1]=p2;
		a = (p[0].y -p[1].y);
		b = -1*(p[0].x-p[1].x);
		c = -1*b*p[0].y - a*p[0].x;}

		int LineSign(Point &p1){
		float s;
		s = a*p1.x + b*p1.y + c;
		//cout<<s<<endl;
		return sign(s);
		}

		bool Intersects(Line *L){
		float xx,yy,lam1, lam2;
		if((this->a/this->b)==(L->a/L->b)){return false;}//parallel	
		//find pt of instersection
		xx = -1*(this->c*L->b - L->c*this->b)/(this->a*L->b - L->a*this->b);
		//yy = -1*(this->a*L->c - L->a*this->c)/(this->a*L->b - L->a*this->b);
		//check if pt of intersection is within the line segment	
		lam1 = (xx-this->p[0].x)/(this->p[1].x - this->p[0].x);
		lam2 = (xx-L->p[0].x)/(L->p[1].x - L->p[0].x);

		if((lam1>=0)&&(lam1<=1)&&(lam2>=0)&&(lam2<=1)){//cout<<"lams:"<<lam1<<","<<lam2;
			return true;}//int inside line segment
		else{return false;}
		}
};

class Triangle{
	public:
	Point p[3];

	Triangle(){
	cout<<"Enter Points for Triangle:\n";
	p[0].read_point();
	p[1].read_point(); 
	p[2].read_point();}
	
	Point Compute_Centroid(){
	Point *centroid;
	centroid = new Point;
	for(int i=0;i<3;i++){
	centroid->x+=p[i].x;
	centroid->y+=p[i].y;}
	centroid->x/=3.0; centroid->y/=3.0;
	return *centroid;}

	bool Contains(Point &p1){
	int sign_c,sign_p1,from_idx, to_idx;
	Line *L;
	Point cent;
	cent = this->Compute_Centroid();
	//cent.print_point();
	for(int i=0;i<3;i++){
	
		if(i==2){from_idx=2;to_idx=0;}
		else{from_idx=i;to_idx=i+1;}
		L = new Line(p[from_idx], p[to_idx]);
		sign_c = L->LineSign(cent);
		sign_p1 = L->LineSign(p1);
		//cout<<sign_c<<" "<<sign_p1<<endl;
		if(sign_c!=sign_p1){return false;}
	}
	return true;
	}

	bool Collides(Triangle *T){
	int i,j, t1_from_idx, t1_to_idx, t2_from_idx, t2_to_idx;
	bool flagCollide=false;
	Line *L1, *L2;
	//checn every line pair for intersection
	for(i=0;i<3;i++){
		if(i==2){t1_from_idx=2; t1_to_idx=0;}
		else{t1_from_idx=i; t1_to_idx=i+1;}
		L1 = new Line(this->p[t1_from_idx],this->p[t1_to_idx]);
	for(j=0;j<3;j++){
		if(j==2){t2_from_idx=2; t2_to_idx=0;}
		else{t2_from_idx=j; t2_to_idx=j+1;}
		L2 = new Line(T->p[t2_from_idx], T->p[t2_to_idx]);
		flagCollide = L1->Intersects(L2);
		if(flagCollide){return true;}
	}
	}
	
	return flagCollide;
	}
};

float calc_area(Triangle &T){
	float a;
	a = (T.p[1].x - T.p[0].x)*(T.p[2].y - T.p[0].y) -	    (T.p[2].x - T.p[0].x)*(T.p[1].y - T.p[0].y);
	return 0.5*my_abs(a);
}


// program to check if two triangles intersect
/*
int main(){
	int from_idx, to_idx;
	bool flagIntersect = false;
	//read in two triangles
	Triangle T1, T2;
	//check if T1 contains any vertex of T2
	for(int i=0;i<3;i++){
	flagIntersect = T1.Contains(T2.p[i]);
	if(flagIntersect){
		cout<<"Point #"<<i+1<<" of T2 is inside T1\n";
		T2.p[i].print_point();
		cout<<"Triangles Intersect!\n";return 0;}
	}
	//check if T2 contains any vertex of T1
	for(int i=0;i<3;i++){
	flagIntersect = T2.Contains(T1.p[i]);
	if(flagIntersect){
		cout<<"Point #"<<i+1<<" of T1 is inside T2\n";
		T1.p[i].print_point();
		cout<<"Triangles Intersect!\n";return 0;}
	}

	//check for intersecting edges
	flagIntersect = T1.Collides(&T2);
	if(flagIntersect){cout<<"Triangles Intersect!\n";return 0;}
	cout<<"Triangles do not intersect\n";
	return 0;
}
*/

//Program to print area of triangle
int main(){
	
	Triangle T;
	float area= calc_area(T);
	cout<<"Area of Triangle: "<<area<<endl;

	return 0;
}

//Program to check if the given point lies inside the triangle
/*
int main(){
Triangle T1;
int i=0;
float x,y;
bool flagContains = false;
while(true){
cout<<"\nFor Point #"<<i+1<<"\n";
cout<<"x,y: ";cin>>x>>y;
Point p1(x,y);
flagContains = T1.Contains(p1);
//cout<<"Point #"<<i+1;
//p1.print_point();
if(flagContains){cout<<" is Inside\n";}
else{cout<<"is Outside\n";}
i++;
}
return 0;
}
*/
