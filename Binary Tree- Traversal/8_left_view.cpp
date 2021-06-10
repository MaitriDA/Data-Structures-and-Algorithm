#include<iostream>
#include<queue>
#include<vector>
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

void leftViewUtil(node*root,int level,int *max_level){
    if(root==NULL){
        return;
    }
    if(*max_level<level){
        cout<<root->data<<" ";
        *max_level=level;
    }

    leftViewUtil(root->left,level+1,max_level);
    leftViewUtil(root->right,level+1,max_level);
}

void leftview(node*root){
    int max_level=0;
    leftViewUtil(root,1,&max_level);
    cout<<endl;
}

int main(){
    node*root=buildTree();
    leftview(root);
    return 0;
}