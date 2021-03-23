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

    vector<int>vr;
    stack<pair<int,int>>sr;
    for(int i=n-1;i>=0;i--){
        if(sr.empty()){
            vr.push_back(-1);
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
                vr.push_back(-1);
                sr.push(make_pair(arr[i],i));
            }

        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<"("<<vl[i]<<" "<<vr[n-i-1]<<") ";
    // }
    cout<<endl;
    int maximum=0;
    int max;
    for(int i=0;i<n;i++){
        int l=vl[i];
        int r=vr[n-i-1];
        if(l==0 and r<0){
            max=(n-l-1)*arr[i];
        }
        else if(l<0 and r>0){
            max=(r)*arr[i];
        }
        else if(l>0 and r<0){
            max=(n-l-1)*arr[i];
        }
        else if(l<0 and r<0){
            max=(n)*arr[i];
        }
        else if(l>=0 and r>=0){
            max=(r-l-1)*arr[i];
        }

        if(max>maximum){
            maximum=max;
        }
    }
    cout<<maximum;
    return 0;
}