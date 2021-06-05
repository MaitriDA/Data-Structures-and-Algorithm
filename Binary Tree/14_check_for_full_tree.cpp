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

bool fullIter(node*root){
    if(root==NULL){
        return true;
    }
    queue<node*>q;
    q.push(root);
    node*curr;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr->left==NULL && curr->right==NULL){
            continue;
        }
        if(curr->left==NULL || curr->right==NULL){
            return false;
        }
        q.push(curr->left);
        q.push(curr->right);
    }
    return true;
}

bool fullRec(node*root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->left==NULL || root->right==NULL){
        return (fullRec(root->left) && fullRec(root->right));
    }
}
int main(){
    node*root=builtTree();
    if(fullIter(root) && fullRec(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}