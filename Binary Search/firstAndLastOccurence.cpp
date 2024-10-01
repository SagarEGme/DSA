// TC -> 0(logn) SC -> 0(1)

#include <bits/stdc++.h>
using namespace std;
int firstOcc(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (ans != 0) ? ans : -1;
}
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int target = 1;
    cout << "The first occurence is in : " << firstOcc(arr, target);
    return 0;
}

// Kind of same for last occurrence.