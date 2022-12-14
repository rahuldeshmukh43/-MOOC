#include<iostream>
#include "binary_tree_1.h"
using namespace std;

int main(){
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
    Node* root_ptr = b1.get_root_ptr();

    cout << "Pre-Order\n";
    b1.traverse(root_ptr, PRE_ORDER);

    cout << "\n\nIn-Order\n";
    b1.traverse(root_ptr,IN_ORDER);

    cout << "\n\nPost-Order\n";
    b1.traverse(root_ptr,POST_ORDER);
    cout<<endl;
    return 0;

}
