#include<iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

int partition (int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	
	for (int j = low; j <= high-1; j++)
		if (arr[j] <= pivot)
			swap (arr[i++], arr[j]);
	swap (arr[i+1], arr[high]);
	
	return (i+1);
}

// Following function implements quickSort recursively
void quickSort1 (int arr[], int low, int high) {
	if (low < high) {
		int partition_index = partition (arr, low, high);
		
		quickSort1 (arr, low, partition_index - 1);
		quickSort1 (arr, partition_index + 1, high);
	}
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting"<<endl;
    printArray(arr,n);
    quickSort1(arr,0,n);
    cout<<"After sorting"<<endl;
    printArray(arr,n);
    return 0;
}