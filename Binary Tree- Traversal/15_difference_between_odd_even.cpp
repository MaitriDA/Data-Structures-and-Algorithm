#include<iostream>
#include<map>
#include<vector>
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

int difference(node*root){
    if(root==NULL){
        return 0;
    }
    int odd=0;
    int even=0;
    int flag=1;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        while(count--){
            node*temp=q.front();
            q.pop();
            if(flag==1){
                odd=odd+temp->data;
            }
            else{
                even=even+temp->data;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        flag=!flag;
    }
    return odd-even;
}

int main(){
    node*root=buildTree();
    cout<<difference(root);
    return 0;
}