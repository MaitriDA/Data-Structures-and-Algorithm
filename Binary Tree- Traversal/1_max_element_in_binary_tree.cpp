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

int findMax(node*root,int ans){
    if(root==NULL){
        return ans;
    }
    else if((root->data)>ans){
        ans=root->data;
    }
    ans=max(findMax(root->left,ans),findMax(root->right,ans));
    return ans;
}
int main(){
    node*root=buildTree();
    int min=INT_MIN;
    int max=findMax(root,INT_MIN);
    cout<<max;

}