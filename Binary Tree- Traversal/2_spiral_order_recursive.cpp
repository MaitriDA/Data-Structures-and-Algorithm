#include<iostream>
#include<climits>
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

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

void print_kth_level(node*root,int i,bool flag){
    if(root==NULL){
        return;
    }
    if(i==1){
        cout<<root->data<<" ";
    }
    if(flag){
        print_kth_level(root->left,i-1,flag);
        print_kth_level(root->right,i-1,flag);
    }
    else{
        print_kth_level(root->right,i-1,flag); 
        print_kth_level(root->left,i-1,flag);
    }
}
void printSpiralRec(node*root){
    int h=height(root);
    bool flag=false;
    for(int i=1;i<=h;i++){
        print_kth_level(root,i,flag);
        flag=!flag;
    }
}

int main(){
    node*root=buildTree();
    printSpiralRec(root);
    return 0;
}