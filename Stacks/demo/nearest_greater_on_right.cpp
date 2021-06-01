#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//BRUTE FORCE APPROACH O(n^2)

/*int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i+1;j<n;j++){
            count++;
            if(arr[i]<arr[j]){
                cout<<arr[j]<<" ";
                break;
            }
            if(count==n-i-1){
                cout<<"-1 ";
            }
        }
    }
    cout<<"-1";
}*/

//USING STACKS O(n)
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    stack<int>s;
    vector<int>v;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            v.push_back(-1);
            s.push(arr[i]);
        }
        else{
            while(!s.empty()){
                if(s.top()>arr[i]){
                    v.push_back(s.top());
                    s.push(arr[i]);
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                v.push_back(-1);
                s.push(arr[i]);
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
}