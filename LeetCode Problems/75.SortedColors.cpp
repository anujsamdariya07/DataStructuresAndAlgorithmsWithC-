#include<iostream>
#include<vector>

using namespace std;

void sortedColors(vector<int>& nums)
{
    int size = nums.size();
    int left = 0, right = size - 1;
    int index = 0;
    while (index <= right)
    {
        if (nums[index] == 0)
        {
            swap(nums[left], nums[index]);
            index++, left++;
        }
        else if (nums[index] == 2)
        {
            swap(nums[right], nums[index]);
            right--;
        }
        else
        {
            index++;
        }
    }
}

int main()
{
    
}