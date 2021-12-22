#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return;
}
void insertAtBottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int d=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(d);
    return;
}
void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,x);
    return;
}
int main(){
    stack<int>s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        s.push(d);
    }
    print(s);
    reverse(s);
    print(s);
}