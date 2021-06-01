#include<iostream>
using namespace std;
int main(){
    int a=10;
    int b=8;
    int or_opr=a|b;
    int and_opr=a&b;
    int xor_opr=a^b;
    int com_opr=~a;
    int left_opr=a<<b;
    int right_opr=a>>b;

    cout<<"OR: "<<or_opr<<endl;
    cout<<"AND: "<<and_opr<<endl;
    cout<<"XOR: "<<xor_opr<<endl;
    cout<<"COMPLIMENT of a: "<<com_opr<<endl;
    cout<<"LEFT SHIFT: "<<left_opr<<endl;
    cout<<"RIGHT SHIFT: "<<right_opr<<endl;
    return 0;
}