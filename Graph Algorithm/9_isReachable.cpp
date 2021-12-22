#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int>*l;
public:
    Graph(int n){
        v=n;
        l=new list<int>[v];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool isReachable(int s,int d){
        if(s==d){
            return true;
        }
        queue<int>q;
        bool *visited=new bool[v];
        q.push(s);
        for(int i=0;i<v;i++){
            visited[i]=false;
        }
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(auto i=l[s].begin();i!=l[s].end();i++){
                if(*i==d){
                    return true;
                }
                if(!visited[*i]){
                    visited[*i]=true;
                    q.push(*i);
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    if(g.isReachable(3,5)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}