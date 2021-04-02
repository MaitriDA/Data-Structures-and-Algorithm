#include<iostream>
#include<cstring>
using namespace std;
int lcs(string s1,string s2,int x,int y){
    int dp[x+1][y+1];
        for(int i=0;i<x+1;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<y+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
}
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    cout<<lcs(s1,s2,s1.length(),s2.length());
    return 0;
}