#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) 
{
        int size = matrix.size();
        // Taking the transpose of the matrix
        for(int i = 0 ; i < size ; i++) 
        {
            for(int j = i ; j < size ; j++) 
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reversing the matrix
        for(int i = 0 ; i < size ; i++) 
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

int main()
{

}