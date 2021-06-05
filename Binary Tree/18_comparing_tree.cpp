#include<iostream>
#include<queue>
#include<math.h>
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

bool isIdentical(node*a,node*b){
    if(a==NULL and b==NULL){
        return true;
    }
    if(a->data==b->data){
        return isIdentical(a->left,b->left) && isIdentical(a->right,b->right);
    }
    return false;
}

bool isSimilar(node*a,node*b){
    if(a==NULL and b==NULL){
        return true;
    }
    if(a!=NULL and b!=NULL){
        return isSimilar(a->left,b->left) && isSimilar(a->left,b->right);
    }
    return false;
}
int main(){
    cout<<"Tree A"<<endl;
    node*a=builtTree();
    cout<<"Tree B"<<endl;
    node*b=builtTree();
    if(isIdentical(a,b)){
        cout<<"Identical"<<endl;
    }
    else if(isSimilar(a,b)){
        cout<<"Similar"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    return 0;
}