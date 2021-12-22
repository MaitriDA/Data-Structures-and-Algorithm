#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int>s1,s2;
public:
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int size(){
        if(s1.empty()){
            return 0;
        }
        return s1.size();
    }

    int deQueue(){
        if(s1.empty()){
            return -1;
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    void print(){
        stack<int>temp;
        temp=s1;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.size()<<endl;
    q.print();
    cout<<q.deQueue()<<endl;
    cout<<q.size()<<endl;
    q.print();
    return 0;
}