#include<iostream>
using namespace std;

class myBio{
    public:
    string name="Maitri Amin";
    int id=191091006;

    myBio(){
        cout<<"Defalut constructor is called"<<endl;
        cout<<"Name is: "<<name<<endl;
        cout<<"Id id: "<<id<<endl;
        cout<<"-----------------------";
        cout<<endl;
    }
    myBio(int x){
        cout<<"Parameterized constructor is called"<<endl;
        cout<<"Name is: "<<name<<endl;
        cout<<"Id id: "<<x<<endl;
        cout<<"-----------------------";
        cout<<endl;
    }
};

int main(){
    myBio obj1;
    myBio obj2(6);
    return 0;
}