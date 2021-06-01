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

node* even_first(node*head){
    node*even_temp=NULL;
    node*odd_temp=NULL;
    node*even=even_temp;
    node*odd=odd_temp;
    while(head!=NULL){
        if((head->data)%2==0){
            node*n=new node(head->data);
            if(even_temp==NULL){
                even_temp=n;
                even=even_temp;
            }
            else{
                even_temp->next=n;
                even_temp=even_temp->next;
            }
        }
        else{
            node*n=new node(head->data);
            if(odd_temp==NULL){
                odd_temp=n;
                odd=odd_temp;
            }
            else{
                odd_temp->next=n;
                odd_temp=odd_temp->next;
            }
        }
        head=head->next;
    }
    even_temp->next=odd;
    head=even;
    return head;
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
    cout<<"original"<<endl;
    print(head);
    cout<<endl;
    node*new_head=even_first(head);
    print(new_head);
    return 0;
}