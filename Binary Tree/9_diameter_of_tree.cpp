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

node*builtTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node*root=new node(d);
    root->left=builtTree();
    root->right=builtTree();
    return root;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int l1=height(root->left);
    int l2=height(root->right);
    return max(l1,l2)+1;
}

int diameter(node*root){
    if(root==NULL){
        return 1;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}
int main(){
    node*root=builtTree();
    cout<<diameter(root);
}