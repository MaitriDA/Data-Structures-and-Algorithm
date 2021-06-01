#include<iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle(){
        cout<<"This is a Vehicle"<<endl;
    }
};

class Plane{
    public:
    Plane(){
        cout<<"This is Plane"<<endl;
    }
};

class TwoWheeler:public Vehicle{
    public:
    TwoWheeler(){
        cout<<"This is Two Wheler"<<endl;
    }
};

class FourWheeler:public Vehicle,public Plane{
    public:
    FourWheeler(){
        cout<<"This is Four Wheeler"<<endl;
    }
};

class Cycle:public TwoWheeler{
    public:
    Cycle(){
        cout<<"This is Cycle"<<endl;
    }
};

class Bike:public TwoWheeler{
    public:
    Bike(){
        cout<<"Thsi is Bike"<<endl;
    }
};


int main(){
    Cycle obj_cycle;
    cout<<"------------"<<endl<<endl;
    Bike obj_bike;
    cout<<"------------"<<endl<<endl;
    FourWheeler obj_four;
    cout<<"------------"<<endl<<endl;
    return 0;
}