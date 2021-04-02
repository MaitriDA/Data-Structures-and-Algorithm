#include<iostream>
#include<cstring>
using namespace std;
int lcs(int n,int m,string x,string y){
    if(n==0 or m==0){
            return 0;
        }
        if(x[n-1]==y[m-1]){
            return 1+lcs(n-1,m-1,x,y);
        }
        else{
            return max(lcs(n,m-1,x,y),lcs(n-1,m,x,y));
        }
}
int main(){
    string x;
    cin>>x;
    string y;
    cin>>y;
    int n=x.length();
    int m=y.length();
    cout<<lcs(n,m,x,y);
    return 0;
}