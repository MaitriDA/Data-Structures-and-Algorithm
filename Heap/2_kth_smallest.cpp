#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>v;
public:
    Heap(){
        v.push_back(-1);
    }
    void push(int d){
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and v[idx]<v[parent]){
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    int top(){
        return v[1];
    }
    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int min_i=i;
        int last=v.size()-1;
        if(left<=last and v[left]<v[i]){
            min_i=left;
        }
        if(right<=last and v[right]<v[min_i]){
            min_i=right;
        }
        if(min_i!=i){
            swap(v[i],v[min_i]);
            heapify(min_i);
        }
    }
    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
    void kthSmallest(int k){
        while(k--){
            pop();
        }
    }
};

int main(){
    Heap h;
    h.push(1);
    h.push(8);
    h.push(0);
    h.push(5);
    h.push(7);
    h.push(23);
    int k;
    cin>>k;
    k=k-1;
    h.kthSmallest(k);
    cout<<h.top();
    return 0;
}