#include<iostream>
using namespace std;
int fastPower(int a,int n){
    if(n==0){
        return 1;
    }
    int ans=fastPower(a,n/2);
    if(n%2==0){
        return ans*ans;
    }
    else{
        return ans*ans*a;
    }
}
int main(){
    int a,n;
    cin>>a>>n;
    cout<<fastPower(a,n);
    return 0;
}