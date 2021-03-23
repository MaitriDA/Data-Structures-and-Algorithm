#include<iostream>
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
    insertionAtHead(head,18);
    insertionAtHead(head,50);
    print(head);
}