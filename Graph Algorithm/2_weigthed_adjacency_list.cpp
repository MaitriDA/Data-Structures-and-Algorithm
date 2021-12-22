#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    map<string,list<pair<string,int>>>l;
public:
    void addEdge(string x,string y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void print(){
        for(auto p:l){
            string v=p.first;
            list<pair<string,int>>edList=p.second;
            cout<<v<<"->";
            for(auto ed:edList){
                string v1=ed.first;
                int wt1=ed.second;
                cout<<"("<<v1<<","<<wt1<<"),";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.addEdge("B","D",true,30);
    g.addEdge("C","D",true,40);
    g.print();
}