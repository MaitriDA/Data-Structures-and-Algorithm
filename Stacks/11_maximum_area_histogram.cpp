#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int max_area(int arr[],int n){
    //nearest smaller on left;
    vector<int>vl;
    stack<pair<int,int>>sl;
    for(int i=0;i<n;i++){
        if(sl.empty()){
            vl.push_back(-1);
            sl.push(make_pair(arr[i],i));
        }
        else{
            while(!sl.empty()){
                if(sl.top().first<arr[i]){
                    vl.push_back(sl.top().second);
                    sl.push(make_pair(arr[i],i));
                    break;
                }
                else{
                    sl.pop();
                }
            }
            if(sl.empty()){
                vl.push_back(-1);
                sl.push(make_pair(arr[i],i));
            }
        }
    }
    
    //nearest smaller on right;
    vector<int>vr;
    stack<pair<int,int>>sr;
    for(int i=n-1;i>=0;i--){
        if(sr.empty()){
            vr.push_back(n);
            sr.push(make_pair(arr[i],i));
        }
        else{
            while(!sr.empty()){
                if(sr.top().first<arr[i]){
                    vr.push_back(sr.top().second);
                    sr.push(make_pair(arr[i],i));
                    break;
                }
                else{
                    sr.pop();
                }
            }
            if(sr.empty()){
                vr.push_back(n);
                sr.push(make_pair(arr[i],i));
            }
        }
    }
    
    int max=0;
    int ans;
    for(int i=0;i<n;i++){
        cout<<vl[i]<<" "<<vr[n-i-1]<<endl;
        ans=((vr[n-i-1]-i-1)+(i-vl[i]-1)+1)*arr[i];
        if(ans>max){
            max=ans;
        }
    }
    return max;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int area=max_area(arr,n);
    cout<<area<<endl;
    return 0;
}