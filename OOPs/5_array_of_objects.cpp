#include<iostream>
#include<string>
using namespace std;

class Employee{
    int id;
    string name;
    int salary;
public:
    void setId(void){
        cout<<"Enter the id: ";
        cin>>id;
    }
    void setName(void){
        cout<<"Enter the name: ";
        cin>>name;
    }
    void setSalary(void){
        cout<<"Enter the salary: ";
        cin>>salary;
    }

    void getData(void){
        cout<<"Id: "<<id<<"  Name: "<<name<<"  Salary: "<<salary;
    }
};

int main(){
    int n;
    cout<<"Enter the number of Employee: ";
    cin>>n;

    Employee e[n];
    for(int i=0;i<n;i++){
        cout<<"Employee no: "<<i<<endl;
        e[i].setId();
        e[i].setName();
        e[i].setSalary();
        cout<<endl;
        cout<<"----------------------"<<endl;
    }

    for(int i=0;i<n;i++){
        cout<<"Employee no: "<<i<<endl;
        e[i].getData();
        cout<<endl;
        cout<<"----------------------"<<endl;
    }

    return 0;
}