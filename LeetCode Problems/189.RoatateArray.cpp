#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k) 
{
    int size = nums.size();
    vector<int> answer(size);
    for(int i = 0 ; i < size ; i++) 
    {
        answer[(i+k) % size] = nums[i];
    }
    for(int i = 0 ; i < size ; i++) 
    {
        nums[i] = answer[i];
    }
}

int main()
{

}