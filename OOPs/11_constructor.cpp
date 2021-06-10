//Conatructor is a special member function with same name as class.It is used to initialise the objects of the class. It is automatically invoked(called) when the object is created.
#include<iostream>
using namespace std;

class Complex{
    int a,b;
public:
    //Creating a constructor
    Complex(void){
        a=7;
        b=6;
    }
    void printComplex(void){
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};

int main(){
    Complex c;
    c.printComplex();
    return 0;
}

/*Properties of CONSTRUCTOR
1: A constructor that does not takes any paramter is known as default constructor.
2: It should always be declared in the public section.
3: It is automatically invoked when an object is created. So no need to call the constructor in the main function.
4: It do not have return types.
5: It can have default arguments.
6: We cannot refer to their address.*/