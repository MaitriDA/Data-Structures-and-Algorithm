#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertionAtTail(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
void deletionAtMiddle(node*&head,int p){
    if(head==NULL){
        return;
    }
    int jump=1;
    node*n=head;
    node*previous=head;
    while(jump<p-1){
        n=n->next;
        previous=previous->next;
        jump++;
    }
    n=n->next;
    previous->next=n->next;
    delete n;
    return;
}
int main(){
    node*head=NULL;
    insertionAtTail(head,50);
    insertionAtTail(head,30);
    insertionAtTail(head,40);
    deletionAtMiddle(head,2);
    print(head);
    return 0;
}