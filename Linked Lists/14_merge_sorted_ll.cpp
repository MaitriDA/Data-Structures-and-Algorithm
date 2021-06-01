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

node*merge_sorted(node*head1,node*head2){
    node*result=NULL;
    while(head1!=NULL and head2!=NULL){
        if((head1->data)>(head2->data)){
            insert_at_tail(result,head2->data);
            head2=head2->next;
        }
        else{
            insert_at_tail(result,head1->data);
            head1=head1->next;
        }
    }
    if(head1==NULL){
        while(head2!=NULL){
            insert_at_tail(result,head2->data);
            head2=head2->next;
        }
    }
    if(head2==NULL){
        while(head1!=NULL){
            insert_at_tail(result,head1->data);
            head1=head1->next;
        }
    }
    return result;
}

int main(){
    node*head1=NULL;
    cout<<"Linked List 1"<<endl;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,4);
    insert_at_tail(head1,8);
    print(head1);
    node*head2=NULL;
    cout<<endl<<endl;
    cout<<"Linked List 2"<<endl;
    insert_at_tail(head2,3);
    insert_at_tail(head2,5);
    insert_at_tail(head2,7);
    insert_at_tail(head2,10);
    print(head2);
    cout<<endl<<endl;
    node*head_ans=NULL;
    cout<<"Merged Linked List"<<endl;
    head_ans=merge_sorted(head1,head2);
    print(head_ans);
    return 0;
}