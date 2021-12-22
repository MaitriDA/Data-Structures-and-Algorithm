#include<iostream>
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

node* insertInBST(node*root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d<root->data){
        root->left=insertInBST(root->left,d);
    }
    else{
        root->right=insertInBST(root->right,d);
    }
    return root;
}

node* builtTree(){
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}

void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

bool search(node*root,int key){
    if(root==NULL){
        return false;
    }
    if(key<(root->data)){
        search(root->left,key);
    }
    else if(key>(root->data)){
        search(root->right,key);
    }
    else if(key==root->data){
        return true;
    }
}

int main(){
    node*root=builtTree();
    int key;
    cin>>key;
    if(search(root,key)){
        cout<<"Key is present";
    }
    else{
        cout<<"Key is not present";
    }
    return 0;
}