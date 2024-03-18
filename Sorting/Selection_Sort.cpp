#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> &v)
{
    cout << "Array before sort:-" << endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for(int i = 0 ;i < v.size() ; i++)
    {
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }

    cout << "Array after sorting:-" << endl;
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