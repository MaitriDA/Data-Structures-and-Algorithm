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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int hl=height(root->left);
    int hr=height(root->right);
    return 1+max(hl,hr);
}
int diameter(node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2+1;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(op1,max(op2,op3));
}

int main(){
    node*root=buildTree();
    cout<<diameter(root);
    return 0;
}