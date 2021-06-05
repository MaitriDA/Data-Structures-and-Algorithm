#include<iostream>
#include<stack>
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

void inOrder_print(node* root) {
    stack<node*>st;
    node*curr=root;
    while(true){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            if(st.empty()){
                return;
            }
            cout<<st.top()->data<<" ";
            curr=st.top()->right;
            st.pop();
        }
    }
}
int main(){
    node*root=builtTree();
    inOrder_print(root);
    return 0;
}