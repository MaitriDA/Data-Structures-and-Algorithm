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
void deletionAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp=head->next;
    delete head;
    head=temp;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
int main(){
    node*head=NULL;
    insertionAtTail(head,15);
    insertionAtTail(head,23);
    insertionAtTail(head,96);
    deletionAtHead(head);
    print(head);
    return 0;
}
