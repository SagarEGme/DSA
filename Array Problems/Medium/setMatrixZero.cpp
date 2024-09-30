#include <bits/stdc++.h>
using namespace std;

// TC -> 0((n^m) * (n+m)) + 0(n*m) n-> rows and m-> columns
// SC -> 0(1)
// void markRow(vector<vector<int>> &matrix, int n, int m, int i)
// {
//     // set all non-zero elements as -1 in the row i:

//     for (int j = 0; j < m; j++)
//     {
//         if (matrix[i][j] != 0)
//             matrix[i][j] = -1;
//     }
// }
// void markCol(vector<vector<int>> &matrix, int n, int m, int j)
// {
//     // set all non-zero elements as -1 in the col j:

//     for (int i = 0; i < n; i++)
//     {
//         if (matrix[i][j] != 0)
//             matrix[i][j] = -1;
//     }
// }

// vector<vector<int>> setMatZero(vector<vector<int>> &matrix, int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == -1)
//                 matrix[i][j] = 0;
//         }
//     }
//     return matrix;
// }

// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 3}, {2, 0, 4}};
//     int row = matrix.size();
//     int col = matrix[0].size();
//     vector<vector<int>> result = setMatZero(matrix, row, col);
//     cout<<"The final matrix is : \n";
//     for(auto it:result){
//         cout<<"[";
//         for(auto i:it){
//             cout<<i<<" ";
//         }
//         cout<<"], \n";
//     }
//     return 0;
// }

// ..............Better Appproach ...............

// TC -> 0(2* n*m)
// SC -> 0(n) + 0(m);

// vector<vector<int>> setMatZero(vector<vector<int>> &matrix, int n, int m)
// {
//     int row[n] = {0};
//     int col[m] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (row[i] == 1 || col[j] == 1)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     return matrix;
// }
// int main()
// {
//     vector<vector<int>> matrix = {{1, 2, 3}, {2, 0, 4}};
//     int row = matrix.size();
//     int col = matrix[0].size();
//     vector<vector<int>> result = setMatZero(matrix, row, col);
//     cout << "The final matrix is : \n";
//     for (auto it : result)
//     {
//         cout << "[";
//         for (auto i : it)
//         {
//             cout << i << " ";
//         }
//         cout << "], \n";
//     }
//     return 0;
// }

// Optimal Approach
// TC -> 0(2*n*m) approx to 0(n^2) which is the best scenerio as we are traversing through 2 loops;
// SC -> 0(1) we aren't using any extra space
vector<vector<int>> setMatZero(vector<vector<int>> &matrix, int n, int m)
{
    matrix[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                }
                else{
                matrix[0][0]=0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][0] == 0 || matrix[0][j]==0){
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {2, 0, 4}};
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result = setMatZero(matrix, row, col);
    cout << "The final matrix is : \n";
    for (auto it : result)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "], \n";
    }
    return 0;
}