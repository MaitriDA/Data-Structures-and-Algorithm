#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node*prev;
    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

void append(Node*&head,int d){
    Node*h=new Node(d);
    if(head==NULL){
        head=h;
        return;
    }
    h->next=head;
    head->prev=h;
    head=h;
    return;
}

void insertAtEnd(Node*&head,int d){
    Node*h=new Node(d);
    if(head==NULL){
        head=h;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=h;
    h->prev=temp;
    return;
}

void insertAfter(Node*pre,int data){
    Node*h=new Node(data);
    h->next=pre->next;
    pre->next->prev=h;
    h->prev=pre;
    pre->next=h;
    return;
}

int main(){
    Node*head=NULL;
    insertAtEnd(head,4);
    append(head,1);
    append(head,2);
    insertAtEnd(head,3);
    insertAfter(head->next,5);
    print(head);
    return 0;
}