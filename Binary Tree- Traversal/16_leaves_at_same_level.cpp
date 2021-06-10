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

bool leafLevelUtil(node*root,int level,int &leafLevel){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        if(leafLevel==0){
            leafLevel=level;
            return true;
        }
        if(leafLevel==level){
            return true;
        }
        else{
            return false;
        }
    }
    return (leafLevelUtil(root->left,level+1,leafLevel)&&leafLevelUtil(root->right,level+1,leafLevel));

}
bool leafLevel(node*root){
    int level=0;
    int leafLevel=0;
    return leafLevelUtil(root,level,leafLevel);
}

int main(){
    node*root=buildTree();
    if(leafLevel(root)){
        cout<<"Leaves are at same level"<<endl;
    }
    else{
        cout<<"Leaves are not at same level"<<endl;
    }
    return 0;
}