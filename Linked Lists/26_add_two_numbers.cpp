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

void insert_at_head(node*&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    node*n=new node(data);
    n->next=head;
    head=n;
}


int reverse(node*head){
    int sum=0;
    while(head!=NULL){
        sum=sum*10+head->data;
        head=head->next;
    }
    return sum;
}
node*add(node*first,node*second){
    int sum1=reverse(first);
        int sum2=reverse(second);
        int total=sum1+sum2;
        node*new_head=NULL;
        while(total!=0){
            int r=total%10;
            total=total/10;
            insert_at_head(new_head,r);
        }
        return new_head;
}


int main(){
    node*head1=NULL;
    insert_at_tail(head1,1);
    insert_at_tail(head1,2);
    insert_at_tail(head1,3);
    insert_at_tail(head1,4);
    //print(head1);
    node*head2=NULL;
    insert_at_tail(head2,1);
    insert_at_tail(head2,2);
    insert_at_tail(head2,3);
    insert_at_tail(head2,4);
    //print(head2);
    node*addHead=NULL;
    addHead=add(head1,head2);
    cout<<endl;
    return 0;
}