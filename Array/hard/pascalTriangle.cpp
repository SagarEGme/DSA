#include <bits/stdc++.h>
using namespace std;

// 1. Find the element at position (n,r ) of pascal's triangle;
// brute force approach : TC -> 0(n) + 0(r) + 0(n-r) because we had to find factorial of n, r, and n-r .
// optimal approach : TC -> 0(column) SC -> 0(1);
// int ncr(int a, int b)
// {
//     long long res = 1;
//     for (int i = 0; i < b; i++)
//     {
//         res = res * (a - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int main()
// {
//     int row = 4, column = 1;
//     int result = ncr(row - 1, column - 1);
//     cout << result;

//     return 0;
// }

// 2. Print the nth row of pascal's triangle.
// TC -> 0(n*r) where n is the no of rows and r is the no of columns.
// SC -> 0(1)
// int ncr(int a, int b)
// {
//     long long res = 1;

//     for (int i = 0; i < b; i++)
//     {
//         res = res * (a - i);
//         res = res / (i + 1);
//     }

//     return res;
// }

// int main()
// {
//     int row = 4;
//     for (int j = 1; j <= row; j++)
//     {
//         int result = ncr(row-1,j-1); // the formula is ncr(row-1,column-1) though the row and column both starts with 1and1;
//         cout << result<<" ";
//     }

//     return 0;
// }

// optimal method : TC -> 0(n)
// void ncr(int n)
// {
//     long long res = 1;
//     cout<<res<<" ";

//     for(int i=1;i<n;i++){
//         res = res * (n-i);
//         res = res / i;
//         cout<<res<<" ";
//     }

// }

// int main()
// {
//     int row = 4;
//     ncr(row);

//     return 0;
// }

// variant 3 -> To print the pascals triangle upto N rows
// Brute approach (using combination of above 2 methods)

// void ncr(int n, int r)
// {
//     long long res = 1;
//     for (int i = 0; i < r; i++)
//     {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     cout<< res;
// }

// int main()
// {
//     int row = 5;
//     // vector<int> tempList;
//     for (int i = 1; i <= row; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {

//             ncr(i - 1, j - 1);
//         }
//         cout<<"\n";
//     }
//     return 0;
// }

// Optimal approach;
// TC -> 0(n^2) n is row SC -> 0(1)
void ncr(int n)
{
    long long res = 1;
    cout << res << " ";
    for (int i = 1; i < n; i++)  //be careful why not i<=n 
    {
        res = res * (n - i);
        res = res / i;
        cout << res << " ";
    }
}

int main()
{
    int row = 5;
    // vector<int> tempList;
    for (int i = 1; i <= row; i++)
    {
        ncr(i);
        cout << "\n";
    }
    return 0;
}