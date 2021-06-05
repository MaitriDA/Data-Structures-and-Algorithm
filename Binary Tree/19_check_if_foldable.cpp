#include<iostream>
#include<queue>
#include<math.h>
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

bool isFoldableHelper(node*a,node*b){
    if(a==NULL and b==NULL){
        return true;
    }
    if(a==NULL || b==NULL){
        return false;
    }
    return isFoldableHelper(a->left,b->left) && isFoldableHelper(a->right,b->right);
}
bool isFoldable(node*root){
    if(root==NULL){
        return true;
    }
    return isFoldableHelper(root->left,root->right);
}

int main(){
    node*root=builtTree();
    if(isFoldable(root)){
        cout<<"Foldable"<<endl;
    }
    else{
        cout<<"Not Foldable"<<endl;
    }
    return 0;
}