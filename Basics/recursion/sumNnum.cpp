#include <bits/stdc++.h>
using namespace std;

//functional way
// int findSum(int n){
//     if(n==0) return 0;
//     return (n + findSum(n-1));
// }
//parameterized way
int findSum(int i,int sum){
    if (i<1){
        cout<<sum<<endl;
        return 0;
    }
    return findSum(i-1,sum+i);
    
}

int main()
{
    int n = 5;
    // int sum = findSum(n);
    findSum(n,0);
    return 0;
}