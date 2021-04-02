#include<iostream>
using namespace std;
int rodCut(int price[],int n){
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<n+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][n]-1;
}
int main(){
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<rodCut(price,n);
    return 0;
}