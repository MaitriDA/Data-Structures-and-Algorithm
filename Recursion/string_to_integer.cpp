#include<iostream>
#include<string>
using namespace std;
int stringToInteger(string s,int n){
    if(n==0){
        return 0;
    }
    int digit=stringToInteger(s,n-1);
    return (s[n-1]-'0')+digit*10;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    cout<<stringToInteger(s,n);
}