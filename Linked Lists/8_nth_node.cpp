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

int length(node*head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
int get_data(node*head,int index){
    if(index>length(head)){
        return -1;
    }
    int count=1;
    while(count<index){
        head=head->next;
        count++;
    }
    return head->data;
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    print(head);
    cout<<endl;
    cout<<"The data at the 3rd node is: "<<get_data(head,3)<<endl;
    cout<<"The data at the 6rd node is: "<<get_data(head,6)<<endl;
    return 0;
}