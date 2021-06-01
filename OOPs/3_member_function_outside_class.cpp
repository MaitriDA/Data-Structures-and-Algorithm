#include<iostream>
using namespace std;

class myBio{
    public:
    string name="Maitri Amin";
    int id=191091006;

    void print();
};
void myBio::print(){
    cout<<"Name is: "<<name;
    cout<<endl;
    cout<<"Id id: "<<id;
    cout<<endl;
    cout<<"------------------------";
}
int main(){
    myBio maitri;
    maitri.print();
    return 0;
}