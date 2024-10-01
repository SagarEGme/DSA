#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMat(vector<vector<int>> matrix, int n, int m)
{
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {

            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }

            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[left][i]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};

    vector<int> ans = spiralMat(matrix, matrix.size(), matrix[0].size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << ",";
    }

    return 0;
}