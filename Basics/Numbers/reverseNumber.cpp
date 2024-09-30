#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 432;
    int last,rev=0;

    while (n!=0){
        last = n % 10; // it causes the complexity to be log10 of n // TC-> 0(log10 of n + 1) SC -> 0(1)
        rev = rev * 10 + last;
        n=n/10;
    }
    cout<<rev;

    return 0;
}