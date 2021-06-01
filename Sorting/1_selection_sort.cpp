#include<bits/stdc++.h>
using namespace std;
void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=arr[i];
        int index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    sort(arr,n);
    cout<<"After sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}