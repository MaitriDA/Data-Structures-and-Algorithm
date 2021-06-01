#include<iostream>
#include<stack>
using namespace std;
void transfer(stack<int>&s,int n,int data){
    stack<int>s_temp;
    for(int i=0;i<n;i++){
        s_temp.push(s.top());
        s.pop();
    }
    s.push(data);
    for(int i=0;i<n;i++){
        s.push(s_temp.top());
        s_temp.pop();
    }
}
void reverse(stack<int>&s){
    int n=s.size();
    for(int i=0;i<n;i++){
        int x=s.top();
        s.pop();
        transfer(s,n-i-1,x);
    }
}
int main(){
    stack<int>s;
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    cout<<"Original Stack: "<<endl;
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    cout<<endl;
    cout<<"Reversed Stack: "<<endl;
    reverse(s);
    for(int i=0;i<5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}