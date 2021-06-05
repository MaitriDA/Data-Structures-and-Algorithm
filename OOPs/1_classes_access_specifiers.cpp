#include<iostream>
using namespace std;

class Employee{
private:
    int a,b,c;
public:
    int d,e;

    //Function Declaration
    void setData(int a,int b,int c);

    //Function Declaration with Defination
    //Function declaration inside the class.
    void getData(){
        cout<<"The value of a: "<<a<<endl;
        cout<<"The value of b: "<<b<<endl;
        cout<<"The value of c: "<<c<<endl;
        cout<<"The value of d: "<<d<<endl;
        cout<<"The value of e: "<<e<<endl;
    }
};

//Function defination outside the class.
void Employee::setData(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;
}
int main(){
    Employee Maitri;
    Maitri.setData(1,2,3);

    //We can assign the value of d and e in the main function because they are public variables.
    Maitri.d=45;
    Maitri.e=48;

    //It is not possible to assign value to a,b,c in the main function becuase they are private data types. So the value is assigned throught the function of the calss.

    //Error
    /*Maitri.a=15;
    Maitri.b=17;
    Maitri.c=85;*/

    Maitri.getData();

    //Error
    //cout<<Maitri.a<<" ";

    //No Error
    //cout<<Maitri.d<<" ";
    return 0;
}