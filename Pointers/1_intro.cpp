//  '*' represents value and '&' represents address
//  'Pi' reresents pointer to integer and 'Pf' represents pointer to integer.
#include<iostream>
#include<typeinfo>
using namespace std;
int main(){
    int var=10;
    int *ptr=&var;

    cout<<"Data type of var: "<<typeid(var).name()<<endl;
    cout<<"Data type of ptr: "<<typeid(ptr).name()<<endl;
    cout<<"Address of variable var: "<<ptr<<" and "<<&var<<endl;
    cout<<"Address of pointer variable: "<<&ptr<<endl;
    cout<<"--------------------------";
    cout<<endl;

    cout<<"var: "<<var<<endl;
    cout<<"&var: "<<&var<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"--------------------------";
    cout<<endl;

    *ptr=20;
    cout<<"var: "<<var<<endl;
    cout<<"&var: "<<&var<<endl;
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout<<"--------------------------";
    cout<<endl;
    
    return 0;
}