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

bool isSymmetricHelper(node*a,node*b){
    if(a==NULL and b==NULL){
        return true;
    }
    if(a==NULL || b==NULL){
        return false;
    }
    if(a->data!=b->data){
        return false;
    }
    return isSymmetricHelper(a->left,b->left) && isSymmetricHelper(a->right,b->right);
}
bool isSymmetricRec(node*root){
    if(root==NULL){
        return true;
    }
    return isSymmetricHelper(root->left,root->right);
}

bool isSymmetricIter(node*root){
    if(root==NULL){
        return true;
    }
    queue<node*>q;
    q.push(root);
    q.push(root);
    node*leftNode,*rightNode;
    while(!q.empty()){
        leftNode=q.front();
        q.pop();
        rightNode=q.front();
        q.pop();
        if(leftNode->data!=rightNode->data){
            return false;
        }
        if(leftNode->left && rightNode->right){
            q.push(leftNode->left);
            q.push(rightNode->right);
        }
        else if(leftNode->left || rightNode->right){
            return false;
        }
    }
    return true;
}
int main(){
    node*root=builtTree();
    if(isSymmetricRec(root) && isSymmetricIter(root)){
        cout<<"Symmetric or Mirror"<<endl;
    }
    else{
        cout<<"Not Symmetric"<<endl;
    }
    return 0;
}