#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void selectionSort(vector<int> &v)
{
    cout << "Array before swap:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < v.size() ; i++)
    {
        int minIndex = i;
        for(int j = i ; j < v.size() ; j++)
        {
            if(v[j] < v[minIndex])
            {
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }

    cout << "Array after swap:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    selectionSort(v);
}