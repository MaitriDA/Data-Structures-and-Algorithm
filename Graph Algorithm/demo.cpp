#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Graph{
    int v;
    map<int,vector<int>>mp;
public:
    void addEdge(int x,int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void print(){
        for(auto i:mp){
            cout<<i.first<<"-->";
            for(auto x:i.second){
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    void printPathHelper(int s,int d,bool visited[],vector<int>path,int &path_index){
        visited[s]=true;
        path[path_index]=s;
        path_index++;

        if(s==d){
            for(int i=0;i<path_index;i++){
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(auto x:mp[s]){
                if(!visited[x]){
                    printPathHelper(x,d,visited,path,path_index);
                }
            }
        }
        path_index--;
        visited[s]=false;
    }
    void printPath(int s,int d){
        int n=mp.size();
        bool visited[n+1];
        for(int i=0;i<=n;i++){
            visited[i]=false;
        }
        vector<int>path;
        int path_index=0;
        printPathHelper(s,d,visited,path,path_index);
    }
};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(5,8);
    g.addEdge(6,7);
    g.addEdge(5,6);
    g.print();
    g.printPath(1,8);
    return 0;
}