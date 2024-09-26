#include <bits/stdc++.h>
using namespace std;

// variant 1 return true or false only

// bool checkSum(int n, vector<int> arr,int target){
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i] + arr[j] == target)
//                 return true;
//         }
//     }
//     return false;
// }

// int main(){
//     vector<int> arr = {1,2,3,4,5};
//     int n = arr.size();
//     int target = 8;
//     bool ans = checkSum(n,arr,target);
//     if(ans) cout<<"There are two numbers such that sum is equal to "<<target<<endl;
//     if(!ans) cout<<"There are no two numbers such that sum is equal to "<<target<<endl;
//     return 0;
// }

// variant 2 return indices of numbers

//  vector<int> checkIndices(int n, vector<int> arr,int target){
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i] + arr[j] == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 // ans.push_back(arr[i]);  to return numbers
//                 // ans.push_back(arr[j]);
//                 return ans;
//             }

//         }
//     }
//     return {-1,-1};
// }

// int main(){
//     vector<int> arr = {1,2,3,4,5};
//     int n = arr.size();
//     int target = 8;
//     vector<int> ans = checkIndices(n,arr,target);
//     cout<<"the indices of two numbers are [" <<ans[0]<<","<<ans[1]<<"]";
//     return 0;
// }

// TC -> 0(n2) SC -> 0(1)

// BETTER APPROACH

// bool checkSum(int n, vector<int> arr, int target)
// {
//     unordered_map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         int num = arr[i];
//         int more = target - num;
//         if (mpp.find(more) != mpp.end()) [[[for variant 2 : return {mpp[more],i}]]]
//             return true;
//         mpp[num] = i;
//     }
//     return false;
// }

// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 8;
//     bool ans = checkSum(n, arr, target);
//     if (ans)
//         cout << "There are two numbers such that sum is equal to " << target << endl;
//     if (!ans)
//         cout << "There are no two numbers such that sum is equal to " << target << endl;

//     return 0;
// }

// TC -> 0(n) SC -> 0(n) because we used a map data structure.

// Optimal Solution
// string twoSum(int n, vector<int> &arr, int target)
// {
//     sort(arr.begin(), arr.end());
//     int left = 0, right = n - 1;
//     while (left < right)
//     {
//         if ((arr[left] + arr[right]) == target)
//             return "yes";
//         else if ((arr[left] + arr[right]) < target)
//             left++;
//         else
//             right--;
//     }
//     return "no";
// }

// int main()
// {
//     int n = 5;
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int target = 14;
//     string ans = twoSum(n, arr, target);
//     cout << "This is the answer for variant 1: " << ans << endl;
//     return 0;
// }

vector<int> twoSum(int n, vector<int> &arr, int target)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        if ((arr[left] + arr[right]) == target)
        {
            ans.push_back(left);
            ans.push_back(right);
            return ans; // return indices of sorted array.
        }
        else if ((arr[left] + arr[right]) < target)
            left++;
        else
            right--;
    }
    return {-1,-1};
}

int main()
{
    int n = 5;
    vector<int> arr = {21, 6, 5, 8, 11};
    int target = 13;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans[0]<<ans[1] << endl;
    return 0;
}

// TC -> 0(n) for looping and 0(nlogn) for sorting
// SC -> 0(1) as we arent using any extra space but 0(n) if we consider original array as it is distorted.