// Brute Force
#include <bits/stdc++.h>
using namespace std;

// int missingElem(vector<int> arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int flag = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == i+1)
//             {
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//             return i+1;
//     }
//     return -1;
// }

// Better Approach -> Use Hashing Algorith
// int hashing(vector<int> arr,int n){

//     int hash[n+1] ={0};
//     for(int i=0;i<n-1;i++){ // remember why n-1 because n = 5 but we only have to travel from 0 to 3.
//         hash[arr[i]]++;
//     }
//     for(int i =1;i<=n;i++){
//         if(hash[i]==0) return i;
//     }
//     return -1;
// }

// Optimal 1 : using formula
// int formula(vector<int> arr,int n){
//     int s1 = (n* (n+1))/2;
//     int s2=0;
//     for(int i = 0;i<n-1;i++) s2+=arr[i];
//     int missing = s1-s2;
//     return missing;
// }

// optimal 2 : xor
int xoor(vector<int> arr, int n)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor1 = xor1 ^ arr[i];  // xor of array elements
        xor2 = xor2 ^ (i + 1); // xor upto N
    }
    xor2 ^= n;
    return xor1 ^ xor2;
}

int main()
{
    vector<int> arr = {1, 3, 4, 5};
    int N = 5;
    // int missing = missingElem(arr,arr.size());
    int missing = xoor(arr, N);
    cout << missing;

    return 0;
}