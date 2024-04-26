#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextSmallerElement(int *arr, int size, vector<int> &next)
{
    stack<int> st;
    st.push(-1);

    for (int i = size-1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        
        next[i] = st.top(); 
        st.push(curr);
    }

    return next;
}

vector<int> prevSmallerElement(int *arr, int size, vector<int> &prev)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        
        prev[i] = st.top(); 
        st.push(curr);
    }

    return prev;
}

int main()
{
    int arr[] = {8, 4, 6, 2, 3};
    int size = 5;
    vector<int> next(size);
    nextSmallerElement(arr, size, next);
    cout << "Array is as follows:" << endl;
    for(auto i: next)
    {
        cout << i << " ";
    }

    vector<int> prev(size);
    prevSmallerElement(arr, size, prev);
    cout << "Array is as follows:" << endl;
    for(auto i: prev)
    {
        cout << i << " ";
    }
}