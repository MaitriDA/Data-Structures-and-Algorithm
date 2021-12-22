#include<iostream>
using namespace std;

class Student{
protected:
    int rollNo;
public:
    void set_rollNo(int);
    void get_rollNo(void);
};

void Student::set_rollNo(int r){
    rollNo=r;
}

void Student::get_rollNo(){
    cout<<"Roll number from Student class: "<<rollNo<<endl;
}

class Exam:public Student{
protected:
    float maths;
    float physics;
public:
    void set_marks(float,float);
    void get_marks(void);
};

void Exam::set_marks(float m,float p){
    maths=m;
    physics=p;
}

void Exam::get_marks(){
    cout<<"Roll number from Exam class: "<<rollNo<<endl;
    cout<<"Maths from Exam class: "<<maths<<endl;
    cout<<"Physics from Exam class: "<<physics<<endl;
}

class Result:public Exam{
    float per;
public:
    void display(){
        get_rollNo();
        get_marks();
        per=(maths+physics)/2;
        cout<<"Precentage is: "<<per<<endl;
    }
};

int main(){
    cout<<"Case 1"<<endl;
    Student s;
    s.set_rollNo(8);
    s.get_rollNo();

    Exam e;
    e.set_marks(95,75);
    e.get_marks();

    Result r;
    r.display();
    cout<<"---------------"<<endl<<endl;

    cout<<"Case 2"<<endl;

    Exam e2;
    e2.set_rollNo(8);
    e2.set_marks(95,75);
    e2.get_rollNo();
    e2.get_marks();

    Result r2;
    r2.display();

    cout<<"---------------"<<endl<<endl;

    cout<<"Case 3"<<endl;
    Result r3;
    r3.set_rollNo(8);
    r3.set_marks(96,85);
    r3.display();
    return 0;
}