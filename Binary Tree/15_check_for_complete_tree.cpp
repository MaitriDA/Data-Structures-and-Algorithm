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

bool completeIter(node*root){
    if(root==NULL){
        return true;
    }
    queue<node*>q;
    q.push(root);
    node*curr;
    bool flag=false;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr->left){
            if(flag){
                return false;
            }
            q.push(curr->left);
        }
        else{
            flag=true;
        }
        if(curr->right){
            if(flag){
                return false;
            }
            q.push(curr->right);
        }
        else{
            flag=true;
        }
    }
    return true;
}

int main(){
    node*root=builtTree();
    if(completeIter(root)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}