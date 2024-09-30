#include <bits/stdc++.h>
using namespace std;

// brute force approach TC -> 0(minimum of two numbers) SC -> 0(1)
// int main()
// {
//     int a = 22, b = 44, gcd;
//     if (a > b)
//         swap(a, b);
//     for (int i = 2; i <= a; i++)
//     {
//         if (a % i == 0 & b % i == 0)
//         {
//             gcd = i;
//         }
//     }
//     cout << gcd << (a*b)/gcd;
//     return 0;
// }

int checkHcf(int a, int b)
{
    if (a == 0 || b == 0)
        return (a == 0) ? b : a;
    else if (a == b)
        return a;
    if (a > b)
    {
       return checkHcf(a - b, b);
    }
    else
        return checkHcf(a, b - a);
};

int main()
{
    int n1 = 10, n2 = 14;
    int gcd = checkHcf(n1, n2);
    cout << gcd;
    return 0;
}