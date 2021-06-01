#include<iostream>
#include<stack>
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

node* demo(node*head){
    node*temp=head;
    int len=0;
    while(temp->next!=NULL){
        len++;
        temp=temp->next;
    }
    len=3;
    temp=head;
    int count=0;
    while(count<len){
        temp=temp->next;
        count++;
    }
    node*store=temp->next;
    temp->next=NULL;
    cout<<store->data<<" ";

    return head;
}
node*reorder(node*head){
    node*temp=head;
    int len=0;
    while(temp->next!=NULL){
        len++;
        temp=temp->next;
    }
    int c=len/2;
    node*temp1=head;
    node*temp2;
    while(c--){
        int l=len-1;
        node*temp3=head;
        while(l--){
            temp3=temp3->next;
        }
        node*store=temp3->next;
        temp3->next=NULL;
        temp2=temp1->next;
        temp1->next=store;
        store->next=temp2;
        temp1=temp1->next->next;
        //print(head);
        //cout<<endl;
        //cout<<"temp1: "<<temp1->data<<" temp2: "<<temp2->data<<" temp1->next->data: "<<temp1->next->data<<endl;
    }
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
    cout<<"original"<<endl;
    print(head);
    cout<<endl;
    node*new_head=reorder(head);
    cout<<"Restored"<<endl;
    print(new_head);
    return 0;
}