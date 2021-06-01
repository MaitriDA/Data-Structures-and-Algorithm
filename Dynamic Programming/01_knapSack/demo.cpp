#include<iostream>
using namespace std;
bool subset(int arr[],int sum,int n){
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
                dp[i][j]=(dp[i-1][j-arr[i-1]] or dp[i-1][j]);
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
    cout<<subset(arr,sum,n);
}