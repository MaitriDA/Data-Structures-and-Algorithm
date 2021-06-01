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
    temp->next=new node(d);
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

void reverse(node*&head){
    node*curr=head;
    node*prev=NULL;
    node*n;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    cout<<"Original Linked List: "<<endl;
    print(head);
    cout<<endl<<endl;
    cout<<"Reversed Linked List: "<<endl;
    reverse(head);
    print(head);
    cout<<endl;
    return 0;
}