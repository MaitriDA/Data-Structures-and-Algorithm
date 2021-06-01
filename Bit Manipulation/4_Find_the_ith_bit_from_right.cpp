#include<iostream>
using namespace std;

bool ith_bit(int n,int i){
    int mask=1<<i;
    int ans=n&mask;
    if(ans==0){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    int n,i;
    cin>>n>>i;
    if(ith_bit(n,i)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}