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

void insertion_at_head(Node*&head,int d){
    if(head==NULL){
        Node*n=new Node(d);
        head=n;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(d);
}

Node* reverse(Node*&head,int k){
    int count=0;
    if(head==NULL){
        return head;
    }
    Node*p=NULL;
    Node*c=head;
    Node*n;
    while(c!=NULL and count<k){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        count++;
    }
    if(n!=NULL){
        head->next=reverse(n,k);
    }
    head=p;
    return head;
}
void delete_without_head(Node*head){
    Node*n=head->next;
    head->data=n->data;
    head->next=n->next;
    return;
}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    return;
}
int main(){
    Node*head=NULL;
    insertion_at_head(head,1);
    insertion_at_head(head,3);
    insertion_at_head(head,7);
    insertion_at_head(head,6);
    insertion_at_head(head,5);
    insertion_at_head(head,4);
    insertion_at_head(head,2);
    print(head);
    cout<<endl;
    delete_without_head(head->next->next);
    print(head);
    return 0;
}