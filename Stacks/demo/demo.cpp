#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>&s,stack<int>&s1,int n,int temp){
    while(n--){
        s1.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }
    return;
}

void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return;
}
int main(){
    stack<int>s,s1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        s.push(d);
    }
    print(s);
    for(int i=0;i<n;i++){
        int temp=s.top();
        s.pop();
        transfer(s,s1,n-i-1,temp);
    }
    print(s);
    return 0;
}