#include<iostream>
using namespace std;

class Parent{
    public:
    int id_p=191;
};

class Child:public Parent{
    public:
    int id_c=265;
};

int main(){
    Child obj1;
    cout<<"Parent id: "<<obj1.id_p<<endl;
    cout<<"Child id: "<<obj1.id_c<<endl;
    return 0;
}