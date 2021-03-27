//01 KnapSack Top Down Approach
//In this problem the we have a choice to choose an element from the array or not.
//We take a 2D matrix of (n+1)*(w+1) .In smaller sub-problems the total weight and number of elements are
//varying and thus array size and weight are the variables and the 2D array size is dependent on n and w.  
#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int w){
    int dp[n+1][w+1];
    //Initialization-The 0th row and 0th column are initialized with 0.
    //Because in 0th row the number of element is 0 and thus the total value is 0.
    //in the 0th column the total weight is 0 and thus the value is zero.
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=w;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                //here there is a choice of including the element or not and the 
                //maximum of both is taken as the answer for further calculations.
                dp[i][j]=max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int w;
    cin>>w;
    cout<<knapsack(wt,val,n,w);
}