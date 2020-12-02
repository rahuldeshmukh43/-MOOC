#include<iostream>
using namespace std;

//struct decls
struct LinkedNodes{
int nodeId;
LinkedNodes * next;
};

struct myNode{
int id;
LinkedNodes * outgoing;
LinkedNodes * incoming;
};

//func decls
void initNodes(myNode * nodes, int numNodes);
void addEdge(myNode * nodes, int start, int end);
void getOutgoingNodes(myNode *nodes, int i, int *nodesArray, int &num);
void getIncomingNodes(myNode *nodes, int i, int *nodesArray, int &num);

//func defs
void initNodes(myNode * nodes, int numNodes){
int i;
for(i=0; i<numNodes; i++){//add nodes serially
nodes[i].id = i+1;
nodes[i].outgoing = NULL;
nodes[i].incoming = NULL;
}
return;
}

void addEdge(myNode * nodes, int start, int end){

bool repeated=false;
int i_idx;
LinkedNodes *iLinkNode;

//check for repeated edge
iLinkNode=nodes[start-1].outgoing;
while(iLinkNode!=NULL){
if(iLinkNode->nodeId==end){repeated=true;break;}
iLinkNode = iLinkNode->next;
}
if(repeated){return;}

//allocate space for linked nodes for start and end
LinkedNodes *endNode,*startNode;
endNode = new LinkedNodes; startNode= new LinkedNodes;
if((startNode==NULL)||(endNode==NULL)){cout<<"MALLOC ERROR!"<<endl; return;}
//put info in linked nodes
endNode->nodeId=end;
startNode->nodeId=start;

//add outgoing edge
//if(nodes[start-1].outgoing==NULL){
//endNode->next=NULL;
//nodes[start-1].outgoing = endNode;
//}
//else{
endNode->next = nodes[start-1].outgoing;
nodes[start-1].outgoing = endNode;
//}
//add incoming edge
//if(nodes[end-1].incoming==NULL){
//startNode->next=NULL;
//nodes[end-1].incoming = startNode;
//}
//else{
startNode->next = nodes[end-1].incoming;
nodes[end-1].incoming = startNode;
//}
return;
}

void getOutgoingNodes(myNode *nodes, int i, int *nodesArray, int &num){
int j;
LinkedNodes *iLinkNode;
iLinkNode = nodes[i].outgoing;
if(iLinkNode==NULL){num=0;return;}
//find num
while(iLinkNode!=NULL){
iLinkNode = iLinkNode->next;
num++;
}
//make nodesArray
iLinkNode = nodes[i].outgoing;
for(j=0;j<num;j++){
nodesArray[j] = iLinkNode->nodeId;
iLinkNode = iLinkNode->next;
}
return;
}

void getIncomingNodes(myNode *nodes, int i, int *nodesArray, int &num){
int j;
LinkedNodes *iLinkNode;
iLinkNode = nodes[i].incoming;
if(iLinkNode==NULL){num=0;return;}
//find num
while(iLinkNode!=NULL){
iLinkNode = iLinkNode->next;
num++;
}
//make nodesArray
iLinkNode = nodes[i].incoming;
for(j=0;j<num;j++){
nodesArray[j] = iLinkNode->nodeId;
iLinkNode = iLinkNode->next;
}
return;
}

int main(){
int i,j, numNodes, numEdges, start, end, num;
int *In_nodesArray, *Out_nodesArray;
LinkedNodes *inLinkNode, *outLinkNode;
//read numNodes
cout<<"Enter number of nodes: ";cin>>numNodes;
if((numNodes<0)||(numNodes>100)){cout<<"Invalid input!"<<endl;return -1;}
//init nodes
myNode *nodes;
nodes = new myNode[numNodes];//array of node ptrs
if(nodes==NULL){cout<<"MALLOC ERROR!"<<endl;return -1;}
initNodes(nodes, numNodes);
//add edges
cout<<"Enter number of edges: ";cin>>numEdges;
if((numEdges<0)||(numEdges>100)){cout<<"Invalid input!"<<endl;return -1;}
for(i=0;i<numEdges;i++){
cout<<"Edge #"<<i+1<<" start, end: ";cin>>start>>end;
if((start<0)||(end<0)||(start>numNodes)||(end>numNodes)){cout<<"Invalid input!";return -1;}
addEdge(nodes, start, end);
}
//print add edge
cout<<"-------------"<<endl;
for(i=0;i<numNodes;i++){
inLinkNode= nodes[i].incoming;
outLinkNode=nodes[i].outgoing;
cout<<"Node #"<<i+1;
cout<<" Incoming: {";
while(true){
if(inLinkNode==NULL){break;}
cout<<inLinkNode->nodeId;
cout<<", ";
inLinkNode=inLinkNode->next;
}
cout<<"} Outgoing: {";
while(true){
if(outLinkNode==NULL){break;}
cout<<outLinkNode->nodeId;
cout<<", ";
outLinkNode=outLinkNode->next;
}
cout<<"}"<<endl;
}
cout<<"-------------"<<endl;

//print outgoing and incoming edges for each node
for(i=0;i<numNodes;i++){
In_nodesArray=new int[numNodes];
Out_nodesArray=new int[numNodes];
if((In_nodesArray==NULL)||(Out_nodesArray==NULL)){
cout<<"MALLOC ERROR!"<<endl;
return -1;
}
cout<<"For Node #"<<i+1<<":"<<endl;
//outgoing edges
num=0;
getOutgoingNodes(nodes, i, Out_nodesArray, num);
//cout<<"#out:"<<num<<"\t";
cout<<"Outgoing edges is/are to: {"; 
for(j=0;j<num;j++){cout<< Out_nodesArray[j]<<", ";}
cout<<"}"<<endl;
//incoming edges
num=0;
getIncomingNodes(nodes, i, In_nodesArray , num);
//cout<<"#In:"<<num<<"\t";
cout<<"Incoming edges is/are to: {"; 
for(j=0;j<num;j++){cout<<In_nodesArray[j] <<", ";}
cout<<"}"<<endl;
//de-allocate space for In_nodesArray
}
delete [] In_nodesArray;
delete [] Out_nodesArray;

return 0;
}

