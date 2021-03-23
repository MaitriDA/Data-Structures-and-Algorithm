#include<iostream>
using namespace std;
int subset(int arr[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<sum+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<subset(arr,n,sum);
}