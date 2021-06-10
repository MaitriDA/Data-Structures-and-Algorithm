#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
}

void printArray(int arr[],int pathLen){
    for(int i=0;i<pathLen;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printPathUtil(node*root,int path[],int pathLen){
    if(root==NULL){
        return;
    }
    path[pathLen]=root->data;
    pathLen++;
    if(root->left==NULL && root->right==NULL){
        printArray(path,pathLen);
    }
    else{
        printPathUtil(root->left,path,pathLen);
        printPathUtil(root->right,path,pathLen);
    }
}

void printPath(node*root){
    int path[1000];
    int pathLen=0;
    printPathUtil(root,path,pathLen);
}

int main(){
    node*root=buildTree();
    printPath(root);
    return 0;
}