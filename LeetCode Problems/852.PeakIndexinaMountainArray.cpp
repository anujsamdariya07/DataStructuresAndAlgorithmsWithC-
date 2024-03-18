#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// Method 1
int peakIndexInMountainArray1(vector<int>& arr) 
{
    int size = arr.size();
    int maxVal = INT_MIN;
    int answer;
    for(int i = 0 ; i < size ; i++) 
    {
        if(arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
    }
    for(int i = 0 ; i < size ; i++) 
    {
        if(arr[i] == maxVal) 
        {
            answer = i;
        }
    }
    return answer;
}

// Method 2 --> Using binary search
int peakIndexInMountainArray2(vector<int>& arr) 
{
        int size = arr.size();
        int start = 0, end = size - 1, mid = (start + end) / 2;
        int answer;
        while(start < end) 
        {
            if(arr[mid] < arr[mid + 1]) 
            {
                start = mid + 1;
            } else 
            {
                end = mid;
            }
            mid = (start + end) / 2;
        }
        return start;
}

int main()
{

}