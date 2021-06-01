#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s="(({[]})())";
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s.empty()){
            st.push(s[i]);
            continue;
        }
        if((s[i]==')' and st.top()=='(') or (s[i]=='}' and st.top()=='{') or (s[i]==']' and st.top()=='[')){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}