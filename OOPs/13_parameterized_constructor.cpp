#include<iostream>
#include<math.h>
using namespace std;

class Point{
    int a,b;
public:
    Point(int x,int y){
        a=x;
        b=y;
    }
    void displayPoint(){
        cout<<"("<<a<<","<<b<<")"<<endl;
    }
    friend float distance(Point,Point);
};

float distance(Point p,Point q){
    float d=pow((p.a-q.a),2)+pow((p.b-q.b),2);
    d=sqrt(d);
    return d;
}
int main(){
    Point p(1,4);
    p.displayPoint();

    Point q(5,8);
    q.displayPoint();

    cout<<"The distance is: "<<distance(p,q);
    return 0;
}
