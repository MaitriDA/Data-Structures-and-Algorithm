#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class NodeDetails{
public:
    int data;
    int min,max;
};

bool array_is_levelOrder(int arr[],int n){
    if(n==0){
        return true;
    }
    queue<NodeDetails>q;
    int i=0;
    NodeDetails newNode;
    newNode.data=arr[i++];
    newNode.min=INT_MIN;
    newNode.max=INT_MAX;
    q.push(newNode);
    while(i!=n && !q.empty()){
        NodeDetails temp=q.front();
        q.pop();
        if(i!=n && (arr[i]<temp.data && arr[i]>temp.min)){
            //cout<<temp.data<<" inside minimum"<<endl;
            newNode.data=arr[i++];
            newNode.min=temp.min;
            newNode.max=temp.data;
            q.push(newNode);
        }
        if(i!=n && (arr[i]>temp.data && arr[i]<temp.max)){
            //cout<<temp.data<<" inside maximum"<<endl;
            newNode.data=arr[i++];
            newNode.min=temp.data;
            newNode.max=temp.max;
            q.push(newNode);
        }
    }
        if(i==n){
            return true;
        }
        return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(array_is_levelOrder(arr,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}