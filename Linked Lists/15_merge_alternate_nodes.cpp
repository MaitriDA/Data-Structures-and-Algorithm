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

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}

void insert_at_tail(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
}

void alternate_merge(node*head1,node*head2){
    node*temp=head1;
    while(temp!=NULL){
        node*n=new node(head2->data);
        n->next=temp->next;
        temp->next=n;
        temp=temp->next->next;
        head2=head2->next;
    }
}
int main(){
    node*head1=NULL;
    cout<<"Linked List 1"<<endl;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    print(head1);
    node*head2=NULL;
    cout<<endl<<endl;
    cout<<"Linked List 2"<<endl;
    insert_at_tail(head2,10);
    insert_at_tail(head2,20);
    insert_at_tail(head2,30);
    insert_at_tail(head2,40);
    print(head2);
    cout<<endl<<endl;
    cout<<"Alternate Merge Linked List with LL 1 first"<<endl;
    alternate_merge(head1,head2);
    print(head1);
    cout<<endl<<endl;
    cout<<"Alternate Merge Linked List with LL 2 first"<<endl;
    alternate_merge(head2,head1);
    print(head2);
    return 0;
}