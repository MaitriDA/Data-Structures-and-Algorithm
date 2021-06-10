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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int hl=height(root->left);
    int hr=height(root->right);
    return 1+max(hl,hr);
}
void kth_level(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    kth_level(root->left,k-1);
    kth_level(root->right,k-1);
    return;
}
void levelOrder(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f=q.front();
        q.pop();
        if(f==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }  
            if(f->right){
                q.push(f->right);
            }
        }
    }
}
int main(){
    node*root=builtTree();
    levelOrder(root);
    return 0;
}