#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach TC -> 0(nlogn for inserting)+0(n for putting the unique values back in original arr array.) SC-> 0(n) for set.
void remDup(vector<int> arr)
{
    set<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans.insert(arr[i]);
    }
    int j=0;
    for(int x:ans){
        arr[j++] = x;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << arr[i] << ' ';
    }
}

// Optimal Approach TC -> 0(n);

// void remDup2(vector<int> arr)
// {
//     int i = 0;
//     for (int j = 0; j < arr.size(); j++)
//     {
//         if (arr[i] != arr[j])
//         {
//             arr[i + 1] = arr[j];
//             i++;
//         }
//     }
//     cout << i + 1;
//     for (int k = 0; k < i; k++)
//     {
//         cout << arr[k] << " ";
//     }
// }
int main()
{
    vector<int> arr = {1, 1, 1, 2, 3, 3, 4, 4, 4, 5};
    remDup(arr);
    

    return 0;
}