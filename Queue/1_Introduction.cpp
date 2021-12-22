#include<iostream>
#include<queue>
using namespace std;
void show(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<",";
        q.pop();
    }
    cout<<endl;
    return;
}
int main(){
    queue<int>q;
    for(int i=0;i<5;i++){
        q.push(i);
    }
    show(q);
    cout<<"The size is: "<<q.size()<<endl;
    cout<<"The front element is: "<<q.front()<<endl;
    cout<<"The end element is: "<<q.back()<<endl;
    q.pop();
    show(q);
    return 0;
}
