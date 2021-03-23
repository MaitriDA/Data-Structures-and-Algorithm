#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ml[n];
    int mr[n];
    int ml_max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>=ml_max){
            ml[i]=arr[i];
            ml_max=arr[i];
        }
        else{
            ml[i]=ml_max;
        }
    }
    int mr_max=arr[n-1];
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=mr_max){
            mr[i]=arr[i];
            mr_max=arr[i];
        }
        else{
            mr[i]=mr_max;
        }
    }
    int water=0;
    for(int i=0;i<n;i++){
        water=water+(min(ml[i],mr[i])-arr[i]);
    }
    cout<<water;
}