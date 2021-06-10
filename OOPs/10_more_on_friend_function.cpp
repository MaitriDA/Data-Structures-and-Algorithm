//Swapping the private data of c1 and c2 class using an external friend function.

#include<iostream>
using namespace std;

class c2;

class c1{
    int val1;
public:
    void setData(int a){
        val1=a;
    }
    void display(void){
        cout<<val1<<endl;
    }
    friend void swap(c1 &x,c2 &y);
};

class c2{
    int val2;
public:
    void setData(int a){
        val2=a;
    }
    void display(void){
        cout<<val2<<endl;
    }
    friend void swap(c1 &x,c2 &y);
};

void swap(c1 &x,c2 &y){
    int temp=x.val1;
    x.val1=y.val2;
    y.val2=temp;
}
int main(){
    c1 o1;
    c2 o2;
    o1.setData(3);
    o2.setData(5);
    cout<<"Before Swapping: "<<endl;
    cout<<"c1: ";
    o1.display();
    cout<<"c2: ";
    o2.display();

    swap(o1,o2);
    cout<<"After Swapping: "<<endl;
    cout<<"c1: ";
    o1.display();
    cout<<"c2: ";
    o2.display();
    return 0;
}