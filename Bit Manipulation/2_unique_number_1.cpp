//Given an array of integers that has odd number of elements. All the numbrs are repeating twice except one. Find that one unique number


#include<iostream>
using namespace std;
int main(){
    int arr[7]={2,5,3,2,6,5,3};
    int ans=0;
    for(int i=0;i<7;i++){
        ans=ans^arr[i];
    }
    cout<<"Unique number is: "<<ans;
}