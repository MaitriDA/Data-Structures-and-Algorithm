/*Copy constructor is a typr of constructor that created a copy of other constructor. Suppose we want to make an object z1 that is exactly similar to z then we make a copy constructor and pass z to it. */

#include<iostream>
using namespace std;

class Number{
    int a;
public:
    Number(){
        cout<<"Default constructor"<<endl;
        a=0;
    }
    Number(int data){
        cout<<"Normal Constructor"<<endl;
        a=data;
    }
    //Copy Constructor
    /*If we comment out the copy constructor part..the program will not give any error..this is because the compiler by default assign a copy constructor to every class.*/
    Number(Number &obj){
        cout<<"Copy constructor"<<endl;
        a=obj.a;
    }

    void display(){
        cout<<"The value of a is: "<<a<<endl;
    }
};

int main(){
    Number x,y,z(45),z2;
    x.display();
    y.display();
    z.display();
    Number z1(z);
    z1.display();
    z2=z;
    Number z3=z;

    return 0;
}