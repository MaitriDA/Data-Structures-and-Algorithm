#include<iostream>
using namespace std;
class myBio{
    public:
    int id;
    ~myBio(){
        cout<<"Destructor called and id is: "<<id<<endl;
    }
};
int main(){
    myBio obj1;
    obj1.id=191091006;
    int i=0;
    cout<<obj1.id<<endl<<endl;
    while(i<5){
        myBio obj2;
        obj2.id=i;
        i++;
    }
    return 0;
}