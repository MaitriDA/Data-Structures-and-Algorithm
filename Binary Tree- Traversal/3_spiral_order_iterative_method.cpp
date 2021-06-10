#include<iostream>
#include<stack>
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

void spiralPrintIter(node*root){
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        if(root==NULL){
            return;
        }
        while(!s1.empty()){
            node*temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right){
                s2.push(temp->right);
            }
            if(temp->left){
                s2.push(temp->left);
            }
        }
        while(!s2.empty()){
            node*temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }
    }
}

int main(){
    node*root=buildTree();
    spiralPrintIter(root);
    return 0;
}