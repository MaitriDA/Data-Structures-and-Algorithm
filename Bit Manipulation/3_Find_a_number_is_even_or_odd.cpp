#include<iostream>
using namespace std;

bool even_odd(int n){
    return n&1;
}
int main(){
    int n;
    cin>>n;
    if(even_odd(n)){
        cout<<"Odd";
    }
    else{
        cout<<"Even";
    }
    return 0;
}