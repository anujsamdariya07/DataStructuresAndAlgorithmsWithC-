#include<iostream>
#include<vector>

using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
{
        int size = mat.size();
        int count = 0, index, maxVal;
        for(int i = 0 ; i < size ; i++) 
        {
            count = 0;
            for(int j = 0 ; j < mat[i].size() ; j++) 
            {
                if(mat[i][j] == 1) 
                {
                    count++;
                }
            }
            if(count > maxVal) 
            {
                maxVal = count;
                index = i;
            }
        }
        vector<int> result;
        result.push_back(index);
        result.push_back(maxVal);
        return result;
}

int main()
{

}