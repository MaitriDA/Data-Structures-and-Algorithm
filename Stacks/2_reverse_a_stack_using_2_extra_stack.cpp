#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s,s1,s2;
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }

    cout<<"Original Stack: "<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s1.push(s.top());
        s.pop();
    }
    while(!s1.empty()){
       s2.push(s1.top());
       s1.pop(); 
    }
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
    cout<<endl<<endl;
    cout<<"Reversed Stack: "<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}