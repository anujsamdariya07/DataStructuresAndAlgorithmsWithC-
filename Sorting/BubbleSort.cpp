#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    cout << "The array before swap is:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v.size() ; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }

    cout << "The array after swap is:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void bubbleSort2(vector<int> &v)
{
    cout << "The array before swap is:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v.size() ; j++)
        {
            if(v[j] < v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }

    cout << "The array after swap is:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    v1 = {5, 4, 3, 2, 1};
    bubbleSort(v1);

    vector<int> v2;
    v2 = {1, 2, 3, 4, 5};
    bubbleSort2(v2);
}