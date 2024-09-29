#include <bits/stdc++.h>
using namespace std;

// Brute Approach
// TC -> 0(n^3 for loops * log(no. of unique triplets)) Not considering sorting because we always do sorting of 3 elements
// which can be considered as having negligible time complexity.
// SC -> 0(2 * no of unique triplets) as we are having set to store ans and list to return value in the list-form named finalAns;
// vector<vector<int>> threeSum(int n, vector<int> arr){
//     set <vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 if((arr[i]+arr[j] + arr[k]) == 0){
//                     vector<int> temp = {arr[i],arr[j],arr[k]};
//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);   // TC of log(no.of unique triplet)
//                 }
//             }
//         }
//     }
//     vector<vector<int>> finalAns(ans.begin(),ans.end());
//     return finalAns;
// }

// int main(){
//     vector<int> arr = {1,2,-3,4,-5};
//     int n=5;
//     vector<vector<int>> ans = threeSum(n,arr);
//     for(auto it:ans){
//         cout<<"[";
//         for(auto i:it){
//             cout<<i<<" ";
//         }
//         cout<<"],";
//     }
//     cout<<"\n";
//     return 0;
// }

// Better Approach
//  We can reduced the TC by 1 n loop by using concept of formula;
// TC -> 0(n^2 + log(no.of unique triplets) for inserting in set) not considering sorting TC
// SC -> 0(2* no. of unique triplet)+0(n)) line no. 51 and 64 + here, +0(n) for inserting n elements in another set.
// vector<vector<int>> threeSum(int n, vector<int> arr)
// {
//     set<vector<int>> ans;

//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashset;
//         for (int j = i + 1; j < n; j++)
//         {
//             int target = -(arr[i] + arr[j]);
//             if(hashset.find(target)!= hashset.end()){
//                 vector<int> temp = { arr[i] , arr[j], target};
//                 sort(temp.begin(),temp.end());
//                 ans.insert(temp);
//             }
//             hashset.insert(arr[j]);
//         }
//     }

//     vector<vector<int>> finalAns(ans.begin(), ans.end());
//     return finalAns;
// }

// int main()
// {
//     vector<int> arr = {1, 2, -3, 4, -5};
//     int n = 5;
//     vector<vector<int>> ans = threeSum(n, arr);
//     for (auto it : ans)
//     {
//         cout << "[";
//         for (auto i : it)
//         {
//             cout << i << " ";
//         }
//         cout << "],";
//     }
//     cout << "\n";
//     return 0;
// }

vector<vector<int>> threeSum(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i],arr[j],arr[k]}; //while copy pasting from line99 be careful whether you have , or + as operator between them.
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 4, -5};
    int n = 5;
    vector<vector<int>> ans = threeSum(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "],";
    }
    cout << "\n";
    return 0;
}