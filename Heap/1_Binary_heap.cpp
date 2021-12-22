#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>v;
    bool minHeap;
    bool compare(int a,int b){
        if(minHeap){
            return a<b;
        }
        else{
            a>b;
        }
    }
    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int min_i=i;
        int last=v.size()-1;
        if(left<=last and compare(v[left],v[i])){
            min_i=left;
        }
        if(right<=last and compare(v[right],v[min_i])){
            min_i=right;
        }
        if(min_i!=i){
            swap(v[min_i],v[i]);
            heapify(min_i);
        }
    }
public:
    Heap(int default_size=10,bool type=true){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap=type;
    }
    void push(int d){
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
};

int main(){
    Heap h(10,true);
    h.push(5);
    h.push(8);
    h.push(45);
    h.push(7);
    h.push(1);
    cout<<h.top();
    h.pop();
    cout<<h.top();
    return 0;
}