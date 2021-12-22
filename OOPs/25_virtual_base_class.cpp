#include<iostream>
using namespace std;

class Student{
protected:
    int roll_no;
public:
    void set_roll_no(int a){
        roll_no=a;
    }
    void print_roll_no(){
        cout<<"Your roll number is "<<roll_no<<endl;
    }
};

class Test:virtual public Student{
protected:
    float maths,phy;
public:
    void set_marks(int m,int p){
        maths=m;
        phy=p;
    }
    void print_marks(){
        cout<<"The marks in Maths is "<<maths<<endl;
        cout<<"The marks in Physics is "<<phy<<endl;
    }
};

class Sport:virtual public Student{
protected:
    char grade;
public:
    void set_grade(char g){
        grade=g;
    }
    void print_grade(){
        cout<<"The grade in sports is "<<grade<<endl;
    }
};

class Result:public Test,public Sport{
private:
    float total;
public:
    void display(){
        print_roll_no();
        print_marks();
        print_grade();
        total=(maths+phy)/2;
        cout<<"The percentage if: "<<total<<endl;
    }
};

int main(){
    Result r;
    r.set_roll_no(5);
    r.set_marks(85,96);
    r.set_grade('A');
    r.display();
    return 0;
}