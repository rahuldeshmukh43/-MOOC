#include<iostream>
#include<bits/stdc++.h>
#define MAX_TREE_HEIGHT 100
using namespace std;

struct node{
    char ch;
    int freq;
    struct node *left,*right;
};
typedef struct node hNode;

struct compare{
    bool operator()(hNode *a,hNode *b){
        return (b->freq < a->freq);
    }
};

struct node* makeNode(char ch,int freq){
    hNode *temp=(hNode*)malloc(sizeof(hNode*));
    temp->ch=ch;
    temp->freq=freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} 
void displayCodes(hNode *root,int code[],int index = 0){
    if(root->left){
        code[index]=0;
        displayCodes(root->left,code,index+1);
    }
    if(root->right){
         code[index]=1;
         displayCodes(root->right,code,index+1);
    }
    if(root->left==NULL && root->right==NULL){
        cout << "Huffman Code for character " << root->ch <<": ";
	for(int i=0;i<index;i++){
            cout<<code[i];
        }
        cout<<endl;
    }
}
void huffmanCodes(char ch[],int fq[],int size){
    int code[MAX_TREE_HEIGHT];
    hNode *left,*right;
    priority_queue<hNode *, vector<hNode*>, compare> pq;
    for(int i=0;i<size;i++){
        pq.push(makeNode(ch[i],fq[i]));
    }
    while(pq.size() != 1){
        left=pq.top(); 
        pq.pop();
        right=pq.top();
        pq.pop();
        hNode *temp = makeNode('#', left->freq + right->freq);
        temp->left=left;
        temp->right=right;
        pq.push(temp);
    }
    displayCodes(pq.top(),code);
}

int main(){
    int size=6;
    char ch[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[6] = {15, 10, 12, 18, 55, 16};
    huffmanCodes(ch, freq, size);
    return 0;
}

/*
Huffman Code for character e: 0
Huffman Code for character a: 100
Huffman Code for character f: 101
Huffman Code for character d: 110
Huffman Code for character b: 1110
Huffman Code for character c: 1111
*/
