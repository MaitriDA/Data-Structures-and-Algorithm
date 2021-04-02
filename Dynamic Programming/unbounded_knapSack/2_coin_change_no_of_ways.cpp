#include<iostream>
using namespace std;
int coinChange(int n,int coin[],int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<sum+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
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
    int coin[n];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    int sum=0;
    cin>>sum;
    cout<<coinChange(n,coin,sum);
}