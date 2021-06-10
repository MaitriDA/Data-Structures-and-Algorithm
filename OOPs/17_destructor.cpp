//It frees the memory taken by the destructor
//It never takes any argument and also don't return any value.
#include<iostream>
using namespace std;
int count=0;

class Number{
public:
    Number(){
        count++;
        cout<<"This is the time when constructor is called "<<count<<endl;
    }
    ~Number(){
        cout<<"Objec is destroyed "<<count<<endl;
        count--;
    }
};

int main(){
    cout<<"We are inside the main function"<<endl<<endl;
    Number n1;
    {
        cout<<"Entering this block"<<endl;
        cout<<"Creting two more objects"<<endl;
        Number n2,n3;
        cout<<"Exiting this block"<<endl;
    }
    cout<<"Back to main"<<endl;
    return 0;
}