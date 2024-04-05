#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int solve(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    int answer = INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (coin <= amount)
        {
            int recursionAnswer = coinChange(coins, amount - coin);
            if (recursionAnswer != INT_MAX)
            {
                answer = 1 + recursionAnswer;
            }
        }
        mini = min(mini, answer);
    }
    return mini;
}

int coinChange(vector<int> &coins, int amount)
{
    int answer = solve(coins, amount);
    if (answer == INT_MAX)
    {
        return -2;
    }
    else
    {
        return answer;
    }
}

int main()
{

}