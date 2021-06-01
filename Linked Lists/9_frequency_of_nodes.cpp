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

int frequency(node*head,int key){
    int count=0;
    while(head!=NULL){
        if((head->data)==key){
            count++;
        }
        head=head->next;
    }
    return count;
}

int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,1);
    insert_at_tail(head,4);
    insert_at_tail(head,1);
    insert_at_tail(head,1);
    print(head);
    cout<<endl;
    cout<<"The frequency of 1 is "<<frequency(head,1);
    
    return 0;
}