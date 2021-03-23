#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int value[n];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            v.push_back(1);
            s.push(make_pair(value[i],i));
        }
        else{
            while(!s.empty()){
                if(value[i]<=s.top().first){
                    v.push_back(i-(s.top().second));
                    s.push(make_pair(value[i],i));
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                v.push_back(1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
