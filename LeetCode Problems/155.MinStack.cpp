// vector<pair<int, int>> st;

// MinStack()
// {
// }

// void push(int val)
// {
//     if (st.empty())
//     {
//         pair<int, int> p;
//         p.first = val;
//         p.second = val;
//         st.push_back(p);
//     }
//     else
//     {
//         pair<int, int> p;
//         p.first = val;
//         p.second = min(val, st.back().second);
//         st.push_back(p);
//     }
// }

// void pop()
// {
//     if (st.empty())
//     {
//         return;
//     }
//     st.pop_back();
// }

// int top()
// {
//     pair<int, int> rightMostPair = st.back();
//     return rightMostPair.first;
// }

// int getMin()
// {
//     pair<int, int> rightMostPair = st.back();
//     return rightMostPair.second;
// }