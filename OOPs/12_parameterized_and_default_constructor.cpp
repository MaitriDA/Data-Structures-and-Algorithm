#include<iostream>
using namespace std;

class Complex{
    int a,b;
public:

    //Parameterized Constructor
    Complex(int,int);
    void printNumber(){
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};
Complex::Complex(int x,int y){
    a=x;
    b=y;
}

int main(){
    int x,y;
    cout<<"Enter the real and Imaginary part: ";
    cin>>x>>y;
    //Implicit Call
    cout<<"Implicit call: ";
    Complex c(x,y);
    c.printNumber();

    //Explicit Call
    cout<<"Explicit call: ";
    Complex c1=Complex(x,y);
    c1.printNumber();
    return 0;
}