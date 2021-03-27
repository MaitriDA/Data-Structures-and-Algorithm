#include<iostream>
using namespace std;
bool equalSumPartition(int n,int arr[],int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int j=1;j<sum+1;j++){
        dp[0][j]=false;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum=sum+arr[i];
    }
    if(sum%2==0){
        if(equalSumPartition(n,arr,sum/2)){
            cout<<"equal sum partition possible";
        }
        else{
            cout<<"not possible";
        }
    }
    else{
        cout<<"not possible";
    }
}