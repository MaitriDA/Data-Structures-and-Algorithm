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
    node*n=new node(d);
    temp->next=n;
    return;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

void remove_loop(node*head){
    node*slow=head;
    node*fast=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast && fast->next){
        
        if(slow==fast){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    print(head);
    cout<<endl;
    head->next->next->next->next=head->next;
    remove_loop(head);
    print(head);
    return 0;
}