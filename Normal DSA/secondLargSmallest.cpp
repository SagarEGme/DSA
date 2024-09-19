#include<bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[],int n){
    if(n<2) return -1;
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            secondSmallest = smallest;
            smallest = arr[i];
        }
        if(arr[i]<secondSmallest && arr[i]!=smallest){
            secondSmallest= arr[i];
        }
    }
    return secondSmallest;
}
int secondLargest(int arr[],int n){
    if(n<2) return -1;
    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest= arr[i];
        }
    }
    return secondLargest;
} 
//hello


int main(){
    int arr[] = {3,2,42,32,55,333};
    int n=6;
    int ss = secondSmallest(arr,n);
    int sl = secondLargest(arr,n);
    cout<<"The second smallest is "<<ss<<endl;
    cout<<"The second largest is "<<sl<<endl;
    return 0;
}