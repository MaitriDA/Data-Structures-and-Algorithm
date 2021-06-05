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

void preOrder_print (node* root) {
    if (root == NULL)   return;

    stack <node*> s;
    s.push(root);

    while (!s.empty()) {
        node* current = s.top();
        cout << current->data << " ";
        s.pop();

        if (current->right)    
            s.push(current->right);
        if (current->left)    
            s.push(current->left);
    }
}
int main(){
    node*root=builtTree();
    preOrder_print(root);
    return 0;
}