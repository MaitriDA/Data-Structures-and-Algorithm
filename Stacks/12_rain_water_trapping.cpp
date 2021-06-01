#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int rain_water(int arr[],int n){
    vector<int>vl;
    vector<int>vr;
    int maxl=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>maxl){
            maxl=arr[i];
        }
        vl.push_back(maxl);
    }
    int maxr=-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxr){
            maxr=arr[i];
        }
        vr.push_back(maxr);
    }
    int water=0;
    for(int i=0;i<n;i++){
        cout<<vl[i]<<" "<<vr[n-i-1]<<endl;
        water=water+(min(vr[n-i-1],vl[i])-arr[i]);
    }
    return water;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rain_water(arr,n);
}