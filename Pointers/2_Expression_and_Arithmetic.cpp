//Pointer Expression and Arithmetic

#include<iostream>
using namespace std;
int main(){
    int v[5]={10,100,200,500,600};
    int *ptr;
    ptr=v;
    for(int i=0;i<5;i++){
        cout<<"Value of *ptr: "<<*ptr<<endl;
        cout<<"value of ptr: "<<ptr<<endl;
        cout<<"--------------------"<<endl;
        ptr++;
    }

    ptr=v;
    cout<<"Elements of array are: ";
    cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<" "<<ptr[4]<<endl;  
    cout<<"--------------------"<<endl;
    cout<<"Address of elements of array are: ";
    cout<<&ptr[0]<<" "<<&ptr[1]<<" "<<&ptr[2]<<" "<<&ptr[3]<<" "<<&ptr[4]<<endl;  
    return 0;
}

//In similar way 2D array can be implemented.