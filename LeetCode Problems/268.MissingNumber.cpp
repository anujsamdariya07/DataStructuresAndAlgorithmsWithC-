#include<iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums) 
{
        int size = nums.size(), sum = 0;
        for(int i = 0 ; i < size ; i++) 
        {
            sum += nums[i];
        }
        int totalSum = (size*(size+1))/2;
        int result = totalSum - sum;
        return result;
}

int main()
{

}