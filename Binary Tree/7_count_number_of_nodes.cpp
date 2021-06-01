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
}

int count_nodes(node*root){
    if(root==NULL){
        return 1;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
}
int main(){
    node*root=builtTree();
    cout<<count_nodes(root)/2;
}