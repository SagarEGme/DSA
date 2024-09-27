#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4334;
    int last,rev=0;
    int temp = n;

    while (n!=0){
        last = n % 10; // it causes the complexity to be log10 of n // TC-> 0(log10 of n + 1) SC -> 0(1)
        rev = rev * 10 + last;
        n=n/10;
    }
   (rev == temp)? cout<<"Pallindrome.": cout<<"No";

    return 0;
}