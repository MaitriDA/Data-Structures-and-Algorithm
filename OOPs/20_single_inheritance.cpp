#include<iostream>
using namespace std;

class Base{
    //By default it is private and is not inheritable.
    int data1;
public:
    int data2;
    void setData(){
        data1=10;
        data2=20;
    }
    int getData1(){
        return data1;
    }
    int getData2(){
        return data2;
    }
};

class Derived:private Base{
    int data3;
public:
    void process(){
        setData();
        data3=data2*getData1();
    }
    void display(){
        cout<<"Data1: "<<getData1()<<endl;
        cout<<"Data2: "<<data2<<endl;
        cout<<"Data3: "<<data3<<endl;
    }
};

int main(){
    cout<<"d1 "<<endl;
    Derived d1;
    d1.display();
    cout<<"----------------"<<endl<<endl;

    cout<<"d2 "<<endl;
    Derived d2;
    //d2.setData();
    d2.process();
    d2.display();
    cout<<"----------------"<<endl<<endl;

    cout<<"d3 "<<endl;
    Base b;
    Derived d3;
    d3.display();
    cout<<"----------------"<<endl<<endl;

    cout<<"d4 "<<endl;
    Base b1;
    b1.setData();
    Derived d4;
    d4.process();
    d4.display();
    return 0;
}