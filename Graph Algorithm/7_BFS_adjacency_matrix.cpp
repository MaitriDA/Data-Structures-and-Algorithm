#include<iostream>
#include<map>
#include<queue>
using namespace std;
void printBFS(int graph[][100],int s,int v,map<int,bool>&mp){
    queue<int>q;
    mp[s]=true;
    q.push(s);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        cout<<t<<" ";
        for(int i=0;i<v;i++){
            if(graph[s][i]==1 and mp[i]!=true){
                mp[i]=true;
                q.push(i);
            }
        }
    }
}
void bfs(int graph[][100],int v){
    map<int,bool>mp;
    for(int i=0;i<v;i++){
        if(mp[i]==false){
            printBFS(graph,i,v,mp);
        }
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    int graph[100][100]={0};
    for(int i=0;i<v;i++){
        graph[0][i]=0;
    }
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    bfs(graph,v);
    return 0;
}