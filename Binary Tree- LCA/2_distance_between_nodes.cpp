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

node*findLCA(node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node*leftAns=findLCA(root->left,n1,n2);
    node*rightAns=findLCA(root->right,n1,n2);
    if(leftAns!=NULL and rightAns!=NULL){
        return root;
    }
    if(leftAns!=NULL){
        return leftAns;
    }
    return rightAns;
}

int findLevel(node*root,int k,int level){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return level;
    }
    int left=findLevel(root->left,k,level+1);
    if(left==-1){
        return findLevel(root->right,k,level+1);
    }
    return left;
}
int main(){
    node*root=buildTree();
    node*ans=findLCA(root,10,9);
    int d1=findLevel(root,10,0);
    int d2=findLevel(root,9,0);
    cout<<d1+d2<<endl;
    return 0;
}