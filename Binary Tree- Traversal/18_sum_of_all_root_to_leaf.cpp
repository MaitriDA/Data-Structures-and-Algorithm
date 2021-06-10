#include<iostream>
#include<map>
#include<vector>
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

int calculateSum(int arr[],int n){
    int arrSum=0;
    for(int i=0;i<n;i++){
        arrSum=arrSum*10+arr[i];
    }
    cout<<arrSum<<endl;
    return arrSum;
}

int sumFromRootLeafUtil(node*root,int &sum,int path[],int pathLen){
    if(root==NULL){
        return 0;
    }
    path[pathLen]=root->data;
    pathLen++;
    if(root->left==NULL && root->right==NULL){
        sum=sum+calculateSum(path,pathLen);
    }
    else{
        sumFromRootLeafUtil(root->left,sum,path,pathLen);
        sumFromRootLeafUtil(root->right,sum,path,pathLen);
    }
    return sum;
}
int sumFromRootLeaf(node*root,int &sum){
    int path[1000];
    int pathLen=0;
    return sumFromRootLeafUtil(root,sum,path,pathLen);
    
}

int main(){
    node*root=buildTree();
    int sum=0;
    cout<<sumFromRootLeaf(root,sum);
    return 0;
}