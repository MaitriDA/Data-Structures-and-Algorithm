#include<iostream>
using namespace std;

class Base1{
public:
    void greet(){
        cout<<"How are you from base1 class"<<endl;
    }
};

class Base2{
public:
    void greet(){
        cout<<"How are you from base2 class"<<endl;
    }
};

class Derived:public Base1,public Base2{
    int a;
public:
    /*void greet(){
        Base1::greet();
    }*/
    void greet(){
        Base2::greet();
    }
};

class B{
public:
    void say(){
        cout<<"Hello world!!"<<endl;
    }
};

class D:public B{
    int a;
    //This say function override the say function og B class
public:
    void say(){
        cout<<"Hello world!! from D class"<<endl;
    }
};
int main(){
    //Ambiguity 1
    Base1 b1;
    Base2 b2;
    b1.greet();
    b2.greet();
    Derived d;
    d.greet();

    //Ambiguity 2
    /*B b;
    b.say();
    D d;
    d.say();*/
    return 0;
}