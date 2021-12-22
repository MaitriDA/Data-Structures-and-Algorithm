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

void deletion(Node*&head,int key){
    if(head->data==key){
        Node*temp=head;
        head->next->prev=NULL;
        head=head->next;
        return;
    }
    Node*temp=head;
    while(temp->next->data!=key){
        temp=temp->next;
    }
    Node*p=temp->next;
    temp->next=p->next;
    p->next->prev=temp;
    delete p;
    return;
}

int main(){
    Node*head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    print(head);
    deletion(head,3);
    print(head);
    return 0;
}