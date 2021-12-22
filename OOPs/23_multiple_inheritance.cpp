#include<iostream>
using namespace std;

class Base1{
protected:
    int var1;
public:
    void set_var1(int a){
        var1=a;
    }
    void get_var1(){
        cout<<"Var 1 "<<var1<<endl;
    }
};

class Base2{
protected:
    int var2;
public:
    void set_var2(int a){
        var2=a;
    }
    void get_var2(){
        cout<<"Var 2 "<<var2<<endl;
    }
};

class Derived:public Base1, public Base2{
    public:
        void show(){
            cout<<"The value of Var 1: "<<var1<<endl;
            cout<<"The value of Var 2: "<<var2<<endl;
            cout<<"The sum is: "<<var1+var2<<endl;
        }
};

int main(){
    Derived d;
    d.show();
    cout<<"--------------------------------"<<endl<<endl;


    Base1 b1;
    b1.set_var1(45);
    b1.get_var1();
    Base2 b2;
    b2.set_var2(12);
    b2.get_var2();
    Derived d1;
    d1.show();
    cout<<"-------------------------------"<<endl<<endl;
    
    Derived d2;
    d2.set_var1(25);
    d2.get_var1();
    d2.set_var2(48);
    d2.get_var2();
    d2.show();
    return 0;
}