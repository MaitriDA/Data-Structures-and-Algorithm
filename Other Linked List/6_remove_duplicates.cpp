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
    cout<<endl;
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

void deletion(Node*&head,Node*P){
    if (head == NULL || P == NULL)
        return;

    if (head == P)
        head = P->next;
    
    if (P->next != NULL)
        P->next->prev = P->prev;

    if (P->prev != NULL)
        P->prev->next = P->next;
    
    delete P;
}

void removeDuplicates(Node*&head){
    if(head==NULL){
        return;
    }
    Node*curr=head;
    Node*n;
    while(curr->next!=NULL){
        if(curr->data!=curr->next->data){
            deletion(head,curr->next);
        }
        else{
            curr=curr->next;
        }
    }
    return;
}

int main(){
    Node*head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    removeDuplicates(head);
    print(head);
    return 0;
}