#include<iostream>
using namespace std;

//Base class
class Employee{
public:
    int id;
    string name;
    float salary;
    Employee(int id1,string name1,float salary1){
        id=id1;
        name=name1;
        salary=10000;
    }
    Employee(){}
    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"NAME: "<<name<<endl;
        cout<<"SALARY: "<<salary<<endl;
        cout<<"-------------------"<<endl;
    }
};

//Default visibility mode is private
//Public visibility mode: public membersof the base class becomes public members of the derived class.
//Private visibility mode: public members of the base class becomes private members of the derived class.
//In any case private members of the base class can never become the members of the derived class. or simply it cannot be inherited by the derived class.
//Derived class
class Programmer:Employee{
    public:
    int languageCode=9;
    Programmer(int id1){
        id=id1;
    }
};

int main(){
    Employee e1(78,"Maitri",10000);
    e1.display();
    Programmer p1(45);
    cout<<p1.languageCode<<endl;
    //Error if visibibity mode is private and no error if visibility mode is public
    //cout<<p1.id<<endl;
    return 0;
}