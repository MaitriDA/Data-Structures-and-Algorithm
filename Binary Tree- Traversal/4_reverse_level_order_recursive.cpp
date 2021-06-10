#include<iostream>
#include<climits>
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
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

void print_kth_level(node*root,int i){
    if(root==NULL){
        return;
    }
    if(i==1){
        cout<<root->data<<" ";
    }
    print_kth_level(root->left,i-1);
    print_kth_level(root->right,i-1);
}

void reverseLevelRec(node*root){
    int h=height(root);
    for(int i=h;i>0;i--){
        print_kth_level(root,i);
    }
}

int main(){
    node*root=buildTree();
    reverseLevelRec(root);
    return 0;
}