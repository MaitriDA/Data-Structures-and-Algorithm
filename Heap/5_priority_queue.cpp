#include<iostream>
#include<queue>
using namespace std;
int main(){
    //Max Heap (Default)
    //priority_queue<int>pq;
    //Min Heap
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        pq.push(d);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}