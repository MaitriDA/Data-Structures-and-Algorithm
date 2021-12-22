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

bool check(node*root,node*l=NULL,node*r=NULL){
    if(root==NULL){
        return true;
    }
    if(l!=NULL and root->data<=l->data){
        return false;
    }
    if(r!=NULL and root->data>=r->data){
        return false;
    }
    return check(root->left,l,root)&&check(root->right,root,r);
}

int main(){
    node*root=new node(20);
    root->left=new node(8);
    root->left->left=new node(3);
    root->left->right=new node(10);
    root->right=new node(22);
    //root->right->left=new node(4);
    root->right->left=new node(21);
    root->right->right=new node(50);
    if(check(root,NULL,NULL)){
        cout<<"Binary Search Tree"<<endl;
    }
    else{
        cout<<"Binary Tree"<<endl;
    }
    return 0;
}