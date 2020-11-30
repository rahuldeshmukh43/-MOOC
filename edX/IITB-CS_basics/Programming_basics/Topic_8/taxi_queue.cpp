#include<iostream>
#include<string>
using namespace std;

//define structures
struct Driver{
string name;
int id;
};

struct LinkedTaxi{
int id;
Driver * drv;
LinkedTaxi * next;
};

struct Queue{
LinkedTaxi *front, *end;
int numTaxi;
};


//Program to build and manage a FIFO Taxi queue
int main(){
char cmd;
Queue q;
q={NULL,NULL,0};

while(true){
cout<<"Enter command: 'a' add, 'd' dispatch, 'x' exit program: ";cin>>cmd;
switch(cmd){
	case 'a':{//add taxi to end
		//allocate space for driver and Taxi
		Driver * newDrv; newDrv = new Driver;
		if(newDrv==NULL){cout<<"Memory Allocation Error!";return -1;}		
		LinkedTaxi * newTaxi; newTaxi = new LinkedTaxi;
		if(newTaxi==NULL){cout<<"Memory Allocation Error!";return -1;}
		//take info of taxi and driver
		cout<<"Give driver name: ";
		cin>>newDrv->name;
		cout<<"Give driver id: ";
		cin>>newDrv->id;
		cout<<"Give Taxi id: ";
		cin>>newTaxi->id;
		newTaxi->drv=newDrv;//pointer to new driver
		newTaxi->next = NULL;//last-in ie next is NULL
		//add Taxi and driver to queue
		//check if queue is empty
		if(q.numTaxi==0){//first in queue
		q.front=newTaxi;
		q.end=newTaxi;
		q.numTaxi++;
		}
		else{//there are taxis already in queue
		q.end->next = newTaxi;//link last taxi in queue to the new taxi
		q.end = newTaxi;
		q.numTaxi++;		
		}		
		break;}
	case 'd':{//dispatch taxi from front
		//check if queue is empty
		if(q.numTaxi==0){cout<<"Queue is empty, cannot dispatch taxi!"<<endl;break;}
		//allocate space for dispatched driver and Taxi
		LinkedTaxi * dispTaxi; Driver * dispDrv;
		dispTaxi=new LinkedTaxi;
		if(dispTaxi==NULL){cout<<"Memory Allocation Error!";return -1;}
		dispDrv=new Driver;
		if(dispDrv==NULL){cout<<"Memory Allocation Error!";return -1;}
		//dispatch the front taxi
		dispDrv = q.front->drv;
		dispTaxi = q.front;
		cout<<"Dispatching Taxi-id: "<< dispTaxi->id;
		cout<<" with Driver-name: "<< dispDrv->name <<endl;
		if(q.numTaxi==1){//only one taxi in queue
		q.front=NULL;
		q.end=NULL;
		}
		else{//more than one taxi in queue
		q.front=dispTaxi->next;
		}
		q.numTaxi--;
		//de-allocate space for driver and taxi
		if(dispDrv!=NULL){delete dispDrv;}
		if(dispTaxi!=NULL){delete dispTaxi;}
	       	break;}
	case 'x':{//exit prgram
		 cout<<"Exiting queuing system ..."<<endl;
		 return 0;}
	default :{cout<<"Invalid command!"<<endl;break;}
}
cout<<"--------------------------------"<<endl;
}
return -1;
}
