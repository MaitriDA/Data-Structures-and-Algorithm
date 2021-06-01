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

node* rotate(node*&head,int k){
    if(k==0){
        return head;
    }
    node*temp=head;
    node*temp2=head;
    int count=1;
    while(count<=k){
        head=head->next;
        count++;
    }
    node*new_head=head;
    count=1;
    while(count<k){
        temp=temp->next;
        count++;
    }
    temp->next=NULL;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=temp2;
    return new_head;
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,9);
    insert_at_tail(head,10);
    insert_at_tail(head,11);
    cout<<"Original Linked List: "<<endl;
    print(head);
    cout<<endl<<endl;
    cout<<"Rotated Linked List: "<<endl;
    node*head_rot=rotate(head,4);
    print(head_rot);
    cout<<endl;
    return 0;
}