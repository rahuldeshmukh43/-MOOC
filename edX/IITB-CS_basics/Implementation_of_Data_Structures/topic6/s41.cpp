#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
using namespace std;

template<class T> 
class graph{
    vector<list<T> > vectorList;
  public: 
    void createGraphNodes(int a, T*);
    bool addEdge(T, T);
    bool removeEdge(T, T);
    void printOutgoing();
    void printIncoming();
};

template<class T>
void graph<T>::createGraphNodes(int a, T vertex[]){
    vectorList.resize(a);
    int arrayIndex = 0;
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++, arrayIndex++){
        (*vectorIterator).push_back(vertex[arrayIndex]);
    }
}

template<class T>
bool graph<T>::addEdge(T source, T destination){
    bool foundDestination = false;
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();
        if ( (*listIterator) == source ) {
            listIterator++;
            for( ; listIterator != (*vectorIterator).end(); listIterator++){
                if (*listIterator == destination) {
                    foundDestination = true;
                    break;
                }
            }
            if (foundDestination == false) {
                (*vectorIterator).push_back(destination);
                return true;
            }
            else {
                return false;
            }
            break; //stop finding
        }
    }
}

template<class T>
bool graph<T>::removeEdge(T source, T destination){
    bool foundDestination = false;
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();
        if ( (*listIterator) == source ) {
            listIterator++;
            for( ; listIterator != (*vectorIterator).end(); listIterator++){
                if (*listIterator == destination) {
                    foundDestination = true;
                    (*vectorIterator).remove(destination);
                    return true;
                }
            }
            if (foundDestination == false) {
                return false;
            }
            break; //stop finding
        }
    }
}

template<class T>
void graph<T>::printOutgoing(){
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();
        cout << (*listIterator) << ": ";
        listIterator++;
        for( ; listIterator != (*vectorIterator).end(); listIterator++){
            cout << (*listIterator) << " ";
        }
        cout << endl;
    }
}

template<class T>
void graph<T>::printIncoming(){

    //Iterate for All Nodes (Incoming)
    for(typename vector<list<T> >::iterator vIt = vectorList.begin(); vIt != vectorList.end(); vIt++){
        typename list<T>::iterator lIt = (*vIt).begin();
        cout << (*lIt) << ": ";
        
        //Examine all nodes starting from A and check 
        for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
            typename list<T>::iterator listIterator = (*vectorIterator).begin();
            listIterator++;
            for( ; listIterator != (*vectorIterator).end(); listIterator++){
                if (*listIterator == *lIt) {
                    cout << (*vectorIterator).front() << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}


int main(){
    int size = 5;
    char vertex[] = {'A','B','C','D','E'};
    graph<char> g;
    g.createGraphNodes(5,vertex);
    cout << "\nCreating graph nodes\n\n";
    
    if (g.addEdge('A','B') )
        cout << "Edge added from A to B\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('A','C') )
        cout << "Edge added from A to C\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('C','A') )
        cout << "Edge added from C to A\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('C','D') )
        cout << "Edge added from C to D\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('C','B') )
        cout << "Edge added from C to B\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('D','B') )
        cout << "Edge added from D to B\n";
    else
        cout << "Edge already present\n";

    if (g.addEdge('D','B') )
        cout << "Edge added from D to B\n";
    else
        cout << "Edge already present\n";
    
    cout << "\nOutgoing Edges\n";
    g.printOutgoing();
    cout << "\nIncoming Edges\n";
    g.printIncoming();
    cout << endl;
    
    if (g.removeEdge('A','B') )
        cout << "Edge removed from A to B\n";
    else
        cout << "Edge not found\n";
    
    if (g.removeEdge('C','D') )
        cout << "Edge removed from C to D\n";
    else
        cout << "Edge not found\n";
    
    if (g.removeEdge('C','D') )
        cout << "Edge removed from C to D\n";
    else
        cout << "Edge not found\n";
    
    cout << "\nOutgoing Edges\n";
    g.printOutgoing();
    cout << "\nIncoming Edges\n";
    g.printIncoming();
    
    return 0;
}
/*
Creating graph nodes

Edge added from A to B
Edge added from A to C
Edge added from C to A
Edge added from C to D
Edge added from C to B
Edge added from D to B
Edge already present

Outgoing Edges
A: B C 
B: 
C: A D B 
D: B 
E: 

Incoming Edges
A: C 
B: A C D 
C: A 
D: C 
E: 

Edge removed from A to B
Edge removed from C to D
Edge not found

Outgoing Edges
A: C 
B: 
C: A B 
D: B 
E: 

Incoming Edges
A: C 
B: C D 
C: A 
D: 
E: 
*/
