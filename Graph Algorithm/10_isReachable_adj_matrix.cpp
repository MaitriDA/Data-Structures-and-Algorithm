#include<iostream>
#include<queue>
using namespace std;

bool isReachable(int**graph,int n,int s,int d){
    if(s==d){
        return true;
    }
    bool hasRoute=false;
    bool visited[n+1]={false};
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty() and !hasRoute){
        int curr=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(graph[curr][i]==1 and !visited[i]){
                if(i==d){
                    hasRoute=true;
                    break;
                }
                visited[i]=true;
                q.push(i);
            }
        }
    }
    return hasRoute;
}
int main(){
    int v,e;
    cin>>v>>e;
    int **graph=new int*[v];
    for(int i=0;i<v;i++){
        graph[i]=new int[v];
        for(int j=0;j<v;j++){
            graph[i][j]=0;
        }
    }
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    if(isReachable(graph,v,v1,v2)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}