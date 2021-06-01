#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int no;
    int res=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        res=res^arr[i];
    }
    int temp=res;
    int pos=0;
    while((temp&1)!=1){
        pos++;
        temp=temp>>1;
    }
    int x=0;
    int y=0;
    int mask=(1>>pos);
    for(int i=0;i<n;i++){
        if((arr[i] & mask)>0){
            x=x^arr[i];
        }
    }
    y=res^x;
    cout<<min(x,y)<<","<<max(x,y)<<endl;
    return 0;
}