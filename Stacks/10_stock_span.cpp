#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void stock_span(int arr[],int n,vector<int>&v){
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(1);
            s.push(make_pair(arr[i],i));
        }
        else{
            while(!s.empty()){
                if(s.top().first>=arr[i]){
                    v.push_back(i-(s.top().second));
                    s.push(make_pair(arr[i],i));
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                s.push(make_pair(arr[i],i));
                v.push_back(1);
            }
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
    vector<int>v;
    stock_span(arr,n,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}