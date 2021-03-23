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
int length(node*head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
void insertionAtMiddle(node*&head,int d,int p){
    if(head==NULL){
        head=new node(d);
        return;
    }
    if(p>=length(head)){
        node*tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=new node(d);
        return;
    }
    int jump=1;
    node*temp=head;
    while(jump<=p-1){
        temp=temp->next;
        jump++;
    }
    node*n=new node(d);
    n->next=temp->next;
    temp->next=n;
    return;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
int main(){
    node*head=NULL;
    insertionAtMiddle(head,5,4);
    insertionAtMiddle(head,2,8);
    insertionAtMiddle(head,89,4);
    insertionAtMiddle(head,20,1);
    print(head);
    return 0;
}