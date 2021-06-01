#include<iostream>
#include<map>
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

int count_nodes(node*head1,node*head2){
    map<int,bool>mp;
    while(head1!=NULL){
        mp[head1->data]=true;
        head1=head1->next;
    }
    int count=0;
    while(head2!=NULL){
        if(mp[head2->data]){
            count++;
        }
        head2=head2->next;
    }
    return count;
}
int main(){
    node*head1=NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    insert_at_tail(head1,5);

    node*head2=NULL;
    insert_at_tail(head2,1);
    insert_at_tail(head2,7);
    insert_at_tail(head2,3);
    insert_at_tail(head2,9);
    insert_at_tail(head2,5);
    insert_at_tail(head2,11);
    cout<<"Linked List 1"<<endl;
    print(head1);
    cout<<endl<<endl;
    cout<<"Linked List 2"<<endl;
    print(head2);
    cout<<endl<<endl;
    int count=count_nodes(head1,head2);
    cout<<"Number of common nodes: "<<count<<endl;
    return 0;
}