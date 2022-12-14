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
    void addEdge(T, T);
    void removeEdge(T, T);
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
void graph<T>::addEdge(T source, T destination){
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();
        if ( (*listIterator) == source ) {
            (*vectorIterator).push_back(destination);
        }
    } //End of for
}

template<class T>
void graph<T>::removeEdge(T source, T destination){
    bool foundDestination = false;
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();
        if ( (*listIterator) == source ) {
            (*vectorIterator).remove(destination);
        }
    } //End of for
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

    g.addEdge('A','B');
    g.addEdge('A','C');
    g.addEdge('C','A');
    g.addEdge('C','D');
    g.addEdge('C','B');
    g.addEdge('D','B');

    cout << "\nOutgoing Edges\n";
    g.printOutgoing();
    cout << "\nIncoming Edges\n";
    g.printIncoming();
    cout << endl;
    
    g.removeEdge('A','B');
    g.removeEdge('C','D');

    cout << "\nOutgoing Edges\n";
    g.printOutgoing();
    cout << "\nIncoming Edges\n";
    g.printIncoming();
    
    return 0;
}
/*
Creating graph nodes


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
