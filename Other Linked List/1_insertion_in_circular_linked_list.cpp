#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void print(Node*last){
    Node*temp;
    if(last==NULL){
        cout<<"Empty list";
        return;
    }
    temp=last->next;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=last->next);
    cout<<endl;
}
Node*addIfEmpty(Node*last,int d){
    if(last!=NULL){
        return last;
    }
    Node*temp=new Node(d);
    last=temp;
    temp->next=last;
    return last;
}

Node*addInBegining(Node*last,int d){
    if(last==NULL){
        return addIfEmpty(last,d);
    }
    Node*temp=new Node(d);
    temp->next=last->next;
    last->next=temp;
    return last;
}

Node*addInEnd(Node*last,int d){
    if(last==NULL){
        return addIfEmpty(last,d);
    }
    Node*temp=new Node(d);
    temp->next=last->next;
    last->next=temp;
    last=temp;
    return last;
}

Node*addAfterNode(Node*last,int d,int item){
    if(last==NULL){
        return addIfEmpty(last,d);
    }
    Node*temp,*p;
    p=last->next;
    do{
        if(p->data==item){
            temp=new Node(d);
            temp->next=p->next;
            p->next=temp;
            if(p==last){
                last=temp;
            }
            return last;
        }
        p=p->next;
    }
    while(p!=last->next);
    cout<<"No item found"<<endl;
    return last;
}
int main(){
    Node*last=NULL;
    last=addIfEmpty(last,1);
    last=addInBegining(last,2);
    last=addInBegining(last,3);
    last=addInEnd(last,4);
    last=addAfterNode(last,5,2);
    print(last);
    return 0;
}