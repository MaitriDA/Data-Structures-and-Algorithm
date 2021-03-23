#include<iostream>
using namespace std;
int countBinaryString(int l){
    if(l==0){
        return 1;
    }
    else if(l==1){
        return 2;
    }
    int ans=0;
    ans=ans+countBinaryString(l-1)+countBinaryString(l-2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<countBinaryString(n);
}