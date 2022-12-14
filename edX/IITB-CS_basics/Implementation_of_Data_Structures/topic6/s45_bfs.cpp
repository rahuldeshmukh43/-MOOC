#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
#include<algorithm>
using namespace std;

template<class T> 
class graph{
    vector<list<T> > vectorList;
    int size;
  public:
    void createGraphNodes(int a, T*);
    bool addEdge(T, T);
    bool removeEdge(T, T);
    void getVertices(T c[]);
    void BFS(T a);
    void printOutgoing();
    void printIncoming();
};


template<class T>
void graph<T>::createGraphNodes(int a, T vertex[]){
    size = a;
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
void graph<T>::getVertices(T c[]){
    int index = 0;
    for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++, index++){
        typename list<T>::iterator listIterator = (*vectorIterator).begin();    
        c[index] = (*listIterator);
    }
}



template<class T>
void graph<T>::BFS(T a){
    T *c = new T[size];
    getVertices(c);
    bool visited[size];
    for(int i = 0; i < size; i++)
        visited[i] = false;
    list<T> s;
    s.push_back(a);
    
    while(s.size() > 0){
        T node = s.front();
        s.pop_front();
        int positionOfNode = find(c,c+size,node) - c;
        if(visited[positionOfNode] == false){
            visited[positionOfNode] = true;
            cout << "Visiting: " << node << endl;
            for(typename vector<list<T> >::iterator vectorIterator = vectorList.begin(); vectorIterator != vectorList.end(); vectorIterator++){
                typename list<T>::iterator listIterator = (*vectorIterator).begin();
                if((*listIterator) == node){
                    listIterator++; 
                    for( ; listIterator != (*vectorIterator).end(); listIterator++){
                        s.push_back((*listIterator));
                    } 
                    break;
                }
            } // End of for
        } // End of if that determines whether the node is visited or not
    } //End of while
} //End of function


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
    char vertex[] = {'A','B','C','D','E'};
    graph<char> g;
    g.createGraphNodes(sizeof(vertex)/sizeof(vertex[0]),vertex);

    g.addEdge('A','B');
    g.addEdge('A','C');
    g.addEdge('B','D');
    g.addEdge('C','D');
    g.addEdge('D','E');
    
    g.printOutgoing();
    cout << endl;
    
    cout << endl <<  "Printing BFS" << endl;
    g.BFS('A');

    return 0;
}

