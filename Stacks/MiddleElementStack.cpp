#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int> &st, int &position, int &ans)
{
    if (position == 1)
    {
        ans = st.top();
        return;
    } 
    
    position--;
    int temp = st.top();
    st.pop();

    solve(st, position, ans);

    st.push(temp);
}

int getMiddleElement (stack<int> &st)
{
    int size = st.size();
    int position = 0;

    if (st.empty()) return -1;
    else 
    {
        if (size & 1)
        {
            position = size/2 + 1;
        } else 
        {
            position = size/2;
        }
    }
    int ans = -1;
    solve(st, position, ans);
    return ans;
}

int main()
{
    // If size = even -> position = n/2
    // If size = odd -> position = n/2 + 1

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int mid = getMiddleElement(st);
    cout << "Middle element: " << mid << endl;
}