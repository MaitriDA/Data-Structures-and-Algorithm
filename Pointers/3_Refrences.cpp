#include<iostream>
using namespace std;
int main(){
    int x=10;
    int &ref=x;
    cout<<"x: "<<x<<endl;
    cout<<"ref: "<<ref<<endl;
    cout<<"&x: "<<&x<<endl;
    cout<<"&ref: "<<&ref<<endl;
    cout<<"---------------"<<endl;
    
    ref=20;
    cout<<"x: "<<x<<endl;
    cout<<"ref: "<<ref<<endl;
    cout<<"&x: "<<&x<<endl;
    cout<<"&ref: "<<&ref<<endl;
    cout<<"---------------"<<endl;
    return 0;
}