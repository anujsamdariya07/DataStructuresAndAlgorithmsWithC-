#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> &v)
{
    for(int i = 0 ; i< v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool myComperator1(int a, int b)
{
    return a < b;// Increasing order
}

bool myComperator2(int a, int b)
{
    return a > b;// Decreasing order
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    sort(v.begin(), v.end());
    print(v);
    sort(v.begin(), v.end(), myComperator1);
    print(v);
    sort(v.begin(), v.end(), myComperator2);
    print(v);
}