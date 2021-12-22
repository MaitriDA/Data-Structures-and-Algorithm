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

int countNodes(Node*head){
    Node*temp=head;
    int count=0;
    if(head!=NULL){
        do{
            temp=temp->next;
            count++;
        }
        while(temp!=head);
    }
    return count;
}
int main(){
    Node*head=NULL;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    print(head);
    cout<<countNodes(head);
    return 0;
}