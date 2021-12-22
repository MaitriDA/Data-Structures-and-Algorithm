#include<iostream>
#include<map>
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

void bottomViewUtil(node*root,int hd,int height,map<int,pair<int,int>>&m){
    if(root==NULL){
        return;
    }
    if(m.find(hd)==m.end()){
        m[hd]=make_pair(root->data,height);
    }
    else{
        pair<int,int>p=(m.find(hd))->second;
        if(p.second<height){
            m.erase(hd);
            m[hd]=make_pair(root->data,height);
        }
    }

    bottomViewUtil(root->left,hd-1,height+1,m);
    bottomViewUtil(root->right,hd+1,height+1,m);
}

void bottomview(node*root){
    map<int,pair<int,int>>m;
    bottomViewUtil(root,0,0,m);
    map<int, pair<int, int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) { 
        pair<int, int> p = it->second; 
        cout << p.first << " "; 
    }
    cout<<endl;
}

int main(){
    node*root=buildTree();
    bottomview(root);
    return 0;
}