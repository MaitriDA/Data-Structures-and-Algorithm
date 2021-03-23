#include<iostream>
#include<string>
using namespace std;
void replace_pi(char s[],int i,int l){
    if(s[i]=='\0'){
        return;
    }
    if(s[i]=='p' and s[i+1]=='i'){
        //Rotate
        int j=l+4;
        while(j>=i+2){
            s[j+2]=s[j];
            j--;
        }
        s[i]='3';
        s[i+1]='.';
        s[i+2]='1';
        s[i+3]='4';
        replace_pi(s,i+4,l);
    }
    else{
        replace_pi(s,i+1,l);
    }
    return;
}
int main(){
    char s[1000];
    cin>>s;
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    replace_pi(s,0,i);
    i=0;
    while(s[i]!='\0'){
        cout<<s[i];
        i++;
    }
    return 0;
}