#include<iostream>
#include<climits>
using namespace std;
int coinChange(int n,int coin[],int sum){
    int dp[n+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j]=INT_MAX-1;
    }
    for(int i=1;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=1;j<sum+1;j++){
        if(j%coin[0]==0){
            dp[1][j]=j/coin[0];
        }
        else{
            dp[1][j]=INT_MAX-1;
        }
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
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
    int coin[n];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    int sum;
    cin>>sum;
    cout<<coinChange(n,coin,sum);
    return 0;
}
