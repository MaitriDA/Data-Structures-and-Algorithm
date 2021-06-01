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

//using stack
bool palindrome_stack(node*head){
    int l=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    temp=head;
    int count=0;
    while(count<l/2){
        temp=temp->next;
        count++;
    }
    stack<int>sp;
    count=0;
    if(l%2!=0){
        l++;
    }
    while(count<l/2){
        sp.push(temp->data);
        temp=temp->next;
        count++;
    }
    count=0;
    while(count<l/2){
        if(head->data!=sp.top()){
            return false;
        }
        //cout<<"LL: "<<head->data<<" SP: "<<sp.top()<<endl;
        head=head->next;
        sp.pop();
        count++;
    }
    return true;

}
int main(){
    node*head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,5);
    insert_at_tail(head,4);
    insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    print(head);
    cout<<endl;
    if(palindrome_stack(head)){
        cout<<"Palindrome: Yes";
    }
    else{
        cout<<"Palindrome: No";
    }
    
    return 0;
}