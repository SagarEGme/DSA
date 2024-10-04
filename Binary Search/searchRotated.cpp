// qn: Search Element in a Rotated Sorted Array
// Brute : linear search
// This method will have a complexity of 0(n) so a better approach
// to it will be binary search since it have Complexity of 0(logn).

// if we see search and sorted then always think of binary search.

#include <bits/stdc++.h>
using namespace std;

int findIndex(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[low] <= arr[mid]) // left side sorted
        {
            if (arr[low] <= target && target <= arr[mid])
            {

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else // right side sorted
        {
            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {4, 5, 1, 2, 3};
    int n = arr.size();
    int target = 3;
    int index = findIndex(arr, n, target);
    cout << target << " lies in the index " << index << endl;
    return 0;
}