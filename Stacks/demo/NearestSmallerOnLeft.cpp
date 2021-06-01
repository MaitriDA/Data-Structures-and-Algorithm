#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>v;
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
                v.push_back(-1);
                s.push(arr[i]);
            }

        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}