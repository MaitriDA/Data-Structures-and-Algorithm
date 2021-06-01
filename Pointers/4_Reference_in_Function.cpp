#include<iostream>
using namespace std;
//pass By value
void pass_by_value(int a,int b){
    cout<<"inside pass_by_value function"<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address of b: "<<&b<<endl;
    int temp=a;
    a=b;
    b=temp;
    cout<<"---------------------"<<endl;
}

//pass By reference
void pass_by_reference(int &a,int &b){
    cout<<"inside pass_by_reference function"<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address of b: "<<&b<<endl;
    int temp=a;
    a=b;
    b=temp;
    cout<<"---------------------"<<endl;
}

int main(){
    int a=2,b=3;
    cout<<endl;
    cout<<"Inside Main"<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address of b: "<<&b<<endl;
    cout<<endl;
    cout<<"Before Swapping"<<endl;
    cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
    cout<<"---------------------"<<endl;
    cout<<"After Swapping"<<endl<<endl;
    pass_by_value(a,b);
    cout<<"Pass By Value: "<<endl;
    cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
    cout<<"---------------------"<<endl;
    pass_by_reference(a,b);
    cout<<"Pass By Reference: "<<endl;
    cout<<"a: "<<a<<" "<<"b: "<<b<<endl;
    return 0;
}