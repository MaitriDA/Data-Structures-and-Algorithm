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
    int total=0;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*curr=q.front();
        total=total+curr->data;
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    return total;
}
int main(){
    node*root=builtTree();
    cout<<sum(root);
    return 0;
}