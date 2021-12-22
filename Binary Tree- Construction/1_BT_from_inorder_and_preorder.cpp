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

Node*builtBT(int *in,int *pre,int s,int e){
    static int index=0;
    if(s>e){
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
        if(in[i]==data){
            rootIndex=i;
            break;
        }
    }
    root->left=builtBT(in,pre,s,rootIndex-1);
    root->right=builtBT(in,pre,rootIndex+1,e);
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
    int inOrder[]={3,2,8,4,1,6,7,5};
    int preOrder[]= {1,2,3,4,8,5,6,7};
    Node*result=builtBT(inOrder,preOrder,0,7);
    print(result);
    return 0;

}