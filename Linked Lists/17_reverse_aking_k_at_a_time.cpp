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

node* reverse(node*&head,int k){
    int count=0;
    node*curr=head;
    node*prev=NULL;
    node*n;
    while(curr!=NULL and count<k){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        count++;
    }
    count=0;
    if(n!=NULL){
        head->next=n;
        while(count<k){
            n=n->next;
            count++;
        }
        head->next=reverse(n,k);
    }
    head=prev;
    return head;
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
    cout<<"Reversed Linked List: "<<endl;
    node*head_rev=reverse(head,3);
    print(head_rev);
    cout<<endl;
    return 0;
}