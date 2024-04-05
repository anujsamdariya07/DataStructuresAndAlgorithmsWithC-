#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    // Robbed
    int option1 = nums[index] + solve(nums, size, index + 2);
    // Not Robbed
    int option2 = 0 + solve(nums, size, index + 1);
    int finalAnswer = max(option1, option2);
    return finalAnswer;
}

int rob(vector<int> &nums)
{
    int answer = solve(nums, nums.size(), 0);
    return answer;
}

int main()
{
}