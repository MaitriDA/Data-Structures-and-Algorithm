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

void insert_at_tail(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node*n=new node(d);
    temp->next=n;
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

void insert_in_sorted_ll(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    //insertion at head;
    if(d<head->data){
        node*n=new node(d);
        n->next=head;
        head=n;
        return;
    }
    //insertion at tail
    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    if(tail->data<d){
        insert_at_tail(head,d);
        return;
    }
    //insertion in middile
    node*mid=head;
    while(mid->next->data<d){
        mid=mid->next;
    }
    node*n=new node(d);
    n->next=mid->next;
    mid->next=n;
    return;
}

int main(){
    node*head=NULL;
    //Sorted Linked List
    insert_at_tail(head,2);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,8);
    cout<<"Previous Linked List"<<endl;
    print(head);
    cout<<endl;
    cout<<"After adding elements"<<endl;
    insert_in_sorted_ll(head,3);
    insert_in_sorted_ll(head,15);
    insert_in_sorted_ll(head,1);
    print(head);
    return 0;
}