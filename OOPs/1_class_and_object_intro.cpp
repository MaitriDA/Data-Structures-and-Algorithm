#include<iostream>
using namespace std;
class Name{

    public:
    string name="Maitri Amin";

    void printName(){
        cout<<"The name is: "<<name;
    }
};

int main(){
    Name obj;
    cout<<obj.name<<endl;
    obj.printName();
    cout<<endl;
    cout<<"------------------------------"<<endl;
    obj.name="Pankti Amin";
    cout<<obj.name<<endl;
    obj.printName();
    return 0;
}
