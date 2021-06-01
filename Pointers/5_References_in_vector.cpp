#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v{10,20,30,40,50};
    cout<<"Original vector"<<endl;
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"-------------------------"<<endl;
    for(int &x:v){
        x=x+5;
    }
    cout<<"Modified vector"<<endl;
    for(int x :v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"-------------------------"<<endl;
    return 0;
}