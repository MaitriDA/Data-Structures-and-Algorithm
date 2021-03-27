#include<iostream>
using namespace std;
int minDiffernce(int arr[], int n) { 
	int tsum=0;
    for(int i=0;i<n;i++){
        tsum=tsum+arr[i];
	}
	int sum=tsum/2;
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
	for(int j=sum;j>=0;j--){
	    if(dp[n][j]==1){
	        int ans=tsum-(2*j);
	        return ans;
	    }
	}
} 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minDiffernce(arr,n);
}