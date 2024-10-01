// The lower bound algorithm finds the first or the smallest
// index in a sorted array where the value at that index is
// greater than or equal to a given key i.e. x.

// Brute Approach -> Linear Search -> 0(n) TC ;

// Optimal Approach -> Binary Search -> 0(log base2of n) TC 


#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}


