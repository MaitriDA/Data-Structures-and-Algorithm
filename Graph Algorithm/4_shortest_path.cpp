#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Graph{
    map<int,list<int>>l;
public:
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void findShortestPath(int src){
        map<int,int>mp;
        queue<int>q;
        q.push(src);
        for(auto x:l){
            int t=x.first;
            mp[t]=INT_MAX;
        }
        mp[src]=0;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(int x:l[n]){
                if(mp[x]==INT_MAX){
                    q.push(x);
                    mp[x]=mp[n]+1;
                }
            }
        }
        for(auto x:l){
            int t=x.first;
            cout<<t<<" "<<mp[t]<<endl;
        }
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
    g.findShortestPath(0);
    return 0;
}
