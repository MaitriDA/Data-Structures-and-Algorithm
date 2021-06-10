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

int max_width(node*root){
    if(root==NULL){
        return 1;
    }
    int result=0;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int count=q.size();
        result=max(result,count);
        while(count--){
            node*temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return result;
}

int main(){
    node*root=buildTree();
    cout<<max_width(root);
    return 0;
}