#include<iostream>
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

int sum(node* root) {
    if(root==NULL){
        return 0;
    }
    int h1=sum(root->left);
    int h2=sum(root->right);
    return 1+max(h1,h2);
}
int main(){
    node*root=builtTree();
    cout<<sum(root);
    return 0;
}