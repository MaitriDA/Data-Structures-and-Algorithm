#include<iostream>
using namespace std;
int getFibonacci(int n){
    if(n==0 or n==1){
        return n;
    }
    int f1=getFibonacci(n-1);
    int f2=getFibonacci(n-2);
    return f1+f2;
}
int main(){
    int n;
    cin>>n;
    cout<<getFibonacci(n);
    return 0;
}