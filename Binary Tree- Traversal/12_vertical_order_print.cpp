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

void verticalOrder(node*root){
    if(root==NULL){
        return;
    }
    map<int,vector<int>>m;
    int hd=0;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,hd));
    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        hd=temp.second;
        node*curr=temp.first;
        m[hd].push_back(curr->data);
        if(curr->left){
            q.push(make_pair(curr->left,hd-1));
        }
        if(curr->right){
            q.push(make_pair(curr->right,hd+1));
        }
    }
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    node*root=buildTree();
    verticalOrder(root);
    return 0;
}