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

int linear_search(node*head,int key){
    int count=1;
    while(head!=NULL){
        if((head->data)==key){
            return count;
        }
        count++;
        head=head->next;
    }
    return -1;
}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    print(head);
    cout<<endl;
    cout<<"The key is present at "<<linear_search(head,3)<<" node"<<endl;
    cout<<"The key is present at "<<linear_search(head,30)<<" node"<<endl;
    return 0;
}