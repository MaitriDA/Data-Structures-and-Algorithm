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

void postOrder_print(node* root) {
    if (root == NULL)   return;
    stack <node*> st, result;
    st.push(root);

    while (!st.empty()) {
        node* current = st.top();
        st.pop();
        result.push(current);

        if (current->left != NULL)
            st.push(current->left);
        if (current->right != NULL)
            st.push(current->right);
    }

    while (!result.empty()) {
        cout << result.top()->data << " ";
        result.pop();
    }
}
int main(){
    node*root=builtTree();
    postOrder_print(root);
    return 0;
}