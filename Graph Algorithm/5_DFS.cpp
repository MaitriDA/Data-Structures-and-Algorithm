#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    map<int,list<int>>l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(int src,map<int,bool>&mp){
        cout<<src<<",";
        mp[src]=true;
        for(auto x:l[src]){
            if(mp[x]!=true){
                dfs_helper(x,mp);
            }
        }
    }
    void dfs(int src){
        map<int,bool>mp;
        for(auto x:l){
            int t=x.first;
            mp[t]=false;
        }
        dfs_helper(src,mp);

    }
};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(1);
    return 0;
}