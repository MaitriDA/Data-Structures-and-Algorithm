#include<iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle(){
        cout<<"This is a Vehicle"<<endl;
    }
};

class TwoWheeler:public Vehicle{
    public:
    TwoWheeler(){
        cout<<"This is Two Wheler"<<endl;
    }
};

class FourWheeler:public Vehicle{
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

class Truck:public FourWheeler{
    public:
    Truck(){
        cout<<"This is Truck"<<endl;
    }
};

class Car:public FourWheeler{
    public:
    Car(){
        cout<<"This is Car"<<endl;
    }
};

int main(){
    Cycle obj_cycle;
    cout<<"------------"<<endl<<endl;
    Bike obj_bike;
    cout<<"------------"<<endl<<endl;
    Truck obj_truck;
    cout<<"------------"<<endl<<endl;
    Car obj_car;
    cout<<"------------"<<endl<<endl;
    return 0;
}