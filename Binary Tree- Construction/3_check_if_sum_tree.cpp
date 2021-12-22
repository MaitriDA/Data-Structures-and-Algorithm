#include<iostream>
#include<map>
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

bool isLeaf(node*root){
    if(root==NULL){
        return false;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
bool isSum(node*root){
    if(root==NULL || isLeaf(root)){
        return true;
    }
    int leftSum,rightSum;
    if(isSum(root->left) && (isSum(root->right))){

    if(root->left==NULL){
        leftSum=0;
    }
    else if(isLeaf(root->left)){
        leftSum=root->left->data;
    }
    else{
        leftSum=2*(root->left->data);
    }

    if(root->right==NULL){
        rightSum=0;
    }
    else if(isLeaf(root->right)){
        rightSum=root->right->data;
    }
    else{
        rightSum=2*(root->right->data);
    }
    return ((root->data)==(leftSum+rightSum));
    }
    return false;

}

int main(){
    node*root=buildTree();
    if(isSum(root)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}