/*Preorder built

                  8
                /   \
               3     4
              /     /  \
              9    5    8

1) Pre Order: root->left->root
2) Post Order: left->right->root
3) In Order: left->root->right
4) Level Order: level by level from left to right

input: 8 3 9 -1 -1 -1 4 5 -1 -1 8 -1 -1
pre order: 8 3 9 4 5 8
post order: 9 3 5 8 4 8
in order: 9 3 8 5 4 8
level order: 8 3 4 9 5 8
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

void preOrder_print(node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder_print(root->left);
    preOrder_print(root->right);
}

void postOrder_print(node*root){
    if(root==NULL){
        return;
    }
    postOrder_print(root->left);
    postOrder_print(root->right);
    cout<<root->data<<" ";
}

void inOrder_print(node*root){
    if(root==NULL){
        return;
    }
    inOrder_print(root->left);
    cout<<root->data<<" ";
    inOrder_print(root->right);
}

int height_of_tree(node*root){
    if(root==NULL){
        return 0;
    }
    int ls=height_of_tree(root->left);
    int rs=height_of_tree(root->right);
    return max(ls,rs)+1;
}

void print_kth_level(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    print_kth_level(root->left,k-1);
    print_kth_level(root->right,k-1);
    return;
}
void levelOrder_print(node*root){
    int height=height_of_tree(root);
    for(int i=1;i<=height;i++){
        print_kth_level(root,i);
    }
    return;
}

int main(){
    node*root=builtTree();
    node*pre=root;
    node*post=root;
    node*in=root;
    cout<<"Preorder: "<<endl;
    preOrder_print(pre);
    cout<<endl;

    cout<<"Postorder: "<<endl;
    postOrder_print(post);
    cout<<endl;

    cout<<"Inorder: "<<endl;
    inOrder_print(post);
    cout<<endl;

    cout<<"Level order: "<<endl;
    levelOrder_print(post);
    cout<<endl;
    return 0;
}