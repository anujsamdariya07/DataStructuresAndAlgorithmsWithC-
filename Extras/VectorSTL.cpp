#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int> v)
{
    int size = v.size();
    cout << "The vector is:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void capacityChecker()
{
    vector<int> v;
    cout << "-----Capacity Checker-----" << endl;
    while(true)
    {
        int i;
        cout << "Enter a number: ";
        cin >> i;
        v.push_back(i);
        cout << "Capacity: " << v.capacity() 
        << "\nSize: " << v.size() << endl;
    }
}

int main()
{
    vector<int> v;

    // Intialisation
    v.push_back(1); 
    v.push_back(2); 
    v.push_back(3);

    // // Printing the vector
    // printVector(v);

    // // Comparing the capacity and the size 
    // // of the array
    // capacityChecker();
}