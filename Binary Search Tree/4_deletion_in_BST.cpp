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

node*minValue(node*root){
    node*curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

node*deletion(node*root,int key){
    if(root==NULL){
        return root;
    }
    if((root->data)>key){
        root->left=deletion(root->left,key);
    }
    else if((root->data)<key){
        root->right=deletion(root->right,key);
    }
    else{
        if(root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        node*temp=minValue(root->right);
        root->data=temp->data;
        root->right=deletion(root->right,temp->data);
    }
}

int main(){
    node*root=builtTree();
    cout<<"Before Deletion"<<endl;
    print(root);
    int key;
    cin>>key;
    cout<<"After Deletion"<<endl;
    deletion(root,key);
    print(root);
    return 0;
}