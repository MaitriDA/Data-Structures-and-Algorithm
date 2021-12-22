#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool path(int**graph,int n,int s,int d,bool*visited,int*parent){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==d){
            return true;
        }
        for(int i=0;i<n;i++){
            if(graph[u][i]==1 and visited[i]==false){
                q.push(i);
                parent[i]=u;
                visited[i]=true;
            }
        }
    }
    return false;
}
int main(){
    int v,e;
    cin>>v>>e;
    int **graph;
    graph=new int*[v];
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
    int *parent=new int[v];
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        parent[i]=-1;
    }
    if(path(graph,v,v1,v2,visited,parent)){
        vector<int>path;
        int c=v2;
        path.push_back(c);
        while(parent[c]!=-1){
            path.push_back(parent[c]);
            c=parent[c];
        }
        for(int i=path.size()-1;i>=0;i--){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"No";
    }
    return 0;
}