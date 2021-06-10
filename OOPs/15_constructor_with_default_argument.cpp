#include<iostream>
using namespace std;

class Simple{
    int data1;
    int data2;
public:
    Simple(int a,int b=10){
        data1=a;
        data2=b;
    }
    void print(){
        cout<<data1<<" and "<<data2<<endl;
    }
};

int main(){
    Simple s1(4,2);
    s1.print();

    Simple s2(4);
    s2.print();
    return 0;
}