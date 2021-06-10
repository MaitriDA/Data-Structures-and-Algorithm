#include<iostream>
#include<stack>
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

void leftBoundary(node*root){
    if(root->left==NULL && root->right==NULL){
        return;
    }
    cout<<root->data<<" ";
    leftBoundary(root->left);
}

void rightBoundary(node*root){
    if(root->left==NULL && root->right==NULL){
        return;
    }
    rightBoundary(root->right);
    cout<<root->data<<" ";
}

void leftLeaf(node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    leftLeaf(root->left);
    leftLeaf(root->right);
}

void rightLeaf(node*root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
    }
    rightLeaf(root->left);
    rightLeaf(root->right);
}

void boundaryTraversal(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    leftBoundary(root->left);
    leftLeaf(root->left);
    rightLeaf(root->right);
    rightBoundary(root->right);
}

int main(){
    node*root=buildTree();
    boundaryTraversal(root);
    return 0;
}