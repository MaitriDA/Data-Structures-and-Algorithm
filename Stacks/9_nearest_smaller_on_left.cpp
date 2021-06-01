#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nearest_smaller_on_left(int arr[],int n,vector<int>&v){
    stack<int>s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(-1);
            s.push(arr[i]);
        }
        else{
            while(!s.empty()){
                if(s.top()<arr[i]){
                    v.push_back(s.top());
                    s.push(arr[i]);
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                s.push(arr[i]);
                v.push_back(-1);
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
    nearest_smaller_on_left(arr,n,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}