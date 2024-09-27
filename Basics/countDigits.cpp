#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 50123;
    int count = int(log10(n) + 1);
    // while(n!=0){         // brute force TC -> 0(log10n + 1 ) 1 is when the number is exact 10 power stg eg 100, log10of 100 gives 2 but its exact count should be 3 . so use + 1
    //     n = n /10;           SC -> 0(1)
    //     count++;
    // }

    
    cout<<count;
}