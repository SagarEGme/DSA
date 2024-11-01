#include<bits/stdc++.h>

using namespace std;

void dec2bin(int n){
    int rem,bin=0;
    while(n>0){
        rem = n % 2;
        bin = bin * 10 + rem;
        n/=2;
    }
    cout<<"the binary representation is:"<<bin;
}

void bin2dec(int bin){
    int n,sum=0,pwr=0;
    while(bin>0){
        n = bin % 10;
        sum = sum + pow(2,pwr) * n;
        pwr+=1;
        bin = bin / 10;
    }
    cout<<"the decimal representation is:"<<sum;
}

int main(){
    int n;
    cout<<"enter number";
    cin>>n;
    // dec2bin(n);
    bin2dec(n);
    return 0;
}