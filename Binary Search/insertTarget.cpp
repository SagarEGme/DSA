
#include <bits/stdc++.h>
using namespace std;

int insertTarget(vector<int> &arr, int target, int low, int high)
{
    int ans=high+1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=target){
            ans = mid;
            high = mid-1;
        } else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 20;
    int final = insertTarget(arr, x, 0, n - 1);
    cout << "The target is in the index:" << final << " \n";
    // for (int i = 0; i < final.size(); i++)
    // {
    //     cout << final[i] << " ";
    // }
    return 0;
}
