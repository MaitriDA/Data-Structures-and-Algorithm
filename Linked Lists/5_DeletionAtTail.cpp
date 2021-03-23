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
void insertAtTail(node*&head,int d){
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
void deletionAtTail(node*&head){
    if(head->next==NULL){
        delete head;
    }
    node*previous=head;
    node*tail=head;
    tail=tail->next;
    while(tail->next!=NULL){
        tail=tail->next;
        previous=previous->next;
    }
    delete tail;
    previous->next=NULL;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
int main(){
    node*head=NULL;
    insertAtTail(head,50);
    insertAtTail(head,40);
    insertAtTail(head,30);
    deletionAtTail(head);
    print(head);
    return 0;
}
