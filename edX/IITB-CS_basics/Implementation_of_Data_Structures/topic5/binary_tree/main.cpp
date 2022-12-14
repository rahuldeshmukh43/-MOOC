#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    int leftIndex;
    int rightIndex;
};

class BinaryTree{
    vector <struct Node> bt;
  public:
    void makeNode(int data);
    void insertLeft(int index, int data);
    void insertRight(int index, int data);
    void insert(int data);
    void traverse(int index, int order);
};

void BinaryTree::makeNode(int data){
    struct Node b = { data, -1, -1};
    bt.push_back(b);
}

void BinaryTree::insertLeft(int index, int data){
    struct Node b = { data, -1, -1 };
    bt[index].leftIndex = bt.size();;
    bt.push_back(b);
}

void BinaryTree::insertRight(int index, int data){
    struct Node b = { data, -1, -1 };
    bt[index].rightIndex = bt.size();;
    bt.push_back(b);
}

void BinaryTree::insert(int data){
    if(bt.size() == 0){
        makeNode(data);
    }
    else {
        int index = 0;
        while ( index < bt.size() ){
            if(data <= bt[index].data){	
                if( bt[index].leftIndex == -1){
                    insertLeft(index, data);
                    break;
                }
                else
                    index = bt[index].leftIndex;
            }
            else{
                if(bt[index].rightIndex == -1){
                    insertRight(index, data);
                    break;
                }
                else
                    index = bt[index].rightIndex;
            }
        } //End of while
    } //End of else
}

void BinaryTree::traverse(int index, int order){
    if(order == -1)
        cout << bt[index].data << "   ";
        
    if(bt[index].leftIndex != -1)
        traverse(bt[index].leftIndex, order);
        
    if(order == 0)
        cout<<bt[index].data <<  "   ";
        
    if( bt[index].rightIndex != -1)
        traverse(bt[index].rightIndex, order);
        
    if(order == 1)
        cout<<bt[index].data <<  "   ";
}

int main() {
    BinaryTree b1;

    b1.insert(60);
    b1.insert(40);
    b1.insert(20);
    b1.insert(25);
    b1.insert(90);
    b1.insert(23);
    b1.insert(95);
    b1.insert(80);
    b1.insert(85);
    
    cout << "Pre-Order\n";
    b1.traverse(0,-1);

    cout << "\n\nIn-Order\n";
    b1.traverse(0,0);

    cout << "\n\nPost-Order\n";
    b1.traverse(0,1);
    return 0;
}
/*
Pre-Order
60   40   20   25   23   90   80   85   95   

In-Order
20   23   25   40   60   80   85   90   95   

Post-Order
23   25   20   40   85   80   95   90   60   
*/

