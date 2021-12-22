#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

Node*builtBT(int *pre,int *post,int s,int e,int size){
    static int index=0;
    if(s>e || index>=size){
        return NULL;
    }
    int data=pre[index];
    index++;
    Node*root=new Node(data);
    if(s==e){
        return root;
    }
    int rootIndex;
    for(int i=s;i<=e;i++){
        if(post[i]==pre[index]){
            rootIndex=i;
            break;
        }
    }
    root->left=builtBT(pre,post,s,rootIndex-1,size);
    root->right=builtBT(pre,post,rootIndex+1,e,size);
    return root;
}
void print(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(){
    int preOrder[]= {1,2,4,8,9,5,3,6,7};
    int postOrder[]={8,9,4,5,2,6,7,3,1};
    Node*result=builtBT(preOrder,postOrder,0,8,9);
    print(result);
    return 0;

}