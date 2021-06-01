#include<iostream>
#include<typeinfo>

using namespace std;

// Basic structure of a node of a linked list
class node{
    public:
    int data;
    node*next;
    node(int d){        //constructor
        data=d;
        next=NULL;
    }
};
void insertionAtHead(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*n=new node(d);
    cout<<"Data type of n: "<<typeid(n).name()<<endl;
    cout<<"Data type of *n: "<<typeid(*n).name()<<endl;
    n->next=head;
    head=n;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
int main(){
    node*head=NULL;
    cout<<"Data type of head: "<<typeid(head).name()<<endl;
    insertionAtHead(head,18);
    insertionAtHead(head,50);
    print(head);
}