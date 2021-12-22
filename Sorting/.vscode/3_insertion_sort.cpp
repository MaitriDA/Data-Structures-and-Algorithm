#include<iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int hole=i-1;
        while(hole>=0 && arr[hole]>key){
            arr[hole+1]=arr[hole];
            hole--;
        }
        arr[hole+1]=key;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting"<<endl;
    printArray(arr,n);
    insertionSort(arr,n);
    cout<<"After sorting"<<endl;
    printArray(arr,n);
    return 0;
}