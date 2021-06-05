#include<iostream>
#include<string>
using namespace std;

class Binary{
private:
    string s;
    void check_binary(void);
public:
    void read(void);
    void ones_complement(void);
    void display(void);
};

void Binary::read(void){
    cout<<"Enter a binary number: ";
    cin>>s;
}

void Binary::check_binary(void){
    for(int i=0;i<s.length();i++){
        if(s.at(i)!='0' && s.at(i)!='1'){
            cout<<"Incorrect binary format"<<endl;
            exit(0);
        }
    }
    cout<<"Correct Binary Format"<<endl;
}

void Binary::ones_complement(void){
    check_binary();
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='0'){
            s.at(i)='1';
        }
        else if(s.at(i)=='1'){
            s.at(i)='0';
        }
    }
}

void Binary::display(void){
    for(int i=0;i<s.length();i++){
        cout<<s.at(i);
    }
}
int main(){
    Binary b;
    b.read();

    //Error
    //b.check_binary();
    b.ones_complement();
    cout<<"Ones Complement: ";
    b.display();
    return 0;
}