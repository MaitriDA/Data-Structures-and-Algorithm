#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void print(Node*last){
    Node*temp;
    if(last==NULL){
        cout<<"Empty list";
        return;
    }
    temp=last->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=last->next);
    cout<<endl;
}

void push(Node*&head,int d){
    Node*ptr=new Node(d);
    ptr->next=head;
    if(head!=NULL){
        Node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=ptr;
    }
    else{
        ptr->next=ptr;
    }
    head=ptr;
}

void deleteNode(Node*&head,int key){
    if(head->data==key and head->next==head){
        delete head;
        head=NULL;
        return;
    }
    Node*last=head;
    if(head->data==key){
        while(last->next!=head){
            last=last->next;
        }
        last->next=head->next;
        delete head;
        head=last->next;
        return;
    }
    while(last->next!=head and last->next->data!=key){
        last=last->next;
    }
    Node*d;
    if(last->next->data==key){
        d=last->next;
        last->next=d->next;
        delete d;
    }
    else{
        cout<<"No such key found";
    }
    return;
}
int main(){
    Node*head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);
    print(head);
    deleteNode(head,2);
    print(head);
    return 0;
}