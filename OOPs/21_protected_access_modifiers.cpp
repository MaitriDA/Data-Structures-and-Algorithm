#include<iostream>
using namespace std;

//Protected is a private member that can be inherited
class Base{
protected:
    int a;
private:
    int b;
};

/*
                    Public Derivation   Private Derivation  Protected Derivation

    1) Private:     Not inherited       Not inherited       Not inherited
    2) Protected:   Protected           Private             Protected
    3) Public:      Public              Private             Protected

*/
class Derived:protected Base{
    int a;
};

int main(){
    Base b;
    Derived d;
    //Error
    //cout<<b.a;
    //cout<<d.a;
    return 0;
}
