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

void findPreSuc(node*root,node*&pre,node*&suc,int key){
    if(root==NULL){
        return;
    }
    if((root->data)==key){
        if(root->left!=NULL){
            node*temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            pre=temp;
        }
        if(root->right!=NULL){
            node*temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            suc=temp;
        }
        return;
    }
    if((root->data)>key){
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else{
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}

int main(){
    node*root=builtTree();
    int key;
    cin>>key;
    node*pre=NULL;
    node*suc=NULL;
    findPreSuc(root,pre,suc,key);
    if(pre!=NULL){
        cout<<"Predecessor: "<<pre->data<<endl;
    }
    else{
        cout<<"No predecessor"<<endl;
    }
    if(suc!=NULL){
        cout<<"Successor: "<<suc->data<<endl;
    }
    else{
        cout<<"No successor"<<endl;
    }
    return 0;
}