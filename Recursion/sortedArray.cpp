#include<iostream>
using namespace std;
bool check(int arr[],int n){
    if(n==0 or n==1){
        return true;
    }
    if(arr[n]>arr[n-1] and check(arr,n-1)){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(check(arr,n)){
        cout<<"yes";
    }
    else{
        cout<<"No";
    }
}