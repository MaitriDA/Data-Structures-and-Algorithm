#include<iostream>
#include<stack>
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

void reverseLevelIter(node*root){
    stack<node*>s;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        s.push(temp);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    
    
    

}

int main(){
    node*root=buildTree();
    reverseLevelIter(root);
    return 0;
}