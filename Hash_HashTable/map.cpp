#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main(){
    map<string,int>m;

    //Insert
    m.insert(make_pair("mango",100));

    pair<string,int>p;
    p.first="apple";
    p.second=120;
    m.insert(p);

    m["banana"]=20;

    //Searching
    string key;
    cin>>key;

    auto it=m.find(key);
    if(it!=m.end()){
        cout<<"price of fruit "<<key<<" is "<<m[key]<<endl;;
    }
    else{
        cout<<"-1"<<endl;
    }

    //Erasing
    m.erase(key);

    //Another way to find a particular element
    if(m.count(key)){
        cout<<"price is "<<m[key]<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }

    //Updating
    m["mango"]+=50;

    m["kiwi"]=60;
    m["pineapple"]=150;

    for (auto it=m.begin();it!=m.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }
    cout<<endl;
    cout<<endl;
    for(auto p:m){
        cout<<p.first<<"->"<<p.second<<endl;
    }
}