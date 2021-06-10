#include<iostream>
using namespace std;

//Forward Declartion
class Complex;

class Calculate{
public:
    int add(int a,int b){
        return (a+b);
    }
    int addRealComplex(Complex,Complex);
    int addImgComplex(Complex,Complex);
};

class Complex{
    int a,b;

    //Friend Functions
    //friend int Calculate ::addRealComplex(Complex,Complex);
    //friend int Calculate ::addImgComplex(Complex,Complex);

    //friend class
    friend class Calculate;
public:
    void setNumber(int n1,int n2){
        a=n1;
        b=n2;
    }
    void printNumber(){
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};

int Calculate :: addRealComplex(Complex o1,Complex o2){
    return (o1.a+o2.a);
}

int Calculate :: addImgComplex(Complex o1,Complex o2){
    return (o1.b+o2.b);
}

int main(){
    Complex o1,o2;
    o1.setNumber(1,4);
    o1.printNumber();
    o2.setNumber(3,5);
    o2.printNumber();
    Calculate calc;
    int real=calc.addRealComplex(o1,o2);
    int img=calc.addImgComplex(o1,o2);
    cout<<"Addition: "<<real<<" + "<<img<<"i"<<endl;
    return 0;
}