#include<iostream>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    int graph[v][v]={0};
    for(int i=0;i<v;i++){
        graph[0][i]=0;
    }
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}