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

void delete_node(node*head,int n,int m){
    n--;
    node*temp=head;
    int count=0;
    while (n--){
        temp=temp->next;
        count++;
    }
    node*prev=temp;
    while(m--){
        temp=temp->next;
    }
    prev->next=temp->next;
    
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_tail(head,8);
    insert_at_tail(head,9);
    insert_at_tail(head,10);
    insert_at_tail(head,11);
    cout<<"original";
    print(head);
    cout<<endl;
    delete_node(head,3,2);
    print(head);
    return 0;
}