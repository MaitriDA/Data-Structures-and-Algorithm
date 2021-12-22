#include<iostream>
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

node* insertInBST(node*root,int d){
    if(root==NULL){
        return new node(d);
    }
    if(d<root->data){
        root->left=insertInBST(root->left,d);
    }
    else{
        root->right=insertInBST(root->right,d);
    }
    return root;
}

node* builtTree(){
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}

void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
    return;
}

int distFromRoot(node*root,int x){
    if(root->data==x){
        return 0;
    }
    if(root->data>x){
        return(1+distFromRoot(root->left,x));
    }
    else{
        return(1+distFromRoot(root->right,x));
    }
}

int shortDist(node*root,int n1,int n2){
    if(root==NULL){
        return 0;
    }
    //If both the keys are in left tree
    if(root->data>n1 && root->data>n2){
        return shortDist(root->left,n1,n2);
    }

    //If both the keys are in right tree
    if(root->data<n1 && root->data<n2){
        return shortDist(root->right,n1,n2);
    }

    //If keys are in opposite
    if(root->data>=n1 && root->data<=n2){
        return (distFromRoot(root,n1)+distFromRoot(root,n2));
    }
}

int main(){
    node*root=builtTree();
    int n1,n2;
    cin>>n1>>n2;
    if(n1>n2){
        swap(n1,n2);
    }
    int dist=shortDist(root,n1,n2);
    cout<<dist;
    return 0;
}