#include <iostream>
using namespace std;
int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0){
            return -1;
        }
        if(arr[0]>=n){
            return 1;
        }
        int pointer=0;
        int jump=0;
        int n_pointer=0;
        for(int i=1;i<n;i++){
            //cout<<pointer<<" "<<arr[pointer]<<endl;
            int max=0;
            int index=0;
            while(i<=pointer+arr[pointer]){
                if(arr[i]>max){
                    max=arr[i];
                    index=i;
                }
                //cout<<arr[i]<<" "<<index<<endl;
                i++;
            }
            pointer=index;
            if(arr[pointer]==0){
                return -1;
            }
            jump++;
        }
        if(jump==1){
            return -1;
        }
        return jump;
    }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minJumps(arr, n);
    return 0;
}