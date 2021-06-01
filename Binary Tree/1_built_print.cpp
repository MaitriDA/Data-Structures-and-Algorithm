/*Preorder built
order root->left->right
                  8
                /   \
               3     4
              /     /  \
              9    5    8
input order: 8 3 9 -1 -1 -1 4 5 -1 -1 8 -1 -1
output: 8 3 9 4 5 8

Whenever -1 is encountered the next node will be empty hence NULL is returned. It means that the branch has terminated.

*/

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

void print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main(){
    node*root=builtTree();
    cout<<"Preorder: "<<endl;
    print(root);
    return 0;
}