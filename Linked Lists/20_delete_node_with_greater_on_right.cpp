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
node* reverse(node*&head){
    node*curr=head;
    node*prev=NULL;
    node*n;
    while(curr!=NULL){
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    head=prev;
    return head;
}
void delete_node(node*&head){
    node*head_new=reverse(head);
    node*prev=head_new;
    node*curr=prev->next;
    node*n=curr->next;
    while(curr->next!=NULL){
        if((prev->data)>(curr->data)){
            prev->next=n;
            curr=n;
            n=n->next;
        }
        else{
            prev=curr;
            curr=n;
            n=n->next;
        }
    }
    reverse(head_new);
    node*temp=head_new;
    if((temp->data)<(temp->next->data)){
        head_new=temp->next;
    }
    print(head_new);
}
int main(){
    node*head=NULL;
    insert_at_tail(head,12);
    insert_at_tail(head,15);
    insert_at_tail(head,10);
    insert_at_tail(head,11);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    cout<<"original";
    print(head);
    cout<<endl;
    delete_node(head);
    return 0;
}