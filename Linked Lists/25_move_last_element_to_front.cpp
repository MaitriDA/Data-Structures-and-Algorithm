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

node* last_to_front(node*&head){
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    node*n=head;
    while(n->next->next!=NULL){
        n=n->next;
    }
    n->next=NULL;
    node*head_new=head;
    head_new=new node(temp->data);
    head_new->next=head;
    return head_new;
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
    cout<<"Updated Linked List: "<<endl;
    node*head_new=last_to_front(head);
    print(head_new);
    cout<<endl;
    return 0;
}