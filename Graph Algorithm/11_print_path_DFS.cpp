#include<iostream>
#include<vector>
using namespace std;

bool path(int**graph,int n,int s,int d,bool*visited,vector<int>&v){
    v.push_back(s);
    visited[s]=true;
    if(s==d){
        return true;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] and graph[s][i]==1){
            if(path(graph,n,i,d,visited,v)){
                return true;
            }
        }
    }
    v.pop_back();
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
    vector<int>vec;
    bool *visited=new bool[v];
    if(path(graph,v,v1,v2,visited,vec)){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }
    else{
        cout<<"No";
    }
    return 0;
}