#include<iostream>
using namespace std;
int main(){
    long long int arr[4];
    for(int i=0;i<4;i++){
        arr[i]=i*i;
    }
    long long int*p=arr;
    long long int*q=arr;
    p++;
    cout<<p-q<<endl;
    return 0;
}