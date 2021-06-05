#include<iostream>
using namespace std;

class Employee{
    string name;
    static int count;
    int id;
public:
    void setData(void){
        cout<<"Enter the id: ";
        cin>>id;
        cout<<"Enter the name: ";
        cin>>name;
        count++;
    }
    void getData(void){
        cout<<"Id: "<<id<<" Name: "<<name<<endl;
    }

    static void getCount(void){
        cout<<"number of Employee created till now: "<<count<<endl<<endl;
        //Error
        //cout<<id<<endl;
    }
};

//static data member;
//In our program this count variable takes memory only one time and then it keeps on updating.
//It is by default initialized with 0. This is shared by all the object. It is also known as Class Variable because it is not a property of an object instead it's a property of a class.
int Employee::count;


//Static function can access only static data members.
int main(){
    Employee Maitri,Pankti;
    
    Maitri.setData();
    Maitri.getData();
    //Static function
    Employee::getCount();
    //Maitri.getCount();

    Pankti.setData();
    Pankti.getData();
    //Static function
    Employee::getCount();
    //Pankti.getCount();
    return 0;
}