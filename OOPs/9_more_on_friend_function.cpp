#include<iostream>
using namespace std;

class Y;

class X{
    int data;
public:
    void setValue(int value){
        data=value;
    }
    friend void add(X,Y);
};

class Y{
    int num;
public:
    void setValue(int value){
        num=value;
    }
    friend void add(X,Y);
};

void add(X o1,Y o2){
    cout<<"Sum: "<<o1.data+o2.num<<endl;
}
int main(){
    X a;
    Y b;
    a.setValue(3);
    b.setValue(5);
    add(a,b);
    return 0;
}