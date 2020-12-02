#include<iostream>
using namespace std;
/*
 * Example of single class inheriting attributes from multiple classes
 */
class Automobile{
double mileage;
float price;
	public:
	Automobile(double x, float y):mileage(x), price(y){}
	float getPrice(){
	return price;
	}	
};

class SolarPowered{
double cellEfficiency;
float price;
	public:
	SolarPowered(double x, float y): cellEfficiency(x), price(y){}
	float getPrice(){return price;}	
};

class SolarAutomobile: public Automobile, public SolarPowered{
int noOfSeats;
	public:
	SolarAutomobile(double a_m, float a_p, double sp_ce, float sp_p, int s):Automobile(a_m, a_p), SolarPowered(sp_ce, sp_p), noOfSeats(s){}
	float getTotalPrice(){
	return Automobile::getPrice() + SolarPowered::getPrice();
	}
};

int main(){
double mileage = 20.5;
float automobilePrice = 40000;
double cellEfficiency = 60.5;
float solarPrice = 10000;
int seats = 4;

SolarAutomobile sa(mileage, automobilePrice, cellEfficiency, solarPrice, seats);
cout<<"SA price: "<<sa.getTotalPrice()<<endl;
//cout<<sa.price<<endl;//price was private and ambiguous
//cout<<sa.getPrice();//request for member is ambiguous as present in both SolarPowered and Automobile
return 0;
}
