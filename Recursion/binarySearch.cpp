#include<iostream>
using namespace std;
int binarySearch(int arr[],int s,int e,int search){
    int mid=(s+e)/2;
    if(search==arr[mid]){
        return mid;
    }
    if(arr[mid]>search){
        s=mid+1;
        binarySearch(arr+s,s,e,search);
    }
    else{
        e=mid-1;
        binarySearch(arr+s,s,e,search);
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int search;
    cin>>search;
    cout<<binarySearch(arr,0,n-1,search);
    return 0;
}