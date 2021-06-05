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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int count_nodes(node*root){
    if(root==NULL){
        return 0;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
}
bool perfectIter(node*root){
    if(root==NULL){
        return true;
    }
    int h=height(root);
    int c=count_nodes(root);
    if((pow(2,h)-1)==c){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    node*root=builtTree();
    if(perfectIter(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}