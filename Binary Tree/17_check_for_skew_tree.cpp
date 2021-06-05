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

bool skewRec(node*root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return true;
    }
    if(root->left && root->right){
        return false;
    }
    if(root->left){
        return skewRec(root->left);
    }
    return skewRec(root->right);
}

int main(){
    node*root=builtTree();
    if(skewRec(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}